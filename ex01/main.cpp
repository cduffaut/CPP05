#include "Bureaucrat.hpp"

int main(void)
{
    // Legit graduation
    try
    {
        Form        form1("form1", 10, 10);
        Bureaucrat  bureaucrat1("bureaucrat1", 1);

        std::cout << "Form message : " << std::endl;
        form1.beSigned(bureaucrat1);

        std::cout << std::endl;
        
        std::cout << "Bureaucrat message : " << std::endl;
        bureaucrat1.signForm(form1, "");

        std::cout << std::endl;

        std::cout << "Form status : " << std::endl;
        std::cout << form1 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    // Failure with too low graduation
    try
    {
        Form        form2("form1", 70, 70);
        Bureaucrat  bureaucrat2("bureaucrat1", 130);

        form2.beSigned(bureaucrat2);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    // Failure with decrementation
    try
    {
        Bureaucrat  office5("worker5", 78);
        // Pass to the grade 77 - Legit
        office5.increment();
        std::cout << office5 << std::endl;
        Bureaucrat  office6("worker6", 150);
        // Pass to the grade 151 - Error
        office6.decrement();
        std::cout << office6 << std::endl;    
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    return (0);
}