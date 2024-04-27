#include "Form.hpp"

Form::Form(std::string _Name, int _toSign, int _toExec) : _Name (_Name), _toSign(_toSign), _toExec(_toExec)
{
    if (_toSign < HIGH)
        throw Form::GradeTooHighException();
    else if (_toSign > LOW)
        throw Form::GradeTooLowException();
    else if (_toExec < HIGH)
        throw Form::GradeTooHighException();
    else if (_toExec > LOW)
        throw Form::GradeTooLowException();
    this->_isSigned = false;
}

Form::~Form(){}

std::string Form::getName() const
{
    return(this->_Name);
}

int Form::getToExec() const
{
    return(this->_toExec);
}

int Form::getToSign() const
{
    return(this->_toSign);
}

bool Form::getisSigned() const
{
    if (this->_isSigned == true)
        return (true);
    else
        return (false);
}

const char  *Form::GradeTooHighException::what() const throw()
{
    return ("Range too high");
}

const char  *Form::GradeTooLowException::what() const throw()
{
    return ("Range too low");
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    std::cout << form.getName() << ", status: " << form.getisSigned() << std::endl;
    std::cout << "Grade to sign: " << form.getToSign() << std::endl;
    std::cout << "Grade to execute: " << form.getToExec() << std::endl;
    return (os);
}

/*
    Add also a beSigned() member function to the Form that takes a 
    Bureaucrat as parameter.
    It changes the form status to signed if 
    the bureaucrat’s grade is high enough 
    (higher or egal to the required one).
*/
void    Form::beSigned(Bureaucrat &bureaucrat)
{
    if (this->_isSigned == true)
    {
        std::cout << "Form already signed." << std::endl;
    }
    else if (bureaucrat.getGrade() > this->_toSign)
    {
        std::cout << bureaucrat.getGrade() << ": Wrong grade, " << bureaucrat.getName() << " hasn't be signed." << std::endl;
        throw Form::GradeTooLowException();
    }
    else
    {
        this->_isSigned = true;
        std::cout << bureaucrat.getGrade() << ": Good grade, " << bureaucrat.getName() << " has be signed." << std::endl;
    }
}