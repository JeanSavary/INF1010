/********************************************
 * Titre: Travail pratique #2 - Client.cpp
 * Date: 25 janvier 2018
 * Auteur: Nicolas PAGE et Jean SAVARY
 *******************************************/

#include "Client.h"

/****************************************************************************
 * Fonction:    Client::Client
 * Description: constructeur par parametres
 * Paramètres:    const string&  nom (IN), const string& prenom (IN), int identifiant(IN), const string& codePostal(IN), long date(IN)
 * Retour:       aucun
 ****************************************************************************/
Client::Client(const string&  nom, const string& prenom, int identifiant, const string& codePostal, long date) :
nom_(nom),
prenom_(prenom),
identifiant_(identifiant),
codePostal_(codePostal),
dateNaissance_(date),
monPanier_(new Panier())
{
}

/****************************************************************************
 * Fonction:    Client::Client()
 * Description: Constructeur par copie
 * Paramètres:    const Client& autreClient (IN)
 * Retour:        aucun
 ****************************************************************************/
Client::Client(const Client& autreClient) : nom_(autreClient.nom_), prenom_(autreClient.prenom_),identifiant_(autreClient.identifiant_),codePostal_(autreClient.codePostal_),dateNaissance_(autreClient.dateNaissance_),monPanier_(nullptr)
{
    monPanier_ = new Panier();
}

/****************************************************************************
 * Fonction:    Client::~Client()
 * Description: Destructeur 
 * Paramètres:    aucun
 * Retour:        aucun
 ****************************************************************************/
Client::~Client()
{
    if (!monPanier_->obtenirContenuPanier().empty())
        monPanier_->livrer(); //réinitialisation du panier
}

/****************************************************************************
 * Fonction:    Client::obtenirNom()
 * Description: retourne le nom du client
 * Paramètres:    aucun
 * Retour:        nom_
 ****************************************************************************/
string Client::obtenirNom() const
{
    return nom_;
}

/****************************************************************************
 * Fonction:    Client::obtenirPrenom()
 * Description: retourne le prenom du client
 * Paramètres:    aucun
 * Retour:        prenom_
 ****************************************************************************/
string Client::obtenirPrenom() const
{
    return prenom_;
}

/****************************************************************************
 * Fonction:    Client::obtenirIdentifiant()
 * Description: retourne l'identifiant du client
 * Paramètres:    aucun
 * Retour:        identifiant_
 ****************************************************************************/
int Client::obtenirIdentifiant() const
{
    return identifiant_;
}

/****************************************************************************
 * Fonction:    Client::obtenirCodePostal()
 * Description: retourne le code postal du client
 * Paramètres:    aucun
 * Retour:        codePostal_
 ****************************************************************************/
string Client::obtenirCodePostal() const
{
    return codePostal_;
}

/****************************************************************************
 * Fonction:    Client::obtenirDateNaissance()
 * Description: retourne la date de naissance du client
 * Paramètres:    aucun
 * Retour:        dateNaissance_
 ****************************************************************************/
long Client::obtenirDateNaissance() const
{
    return dateNaissance_;
}

/****************************************************************************
 * Fonction:    Client::obtenirDateNaissance()
 * Description: retourne la date de naissance du client
 * Paramètres:    aucun
 * Retour:        dateNaissance_
 ****************************************************************************/
Panier* Client::obtenirPanier() const
{
    return monPanier_;
}

/****************************************************************************
 * Fonction:    Client::modifierNom
 * Description: modifie le nom du client
 * Paramètres:    const string& nom (IN)
 * Retour:        aucun
 ****************************************************************************/
void  Client::modifierNom(const string& nom)
{
    nom_ = nom;
}

/****************************************************************************
 * Fonction:    Client::modifierPrenom
 * Description: modifie le prenom du client
 * Paramètres:    const string& prenom (IN)
 * Retour:        aucun
 ****************************************************************************/
void Client::modifierPrenom(const string& prenom)
{
    prenom_ = prenom;
}

/****************************************************************************
 * Fonction:    Client::modifierIdentifiant
 * Description: modifie l'identifiant du client
 * Paramètres:    int identifiant (IN)
 * Retour:        aucun
 ****************************************************************************/
void Client::modifierIdentifiant(int identifiant)
{
    identifiant_ = identifiant;
}

/****************************************************************************
 * Fonction:    Client::modifierCodePostal
 * Description: modifie le code postal du client
 * Paramètres:    const string& codePostal (IN)
 * Retour:        aucun
 ****************************************************************************/
void Client::modifierCodePostal(const string& codePostal)
{
    codePostal_ = codePostal;
}

/****************************************************************************
 * Fonction:    Client::modifierDateNaissance
 * Description: modifie la date de naissance du client
 * Paramètres:    long date (IN)
 * Retour:        aucun
 ****************************************************************************/
void Client::modifierDateNaissance(long date)
{
    dateNaissance_ = date;
}

/****************************************************************************
 * Fonction:    Client::operator=
 * Description: rend les attributs d'un client egal a un autre
 * Paramètres:    const Client& client (IN)
 * Retour:        *this (represente le nouveau client)
 ****************************************************************************/
Client& Client::operator=(const Client& client)
{
    if (this != &client) {

        delete monPanier_;
        *monPanier_ = *client.monPanier_;
        nom_ = client.nom_;
        prenom_ = client.prenom_;
        identifiant_ = client.identifiant_;
        codePostal_ = client.codePostal_;
        dateNaissance_ = client.dateNaissance_;
        
    }
    
    return *this;
}

/****************************************************************************
 * Fonction:    Client::operator==
 * Description: verifie si l'identifiant d'un client est egal a celui d'un autre
 * Paramètres:    const int& identifiant (IN)
 * Retour:        bool
 ****************************************************************************/
bool Client::operator==(const int& identifiant) const
{
    if (identifiant_ == identifiant)
        return true;
    else
        return false;
}

/****************************************************************************
 * Fonction:    Client::operator==
 * Description: verifie si l'identifiant d'un client est egal a celui d'un autre
 * Paramètres:    const int& identifiant(IN) , const Client& client (IN)
 * Retour:        bool
 ****************************************************************************/
bool operator==(const int& identifiant, const Client& client)
{
    return (client == identifiant);
}

/****************************************************************************
 * Fonction:    Client::acheter
 * Description: ajout d'un produit au panier du client
 * Paramètres:    Produit * prod(IN)
 * Retour:          aucun
 ****************************************************************************/
void Client::acheter(Produit * prod)
{
    if (monPanier_ == nullptr)
        monPanier_ = new Panier();
    monPanier_->ajouter(prod);
}
/****************************************************************************
 * Fonction:    Client::livrerPanier
 * Description: livre le panier du client
 * Paramètres:    aucun
 * Retour:      aucun
 ****************************************************************************/
void Client::livrerPanier()
{
    monPanier_->livrer();
}

/****************************************************************************
 * Fonction:    Client::operator<<
 * Description: affiche le nom du client et le contenu de son panier
 * Paramètres: ostream& flux (OUT), const Client& client (IN)
 * Retour:   aucun
 ****************************************************************************/
ostream& operator<<(ostream& flux, const Client& client)
{
    if (client.monPanier_->obtenirContenuPanier().empty()) {
        flux<<"Le panier de "<<client.prenom_<<" est vide."<<endl;
        
    }
    else {
        flux<<"Voici le panier de "<<client.prenom_<<" :"<<endl<<endl;
        flux<<*client.monPanier_<<endl;
    }
    return flux;
}