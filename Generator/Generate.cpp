#include "Generate.h"



Generator::Generator(std::string file) {
  this->fileName = file;
}

void Generator::write_to_file(int iterations) {
  //Idea: If future types of information is made for generation, could use Enums to write different types
  std::ofstream file;
  file.open(this->fileName, std::ios::out | std::ios::app);
  std::string full;
  for (int i = 0; i < iterations; i ++) {
    full = generate_full();
    file << full << std::endl;
  }
  file.close();
}

std::string Generator::generate_full() {
    std::string full = "";
    std::string holder = generate_holder(this->generator, this->first_name_range, this->last_name_range);
    std::string account = generate_acc(this->generator, this->digits);
    std::string money = generate_money(this->generator, this->money_range);
    std::string credit_card = generate_cc(this->generator, this->digits);
    std::string expiration = generate_exp(this->generator, this->months);

    full = holder + "\n" + account + "\n" + money + "\n" + credit_card + "\n" + expiration + "\n";
    return full;
}


std::string Generator::generate_holder(std::minstd_rand0 &generator, std::uniform_int_distribution<int> first_index,
                                        std::uniform_int_distribution<int>last_index) {
  std::string full_name = "";
  std::string first_name = this->first_names[first_index(generator)]; //Grabs a random first name from first_name vector
  std::string last_name = this->last_names[last_index(generator)]; //Grabs a random last name from last_name vector

  full_name = first_name + " " + last_name;
  return full_name;
}

std::string Generator::generate_acc(std::minstd_rand0 &generator, std::uniform_int_distribution<int> digits) {
  std::string account_num = "Account Number: ";

  for (int i = 0; i < 10; i++) { //The Typical bank account has 9 or 10 digits to safely hold its member count
    int num = digits(generator);
    account_num += std::to_string(num);
  }
  return account_num;
}

std::string Generator::generate_money(std::minstd_rand0 & generator,
                          std::uniform_int_distribution<int> size) {

  std::string full_string = "";

  std::string checking = "Checking: $";
  std::string check_amount;

  std::string savings = "Savings: $";
  std::string savings_amount;

  std::uniform_int_distribution<int> change(10,99);

  int change_check = change(generator);
  int change_savings = change(generator);

  int check_amount_int = size(generator);
  int savings_amount_int = size(generator);

  checking += std::to_string(check_amount_int);
  checking += ".";
  checking += std::to_string(change_check);

  savings += std::to_string(savings_amount_int);
  savings += ".";
  savings += std::to_string(change_savings);

  full_string = checking + " " + savings;

  return full_string;

}

std::string Generator::generate_cc(std::minstd_rand0 & generator,
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

std::string Generator::generate_exp(std::minstd_rand0 & generator,
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
