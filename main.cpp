#include "Generate.h"


int main () {
  time_t timer;
  unsigned seed = time(0);
  std::minstd_rand0 generator(seed);
  std::uniform_int_distribution<int> digits(0,9);
  std::string cc_num;

//for (int i = 0; i < 3; i ++) { Testing for multiple random numbers
  seed = time(&timer);
  cc_num = generate_cc(generator, digits);
  //int test = digits(generator);
  //std::cout << test << std::endl;
  std::cout << cc_num << std::endl;
//}

return 0;
}
