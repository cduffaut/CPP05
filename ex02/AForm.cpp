#include "AForm.hpp"

AForm::AForm(std::string _Name, int _toSign, int _toExec) : _Name (_Name), _toSign(_toSign), _toExec(_toExec)
{
    if (_toSign < HIGH)
        throw AForm::GradeTooHighException();
    else if (_toSign > LOW)
        throw AForm::GradeTooLowException();
    else if (_toExec < HIGH)
        throw AForm::GradeTooHighException();
    else if (_toExec > LOW)
        throw AForm::GradeTooLowException();
    this->_isSigned = false;
}

AForm::~AForm(){}

std::string AForm::getName() const
{
    return(this->_Name);
}

int AForm::getToExec() const
{
    return(this->_toExec);
}

int AForm::getToSign() const
{
    return(this->_toSign);
}

bool AForm::getisSigned() const
{
    if (this->_isSigned == true)
        return (true);
    else
        return (false);
}

const char  *AForm::GradeTooHighException::what() const throw()
{
    return ("Range too high");
}

const char  *AForm::GradeTooLowException::what() const throw()
{
    return ("Range too low");
}

std::ostream& operator<<(std::ostream& os, const AForm& AForm)
{
    std::cout << AForm.getName() << ", status: " << AForm.getisSigned() << std::endl;
    std::cout << "Grade to sign: " << AForm.getToSign() << std::endl;
    std::cout << "Grade to execute: " << AForm.getToExec() << std::endl;
    return (os);
}

/*
    Add also a beSigned() member function to the Form that takes a 
    Bureaucrat as parameter.
    It changes the form status to signed if 
    the bureaucrat’s grade is high enough 
    (higher or egal to the required one).
*/
void    AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (this->_isSigned == true)
    {
        std::cout << "AForm already signed." << std::endl;
    }
    else if (bureaucrat.getGrade() > this->_toSign)
    {
        std::cout << bureaucrat.getGrade() << ": Wrong grade, " << bureaucrat.getName() << " hasn't be signed." << std::endl;
        throw AForm::GradeTooLowException();
    }
    else
    {
        this->_isSigned = true;
        std::cout << bureaucrat.getGrade() << ": Good grade, " << bureaucrat.getName() << " has be signed." << std::endl;
    }
}

// ex02

void AForm::execute(Bureaucrat const & executor) const
{
    std::cout << "\n\n\ngetToExec: " << this->getToExec() << "    getGrade: " << executor.getGrade() << "\n\n\n" << std::endl;
    if (this->getToExec() < executor.getGrade())
        throw AForm::GradeTooLowException();
    if (this->getisSigned() == false)
    {
        std::cout << "Couldn't process, file is not signed." << std::endl;
        return ;
    }
    this->action();
}