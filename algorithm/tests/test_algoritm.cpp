#include "catch2/catch.hpp"


TEST_CASE("algo tests") {
    SECTION("Sanity check", "[adder]") {
        int four = 4;
        REQUIRE(four == 4);
    }
}