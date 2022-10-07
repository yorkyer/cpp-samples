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
using namespace ns;

struct A {
    std::vector<person> ps;
};

namespace ns {
    class address {
      private:
        std::string street;
        int housenumber;
        int postcode;

      public:
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(address, street, housenumber, postcode)
    };
}

int main(int argc, char **argv)
{
    // create a person
    person p {"Ned Flanders", "744 Evergreen Terrace", 60};
    person p2 {"Nedfeafafear Flanders", "744 Evergreen Terrace", 60};

    // conversion: person -> json
    json j;
    // std::vector<person> ps = {p, p, p, p};
    // j.push_back(ps);
    j.push_back(3);
    j.push_back("hello");
    // j.push_back(ps);

    std::cout << j << std::endl;
    // {"address":"744 Evergreen Terrace","age":60,"name":"Ned Flanders"}

    // conversion: json -> person
    // A a;
    // a.ps = {p2, p2};
    // j.at(3).get_to<std::vector<person>>(a.ps);
    // std::cout << a.ps.size() << std::endl;
    // std::cout << ps.size() << std::endl;


    return 0;
}
