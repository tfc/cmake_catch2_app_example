#include <catch2/catch.hpp>

#include <lib.hpp>

TEST_CASE( "plus function adds", "[plus]" ) {
    REQUIRE( plus(1, 2) == 3 );
}
