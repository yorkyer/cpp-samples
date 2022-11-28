#include <bits/stdc++.h> 
#include <pprint.hpp>
#include <backward.hpp>
#include <spdlog/spdlog.h>
#include <pystring.h>
#include <mio/mmap.hpp>
#include <spy/spy.hpp>
#include <args.hxx>
#include <tscns.h>
#include <nlohmann/json.hpp>
#include <LatencyStat.hpp>


namespace backward
{
    backward::SignalHandling sh;
}


using namespace std;
using namespace nlohmann;


#define P(...) \
do { \
    pprint::PrettyPrinter printer; \
    printer.quotes(false); \
    printer.compact(false); \
    printer.print(__VA_ARGS__); \
} while (0)

constexpr static int PSTA_SIZE{6};
struct PrivateOrdersInfo
{
    struct PSTA
    {
        //   0: default
        //   1: success
        //   -1: Use unconditional_sta because normalized_ntl_in_front is smaller than model_normalized_ntl_in_front.
        //   -2: Not inference because normalized_ntl_in_front is bigger than inference_normalized_ntl_in_front.
        //   -3: Not inference because there are no 5 price levels around bbo (near limit).
        //   -4: Not inference because our order is not among the best 5 price levels.
        //   -5: Not inference because time is not long enough to get lag_180s ticks. (the beginning 3 minutes of trading).
        int successState{0};
        double price{-1};
        double atr{-1};
        double fp10{-1};
        double fp300{-1};
        double reserved0{-1};
        double reserved1{-1};
        double reserved2{-1};
        double reserved3{-1};
        double reserved4{-1};
        double reserved5{-1};
    };
    struct POrder
    {
        int64_t accountId{-1};
        int64_t orderId{-1};
        double price{-1};
        int direction{-1};
        int64_t originalSize{-1};
        int64_t remainingSize{-1};
        int numOrderInFront{-1};
        int64_t qtyInFront{-1};
        PSTA sta;
    };
    int secid{-1};
    int64_t sequenceNo{-1};
    int64_t ApplSeqNum{-1};
    std::array<PSTA, PSTA_SIZE> bidSta;
    std::array<PSTA, PSTA_SIZE> askSta;
    std::vector<POrder> orders;
    int version{-1};
};

// void to_json(json& j, const PrivateOrdersInfo::PSTA& psta)
// {
//     j.push_back(psta.successState);
//     j.push_back(psta.price);
//     j.push_back(psta.atr);
//     j.push_back(psta.fp10);
//     j.push_back(psta.fp300);
//     j.push_back(psta.reserved0);
//     j.push_back(psta.reserved1);
//     j.push_back(psta.reserved2);
//     j.push_back(psta.reserved3);
//     j.push_back(psta.reserved4);
//     j.push_back(psta.reserved5);
// }

// void from_json(const json& j, PrivateOrdersInfo::PSTA& psta)
// {
//     j[0].get_to(psta.successState);
//     j[1].get_to(psta.price);
//     j[2].get_to(psta.atr);
//     j[3].get_to(psta.fp10);
//     j[4].get_to(psta.fp300);
//     j[5].get_to(psta.reserved0);
//     j[6].get_to(psta.reserved1);
//     j[7].get_to(psta.reserved2);
//     j[8].get_to(psta.reserved3);
//     j[9].get_to(psta.reserved4);
//     j[10].get_to(psta.reserved5);
// }

// void to_json(json& j, const PrivateOrdersInfo::POrder& order)
// {
//     j.push_back(order.accountId);
//     j.push_back(order.orderId);
//     j.push_back(order.price);
//     j.push_back(order.direction);
//     j.push_back(order.originalSize);
//     j.push_back(order.remainingSize);
//     j.push_back(order.numOrderInFront);
//     j.push_back(order.qtyInFront);
//     j.push_back(order.sta);
// }

// void from_json(const json& j, PrivateOrdersInfo::POrder& order)
// {
//     j[0].get_to(order.accountId);
//     j[1].get_to(order.orderId);
//     j[2].get_to(order.price);
//     j[3].get_to(order.direction);
//     j[4].get_to(order.originalSize);
//     j[5].get_to(order.remainingSize);
//     j[6].get_to(order.numOrderInFront);
//     j[7].get_to(order.qtyInFront);
//     j[8].get_to(order.sta);
// }

// void to_json(json& j, const PrivateOrdersInfo& pOrdersInfo)
// {
//     j.push_back(pOrdersInfo.secid);
//     j.push_back(pOrdersInfo.sequenceNo);
//     j.push_back(pOrdersInfo.ApplSeqNum);
//     j.push_back(pOrdersInfo.bidSta);
//     j.push_back(pOrdersInfo.askSta);
//     j.push_back(pOrdersInfo.orders);
//     j.push_back(pOrdersInfo.version);
// }

// void from_json(const json &j, PrivateOrdersInfo &pOrdersInfo)
// {
//     j[0].get_to(pOrdersInfo.secid);
//     j[1].get_to(pOrdersInfo.sequenceNo);
//     j[2].get_to(pOrdersInfo.ApplSeqNum);
//     j[3].get_to<std::array<PrivateOrdersInfo::PSTA, PSTA_SIZE>>(pOrdersInfo.bidSta);
//     j[4].get_to<std::array<PrivateOrdersInfo::PSTA, PSTA_SIZE>>(pOrdersInfo.askSta);
//     j[5].get_to<std::vector<PrivateOrdersInfo::POrder>>(pOrdersInfo.orders);
//     j[6].get_to<int>(pOrdersInfo.version);
// }

void to_json(json& j, const PrivateOrdersInfo::PSTA& psta)
{
    j["successState"] = psta.successState;
    j["price"] = psta.price;
    j["atr"] = psta.atr;
    j["fp10"] = psta.fp10;
    j["fp300"] = psta.fp300;
    j["reserved0"] = psta.reserved0;
    j["reserved1"] = psta.reserved1;
    j["reserved2"] = psta.reserved2;
    j["reserved3"] = psta.reserved3;
    j["reserved4"] = psta.reserved4;
    j["reserved5"] = psta.reserved5;
}

void from_json(const json& j, PrivateOrdersInfo::PSTA& psta)
{
    j.at("successState").get_to(psta.successState);
    j.at("price").get_to(psta.price);
    j.at("atr").get_to(psta.atr);
    j.at("fp10").get_to(psta.fp10);
    j.at("fp300").get_to(psta.fp300);
    j.at("reserved0").get_to(psta.reserved0);
    j.at("reserved1").get_to(psta.reserved1);
    j.at("reserved2").get_to(psta.reserved2);
    j.at("reserved3").get_to(psta.reserved3);
    j.at("reserved4").get_to(psta.reserved4);
    j.at("reserved5").get_to(psta.reserved5);
}

void to_json(json& j, const PrivateOrdersInfo::POrder& order)
{
    j["accountId"] = order.accountId;
    j["orderId"] = order.orderId;
    j["price"] = order.price;
    j["direction"] = order.direction;
    j["originalSize"] = order.originalSize;
    j["remainingSize"] = order.remainingSize;
    j["numOrderInFront"] = order.numOrderInFront;
    j["qtyInFront"] = order.qtyInFront;
    j["sta"] = order.sta;
}

void from_json(const json& j, PrivateOrdersInfo::POrder& order)
{
    j.at("accountId").get_to(order.accountId);
    j.at("orderId").get_to(order.orderId);
    j.at("price").get_to(order.price);
    j.at("direction").get_to(order.direction);
    j.at("originalSize").get_to(order.originalSize);
    j.at("remainingSize").get_to(order.remainingSize);
    j.at("numOrderInFront").get_to(order.numOrderInFront);
    j.at("qtyInFront").get_to(order.qtyInFront);
    j.at("sta").get_to(order.sta);
}

void to_json(json& j, const PrivateOrdersInfo& pOrdersInfo)
{
    j["secid"] = pOrdersInfo.secid;
    j["sequenceNo"] = pOrdersInfo.sequenceNo;
    j["ApplSeqNum"] = pOrdersInfo.ApplSeqNum;
    j["bidSta"] = pOrdersInfo.bidSta;
    j["askSta"] = pOrdersInfo.askSta;
    j["orders"] = pOrdersInfo.orders;
    j["version"] = pOrdersInfo.version;
}

void from_json(const json &j, PrivateOrdersInfo &pOrdersInfo)
{
    j.at("secid").get_to(pOrdersInfo.secid);
    j.at("sequenceNo").get_to(pOrdersInfo.sequenceNo);
    j.at("ApplSeqNum").get_to(pOrdersInfo.ApplSeqNum);
    j.at("bidSta").get_to<std::array<PrivateOrdersInfo::PSTA, PSTA_SIZE>>(pOrdersInfo.bidSta);
    j.at("askSta").get_to<std::array<PrivateOrdersInfo::PSTA, PSTA_SIZE>>(pOrdersInfo.askSta);
    j.at("orders").get_to<std::vector<PrivateOrdersInfo::POrder>>(pOrdersInfo.orders);
    j.at("version").get_to<int>(pOrdersInfo.version);
}

struct PrivateOrderMessage
{
    PrivateOrdersInfo privateOrdersInfo;

    std::string serialize() const;
    void deserialize(const std::string &data);
    std::string toText() const { return serialize(); }
};

std::string PrivateOrderMessage::serialize() const
{
    json j;
    j["privateOrdersInfo"] = privateOrdersInfo;
    return j.dump();
}

void PrivateOrderMessage::deserialize(const std::string &data)
{
    nlohmann::json j = nlohmann::json::parse(data);
    privateOrdersInfo = j.at("privateOrdersInfo");
}

PrivateOrderMessage pom;

int main(int argc, char **argv)
{
    TSCNS tscns;
    tscns.init();

    LatencyStat stat1("seralize", 10000);
    LatencyStat stat2("deseralize", 10000);

    for (int i = 0; i < 100000; i++) {
        auto t1 = tscns.rdns();
        std::string s = pom.serialize();
        auto t2 = tscns.rdns();
        pom.deserialize(s);
        auto t3 = tscns.rdns();

        stat1.stat(t2 - t1, true);
        stat2.stat(t3 - t2, true);
    }

    return 0;
}
