#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

# include <iostream>
# include <string>
# include <ctime>

class RobotomyRequestForm : public Form
{
    public:
            RobotomyRequestForm(std::string _Target);
            ~RobotomyRequestForm();

        void action() const;
        Form *dupForm(std::string target);
    private:
            std::string _Target;
};


#endif