/********************************************
 * Titre: Travail pratique #2 - Client.h
 * Date: 25 janvier 2018
 * Auteur: Nicolas PAGE et Jean SAVARY
 *******************************************/

#pragma once

#include <string>
#include "Panier.h"
#include <vector>

using namespace std;

class Client
{
    
public:
    //Constructeur par parametres
    Client(const string&  nom, const string& prenom, int identifiant, const string& codePostal, long date);
    
    //Constructeur par copie
    Client(const Client& autreClient);
    
    //Destructeur
    ~Client();
    
    //Méthodes d'accès
    string obtenirNom() const;
    string obtenirPrenom() const;
    int obtenirIdentifiant() const;
    string obtenirCodePostal() const;
    long obtenirDateNaissance() const;
    Panier* obtenirPanier() const;
    
    //methode de modification
    void modifierNom(const string& nom);
    void modifierPrenom(const string& prenom);
    void modifierIdentifiant(int identifiant);
    void modifierCodePostal(const string& codePostal);
    void modifierDateNaissance(long date);
    
    //Méthode d'achat de produit
    void acheter(Produit * prod);

    //Méthode pour livrer le panier du Client
    void livrerPanier();
    
    //Surcharge des operateurs
    Client& operator=(const Client& client);
    bool operator==(const int& identifiant) const ;
    friend bool operator==(const int& identifiant, const Client& client);
    friend ostream& operator<<(ostream& flux, const Client& client);
    
private:
    string nom_;
    string prenom_;
    int identifiant_;
    string codePostal_;
    long dateNaissance_;
    Panier* monPanier_;
};


