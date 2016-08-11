#include "Generate.h"




std::string generate_cc(std::minstd_rand0 generator,
                        std::uniform_int_distribution<int> digits) {
  std::string cc_num = "";

  char buffer[1];
  for (int i = 0; i < 16; i++) { //Typical credit card has 16 digits
    if (i > 0 && i % 4 == 0) {
      cc_num += " ";
    }
    int num = digits(generator);
    cc_num += std::to_string(num);
    //std::cout << cc_num << std::endl;
  }
  return cc_num;

}

std::string generate_exp(std::minstd_rand0 generator,
                         std::uniform_int_distribution<int> digits) {
  std::string expiration = "";
  std::string start;
  std::string end;

  return expiration;

}
