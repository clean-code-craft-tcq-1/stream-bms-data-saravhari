#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "Bms_Receiver/Receiver_DataCalc.h"
#include "stddef.h"
#include "string.h"


TEST_CASE("Test case to test the Maximum Value with less Value")
{
  float current_value = 10.1;
  float prev_maxi = 20.1;
  float max_value = 20.1;
  REQUIRE(Calc_Max(current_value, prev_maxi) == max_value);
}

