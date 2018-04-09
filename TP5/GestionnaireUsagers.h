/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.h
* Date: 9 mars 2018
* Auteurs: SAVARY Jean, PAGE Nicolas
*******************************************/
#ifndef GESTIONNAIREUSAGER_H
#define GESTIONNAIREUSAGER_H
#pragma once

#include "GestionnaireGenerique.h"
#include <set>
#include "Foncteur.h"
#include "Client.h"
#include "ProduitAuxEncheres.h"

class GestionnaireUsagers : public GestionnaireGenerique<Usager, set<Usager*>, FoncteurAjouterUsager, FoncteurSupprimerUsager>
{
    public:
        double obtenirChiffreAffaires() const;
        void encherir(Client *client, ProduitAuxEncheres *produit, double montant) const;
        void reinitialiser();
        void afficherLesProfils() const;
};

#endif
