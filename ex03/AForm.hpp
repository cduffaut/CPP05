#ifndef AFORM_HPP
# define AFORM_HPP

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
        virtual ~Form();

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

        // ex02
        void execute(Bureaucrat const & executor) const;
        virtual void action() const = 0;

        // ex 03
        virtual Form *dupForm(std::string target) = 0;
};

std::ostream& operator<<(std::ostream& os, const Form& Form);

#endif
