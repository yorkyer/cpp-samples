#include <iostream>
#include <string.h>
#include <string>
#include <memory>

namespace POIDef {

struct Item {
    int64_t price;
    int64_t qty;
    int64_t a;
    int64_t b;
};

struct Header {
    int acc;
    int oid;
    int asn;
    int a;
    int b;
    int c;
};

}

template<typename Header, typename Item>
struct MsgTemplate
{
    Header header;
    int nItem;
    Item items[0];

    static size_t nbytes(int nItem)
    {
        size_t off = (size_t)(&((MsgTemplate<Header, Item>*)0)->items[0]);
        std::cout << "off: " << off << std::endl;
        return off + nItem * sizeof(Item);
    }

    size_t nbytes() const
    {
        return nbytes(nItem);
    }

    struct free_deleter
    {
        template <typename T>
        void operator()(T *p) const { std::free(const_cast<std::remove_const_t<T>*>(p)); }
    };

    template <typename T>
    using unique_c_ptr = std::unique_ptr<T, free_deleter>;

    using msg_ptr = MsgTemplate<Header, Item>*;
    using unique_msg_ptr = unique_c_ptr<MsgTemplate<Header, Item>>;

    static unique_msg_ptr alloc(int nItem)
    {
        msg_ptr ptr = (msg_ptr)std::malloc(nbytes(nItem));
        ptr->nItem = nItem;
        return unique_msg_ptr(ptr);
    }

    std::string dump() const
    {
        std::string buf(nbytes(), ' ');
        memcpy(&buf[0], this, buf.size());
        return buf;
    }

    static const MsgTemplate<Header, Item>* load(const std::string &buf)
    {
        return (MsgTemplate*)&buf[0];
    }
};

typedef MsgTemplate<POIDef::Header, POIDef::Item> POI;

int main()
{
    auto obj = POI::alloc(3);
    obj->header.acc = 123;
    obj->header.oid = 456;
    obj->header.asn = 789;
    obj->items[0] = {100, 1500, 1, 2};
    obj->items[1] = {110, 300, 1, 2};
    obj->items[2] = {120, 800, 1, 2};

    printf("%p\n", obj.get());

    // ser
    std::string buf = obj->dump();

    std::cout << buf << std::endl;

    // deser
    auto *obj2 = POI::load(buf);

    auto obj3 = POI::alloc(obj2->nItem);
    obj3->header = obj2->header;
    for (int i = 0; i < obj2->nItem; i++) {
        obj3->items[i] = obj2->items[i];
    }
    obj = std::move(obj3);

    for (int i = 0; i < obj->nItem; i++) {
        auto &item = obj->items[i];
        printf("%ld %ld\n", item.price, item.qty);
    }

    printf("%p\n", obj.get());

    return 0;
}