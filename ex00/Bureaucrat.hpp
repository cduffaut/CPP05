#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

# define LOW 150
# define HIGH 1

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
                        const char  *what();
            };
            class GradeTooLowException : public std::exception
            {
                public:
                        const char  *what();
            };
            std::string getName() const ;
            int         getGrade() const ;
            
            void        increment();
            void        decrement();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif