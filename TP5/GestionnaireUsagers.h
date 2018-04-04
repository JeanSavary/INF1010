/********************************************
 * Titre: Travail pratique #5 - GestionnaireUsagers.h
 * Date: 9 mars 2018
 * Auteur: Ryan Hardie
 *******************************************/
#pragma once

#include "GestionnaireGenerique.h"
#include <set>
#include "Foncteur.h"
#include "Client.h"
#include "ProduitAuxEncheres.h"
// TODO : CrÈer la classe GestionnaireUsager

// TODO : La classe ressemble beaucoup ‡ la classe Gestionnaire
/*
 Les mÈthodes retrouvÈes de la classe Gestionnaire sont :
 - double obtenirChiffreAffaires() const;
 - void encherir(Client *client, ProduitAuxEncheres *produit, double montant) const;
 - void reinitialiser();
 - void afficherProfils() const;
 */
using namespace std;

class GestionnaireUsagers : public GestionnaireGenerique<Usager, set<Usager*>, FoncteurAjouterUsager, FoncteurSupprimerUsager>
{
public:
    GestionnaireUsagers( set<Usager*>);
    double obtenirChiffreAffaires() const;
    void encherir(Client *client, ProduitAuxEncheres *produit, double montant) const;
    void reinitialiser();
    void afficherLesProfils() const;
private:
    
};
