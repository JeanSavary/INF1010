/********************************************
 * Titre: Travail pratique #2 - Panier.h
 * Date: 25 janvier 2018
 * Auteur: Nicolas PAGE et Jean SAVARY
 *******************************************/

#pragma once

#include <string>
#include <vector>
#include "Produit.h"

using namespace std;

class Panier
{
    
public:  
    //Constructeur par defaut
    Panier();
    
    //Destructeur
    ~Panier();
    
    //Méthodes d'accès
    vector<Produit*>  obtenirContenuPanier()const;
    int obtenirNombreContenu() const;
    double obtenirTotalApayer() const;
    
    //Méthodes de modification
    void modifierTotalAPayer(double totalAPayer);

    //Méthode pour ajouter un produit au panier
    void ajouter(Produit * prod);

    //Méthode pour livrer le panier
    void livrer();

    //Méthode pour trouver le produit le plus cher du panier
    Produit* trouverProduitPlusCher();
    
    //Surcharge des operateurs
    friend ostream& operator<<(ostream& flux, const Panier& panier);
    
private:
    
    double totalAPayer_;
    vector <Produit*> contenuPanier_;
    
};

