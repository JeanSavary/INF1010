/********************************************
 * Titre: Travail pratique #3 - Produit.cpp
 * Date: 16 février 2018
 * Auteur: Nicolas PAGE et Jean SAVARY
 *******************************************/

#include "Produit.h"

/****************************************************************************
 * Fonction:    Produit::Produit
 * Description: constructeur de produit et ajoute le produit au fournisseur
 * ParamËtres:    Fournisseur& fournisseur (IN),const string& nom(IN), int reference(IN), double prix (IN),TypeProduit type(IN)
 * Retour:        aucun
 ****************************************************************************/
Produit::Produit(Fournisseur& fournisseur,const string& nom, int reference, double prix,TypeProduit type) : fournisseur_(fournisseur), nom_(nom), reference_(reference), prix_(prix), type_(type)
{
    fournisseur.ajouterProduit(this);
}


/****************************************************************************
 * Fonction:    Produit::~Produit()
 * Description: destructeur de produit et enleve le produit au fournisseur
 * ParamËtres:    aucun
 * Retour:        aucun
 ****************************************************************************/
Produit::~Produit() 
{
    fournisseur_.enleverProduit(this);
}

/****************************************************************************
 * Fonction:    Produit::obtenirNom()
 * Description: retourne le nom du produit
 * ParamËtres:    aucun
 * Retour:        nom_ (string)
 ****************************************************************************/
string Produit::obtenirNom() const
{
    return nom_;
}

/****************************************************************************
 * Fonction:    Produit::obtenirReference()
 * Description: retourne la reference du produit
 * ParamËtres:    aucun
 * Retour:        reference_ (int)
 ****************************************************************************/
int Produit::obtenirReference() const
{
    return reference_;
}

/****************************************************************************
 * Fonction:    Produit::obtenirPrix()
 * Description: retourne le prix du produit
 * ParamËtres:    aucun
 * Retour:        prix_ (double)
 ****************************************************************************/
double Produit::obtenirPrix() const
{
    return prix_;
}

/****************************************************************************
 * Fonction:    Produit::obtenirFournisseur()
 * Description: retourne le fournisseur du produit
 * ParamËtres:    aucun
 * Retour:        fournisseur_ (Fournisseur&)
 ****************************************************************************/
Fournisseur& Produit::obtenirFournisseur() const
{
    return fournisseur_;
}

/****************************************************************************
 * Fonction:    Produit::retournerType()
 * Description: retourne le type du produit
 * ParamËtres:    aucun
 * Retour:        type_ (TypeProduit)
 ****************************************************************************/
TypeProduit Produit::retournerType() {
    return type_;
}

/****************************************************************************
 * Fonction:    Produit::modifierNom()
 * Description: modifie le nom du produit
 * ParamËtres:    string& nom (IN)
 * Retour:        aucun
 ****************************************************************************/
void Produit::modifierNom(const string& nom)
{
    nom_ = nom;
}

/****************************************************************************
 * Fonction:    Produit::modifierReference()
 * Description: modifie la reference du produit
 * ParamËtres:    int reference (IN)
 * Retour:        aucun
 ****************************************************************************/
void Produit::modifierReference(int reference)
{
    reference_ = reference;
}

/****************************************************************************
 * Fonction:    Produit::modifierPrix()
 * Description: modifie le prix du produit
 * ParamËtres:    double prix (IN)
 * Retour:        aucun
 ****************************************************************************/
void Produit::modifierPrix(double prix)
{
    prix_ = prix;
}

/****************************************************************************
 * Fonction:    Produit:: operator>
 * Description: permet de vérifier si un produit est plus cher qu'un autre
 * ParamËtres:    Produit & produit (IN)
 * Retour:        bool
 ****************************************************************************/
bool Produit::operator>(const Produit & produit) const
{
    return prix_ > produit.prix_;
}

/****************************************************************************
 * Fonction:    Produit:: operator<
 * Description: permet de vérifier si un produit est moin cher qu'un autre
 * ParamËtres:    Produit & produit (IN)
 * Retour:        bool
 ****************************************************************************/
bool Produit::operator<(const Produit & produit) const
{
    return prix_ < produit.prix_;
}

/****************************************************************************
 * Fonction:    Produit:: operator==
 * Description: permet de vérifier si un produit est équivalent à un autre
 * ParamËtres:    Produit & produit (IN)
 * Retour:        bool
 ****************************************************************************/
bool Produit::operator==(const Produit & produit) const
{
    return (nom_ == produit.nom_ &&
            prix_ == produit.prix_ &&
            reference_ == produit.reference_);
}


/****************************************************************************
 * Fonction:    istream & operator>>
 * Description: permet de prendre un type de produit
 * ParamËtres:    istream & is (IN/OUT) , TypeProduit & typeProduit (IN)
 * Retour:        istream & is
 ****************************************************************************/
inline istream & operator >> (istream & is, TypeProduit & typeProduit) {
    unsigned int type = 0;
    if (is >> type)
        typeProduit = static_cast<TypeProduit>(type);
    return is;
}

/****************************************************************************
 * Fonction:    istream & operator>>
 * Description: permet de prendre un produit
 * ParamËtres:    istream & is (IN/OUT) , TypeProduit & typeProduit (IN)
 * Retour:        istream & is
 ****************************************************************************/
istream & operator>>(istream & is, Produit & produit)
{
    return is >> produit.nom_ >> produit.reference_ >> produit.prix_ >> produit.type_;
}

/****************************************************************************
 * Fonction:    ostream & operator<<
 * Description: permet d'afficher un produit
 * ParamËtres:    ostream & os (IN/OUT), Produit & produit (IN)
 * Retour:        ostream & os
 ****************************************************************************/
ostream & operator<<(ostream & os, const Produit & produit)
{
    os << "Produit :" << endl << endl
    << "\t Nom : " << produit.obtenirNom() << endl
    << "\t Référence : " << produit.obtenirReference() << endl
    << "\t Prix actuel : " << produit.obtenirPrix() << "€" << endl
    << "\t Fournisseur : " << produit.obtenirFournisseur().obtenirNom() << endl;
    return os;
}



