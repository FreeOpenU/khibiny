#include "Generate.h"


std::string generate_holder(std::minstd_rand0 &generator, std::uniform_int_distribution<int> index) {
  std::string full_name = "";

  return full_name;
}

std::string generate_acc(std::minstd_rand0 &generator, std::uniform_int_distribution<int> digits) {
  std::string account_num = "Account Number: ";

  for (int i = 0; i < 10; i++) { //The Typical bank account has 9 or 10 digits to safely hold its member count
    int num = digits(generator);
    account_num += std::to_string(num);
  }
  return account_num;
}

std::string generate_money(std::minstd_rand0 & generator,
                          std::uniform_int_distribution<int> size) {

  std::string full_string = "";

  std::string checking = "Checking: $";
  std::string check_amount;

  std::string savings = "Savings: $";
  std::string savings_amount;

  std::uniform_int_distribution<int> change(10,99);

  int change_check = change(generator);
  int change_savings = change(generator);

  int check_amount_int = digits(generator);
  int savings_amount_int = digits(generator);

  checking += std::to_string(check_amount_int);
  checking += ".";
  checking += std::to_string(change_check);

  savings += std::to_string(savings_amount_int);
  savings += ".";
  savings += std::to_string(change_savings);

  full_string = checking + " " + savings;

  return full_string;

}

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
                         std::uniform_int_distribution<int> months) {
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
