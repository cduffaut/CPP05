#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>

# include "AForm.hpp"

class Intern
{
    public:
            Intern();
            ~Intern();

            Form *makeForm(std::string name, std::string target);

            class DoesNotExist : public std::exception
            {
                public:
                        const char *what() const throw();
            };
            private:
                    Form *formName[3];
};

#endif