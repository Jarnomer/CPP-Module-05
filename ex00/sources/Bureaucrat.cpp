#include <Bureaucrat.hpp>

Bureaucrat::Bureaucrat(void) : name("Bureaucrat") {
  std::cout << "Default constructor called\n";
  std::cout << "Name: " << name << "\n";
  setGrade(lowerLimit);
  std::cout << "Grade: " << grade << "\n\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
  std::cout << "Grade constructor called\n";
  std::cout << "Name: " << name << "\n";
  setGrade(grade);
  std::cout << "Grade: " << grade << "\n\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name(other.name), grade(other.grade) {
  std::cout << "Copy constructor called\n";
}

Bureaucrat::~Bureaucrat(void) { std::cout << "Deconstructor called\n"; }

std::string Bureaucrat::getName(void) const noexcept { return name; }

int Bureaucrat::getGrade(void) const noexcept { return grade; }

void Bureaucrat::setName(const std::string &name) { this->name = name; }

void Bureaucrat::setGrade(const int &grade) {
  if (grade > lowerLimit) {
    throw GradeTooLowException();
  } else if (grade < upperLimit) {
    throw GradeTooHighException();
  } else {
    this->grade = grade;
  }
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept {
  return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept {
  return "Grade too low!";
}

void Bureaucrat::incrementGrade(void) { setGrade(--grade); }

void Bureaucrat::decrementGrade(void) { setGrade(++grade); }
