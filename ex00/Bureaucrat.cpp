#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
    if (grade < HIGH)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > LOW)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;

}

Bureaucrat::~Bureaucrat(){}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

std::string Bureaucrat::getName() const
{
    return (this->name);
}

void Bureaucrat::increment()
{
    if ((this->grade - 1) < HIGH)
        throw Bureaucrat::GradeTooHighException();
    else
    {
        this->grade -= 1;
        return ;
    }
}

void Bureaucrat::decrement()
{
    if ((this->grade + 1) > LOW)
        throw Bureaucrat::GradeTooLowException();
    else
    {
        this->grade += 1;
        return ;
    }    
}

const char  *Bureaucrat::GradeTooHighException::what()
{
    return ("Range too high");
}

const char  *Bureaucrat::GradeTooLowException::what()
{
    return ("Range too low");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    std::cout << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return (os);
}