
//  client.h
//  Created by Martine Bellaiche on 18-01-22.
//  Copyright © 2018 Martine Bellaiche. All rights reserved.
//

#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include "Panier.h"
using namespace std;
class Client
{
public:

    //********************************************
    //Constructeur par paramètres
    Client (string  nom,  string prenom, int identifiant, string codePostal,  long date);
    
    //********************************************
	//Destructeur
    ~Client();
    
    //********************************************
    //Méthodes d'accès aux attributs
    string obtenirNom() const;
    string obtenirPrenom() const;
    int obtenirIdentifiant() const;
    string obtenirCodePostal() const;
    long obtenirDateNaissance() const;
    
    //********************************************
    //Méthode de modification des attributs
    void modifierNom(string nom) ;
    void modifierPrenom(string prenom) ;
    void modifierIdentifiant(int identifiant) ;
    void modifierCodePostal(string codePostal);
    void modifierDateNaissance(long date);
    
    //********************************************
    //Méthode d'ajout d'un produit au panier du client
    void acheter (Produit * prod);

    //********************************************
    //Méthode d'ajout d'un produit au panier du client
    void afficherPanier() const;

    //********************************************
    //Méthode permettant de réinitialiser le contenu 
    //du panier après que le client ait payé
    void livrerPanier();
    
    
private:
    
    string nom_;
    string prenom_;
    int identifiant_;
    string codePostal_;
    long dateNaissance_;
    Panier *  monPanier_;
};
#endif /* client_h */
