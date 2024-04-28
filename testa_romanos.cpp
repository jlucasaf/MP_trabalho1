#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "romanos.hpp"

TEST_CASE("Numeros romanos - algarismos unicos", "[romanos]")
{
    REQUIRE(romanos_para_decimal("I") == 1);

    REQUIRE(romanos_para_decimal("V") == 5);

    REQUIRE(romanos_para_decimal("X") == 10);

    REQUIRE(romanos_para_decimal("L") == 50);

    REQUIRE(romanos_para_decimal("C") == 100);

    REQUIRE(romanos_para_decimal("D") == 500);

    REQUIRE(romanos_para_decimal("M") == 1000);
}

TEST_CASE("Numeros romanos - algarismos multiplos iguais", "[romanos]")
{
    REQUIRE(romanos_para_decimal("II") == 2);

    REQUIRE(romanos_para_decimal("III") == 3);

    REQUIRE(romanos_para_decimal("XX") == 20);

    REQUIRE(romanos_para_decimal("XXX") == 30);

    REQUIRE(romanos_para_decimal("CC") == 200);

    REQUIRE(romanos_para_decimal("CCC") == 300);

    REQUIRE(romanos_para_decimal("MM") == 2000);

    REQUIRE(romanos_para_decimal("MMM") == 3000);
}

TEST_CASE("Numeros romanos - algarismos multiplos iguais invalidos", "[romanos]")
{
    REQUIRE(romanos_para_decimal("VV") == -1);

    REQUIRE(romanos_para_decimal("LL") == -1);

    REQUIRE(romanos_para_decimal("DD") == -1);

    REQUIRE(romanos_para_decimal("IIII") == -1);

    REQUIRE(romanos_para_decimal("XXXX") == -1);

    REQUIRE(romanos_para_decimal("CCCC") == -1);
    
    REQUIRE(romanos_para_decimal("MMMM") == -1);

}

TEST_CASE("Numeros romanos - algarismos invalidos", "[romanos]")
{
    REQUIRE(romanos_para_decimal("G") == -1);

    REQUIRE(romanos_para_decimal("i") == -1);
}
