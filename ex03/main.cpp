#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <new>

int main(void)
{
    Intern intern;
    Intern intern2;
    Intern intern3;
    Intern intern4;

    Form    *form;

    std::cout << "---------TEST ONE---------" << std::endl;
    try
    {
        form = intern.makeForm("PresidentialPardonForm", "intern");
        delete form;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "---------TEST TWO---------" << std::endl;
    try
    {
        form = intern2.makeForm("RobotomyRequestForm", "intern2");
        delete form;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "---------TEST THREE---------" << std::endl;
    try
    {
        form = intern3.makeForm("ShrubberyCreationForm", "intern3");
        delete form;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "---------TEST ERROR---------" << std::endl;
    try
    {
        intern4.makeForm("DoesNotExist", "intern4");
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return (0);
}