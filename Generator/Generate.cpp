#include "Generate.h"




std::string generate_cc(std::minstd_rand0 & generator,
                        std::uniform_int_distribution<int> digits) {
  std::string cc_num = "Credit Card Number: ";

  for (int i = 0; i < 16; i++) { //Typical credit card has 16 digits
    if (i > 0 && i % 4 == 0) {
      cc_num += " ";
    }
    int num = digits(generator);
    cc_num += std::to_string(num);
  }
  return cc_num;

}

std::string generate_exp(std::minstd_rand0 & generator,
                         std::uniform_int_distribution<int> digits) {
  std::string expiration = "EXP: ";
  std::string month;
  std::string year;

  int month_num = digits(generator);
  if (month_num < 10) {
    expiration += "0";
  }
  expiration += std::to_string(month_num);

  expiration += "/";

  int year_num = digits(generator);
  if (year_num < 10) {
    expiration += "0";
  }
  expiration += std::to_string(year_num);

  return expiration;

}
