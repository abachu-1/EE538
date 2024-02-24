#include <iostream>
#include <set>
#include <vector>
// - Run the following code with Address Sanitizer enabled:
//   - bazel run //files/3:non_coding_q --config=asan
//   - Note: the program might crash!
// - What is wrong with each piece of code below?
// - For each case modify the code so that the issue is fixed.

void Question1() {
  std::vector<int> elements;

  // Number of values to read from the input
  const int number_of_items = 10;

  // Initializing the elements vector.
  for (int i = 0; i < number_of_items; i++) {
    elements.push_back(0);
  }
}

void Question2() {
  //Allocate memory
  int* a=new int;
  (*a) = 12;
  (*a)++;
  std::cout << "(*a): " << (*a) << std::endl;
  //delete after use
  delete a;
}

void Question3() {
  int* a = new int;
  int* b = new int;
  (*a) = 1;
  (*b) = 2;

  std::cout << "(*a) + (*b): " << (*a) + (*b) << std::endl;
  //delete after use
  delete a;
  delete b;
}

void Question4() {
  int* a = new int;
  int* b = new int;
  (*a) = 1;
  (*b) = 2;
  std::cout << "(*a) + (*b): " << (*a) + (*b) << std::endl;
  //Delete after use
  delete a;
  delete b;
//After deleting, again we need to allocate memory
  a= new int;
  b= new int;

  (*a) = 1;
  (*b) = 2;
  std::cout << "(*a) + (*b): " << (*a) + (*b) << std::endl;
  delete a;
  delete b;
}

void Question5() {
  for (int i = 0; i < 10; i++) {
    std::cout << "i: " << i << std::endl;
    
    std::cout << "i: " << i-1 << std::endl;
  }
}

void Question6() {
  std::set<int> elements = {0, 1, 2, 3, 4, 5};
  for (auto it = elements.begin(); it != elements.end(); ++it) {
    it= elements.insert(it, ((*it) + 1));
  }
  for (auto el : elements) {
    std::cout << "e: " << el << std::endl;
  }
}

int main() {
  int user_choice;

  bool run_the_loop = true;
  while (run_the_loop) {
    std::cout << "Please enter a value between 1 to 6 to run a function. Any "
                 "other value to exit."
              << std::endl;
    std::cin >> user_choice;
    switch (user_choice) {
      case 1:
        Question1();
        break;
      case 2:
        Question2();
        break;
      case 3:
        Question3();
        break;
      case 4:
        Question4();
        break;
      case 5:
        Question5();
        break;
      case 6:
        Question6();
        break;
      default:
        std::cout << "Invalid value entered. Exit the program!" << std::endl;
        run_the_loop = false;
        break;
    }
  }
  return 0;
}
