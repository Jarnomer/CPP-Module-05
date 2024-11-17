#include <AForm.hpp>
#include <Bureaucrat.hpp>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>

int main(void) {
  {
    std::cout << "Testing constructors...\n\n";
    ShrubberyCreationForm s;
    ShrubberyCreationForm t("Unique");
    ShrubberyCreationForm u(s);
    u = t;
    std::cout << "Deconstructors...\n\n";
  }

  std::cout << "\n";
  int grade;

  {
    grade = 100;
    std::cout << "Testing non signed form\n";
    Bureaucrat b("Jackson", grade);
    ShrubberyCreationForm f("Illegal");
    try {
      b.executeForm(f);
    } catch (std::exception &e) {
      std::cout << "Exception catched: " << e.what() << "\n\n";
    }
  }

  std::cout << "\n";

  {
    grade = 140;
    std::cout << "Testing invalid execute grade " << grade << "\n";
    Bureaucrat b("Jackson", grade);
    ShrubberyCreationForm f("Illegal");
    try {
      b.signForm(f);
      b.executeForm(f);
    } catch (std::exception &e) {
      std::cout << "Exception catched: " << e.what() << "\n\n";
    }
  }

  std::cout << "\n";

  {
    grade = 130;
    std::cout << "Testing valid execute grade " << grade << "\n";
    Bureaucrat b("Jackson", grade);
    ShrubberyCreationForm f("Illegal");
    try {
      b.signForm(f);
      b.executeForm(f);
    } catch (std::exception &e) {
      std::cout << "Exception catched: " << e.what() << "\n\n";
    }
  }

  return 0;
}
