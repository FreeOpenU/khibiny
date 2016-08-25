#ifndef __GENERATE_H__
#define __GENERATE_H__
#include <string>
#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include <fstream>
//! A Generator class
/*!
Generator class creates a generator object whose functions output strings.
These output strings are strung together to be output into a file.
Generator class is initialized with a string for a filename to use for output.
The default filename is "Information.txt"
*/
class Generator {
public:
  //write_to_file handles the output to a file and takes an unsigned for the number of iterations. This determines the size of the file.

  //Pass random number generators by reference so generator isn't initialized with same seed for each function call
  //! Generator Constructor
  /*!
    Generator constructor takes a string as input(The File Name).
    This string will be used by write_to_file() for output.
    \sa write_to_file()
    \param file is the filename for the object to be initialized with. If no file name is given, default is "Information.txt"
  */
  Generator(std::string file="Information.txt");

  //! write_to_file() uses generate_full() to write to the output file. The default output size is ~130 MB.

  /*!
    \sa generate_full()
    \param iterations is used to determine the file size. For example, 10,000,00 provides a 1.3 GB File.
  */

  void write_to_file(unsigned iterations=1000000);

  //!generate_full() Combines all information field functions to create a full string
  /*!
   \sa generate_holder(), generate_acc(), generate_money(), generate_cc(), generate_exp
   \return A full string of all generated information.
  */

  std::string generate_full();

  //!generate_holder() Creates a full name for the account

  /*!
    \param generator The generator used to generate a random number from the distributions.
    \param first_index The range to select a random first name from the vector
    \param last_index The range to select a random last name from the vector
    \return A string consisting of a first and last name to simulate an account holder.
    */

  std::string generate_holder(std::minstd_rand0 &generator, std::uniform_int_distribution<int> first_index,
                                std::uniform_int_distribution<int> last_index);

  //!generate_acc() creates a fake account number

  /*!
  \param generator The generator used to generate a random number from the distribution.
  \param digits The range of numbers to select from to create an account number.
  \return A string consisting of digits (0-9) to simulate an account number.
  */

  std::string generate_acc(std::minstd_rand0 &generator, std::uniform_int_distribution<int> digits);

  //!generate_money() creates the amount of money within the bank accounts

  /*!
    \param generator The generator used to generate a random number from the distribution.
    \param size The range of numbers to select an amount to assign to the checkings and savings of the account
    \return A string to simulate the amount of money within an account's savings and checkings.
  */

  std::string generate_money(std::minstd_rand0 &generator, std::uniform_int_distribution<int> size);

  //!generate_cc() creates a credit card number

  /*!
    \param generator The generator used to generate a random number from the distribution.
    \param digits The range of numbers used to select from to create a credit card number.
    \return A string to simulate a credit card number.
  */

  std::string generate_cc(std::minstd_rand0 & generator, std::uniform_int_distribution<int> digits);

  //!generate_exp() creates an expiration date for the credit card numbers

  /*!
    \param generator The generator used to generate a random number from the distribution.
    \param months The range of numbers used to select from to create an expiration date.
    \return A string to simulate the expiration date assigned to a credit card.
  */

  std::string generate_exp(std::minstd_rand0 & generator, std::uniform_int_distribution<int> months);

private:



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
  //!List of names taken from Top 100 Names Over the Past 100 Years from the Social Security Administration


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
  //!List of most common surnames taken from "behindthename.com"

  std::string fileName; //! The file name passed upon creation of Generator object
  time_t timer; //!Timer is used to create a seed based on the clock
  unsigned seed = time(&timer); //!Seed used for teh minstd_rand0 generator
  std::minstd_rand0 generator{seed}; //!Choice of minstd_rand0 is due to speed
  std::uniform_int_distribution<int> digits{0, 9}; //!Range to select from for CC numbers
  std::uniform_int_distribution<int> months{0, 12}; //!Range to select from for Expiration Dates
  std::uniform_int_distribution<int> money_range{300, 15000}; //!Range to select from for amount within accounts
  std::uniform_int_distribution<int> first_name_range{0, 197}; //!Range to select a first name from
  std::uniform_int_distribution<int> last_name_range{0, 101}; //!Range to select last names from

};
#endif
