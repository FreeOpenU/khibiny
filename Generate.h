#ifndef __GENERATE_H__
#define __GENERATE_H__
#include <string>
#include <iostream>
#include <random>
#include <ctime>


std::string generate_cc(std::minstd_rand0 generator, std::uniform_int_distribution<int> digits);
std::string generate_exp(std::minstd_rand0 generator, std::uniform_int_distribution<int> digits);




#endif
