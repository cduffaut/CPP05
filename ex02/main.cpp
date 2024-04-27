#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <new>

int main(void)
{
    std::cout << "\n-----------TEST ONE---------\n" << std::endl;
    try
    {
        AForm *Test = new PresidentialPardonForm("Mr Poinc");
        Bureaucrat A("BureaucratA", 3);
        Test->beSigned(A);

        A.executeForm(*Test);
        delete(Test);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception error: " << e.what() << std::endl;
    }

    std::cout << "\n-----------TEST TWO---------\n" << std::endl;
    try
    {
        AForm *Test = new RobotomyRequestForm("BipBop");
        Bureaucrat A("BureaucratA", 30);
        Test->beSigned(A);

        A.executeForm(*Test);
        delete(Test);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception error: " << e.what() << std::endl;
    }

    std::cout << "\n-----------TEST THREE---------\n" << std::endl;
    try
    {
        AForm *Test = new ShrubberyCreationForm("Treeee");
        Bureaucrat A("BureaucratA", 100);
        Test->beSigned(A);

        A.executeForm(*Test);
        delete(Test);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception error: " << e.what() << std::endl;
    }

        std::cout << "\n-----------ERROR TEST---------\n" << std::endl;
    try
    {
        AForm *Test = new ShrubberyCreationForm("Treeee");
        Bureaucrat A("BureaucratA", 1500);
        Test->beSigned(A);

        A.executeForm(*Test);
        delete(Test);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception error: " << e.what() << std::endl;
    }
    return (0);
}