#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

# include <iostream>
# include <string>
# include <fstream>

class ShrubberyCreationForm : public AForm
{
    public:
            ShrubberyCreationForm(std::string _Target);
            ~ShrubberyCreationForm();

    void action() const;
    private:
            std::string _Target;
};

#endif