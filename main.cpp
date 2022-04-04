#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

#include <iostream>

class A {
public:
    A() = default;
    void hello() { std::cout << "hello" << "\n"; }
};

TEST_SUITE("My TestSuite") {

TEST_CASE("This is a test") {
        auto test_obj = A{};
        CHECK_NOTHROW(test_obj.hello());
    }
}

