#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

# include <iostream>
# include <string>

# define LOW 150
# define HIGH 1

class Bureaucrat;

class Form
{
private:
        const std::string   _Name;
        const int           _toSign;
        const int           _toExec;
        // Boolean var
        bool                _isSigned;    

public:
        Form(std::string _Name, int _toSign, int _toExec);
        ~Form();

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
        std::string getName() const;
        int         getToSign() const;
        int         getToExec() const;
        bool        getisSigned() const;

        void        beSigned(Bureaucrat &bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
