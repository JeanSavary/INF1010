#include "ClientPremium.h"
#include <iostream>

ClientPremium::ClientPremium(unsigned int joursRestants)
: Client(),
joursRestants_(joursRestants)
{
}

ClientPremium::ClientPremium(const string &nom, const string &prenom, int identifiant,
                             const string &codePostal, unsigned int codeClient,
                             unsigned int joursRestants)
: Client(nom, prenom, identifiant, codePostal, codeClient),
joursRestants_(joursRestants)
{
}

unsigned int ClientPremium::obtenirJoursRestants() const
{
    return joursRestants_;
}

double ClientPremium::obtenirTotalAPayer() const
{
    
    double total=0;
    for (int i=0; i<obtenirPanier().size();i++) {
        if ((obtenirPanier()[i]->obtenirPrix())-5 >0) {
            total+=(obtenirPanier()[i]->obtenirPrix()-5);
        }
    }
    return total;
}
/****************************************************************************
 * Fonction:  ClientPremium::afficherProfil()
 * Description: affiche le profil du client premium
 * ParamËtres: aucun
 * Retour: aucun
 ****************************************************************************/
void ClientPremium::afficherProfil() const
{
  
    Client::afficherProfil();//on utilise ici les avantages de l'héritage
    cout<< "\t Jours restants : "<< obtenirJoursRestants()<< endl;
    
}

void ClientPremium::modifierJoursRestants(unsigned int joursRestants)
{
    joursRestants_ = joursRestants;
}

