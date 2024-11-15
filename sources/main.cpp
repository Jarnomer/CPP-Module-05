#include <Bureaucrat.hpp>
#include <exception>

int main(void) {
  try {
    Bureaucrat b("Jackson", 9001);
  } catch (std::exception &e) {
    std::cout << "Exception catched!\n";
  }
  return 0;
}
