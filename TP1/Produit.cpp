#include "Produit.h"

//********************************************
//Constructeur par défaut
Produit::Produit() : nom_("outil"), reference_(0),prix_(0.0) {

}

//********************************************
//Constructeur par paramètres
Produit::Produit(string nom, int reference, double prix) : nom_(nom), reference_(reference),prix_(prix) {

}

//********************************************
//Destructeur
Produit::~Produit(){
    
}

//********************************************
//Méthodes d'accès aux attributs
string Produit::obtenirNom() const {

    return nom_;
}

int Produit::obtenirReference() const {

    return reference_;
}

double Produit::obtenirPrix() const {

    return prix_;
}

//********************************************
//Méthodes de modification des attributs
void Produit::modifierNom(string nom) {

    nom_ = nom;
}

void Produit::modifierReference(int reference) {

    reference_ = reference;
}

void Produit::modifierPrix(double prix) {

    prix_ = prix;
}

//********************************************
//Méthodes pour afficher l'état du produit
void Produit::afficher() const {

    cout << "Le nom est - " << obtenirNom() << endl;
    cout << "La référence est - " << obtenirReference() << endl;
    cout << "Le prix est de - " << obtenirPrix() << endl;
}
