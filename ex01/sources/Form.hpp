#pragma once

#include <Bureaucrat.hpp>

#include <exception>
#include <iostream>
#include <string>

class Form {
private:
  bool isSigned = false;
  const std::string name;
  const int signGrade;
  const int execGrade;

public: // constructors
  Form(void);
  Form(const std::string &name, const int sign, const int exec);
  Form(const Form &other);
  Form &operator=(const Form &other);

public: // deconstructor
  ~Form(void);

public: // getters
  std::string getName(void) const noexcept;
  int getSignGrade(void) const noexcept;
  int getExecGrade(void) const noexcept;
  int getIsSigned(void) const noexcept;

public: // mutators
  void beSigned(const Bureaucrat &person);

private: // nested exception classes
  class GradeTooHighException : public std::exception {
    const char *what() const noexcept override;
  };
  class GradeTooLowException : public std::exception {
    const char *what() const noexcept override;
  };
};

std::ostream &operator<<(std::ostream &os, const Form &form);
