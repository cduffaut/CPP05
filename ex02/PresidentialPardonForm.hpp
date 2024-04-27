#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

# include <iostream>
# include <string>

class PresidentialPardonForm : public AForm
{
    public:
            PresidentialPardonForm(std::string _Target);
            ~PresidentialPardonForm();

    void action() const;
    private:
            std::string _Target;
};

#endif