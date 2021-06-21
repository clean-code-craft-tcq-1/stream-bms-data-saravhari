#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "Bms_Receiver/Receiver_DataCalc.h"
#include "stddef.h"
#include "string.h"


/*TEST_CASE("Test case to test the Maximum Value with lesser Value")
{
  float current_value = 10.1;
  float prev_maxi = 20.2;
  float max_value = 20.2;
  REQUIRE(Calc_Maxi(current_value, prev_maxi) == max_value);
}

TEST_CASE("Test case to test the Maximum Value with greater Value")
{
  float current_value = 100.8;
  float prev_maxi = 2;
  float max_value = 100.8;
  REQUIRE(Calc_Maxi(current_value, prev_maxi) == max_value);
}

TEST_CASE("Test case to test the Maximum Value with Negative Value")
{
  float current_value = -1.8;
  float prev_maxi = -29;
  float max_value = -1.8;
  REQUIRE(Calc_Maxi(current_value, prev_maxi) == max_value);
}

TEST_CASE("Test case to test the Minimum Value with lesser Value")
{
  float current_value = 9.8;
  float prev_mini = 11.8;
  float mini_value = 9.8;
  REQUIRE(Calc_Mini(current_value, prev_mini) == mini_value);
}

TEST_CASE("Test case to test the Minimum Value with greater Value")
{
  float current_value = 187.5;
  float prev_mini = 181.8;
  float mini_value = 181.8;
  REQUIRE(Calc_Mini(current_value, prev_mini) == mini_value);
}

TEST_CASE("Test case to test the Minimum Value with negative Value")
{
  float current_value = -0.5;
  float prev_mini = -1.8;
  float mini_value = -1.8;
  REQUIRE(Calc_Mini(current_value, prev_mini) == mini_value);
}

TEST_CASE("Test case to test the Average Value")
{
  float arr[] = {10.3,10.1};
  float average = (10.3+10.1)/2;
  float calc_aver = 0;
  float epsilon = 0.001;
  calc_aver = Calc_Average(arr, 2);
  REQUIRE(abs(calc_aver - average) < epsilon);
}

TEST_CASE("Test case to test the empty array for average")
{
  float arr[] = {};
  float average = 0;
  REQUIRE(Calc_Average(arr, 0) == average);
}*/
