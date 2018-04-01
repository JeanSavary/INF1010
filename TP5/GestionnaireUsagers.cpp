/********************************************
 * Titre: Travail pratique #5 - GestionnaireUsagers.cpp
 * Date: 9 mars 2018
 * Auteur: Ryan Hardie
 *******************************************/

#include "GestionnaireUsagers.h"


double GestionnaireUsagers::obtenirChiffreAffaires() const
{
    double chiffreAffaires = 0;
    for_each(conteneur_.begin(),conteneur_.end(),chiffreAffaires+=conteneur_.first->obtenirTotalAPayer());
    return chiffreAffaires;
}

void GestionnaireUsagers::encherir(Client *client, ProduitAuxEncheres *produit, double montant) const
{
    
    /* if (produit->obtenirPrix() < montant)
     produit->mettreAJourEnchere(client, montant);*/
}
void GestionnaireUsagers::reinitialiser()
{
    for_each(conteneur_.begin(),conteneur_.end(),conteneur_.first->reinitialiser());
}
void GestionnaireUsagers::afficherLesProfils() const
{
    cout << "PROFILS" << endl;
    for_each(conteneur_.begin(),conteneur_.end(),conteneur_.first->afficher());
    /*for (unsigned int i = 0; i < usagers_.size(); i++)
     usagers_[i]->afficherProfil();*/
    cout << endl;
}

