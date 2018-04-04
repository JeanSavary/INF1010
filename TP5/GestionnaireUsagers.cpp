/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/
#include "GestionnaireGenerique.h"
#include "GestionnaireUsagers.h"
#include "Usager.h"
#include "Client.h"
#include "ProduitAuxEncheres.h"

GestionnaireUsagers::GestionnaireUsagers()
{
    set<Usager*> conteneur_;
}

double GestionnaireUsagers::obtenirChiffreAffaires() const
{
    double chiffreAffaires = 0.0;
    for (Usager* usager:conteneur_) {
        chiffreAffaires+= usager->obtenirTotalAPayer();
    }
    return chiffreAffaires;
}

void GestionnaireUsagers::encherir(Client *client, ProduitAuxEncheres *produit, double montant) const
{
    
   /* if (produit->obtenirPrix() < montant)
        produit->mettreAJourEnchere(client, montant);*/
    
}
void GestionnaireUsagers::reinitialiser()
{
    for (Usager* usager:conteneur_) {
       usager->reinitialiser();
    }
}
void GestionnaireUsagers::afficherLesProfils() const
{
   cout << "PROFILS" << endl;
    for (Usager* usager:conteneur_) {
        usager->afficher();
    }
    cout << endl;
}
