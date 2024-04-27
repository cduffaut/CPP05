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

const char  *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Try to suprass range limit (too high)");
}

const char  *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Try to suprass range limit (too low)");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    std::cout << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return (os);
}

void        Bureaucrat::signForm(Form &form, std::string reason)
{
    if (form.getisSigned() == true)
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    else
        std::cout << this->getName() << " couldn’t sign " << form.getName() << " because " << reason << "." << std::endl;
}