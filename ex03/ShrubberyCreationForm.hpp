#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

# include <iostream>
# include <string>
# include <fstream>

class ShrubberyCreationForm : public Form
{
    public:
            ShrubberyCreationForm(std::string _Target);
            ~ShrubberyCreationForm();

        void action() const;
        Form *dupForm(std::string target);
    private:
            std::string _Target;
};

#endif