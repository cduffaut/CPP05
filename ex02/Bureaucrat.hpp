#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "AForm.hpp"

# include <iostream>
# include <string>

# define LOW 150
# define HIGH 1

class AForm;

class Bureaucrat
{
    private:
            const std::string   name;
            int                 grade;            
    public:
            Bureaucrat(std::string name, int grade);
            ~Bureaucrat();

            class GradeTooHighException : public std::exception
            {
                public:
                        virtual const char  *what() const throw();
            };
            class GradeTooLowException : public std::exception
            {
                public:
                        virtual const char  *what() const throw();
            };
            std::string getName() const ;
            int         getGrade() const ;
            
            void        increment();
            void        decrement();
            // ex 01
            void        signForm(AForm &form, std::string reason);
            // ex 02
            void        executeForm(AForm const & form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif