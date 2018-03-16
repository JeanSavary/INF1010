#include "Client.h"

//********************************************
//Constructeur par paramètres
Client::Client(string  nom, string prenom, int identifiant, string codePostal, long date) : nom_(nom), prenom_(prenom), identifiant_(identifiant), codePostal_(codePostal), dateNaissance_(date), monPanier_(nullptr)
{

}

//********************************************
//Destructeur
Client::~Client(){
	delete monPanier_;
}

//********************************************
//Méthodes d'accès aux attributs
string Client::obtenirNom() const
{
	return nom_;
}
string Client::obtenirPrenom() const
{
	return prenom_;
}

int Client::obtenirIdentifiant() const
{
	return identifiant_;
}
string Client::obtenirCodePostal() const
{
	return codePostal_;
}

long Client::obtenirDateNaissance() const
{
	return dateNaissance_;
}

//********************************************
//Méthode de modification des attributs
void Client::modifierNom(string nom)
{
	nom_ = nom;
}

void Client::modifierPrenom(string prenom)
{
	prenom_ = prenom;
}

void Client::modifierIdentifiant(int identifiant)
{
	identifiant_ = identifiant;
}

void Client::modifierCodePostal(string codePostal)
{
	codePostal_ = codePostal;
}

void Client::modifierDateNaissance(long date)
{
	dateNaissance_ = date;
}

//********************************************
//Méthode d'ajout d'un produit au panier du client
void Client::acheter (Produit * prod){

    if (monPanier_ == nullptr) {
		
		monPanier_ = new Panier(4);
		monPanier_->ajouter(prod);
    }
    else {
		
        monPanier_->ajouter(prod);
    }
}

//********************************************
//Méthode d'ajout d'un produit au panier du client
void Client::afficherPanier() const {

    if (monPanier_ != nullptr) {
        monPanier_->afficher();
    }

}

//********************************************
//Méthode permettant de réinitialiser le contenu 
//du panier après que le client ait payé
void Client::livrerPanier() {
    monPanier_->livrer();
}


