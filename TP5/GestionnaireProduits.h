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
#include <vector>

// TODO : Creer la classe GestionnaireProduits

// TODO : Methodes :
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
    
    Produit* trouverProduitPlusCher() const;
    vector< pair<int,Produit*> > obtenirProduitsEntre(double borneInf, double borneSup);
    Produit* obtenirProduitSuivant(Produit* produit);
    
    
};

