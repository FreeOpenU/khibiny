#include "Generate.h"
#include <fstream>

int main () {
  std::ofstream file;
  file.open("information.txt", std::ios::out | std::ios::app);

  time_t timer;
  unsigned seed = time(&timer);
  std::minstd_rand0 generator(seed);
  std::uniform_int_distribution<int> digits(0,9);
  std::uniform_int_distribution<int> months(0,12);
  std::string full; //Full String of all fields
  std::string cc_num; //Credit Card Number
  std::string exp; //Expiration Date

for (int i = 0; i < 3; i ++) { //Testing for multiple random numbers

  exp = generate_exp(generator, months);
  cc_num = generate_cc(generator, digits);

  full = cc_num + ' ' + exp;

  file << full << std::endl;
  std::cout << full << std::endl;
}

  file.close();
return 0;
}
