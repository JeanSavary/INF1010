
//  panier.cpp
//  Created by Martine Bellaiche on 18-01-22.
//  Copyright © 2018 Martine Bellaiche. All rights reserved.
//

#include <string>
#include "Produit.h"

#ifndef PANIER_H
#define PANIER_H
class Panier
{
public:

    //********************************************
    //Constructeur par paramètres
    Panier (int capacite);
   
    //********************************************
    //Méthodes d'accès aux attributs
    Produit **  obtenirContenuPanier() const;
    int obtenirNombreContenu() const;
    double obtenirTotalApayer() const;
    
    
    //********************************************
    //Méthode d'ajout d'un produit au panier
    void ajouter ( Produit * prod);

    //********************************************
    //Méthode vidant le panier après que le client
    //ait payé
    void livrer();

    //********************************************
    //Méthode qui affiche l'état du panier
    void afficher() const;

private:

    //********************************************
	// Attributs prives
    Produit ** contenuPanier_;
    int  nombreContenu_;
    int capaciteContenu_;
    double totalAPayer_;
};

#endif

