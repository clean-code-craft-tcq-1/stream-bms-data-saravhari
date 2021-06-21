#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test_receiver.h"

#include "test/catch.hpp"
#include "Bms_Receiver/Receiver_DataCalc.h"
#include "Bms_Receiver/Receiver_RxData.h"
#include "stddef.h"
#include "string.h"

TEST_CASE("Test case to test the Maximum Value with lesser Value")
{
  float current_value = 10.1;
  float prev_maxi = 20.2;
  float max_value = 20.2;
  float prev_min = 0;
  Calc_MinMax(current_value, &prev_maxi, &prev_min);
  REQUIRE(max_value == prev_maxi);
}

TEST_CASE("Test case to test the Maximum Value with greater Value")
{
  float current_value = 100.8;
  float prev_maxi = 2;
  float prev_min = 0;
  float max_value = 100.8;
  Calc_MinMax(current_value, &prev_maxi, &prev_min);
  REQUIRE(current_value == max_value);
}

TEST_CASE("Test case to test the Maximum Value with Negative Value")
{
  float current_value = -1.8;
  float prev_maxi = -29;
  float max_value = -1.8;
  float prev_min = 0;
  Calc_MinMax(current_value, &prev_maxi, &prev_min);
  REQUIRE(prev_maxi == max_value);
}

TEST_CASE("Test case to test the Minimum Value with lesser Value")
{
  float current_value = 9.8;
  float prev_min = 11.8;
  float min_value = 9.8;
  float prev_maxi = 0;
  Calc_MinMax(current_value, &prev_maxi, &prev_min);
  REQUIRE(prev_min == current_value);
}

TEST_CASE("Test case to test the Minimum Value with greater Value")
{
  float current_value = 187.5;
  float prev_min = 181.8;
  float min_value = 181.8;
  float prev_maxi = 0;
  Calc_MinMax(current_value, &prev_maxi, &prev_min);
  REQUIRE(prev_min == min_value);
}

TEST_CASE("Test case to test the Minimum Value with negative Value")
{
  float current_value = -0.5;
  float prev_min = -1.8;
  float mini_value = -1.8;
  float prev_maxi = 0;
  Calc_MinMax(current_value, &prev_maxi, &prev_min);
  REQUIRE(prev_min == mini_value);
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
}

TEST_CASE("Test case to test with Dummy Data")
{
  /*#if(TEST_ON == TRUE)
void test_Scanf(char *rv_data)
{
	char data[100] = "{\"temperature\":36.19,\"soc\":56.37,\"chargeRate\":0.72}";
	strcpy(rv_data , data);
}
#endif*/
  /* Dummy data sent */
  REQUIRE(receive_data() == 0);
}

TEST_CASE("Test case to test the decode operation")
{
	char *Copy_buffer = {"{\"temperature\":96.59,\"soc\":57.17,\"chargeRate\":0.39}"};
	float temperature =0;
	float soc =0;
	float chargerate=0;
	float epsilon = 0.001;
	decode_data(Copy_buffer, &temperature, &soc, &chargerate);
	REQUIRE(abs(temperature - 96.59) < epsilon);
}

TEST_CASE("Test case to test the Min Max Average")
{
	float temperature = 21.78;
	float soc = 41.78;
	float chargerate = 0.42;
	analyse_data( temperature, soc, chargerate);
}

