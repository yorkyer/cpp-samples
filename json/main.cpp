#include<bits/stdc++.h>
#include <nlohmann/json.hpp>

using namespace nlohmann;
namespace ns {
    // a simple struct to model a person
    struct person {
        std::string name;
        std::string address;
        int age;
    };

    void to_json(json& j, const person& p) {
        j = json{{"name", p.name}, {"address", p.address}, {"age", p.age}};
    }

    void from_json(const json& j, person& p) {
        j.at("name").get_to(p.name);
        j.at("address").get_to(p.address);
        j.at("age").get_to(p.age);
    }
} // namespace ns


// void to_json(json &j, const Object& a) {
//     j["c"] = a.c;
// }


// void from_json(const json &j, Object& a) {
//     j.at("c").get_to<int>(a.c);
// }

// void to_json(json &j, const std::vector<Object>& a) {
//     j["c"] = a;
// }


// void from_json(const json &j, std::vector<Object>& a) {
//     j.at("c").get_to<std::vector<Object>>(a);
// }

// struct A {
//     std::vector<int> b{1,2};
// };

// void to_json(json &j, const A& a){
//     j["b"] = a.b;
// }

// void from_json(const json &j, A& a) {
//     a.b = j.at("b").get<std::vector<int>>();
// }

/** @important 
  * The functions from_json and to_json must be defined in the same namespace as the type. They must not be member functions.
  */
// using namespace ns;

// struct A {
//     std::vector<person> ps;
// };

// namespace ns {
//     class address {
//       private:
//         std::string street;
//         int housenumber;
//         int postcode;

//       public:
//         NLOHMANN_DEFINE_TYPE_INTRUSIVE(address, street, housenumber, postcode)
//     };
// }

// struct A {
//     int a;
//     int b;
// };

// struct B {
//     int a;
// };

// void to_json(json& j, const A& a)
// {
//     j["a"] = a.a;
//     j["b"] = a.b;
// }

// void from_json(const json& j, A& a)
// {
//     j.at("a").get_to(a.a);
//     j.at("b").get_to(a.b);
// }

// void to_json(json& j, const B& a)
// {
//     j["a"] = a.a;
// }

// void from_json(const json& j, B& a)
// {
//     j.at("a").get_to(a.a);
// }

// #define PARSE_CONFIG_FIELD(field, type) \
// do { \
//     if (data.contains(#field)) { \
//         data[#field].get_to<type>(config.field); \
//     } \
//     else { \
//         std::cerr << "config.json needs <" #field "> field." << std::endl; \
//         exit(EXIT_FAILURE); \
//     } \
// } while (0)

// Config parse_config(int argc, char **argv)
// {
//     if (argc != 2) {
//         std::cerr << "Usage: ./runner config.json" << std::endl;
//         exit(EXIT_FAILURE);
//     }

//     Config config;
//     json data = json::parse(std::ifstream(argv[1]));

//     std::cout << data << std::endl;

//     PARSE_CONFIG_FIELD(order_path, std::string);
//     PARSE_CONFIG_FIELD(trade_path, std::string);
//     PARSE_CONFIG_FIELD(md_path, std::string);
//     PARSE_CONFIG_FIELD(sta_path, std::string);
//     PARSE_CONFIG_FIELD(feat_meta_path, std::string);
//     PARSE_CONFIG_FIELD(model_meta_path, std::string);
//     PARSE_CONFIG_FIELD(feat_lib_path, std::string);
//     PARSE_CONFIG_FIELD(order_lib_path, std::string);
//     PARSE_CONFIG_FIELD(feat_out_path, std::string);
//     PARSE_CONFIG_FIELD(order_out_path, std::string);

//     PARSE_CONFIG_FIELD(bid_insert_latency, int);
//     PARSE_CONFIG_FIELD(ask_insert_latency, int);
//     PARSE_CONFIG_FIELD(bid_cancel_latency, int);
//     PARSE_CONFIG_FIELD(ask_cancel_latency, int);

//     PARSE_CONFIG_FIELD(out_early_stop, int);

//     return config;
// }

// constexpr static int PSTA_SIZE{6};
// struct PrivateOrdersInfo
// {
//     struct PSTA
//     {
//         int successState{0};
//             // 0 default
//             // 1 success
//             // -1,-2,-3,-4 are failure reasons
//         double price{-1};
//         double atr{-1};
//         double fp10{-1};
//         double fp300{-1};
//         double reserved0{-1};
//         double reserved1{-1};
//         double reserved2{-1};
//         double reserved3{-1};
//         double reserved4{-1};
//         double reserved5{-1};
//     };
//     struct POrder
//     {
//         int64_t accountId{-1};
//         int64_t orderId{-1};
//         double price{-1};
//         int direction{-1};
//         int64_t originalSize{-1};
//         int64_t remainingSize{-1};
//         int numOrderInFront{-1};
//         int64_t qtyInFront{-1};
//         PSTA sta;
//     };
//     int secid{-1};
//     int64_t sequenceNo{-1};
//     int64_t ApplSeqNum{-1};
//     std::array<PSTA, PSTA_SIZE> bidSta;
//     std::array<PSTA, PSTA_SIZE> askSta;
//     std::vector<POrder> orders;
//     int version{-1};
// };

int main(int argc, char **argv)
{
    // std::cout << "Version: " << VERSION << std::endl;
    // Config config = parse_config(argc, argv);
    // create a person
    // person p {"Ned Flanders", "744 Evergreen Terrace", 60};
    // person p2 {"Nedfeafafear Flanders", "744 Evergreen Terrace", 60};

    // // conversion: person -> json
    // json j;
    // // std::vector<person> ps = {p, p, p, p};
    // // j.push_back(ps);
    // j.push_back(3);
    // j.push_back("hello");
    // // j.push_back(ps);

    // std::cout << j << std::endl;
    // {"address":"744 Evergreen Terrace","age":60,"name":"Ned Flanders"}

    // conversion: json -> person
    // A a;
    // a.ps = {p2, p2};
    // j.at(3).get_to<std::vector<person>>(a.ps);
    // std::cout << a.ps.size() << std::endl;
    // std::cout << ps.size() << std::endl;


    // json config = json::parse(std::ifstream("config.json"));
    // std::cout << config["order_pat234h"].get<std::string>() << std::endl;
    // std::cout << config["bid_insert_latency"].get<int>() << std::endl;
    // if (config.contains("bid_insert_latency")) {
    //     std::cout << true << std::endl;
    // }
    return 0;
}
