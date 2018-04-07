/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/
#ifndef GESTIONNAIREUSAGER_H
#define GESTIONNAIREUSAGER_H
#pragma once

#include "GestionnaireGenerique.h"
#include <set>
#include "Foncteur.h"
#include "Client.h"
#include "ProduitAuxEncheres.h"
// TODO : Cr�er la classe GestionnaireUsager

// TODO : La classe ressemble beaucoup � la classe Gestionnaire
/*
Les m�thodes retrouv�es de la classe Gestionnaire sont :
- double obtenirChiffreAffaires() const;
- void encherir(Client *client, ProduitAuxEncheres *produit, double montant) const;
- void reinitialiser();
- void afficherProfils() const;
 */

class GestionnaireUsagers : public GestionnaireGenerique<Usager, set<Usager*>, FoncteurAjouterUsager, FoncteurSupprimerUsager>
{
    public:
    
        double obtenirChiffreAffaires() const;
        void encherir(Client *client, ProduitAuxEncheres *produit, double montant) const;
        void reinitialiser();
        void afficherLesProfils() const;
private:
    
};

#endif
