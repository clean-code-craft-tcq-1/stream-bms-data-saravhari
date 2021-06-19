#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "Bms_Receiver/Receiver_DataCalc.h"
#include "stddef.h"
#include "string.h"


TEST_CASE("Test case to test the Maximum Value with less Value")
{
  REQUIRE(Calc_Maxi(10.1, 20.1)== 20.1);
}

