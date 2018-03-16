/********************************************
* Titre: Travail pratique #1 -Rayon.h
* Date: 20 janvier 2018
* Auteur: 
*******************************************/

#ifndef RAYON_H
#define RAYON_H

#include <string>
#include "Produit.h"
using namespace std;

class Rayon
{
public:

	//********************************************
	//Constructeur par défaut
    Rayon();

	//********************************************
	//Constructeur par paramètres
	Rayon(string categorie);
   
	//********************************************
	//Destructeur
	~Rayon();
	
	//********************************************
	//Méthodes d'accès aux attributs de la classe
	string obtenirCategorie() const;
	Produit ** obtenirTousProduits() const;
    int obtenirCapaciteProduits() const;
    int obtenirNombreProduits() const;
	
	//********************************************
	// Methode de modification des attributs
	void modifierCategorie(string categorie);

    //********************************************
	// Methode d'ajout d'un produit dans un rayon
    void ajouterProduit (Produit * produit);

	//********************************************
	// Methode pour afficher le contenu du rayon
    void afficher() const;
	

private:

	//********************************************
	// Attributs prives
	string categorie_;
    Produit** tousProduits_;
    int capaciteProduits_;
	int nombreProduits_;

};

#endif
