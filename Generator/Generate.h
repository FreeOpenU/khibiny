#ifndef __GENERATE_H__
#define __GENERATE_H__
#include <string>
#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include <fstream>

class Generator {
public:
  //Generator class creates a generator object that can create different string fields for output
  //Generator class is initialized with a string for a filename to use for output.
  //write_to_file handles the output to a file and takes an unsigned for the number of iterations. This determines the size of the file.

  //Pass random number generator by reference so generator isn't initialized with same seed for each function call
  Generator(std::string file="Information.txt");
  void write_to_file(unsigned iterations=1000000); //Iterations determine size of file, Example, 10,000,000 provides a 1.3 GB File.
                                        //Default will provide a ~130 MB File.
  std::string generate_full();
   //generate_full() Combines all fields to create a full string

  std::string generate_holder(std::minstd_rand0 &generator, std::uniform_int_distribution<int> first_index,
                                std::uniform_int_distribution<int> last_index);
  //generate_holder() Creates a full name for the account

  std::string generate_acc(std::minstd_rand0 &generator, std::uniform_int_distribution<int> digits);
  //generate_acc() creates a fake account number

  std::string generate_money(std::minstd_rand0 &generator, std::uniform_int_distribution<int> size);
  //generate_money() creates the amount of money within the bank accounts

  std::string generate_cc(std::minstd_rand0 & generator, std::uniform_int_distribution<int> digits);
  //generate_cc() creates a credit card number

  std::string generate_exp(std::minstd_rand0 & generator, std::uniform_int_distribution<int> months);
  //generate_exp() creates an expiration date for the credit card numbers


private:


//List of names taken from Top 100 Names Over the Past 100 Years from the Social Security Administration
  std::vector<std::string> first_names = {"James", "Mary",
  "John", "Patricia", "Robert", "Jennifer", "Michael",
  "Elizabeth", "William", "Linda", "David", "Barbara",
  "Richard", "Susan", "Joseph", "Jessica", "Thomas",
  "Margaret", "Charles", "Sarah", "Christopher", "Karen",
  "Daniel", "Nancy", "Mathew", "Betty", "Anthony",
  "Dorothy", "Donald", "Lisa", "Mark", "Sandra",
  "Paul", "Ashley", "Steven", "Kimberly", "George",
  "Donna", "Kenneth", "Carol", "Andrew", "Michelle",
  "Joshua", "Emily", "Edward", "Helen", "Brian",
  "Amanda", "Kevin", "Melissa", "Ronald", "Stephanie",
  "Jason", "Laura", "Jeffrey", "Rebecca", "Ryan",
  "Sharon", "Gary", "Cynthia", "Jacob", "Kathleen",
  "Nicholas", "Shirley", "Eric", "Amy", "Stephen",
  "Anna", "Jonathan", "Angela", "Larry", "Ruth",
  "Scott", "Brenda", "Frank", "Pamela", "Justin",
  "Virginia", "Brandon", "Katherine", "Raymond", "Nicole",
  "Gregory", "Catherine", "Samuel", "Christine", "Benjamin",
  "Samantha", "Patrick", "Debra", "Jack", "Janet",
  "Alexander", "Carolyn", "Dennis", "Rachel", "Jerry",
  "Heather", "Tyler", "Maria", "Aaron", "Diane",
  "Henry", "Emma", "Douglas", "Jule", "Peter",
  "Joyce", "Jose", "Frances", "Adam", "Evelyn",
  "Zachary", "Joan", "Walter", "Christina", "Nathan",
  "Kelly", "Harold", "Martha", "Kyle", "Lauren",
  "Carl", "Victoria", "Arthur", "Judith", "Gerald",
  "Cheryl", "Roger", "Megan", "Keith", "Alice",
  "Jeremy", "Ann", "Lawrence", "Jean", "Terry",
  "Doris", "Sean", "Andrea", "Albert", "Marie",
  "Joe", "Kathryn", "Christian", "Jacqueline", "Austin",
  "Gloria", "Willie", "Teresa", "Jesse", "Hannah",
  "Ethan", "Sara", "Billy", "Janice", "Bruce",
  "Julia", "Bryan", "Olivia", "Ralph", "Grace",
  "Roy", "Rose", "Jordan", "Theresa", "Eugene",
  "Judy", "Wayne", "Beverly", "Louis", "Dennis",
  "Dylan", "Marilyn", "Alan", "Amber", "Juan",
  "Danielle", "Noah", "Brittany", "Russell", "Madison",
  "Harry", "Diana", "Randy", "Jane", "Philip","Lori",
  "Vincent", "Mildred","Gabriel", "Tiffany", "Bobby",
  "Natalie", "Johnny", "Abigail", "Howard", "Kathy"};

//List of most common surnames taken from "behindthename.com"
  std::vector<std::string> last_names = {"Smith", "Johnson", "Smith", "Johnson",
  "Williams", "Jones", "Brown", "Davis", "Miller",
  "Wilson", "Moore", "Taylor", "Anderson", "Thomas",
  "Jackson", "White", "Harris", "Martin", "Thompson",
  "Garcia", "Martinez", "Robinson", "Clark", "Rodriguez",
  "Lewis", "Lee", "Walker", "Hall", "Allen",
  "Young", "Hernandez", "King", "Wright", "Lopez",
  "Hill", "Scott", "Green", "Adams", "Baker",
  "Gonzalez", "Nelson", "Carter", "Mitchell", "Perez",
  "Roberts", "Turner", "Phillips", "Campbell", "Parker",
  "Evans", "Edwards", "Collins", "Stewart", "Sanchez",
  "Morris", "Rogers", "Reed", "Cook", "Morgan",
  "Bell", "Murphy", "Bailey", "Rivera", "Cooper",
  "Richardson", "Cox", "Howard", "Ward", "Torres",
  "Peterson", "Gray", "Ramirez", "James", "Watson",
  "Brooks", "Kelly", "Sanders", "Price", "Bennett",
  "Wood", "Barnes", "Ross", "Henderson", "Coleman",
  "Jenkins", "Perry", "Powell", "Long", "Patterson",
  "Hughes", "Flores", "Washington", "Butler", "Simmons",
  "Foster", "Gonzales", "Bryant", "Alexander", "Russell",
  "Griffin", "Diaz", "Hayes"};

  std::string fileName;
  time_t timer; //Timer is used to create a seed based on the clock
  unsigned seed = time(&timer); //Seed used for teh minstd_rand0 generator
  std::minstd_rand0 generator{seed}; //Choice of minstd_rand0 is due to speed
  std::uniform_int_distribution<int> digits{0, 9}; //Range to select from for CC numbers
  std::uniform_int_distribution<int> months{0, 12}; //Range to select from for Expiration Dates
  std::uniform_int_distribution<int> money_range{300, 15000}; //Range to select from for amount within accounts
  std::uniform_int_distribution<int> first_name_range{0, 197}; //Range to select a first name from
  std::uniform_int_distribution<int> last_name_range{0, 101}; //Range to select last names from

};
#endif
