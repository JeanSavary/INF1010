#include "Rayon.h"

//********************************************
//Constructeur par défaut
Rayon::Rayon() : categorie_("inconnu"), capaciteProduits_(0), nombreProduits_(0)
{
	tousProduits_ = new Produit* [capaciteProduits_];	
}

//********************************************
//Constructeur par paramètres
Rayon::Rayon(string categorie) : categorie_(categorie), capaciteProduits_(0), nombreProduits_(0)
{
	tousProduits_ = new Produit* [capaciteProduits_];
}

//********************************************
//Destructeur
Rayon::~Rayon()
{
}

//********************************************
//Méthodes d'accès aux attributs de la classe
string Rayon::obtenirCategorie() const 
{
	return categorie_;
}
Produit** Rayon::obtenirTousProduits() const
{
	return tousProduits_;
}
int Rayon::obtenirCapaciteProduits() const
{
	return capaciteProduits_;
}
int Rayon::obtenirNombreProduits()const
{
	return nombreProduits_;
}

//********************************************
// Methode de modification des attributs
void Rayon::modifierCategorie(string categorie)
{
	categorie_ = categorie;
}

void Rayon::ajouterProduit(Produit * produit)
{
	if (capaciteProduits_ == 0) {
		capaciteProduits_ = 5;
		delete[] tousProduits_;
		tousProduits_ = new Produit*[capaciteProduits_];
		tousProduits_[nombreProduits_] = produit;
		nombreProduits_+=1;
	}

	else if (nombreProduits_ >= capaciteProduits_) {	
		capaciteProduits_ += 5;
		Produit** temp = new Produit*[capaciteProduits_];
		for (int i=0;i<nombreProduits_;i++){
			temp[i] = tousProduits_[i];
		}
		delete[] tousProduits_;
		tousProduits_ = temp;
		delete[] temp;
		tousProduits_[nombreProduits_] = produit;
		nombreProduits_ += 1;
	}

	else {
		tousProduits_[nombreProduits_] = produit;
		nombreProduits_ += 1;
	}
}

//********************************************
// Methode pour afficher le contenu du rayon
void Rayon::afficher() const
{
	cout << "Categorie : " << obtenirCategorie() << endl;
	cout << "Contenu du rayon: " << endl;
	for (int i = 0; i < nombreProduits_; i++)
	{
		cout << "   - "<<tousProduits_[i]->obtenirNom() << endl;
	}
	cout << "Capacite du tableau : " << obtenirCapaciteProduits() << endl;
	cout << "Nombre de produits : " << obtenirNombreProduits() << endl;


}





