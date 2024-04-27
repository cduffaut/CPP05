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

void        Bureaucrat::signForm(AForm &form, std::string reason)
{
    if (form.getisSigned() == true)
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    else
        std::cout << this->getName() << " couldn’t sign " << form.getName() << " because " << reason << "." << std::endl;
}

// Ex02
/*
    Doit appeler la fonction execute sur l'objet form fourni en paramètre
    Si succès: la fonction doit imprimer un message indiquant que le bureaucrate a exécuté le formulaire. 
    Sinon, elle doit imprimer un message d'erreur explicite.  
*/
void        Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << "\nCould not treat the demand" << std::endl;
    }
    std::cout << this->getName() << " executed " << form.getName() << std::endl;
}