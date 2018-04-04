/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

#include <map>
#include "GestionnaireGenerique.h"
#include "Foncteur.h"
#include "Produit.h"
#include "ProduitAuxEncheres.h"
// TODO : Créer la classe GestionnaireProduits

// TODO : Méthodes :
/*
- reinitialiserClient();
- reinitialiserFournisseur();
- afficher();
- obtenirTotalAPayer();
- obtenirTotalApayerPremium();
- trouverProduitPlusCher();
- obtenirProduitsEntre();
- obtenirProduitSuivant();
*/
class GestionnaireProduits: public GestionnaireGenerique<Produit, multimap<int, Produit* >, FoncteurAjouterProduit, FoncteurSupprimerProduit>
{
public:
    
    GestionnaireProduits(); //initialisation du conteneur
    void reinitialiserClient();
    void reinitialiserFournisseur();
    void afficher() const;
    double obtenirTotalAPayer() const;
    double obtenirTotalAPayerPremium() const;
    
    
    
};
