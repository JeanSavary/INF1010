#include "Client.h"
#include "ProduitAuxEncheres.h"
#include <iostream>

Client::Client(unsigned int codeClient)
: Usager(),
codeClient_(codeClient)
{
}

Client::Client(const string &nom, const string &prenom, int identifiant,
               const string &codePostal, unsigned int codeClient)
: Usager(nom, prenom, identifiant, codePostal),
codeClient_(codeClient)
{
}

Client::Client(const Client& client) : Usager(client.obtenirNom(), client.obtenirPrenom(), client.obtenirIdentifiant(), client.obtenirCodePostal()),
codeClient_(client.obtenirCodeClient())
{
    for (int i=0; i<client.obtenirPanier().size();i++)
    {
        panier_.push_back(client.obtenirPanier()[i]);
    }
}

unsigned int Client::obtenirCodeClient() const
{
    return codeClient_;
}

vector<Produit *> Client::obtenirPanier() const
{
    return panier_;
}

double Client::obtenirTotalAPayer() const
{
    
    double total=0;
    for(int i=0;i<panier_.size();i++){
       total += panier_[i]->obtenirPrix();
    }
    return total;
}

void Client::afficherPanier() const
{
    cout << "PANIER (de " << obtenirNom() << ")"
    << "\n";
    for (unsigned int i = 0; i < panier_.size(); i++)
        panier_[i]->afficher();
    cout << endl;
}

void Client::afficherProfil() const
{
    Usager::afficherProfil();
    cout << "\t Type : client " << endl;
    cout<< "\t Panier de "<< panier_.size()<< " elements"<<endl;
    
}

void Client::modifierCodeClient(unsigned int codeClient)
{
    codeClient_ = codeClient;
}

void Client::enleverProduit(Produit *produit)
{
    for (unsigned int i = 0; i < panier_.size(); i++)
    {
        if (panier_[i] == produit)
        {
            panier_[i] = panier_[panier_.size() - 1];
            panier_.pop_back();
            return;
        }
    }
}

void Client::ajouterProduit(Produit *produit)
{
    for (unsigned int i = 0; i < panier_.size(); i++)
        if (panier_[i] == produit)
            return;
    panier_.push_back(produit);
}

/****************************************************************************
 * Fonction:  Client::reinitialiser()
 * Description: reinitialise le panier du client 
 * Paramètres: aucun
 * Retour: aucun
 ****************************************************************************/
void Client::reinitialiser()
{
    for (int i=0; i<panier_.size();i++)
    {
        if(typeid(*panier_[i])==typeid(ProduitAuxEncheres))
        {
            ProduitAuxEncheres* produitConverti = dynamic_cast<ProduitAuxEncheres*>(panier_[i]);//on réalise un dynamic cast afin de pouvoir utiliser les méthodes de la classe ProduitAuxEncheres
            produitConverti->mettreAJourEnchere(nullptr, produitConverti->obtenirPrixInitial());
        }
    }
    panier_.clear();
}

/****************************************************************************
 * Fonction:  Client::operator=
 * Description: operateur = permettant d'écraser tous les attributs d'un client
 * et de les remplacer par ceux du client passé en paramètre.
 * Paramètres: aucun
 * Retour: aucun
 ****************************************************************************/
Client & Client::operator=(const Client & client)
{
    if (this != &client) 
    {
		this->modifierNom(client.obtenirNom()); 
		this->modifierPrenom(client.obtenirPrenom()); 
		this->modifierIdentifiant(client.obtenirIdentifiant()); 
		this->modifierCodePostal(client.obtenirCodePostal()); 
        this->modifierCodeClient(client.obtenirCodeClient());
        this->panier_.clear();
        for (int i=0; i<client.obtenirPanier().size();i++) //on réalise une deep copie en parcourant les éléments un par un car panier_ contient des pointeurs
        // on ne peut donc pas faire de Shallow copy.
        {
            this->panier_.push_back(client.obtenirPanier()[i]);
        }

    }
    return *this;  
}