#include <string>
#include <vector>
#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <cstring>
#include <iostream>
#include <fstream>

#define AES_GCM_NONCE_SIZE 12

inline bool
AESGCMEncrypt(const unsigned char *in, size_t in_size, unsigned char *out, size_t *out_size, const unsigned char *key,
              size_t key_size)
{
    unsigned char iv[AES_GCM_NONCE_SIZE];
    unsigned char tag[AES_BLOCK_SIZE];

    RAND_bytes(iv, AES_GCM_NONCE_SIZE);
    memcpy(out, iv, AES_GCM_NONCE_SIZE);
    out += AES_GCM_NONCE_SIZE;

    int actual_size{0};
    int final_size{0};

    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit(ctx, EVP_aes_128_gcm(), key, iv);

    EVP_EncryptUpdate(ctx, out, &actual_size, in, in_size);

    if (actual_size != in_size) {
        std::cerr << "AESGCMEncrypt encrypt file error!" << std::endl;
        std::abort();
    }

    out += in_size;

    EVP_EncryptFinal(ctx, out, &final_size);
    EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_GET_TAG, AES_BLOCK_SIZE, tag);

    memcpy(out, tag, AES_BLOCK_SIZE);
    
    *out_size = AES_BLOCK_SIZE + AES_GCM_NONCE_SIZE + actual_size + final_size;
    
    EVP_CIPHER_CTX_free(ctx);

    return true;
}

inline bool AESGCMEncrypt(const std::string &in, std::string *out, const std::string &key)
{
    out->resize(in.size() + AES_BLOCK_SIZE + AES_GCM_NONCE_SIZE);

    size_t out_size;
    if (!AESGCMEncrypt(
            reinterpret_cast<const unsigned char *>(in.data()), in.size(),
            reinterpret_cast<unsigned char *>(out->data()), &out_size,
            reinterpret_cast<const unsigned char *>(key.data()), key.size())) {
        return false;
    }
    out->resize(out_size);

    return true;
}

inline bool
AESGCMDecrypt(const unsigned char *in, size_t in_size, unsigned char *out, size_t *out_size, const unsigned char *key,
              size_t key_size)
{
    if (in_size <= AES_BLOCK_SIZE)
        return false;

    unsigned char iv[AES_GCM_NONCE_SIZE];
    unsigned char tag[AES_BLOCK_SIZE];
    memcpy(iv, in, AES_GCM_NONCE_SIZE);
    in_size -= AES_GCM_NONCE_SIZE; // for iv
    in_size -= AES_BLOCK_SIZE; // for tag
    in += AES_GCM_NONCE_SIZE;

    int actual_size{0};
    int final_size{0};

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit(ctx, EVP_aes_128_gcm(), key, iv);
    EVP_DecryptUpdate(ctx, out, &actual_size, in, in_size);

    if (actual_size != in_size) {
        std::cerr << "AESGCMDecrypt decrypt file error!" << std::endl;
        std::abort();
    }

    in += in_size;
    out += in_size;

    memcpy(tag, in, AES_BLOCK_SIZE);
    EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_TAG, AES_BLOCK_SIZE, tag);

    int ret = EVP_DecryptFinal(ctx, out, &final_size);
    EVP_CIPHER_CTX_free(ctx);

    if (ret != 1) {
        std::cerr << "AESGCMDecrypt decrypt failure because of content corruption." << std::endl;
        return false;
    }

    *out_size = actual_size + final_size;

    return true;
}

inline bool AESGCMDecrypt(const std::string &in, std::string *out, const std::string &key)
{
    out->resize(in.size());

    size_t out_size{0};
    if (!AESGCMDecrypt(
            reinterpret_cast<const unsigned char *>(in.data()), in.size(),
            reinterpret_cast<unsigned char *>(out->data()), &out_size,
            reinterpret_cast<const unsigned char *>(key.data()), key.size())) {
        return false;
    }
    out->resize(out_size);

    return true;
}


void test()
{
    //create a sample key
    unsigned char key_bytes[16];
    RAND_bytes(key_bytes, sizeof(key_bytes));
    std::string key = std::string((char *)key_bytes, sizeof(key_bytes));
 
    //text to encrypt
    std::string plaintext= "elephants in space";
    std::cout << plaintext << std::endl;
 
    //encrypt
    std::string ciphertext;
    if (!AESGCMEncrypt(plaintext, &ciphertext, key)) {
        std::cerr << "encryption failed\n";
    }
 
    //output
    static const char *chars="0123456789ABCDEF";
    for(int i=0; i<ciphertext.size(); i++)
    {
        std::cout << chars[ciphertext[i]/16];
        std::cout << chars[ciphertext[i]%16];
    }
    std::cout << std::endl;
 
    //decrypt
    std::string out;
    bool suc = AESGCMDecrypt(ciphertext, &out, key);
    std::cout << out << std::endl;
}

std::string string_to_hex(const std::string& input)
{
    static const char hex_digits[] = "0123456789ABCDEF";

    std::string output;
    output.reserve(input.length() * 2);
    for (unsigned char c : input)
    {
        output.push_back(hex_digits[c >> 4]);
        output.push_back(hex_digits[c & 15]);
    }
    return output;
}

#include <stdexcept>

int hex_value(unsigned char hex_digit)
{
    static const signed char hex_values[256] = {
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
         0,  1,  2,  3,  4,  5,  6,  7,  8,  9, -1, -1, -1, -1, -1, -1,
        -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    };
    int value = hex_values[hex_digit];
    if (value == -1) throw std::invalid_argument("hex_value() hex_digit is invalid");
    return value;
}

std::string hex_to_string(const std::string& input)
{
    const auto len = input.length();
    if (len & 1) throw std::invalid_argument("hex_to_string() input has odd length");

    std::string output;
    output.reserve(len / 2);
    for (auto it = input.begin(); it != input.end(); )
    {
        int hi = hex_value(*it++);
        int lo = hex_value(*it++);
        output.push_back(hi << 4 | lo);
    }
    return output;
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cerr << "Usage: ./AES <file>" << std::endl;
        std::exit(1);
    }

    std::string hex_key = "e2b39a061046e945ed09622401b26c9b";
    std::string key = hex_to_string(hex_key);

    std::ifstream file(argv[1]);
    std::string str((std::istreambuf_iterator<char>(file)),
                    std::istreambuf_iterator<char>());
    std::string out;
    if (AESGCMDecrypt(str, &out, key))
        std::cout << out << std::endl;
}