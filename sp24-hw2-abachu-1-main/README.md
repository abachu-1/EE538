[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/val-avXT)

# HW2 EE538
## University of Southern California
## Instructor: Arash Saifhashemi

Please clone this repository, edit README.md to answer the questions, and fill up functions to finish the homework.

Important: Please use bazel with c++17:

```bash
bazel test --cxxopt="-std=c++17"  {test_target}
```

- Please find each question in a separate folder under [files](/files).
- For non-coding questions, fill out the answers in the README file.
- For coding questions, edit the files and check them in.
- For coding questions unless specified, you should add unit tests to the student_test.cc. We will clone and test your repo using your tests and some other tests (that are not provided). Your code should pass all of them.
- For submission, please push your answers to Github before the deadline.
- Rubrics:
  
| Question | Points |
| -------- | ------ |
| 1        | 10     |
| 2        | 18     |
| 3        | 10     |
| 4        | 20     |
| 5        | 25     |
| 6        | 30     |

- 100 points is considered full credit.


See [cpp-template](https://github.com/ourarash/cpp-template) for help on installing bazel and debugging.

# Write non-coding answers below

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
  int* a=new int;
  (*a) = 12;
  (*a)++;
  std::cout << "(*a): " << (*a) << std::endl;
}

void Question3() {
  int* a = new int;
  int* b = new int;
  (*a) = 1;
  (*b) = 2;

  std::cout << "(*a) + (*b): " << (*a) + (*b) << std::endl;
  delete a;
  delete b;
}

void Question4() {
  int* a = new int;
  int* b = new int;
  (*a) = 1;
  (*b) = 2;
  std::cout << "(*a) + (*b): " << (*a) + (*b) << std::endl;
  delete a;
  delete b;

  a= new int;
  b= new int;

  (*a) = 1;
  (*b) = 4;
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
  for (auto e : elements) {
    std::cout << "e: " << e << std::endl;
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
