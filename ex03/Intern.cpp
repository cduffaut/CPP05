#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
    this->formName[0] = new PresidentialPardonForm("Presidential");
    this->formName[1] = new RobotomyRequestForm("Robotomy");
    this->formName[2] = new ShrubberyCreationForm("Shrubbery");
}

Intern::~Intern()
{
    delete formName[0];
    delete formName[1];
    delete formName[2];
}

Form *Intern::makeForm(std::string name, std::string target)
{
    std::string tabName[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
    int     i;

    for (i = 0; i < 3 && name != tabName[i]; i++);

    return (i < 3) ? formName[i]->dupForm(target) : throw Intern::DoesNotExist();
}

const char *Intern::DoesNotExist::what() const throw()
{
    return ("This form format does not exist.");
}