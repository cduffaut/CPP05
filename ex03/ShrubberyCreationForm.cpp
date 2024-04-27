#include "ShrubberyCreationForm.hpp"

/*
    ShrubberyCreationForm : Notes requises : signature 145, exécution 137. 
    Crée un fichier <cible>_shrubbery dans le répertoire de travail 
    et écrit des arbres ASCII à l'intérieur.
*/

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137)
{
    this->_Target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){};

/*
    srand() will generate a "random nbr"
    if the random nbr is odd : go for a "success"
    else : go for a fail
*/
void ShrubberyCreationForm::action() const
{
    std::ofstream file(this->_Target + "_shrubbery");
    if (file.is_open())
    {
        file << "        # #### ####" << std::endl;
        file << "      ### |/#|### |/####" << std::endl;
        file << "    ##|/#/ |||/##/_/##/_#" << std::endl;
        file << "   ###  |/###|/ |/ # ###" << std::endl;
        file << " ##_|_#|_|## | #/###_/_####" << std::endl;
        file << "## #### # | #| /  #### ##/##" << std::endl;
        file << " __#_--###`  |{,###---###-~" << std::endl;
        file << "           | }{" << std::endl;
        file << "            }}{" << std::endl;
        file << "            }}{" << std::endl;
        file << "            {{}" << std::endl;
        file << "      , -=-~{ .-^- _" << std::endl;
        file << "            `}" << std::endl;
        file << "             {" << std::endl;
        file.close();
    }
    else
    {
        std::cout << "Error: The file failed to open (ref: ShrubberyCreationForm)" << std::endl;
    }
}

Form *ShrubberyCreationForm::dupForm(std::string target)
{
    std::cout << "Intern creates " << target << std::endl;
    return (new ShrubberyCreationForm(target));
}