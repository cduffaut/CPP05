#include "Bureaucrat.hpp"

int main(void)
{
    // Legit worker grade test
    try
    {
        Bureaucrat  office("worker", 4);
        // Pass to the grade 3
        office.increment();
        std::cout << office << std::endl;
        Bureaucrat  office2("worker2", 70);
        // Pass to the grade 71
        office2.decrement();
        std::cout << office2 << std::endl;
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Failure with incrementation
    try
    {
        Bureaucrat  office3("worker3", 1);
        // Pass to the grade 0 err
        office3.increment();
        std::cout << office3 << std::endl;
        Bureaucrat  office4("worker4", 32);
        // Pass to the grade 33
        office4.decrement();
        std::cout << office4 << std::endl;
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    // Failure with decrementation
    try
    {
        Bureaucrat  office5("worker5", 78);
        // Pass to the grade 77
        office5.increment();
        std::cout << office5 << std::endl;
        Bureaucrat  office6("worker6", 150);
        // Pass to the grade 151 err
        office6.decrement();
        std::cout << office6 << std::endl;
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return (0);
}