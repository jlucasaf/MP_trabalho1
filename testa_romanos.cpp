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

TEST_CASE("Numeros romanos - algarismos diferentes", "[romanos]")
{
    REQUIRE(romanos_para_decimal("VI") == 6);

    REQUIRE(romanos_para_decimal("VII") == 7);

    REQUIRE(romanos_para_decimal("VIII") == 8);

    REQUIRE(romanos_para_decimal("IV") == 4);
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

TEST_CASE("Numeros romanos - algarismo válido com inválido", "[romanos]")
{
    REQUIRE(romanos_para_decimal("iM") == -1);

    REQUIRE(romanos_para_decimal("Mi") == -1);

    REQUIRE(romanos_para_decimal("MMi") == -1);

    REQUIRE(romanos_para_decimal("MiI") == -1);

    REQUIRE(romanos_para_decimal("MMMiI") == -1);

    REQUIRE(romanos_para_decimal("MMMiII") == -1);

    REQUIRE(romanos_para_decimal("MMMiIII") == -1);
}

TEST_CASE("Numeros romanos - algarismos invalidos", "[romanos]")
{
    REQUIRE(romanos_para_decimal("G") == -1);

    REQUIRE(romanos_para_decimal("i") == -1);
}
