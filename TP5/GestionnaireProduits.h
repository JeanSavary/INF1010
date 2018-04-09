/********************************************
 * Titre: Travail pratique #5 - GestionnaireProduits.h
 * Date: 9 mars 2018
 * Auteur: Ryan Hardie
 *******************************************/
#ifndef GESTIONNAIREGENERIQUE_H
#define GESTIONNAIREGENERIQUE_H

#pragma once

#include <map>
#include "GestionnaireGenerique.h"
#include "Foncteur.h"
#include "Produit.h"
#include <vector>

class GestionnaireProduits: public GestionnaireGenerique<Produit, multimap<int, Produit* >, FoncteurAjouterProduit, FoncteurSupprimerProduit>
{
public:
    
    GestionnaireProduits(); 
    ~GestionnaireProduits();
    
    void reinitialiserClient();
    void reinitialiserFournisseur();
    void afficher() const;
    double obtenirTotalAPayer() const;
    double obtenirTotalAPayerPremium() const;
    
    Produit* trouverProduitPlusCher() const;
    vector< pair<int,Produit*> > obtenirProduitsEntre(double borneInf, double borneSup);
    Produit* obtenirProduitSuivant(Produit* produit);
    
    
};

#endif

