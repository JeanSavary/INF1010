/********************************************
 * Titre: Travail pratique #2 -Rayon.h
 * Date: 25 janvier 2018
 * Auteur: Nicolas PAGE et Jean SAVARY
 *******************************************/

#pragma once

#include <string>
#include <vector>
#include "Produit.h"

using namespace std;

class Rayon
{
    
public:
    //Constructeur par defaut
    Rayon(const string& cat = "inconnu");
    
    //Destructeur
    ~Rayon();
    
    //Méthodes d'accès
    string obtenirCategorie() const;
    vector<Produit*> obtenirTousProduits() const;
    int obtenirNombreProduits() const;
    
    //Méthodes de modification
    void modifierCategorie(const string& cat);
    
    //Méthode pour compter les doublons au sein du rayon
    int compterDoublons(const Produit& produit);
    
    //Surcharge des opérateurs
    Rayon& operator+=(Produit &produit);
    friend ostream& operator<<(ostream& flux, const Rayon& rayon);
    
private:
    string categorie_;
    vector<Produit*>tousProduits_;
  
};

