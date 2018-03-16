/********************************************
 * Titre: Travail pratique #2 - Produit.h
 * Date: 25 janvier 2018
 * Auteur: Nicolas PAGE et Jean SAVARY
 *******************************************/

#pragma once

#include <string>
#include <iostream>

using namespace std;

class Produit
{
public:
    //Constructeur par defaut
    Produit(const string& nom = "outil", int reference = 0, double prix = 0.0);
    
    //Méthodes d'accès
    string obtenirNom() const;
    int obtenirReference() const;
    double obtenirPrix() const;
    
    //Méthodes de modification
    void modifierNom(const string& nom);
    void modifierReference(int reference);
    void modifierPrix(double prix);
    
   //Surcharge des operateurs
    bool operator>(const Produit& produit1) const;
    bool operator<(const Produit& produit1) const;
    bool operator==(const Produit& produit1) const;
    friend istream& operator>>(istream& flux,Produit* produit1);
    friend ostream& operator<<(ostream& flux, const Produit& produit1);

private:
    string nom_;
    int reference_;
    double prix_;
};

