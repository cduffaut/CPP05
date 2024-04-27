# include "PresidentialPardonForm.hpp"

/*
    PresidentialPardonForm : Notes requises : signature 25, exécution 5. 
    Informe que <cible> a été graciée par Zaphod Beeblebrox.
*/

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5)
{
    this->_Target = target;
}

PresidentialPardonForm::~PresidentialPardonForm(){};

void PresidentialPardonForm::action() const
{
    std::cout << this->_Target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

Form *PresidentialPardonForm::dupForm(std::string target)
{
    std::cout << "Intern creates " << target << std::endl;
    return (new PresidentialPardonForm(target));
}