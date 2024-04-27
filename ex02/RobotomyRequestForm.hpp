#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

# include <iostream>
# include <string>
# include <ctime>

class RobotomyRequestForm : public AForm
{
    public:
            RobotomyRequestForm(std::string _Target);
            ~RobotomyRequestForm();

    void action() const;
    private:
            std::string _Target;
};


#endif