// Name = Harmanjot Singh Malhi
// Student number = 7300973
#include <iostream>
using namespace std;
int main()
{
       std::cout << fixed;
       int j, k;
       int studentnum = 7300973;
       int tenMultiplyier = 1;
       int temp = 0;
       while (studentnum > 0)
       {
              int rem = studentnum % 10;

              if (rem % 2 == 0)
                     rem = rem / 2;
              else if (rem % 2 == 1)
                     rem = rem * 2;

              if (rem > 10)
                     rem = rem % 10;

              int placeholder = rem * tenMultiplyier;
              tenMultiplyier = tenMultiplyier * 10;
              temp = temp + placeholder;
              studentnum = studentnum / 10;
       }
       cout << "student num: " << temp << endl;
       cout << "" << endl;
       cout << "" << endl;

       int monkeys;
       cin >> monkeys;
       string nummonkeys = (monkeys >= 1000000) ? "I have " + std::to_string(monkeys / 1000000.0) + " million monkeys" : (monkeys == 1) ? "I have " + std::to_string(monkeys) + " monkey"
                                                                                                                                        : "I have " + std::to_string(monkeys) + " monkeys";
       cout << nummonkeys << endl;

       int choice1, choice2;
       cout << "Do you have room for tiramisu? (1:yes, 0:no)";
       cin >> choice1;
       cout << "Do you actually like tiramisu? (1:yes, 0:no)";
       cin >> choice2;
       if (choice1)
       {
              if (choice2)
              {
                     cout << "Ready, willing, and able to enjoy tiramisu!\n";
              }
       }
       else
       {
              cout << "It doesn't matter if I like it or not, I don't have room for dessert!\n";
       }
}
