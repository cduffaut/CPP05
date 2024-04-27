#include "RobotomyRequestForm.hpp"

/*
    RobotomyRequestForm : Notes requises : signature 72, exécution 45.
    Fait quelques bruits de forage. Ensuite, informe que <cible> a été 
    robotomisée avec succès 50% du temps. Sinon, informe que la robotomie a échoué.
*/

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45)
{
    this->_Target = target;
}

RobotomyRequestForm::~RobotomyRequestForm(){};

/*
    srand() will generate a "random nbr"
    if the random nbr is odd : go for a "success"
    else : go for a fail
*/
void RobotomyRequestForm::action() const
{
    srand((unsigned int)(time(nullptr)));
    // allow us to see if nbr is odd or not
    if (rand() & 1)
    {
        std::cout << "*Vrrrrr vrrr vrrr*" << std::endl;
        std::cout << this->_Target << " has been robotomized successfully 50% of the time." << std::endl;
    }
    else
    {
        std::cout << "Error: " << this->_Target << " Robotomy failed." << std::endl;
    }
}

Form *RobotomyRequestForm::dupForm(std::string target)
{
    std::cout << "Intern creates " << target << std::endl;
    return (new RobotomyRequestForm(target));
}