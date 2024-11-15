#pragma once

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat {
private:
  std::string name;
  int grade;

private:
  const int lowerLimit = 150;
  const int upperLimit = 1;

public: // constructors
  Bureaucrat(void);
  Bureaucrat(std::string name, int grade);
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &other);

public: // deconstructor
  ~Bureaucrat(void);

public: // getters
  std::string getName(void) const noexcept;
  int getGrade(void) const noexcept;

public: // setters
  void setName(const std::string &name);
  void setGrade(const int &grade);

public: // mutators
  void decrementGrade(void);
  void incrementGrade(void);

private: // nested exception classes
  class GradeTooHighException : public std::exception {
    const char *what() const noexcept override;
  };
  class GradeTooLowException : public std::exception {
    const char *what() const noexcept override;
  };
};
