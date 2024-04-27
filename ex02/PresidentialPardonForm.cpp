# include "PresidentialPardonForm.hpp"

/*
    PresidentialPardonForm : Notes requises : signature 25, exécution 5. 
    Informe que <cible> a été graciée par Zaphod Beeblebrox.
*/

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
    this->_Target = target;
}

PresidentialPardonForm::~PresidentialPardonForm(){};

void PresidentialPardonForm::action() const
{
    std::cout << this->_Target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}