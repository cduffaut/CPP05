#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

# include <iostream>
# include <string>

class PresidentialPardonForm : public Form
{
    public:
            PresidentialPardonForm(std::string _Target);
            ~PresidentialPardonForm();

        void action() const;
        Form *dupForm(std::string target);
    private:
            std::string _Target;
};

#endif