/********************************************
 * Titre: Travail pratique #3 - ProduitAuxEncheres.cpp
 * Date: 16 février 2018
 * Auteur: Nicolas PAGE et Jean SAVARY
 *******************************************/

#include "Client.h"
#include "Fournisseur.h"

/****************************************************************************
 * Fonction:    Client::Client
 * Description: constructeur par parametres
 * Paramètres:  const string&  nom, const string& prenom, int identifiant, const string& codePostal, long date
 * Retour:        aucun
 ****************************************************************************/
Client::Client(const string&  nom, const string& prenom, int identifiant, const string& codePostal, long date) :
Usager(nom, prenom, identifiant, codePostal), dateNaissance_(date), monPanier_(nullptr)
{

}

/****************************************************************************
 * Fonction:    Client::~Client
 * Description: destructeur
 * Paramètres:  aucun
 * Retour:        aucun
 ****************************************************************************/
Client::~Client()
{
	if (monPanier_ != nullptr)
		delete monPanier_;
}

/****************************************************************************
 * Fonction:    Client::Client
 * Description: constructeur par copie
 * Paramètres:  const Client& client
 * Retour:        aucun
 ****************************************************************************/
Client::Client(const Client & client) :
	Usager(client.obtenirNom(), client.obtenirPrenom(), client.obtenirIdentifiant(), client.obtenirCodePostal()),	
	dateNaissance_(client.dateNaissance_)
{
	if (client.monPanier_ == nullptr)
		monPanier_ = nullptr;
	else {
		monPanier_ = new Panier(client.obtenirIdentifiant());
		for (int i = 0; i < client.monPanier_->obtenirNombreContenu(); i++) {
			monPanier_->ajouter(client.monPanier_->obtenirContenuPanier()[i]);
		}
		int idClient = this->obtenirIdentifiant();
		monPanier_->modifierTotalAPayer(client.monPanier_->obtenirTotalApayer());
	}
}

/****************************************************************************
 * Fonction:    Client::obtenirDateNaissance
 * Description: accès à l'attribut dateNaissance_
 * Paramètres:  aucun
 * Retour:        long dateNaissance_
 ****************************************************************************/
long Client::obtenirDateNaissance() const
{
	return dateNaissance_;
}

/****************************************************************************
 * Fonction:    Client::obtenirPanier
 * Description: accès à l'attribut monPanier_
 * Paramètres:  aucun
 * Retour:      Panier* monPanier_
 ****************************************************************************/
Panier * Client::obtenirPanier() const
{
	return monPanier_;
}


/****************************************************************************
 * Fonction:    Client::modifierDateNaissance
 * Description: modification de l'attribut dateNaissance_
 * Paramètres:  long date
 * Retour:      aucun
 ****************************************************************************/
void Client::modifierDateNaissance(long date)
{
	dateNaissance_ = date;
}

/****************************************************************************
 * Fonction:    Client::acheter
 * Description: achat d'un produit
 * Paramètres:  ProduitOrdinaire * prod
 * Retour:      aucun
 ****************************************************************************/
void Client::acheter(ProduitOrdinaire * prod)
{
	if (monPanier_ == nullptr)
		monPanier_ = new Panier(this->obtenirIdentifiant());
	monPanier_->ajouter(prod);
	int note = rand() % 5 + 1;
	Fournisseur& fournisseur = prod->obtenirFournisseur();
	fournisseur.noter(note);
}

/****************************************************************************
 * Fonction:    Client::livrerPanier
 * Description: livre le panier du client
 * Paramètres:  aucun
 * Retour:      aucun
 ****************************************************************************/
void Client::livrerPanier()
{
	monPanier_->livrer();
	delete monPanier_;
	monPanier_ = nullptr;
	cout << "Le panier de " << this->obtenirPrenom() << " a été vidé." << endl;
}

/****************************************************************************
 * Fonction:    Client::miserProduit
 * Description: permet au client de miser sur un produit aux enchères
 * Paramètres:  aucun
 * Retour:      aucun
 ****************************************************************************/
void Client::miserProduit(ProduitAuxEncheres* produitAuxEncheres, double montantMise) 
{

	if (montantMise > produitAuxEncheres->obtenirPrix()) 
	{
		if (monPanier_ == nullptr) 
		{
			monPanier_ = new Panier(this->obtenirIdentifiant());
		}
		produitAuxEncheres->modifierPrix(montantMise);
		produitAuxEncheres->modifierIdentifiantClient(this->obtenirIdentifiant());
		monPanier_->ajouter(produitAuxEncheres);
	}
}

/****************************************************************************
 * Fonction:    Client::operator=
 * Description: surcharge de l'opérateur '=' 
 * Paramètres:  const Client & client
 * Retour:      Client *this
 ****************************************************************************/
Client & Client::operator=(const Client & client)
{
	if (this != &client) {
		this->modifierNom(client.obtenirNom()); 
		this->modifierPrenom(client.obtenirPrenom()); 
		this->modifierIdentifiant(client.obtenirIdentifiant()); 
		this->modifierCodePostal(client.obtenirCodePostal()); 
		dateNaissance_ = client.obtenirDateNaissance();
		if (client.monPanier_ != nullptr) {
			delete monPanier_;
			monPanier_ = new Panier(obtenirIdentifiant());
			for (int i = 0; i < client.monPanier_->obtenirNombreContenu(); i++) {
				monPanier_->ajouter(client.monPanier_->obtenirContenuPanier()[i]);
			}
		}
		else
			monPanier_ = nullptr;
	}
	return *this;
}

/****************************************************************************
 * Fonction:    Client::operator<<
 * Description: surcharge de l'opérateur << pour afficher les attributs du client 
 * Paramètres:  ostream & os, const Client & client
 * Retour:      ostream& os
 ****************************************************************************/
ostream & operator<<(ostream & os, const Client & client)
{
	Usager clientConverti = static_cast<Usager> (client);
	os << clientConverti;
	os << "\t - Date de naissance : " << client.dateNaissance_ << endl << endl;
	if (client.obtenirPanier() != nullptr) 
	{
		os << *client.obtenirPanier();
	}
	return os;
}
