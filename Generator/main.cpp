#include "Generate.h"


int main () {
  std::ofstream file;
  file.open("information.txt", std::ios::out | std::ios::app);
  Generator account_info("ThisIsATest.txt");

  std::string full; //Full String of all fields

for (int i = 0; i < 1000; i ++) {
  full = account_info.generate_full();
  file << full;

}
file.close();
account_info.write_to_file();

return 0;
}
