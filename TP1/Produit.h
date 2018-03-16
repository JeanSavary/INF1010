/********************************************
* Titre: Travail pratique #1 - Produit.h
* Date: 20 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA
*******************************************/

#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>
#include <iostream>
using namespace std;

class Produit
{
public:

	//********************************************
	//Constructeur par défaut
	Produit();
	Produit(string nom, int reference, double prix);

	//********************************************
	//Destructeur
	~Produit();

	//********************************************
	//Méthodes d'accès aux attributs
	string obtenirNom() const;
	int obtenirReference() const;
	double obtenirPrix() const;

	//********************************************
	//Méthodes de modification des attributs
	void modifierNom(string nom);
	void modifierReference(int reference);
	void modifierPrix(double prix);
   
    //********************************************
	//Méthodes pour afficher l'état du produit
    void afficher() const;
   
private:

	//********************************************
	// Attributs prives
	string nom_;
	int reference_;
    double prix_;
};

#endif
