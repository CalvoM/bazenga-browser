#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "DomTokenList.hpp"
#include "doctest.h"
int factorial(int number) { return number <= 1 ? number : factorial(number - 1) * number; }

TEST_CASE("Testing DOMTokenList operations"){
    DomTokenList list;
    std::vector<std::string> classes{"medium","check","large","small",};
    CHECK(list.length==0);
    CHECK(list.contains("padded")==false);
    
    SUBCASE("Adding to the list should increase size"){
        list.add(classes);
        CHECK(list.length==4);

    }
    SUBCASE("Removing from the list should decrease size"){
        list.add(classes);
        list.remove(classes);
        CHECK(list.length==4);
    }
    SUBCASE("Adding to the list and check if token is present"){
        list.add(classes);
        CHECK(list.contains("medium")==true);
    }
    SUBCASE("Adding to the list and check if token is not present"){
        list.add(classes);
        CHECK(list.contains("extra")==false);
    }
    SUBCASE("Check index of tokens"){
        list.add(classes);
        CHECK(list[0]=="medium");
    }
}
