/********************************************
 * Titre: Travail pratique #2 - Produit.cpp
 * Date: 25 janvier 2018
 * Auteur: Nicolas PAGE et Jean SAVARY
 *******************************************/

#include "Produit.h"

/****************************************************************************
 * Fonction:    Produit::Produit
 * Description: constructeur par parametres
 * Paramètres:  const string& nom (IN), int reference (IN) , double prix (IN)
 * Retour:        aucun
 ****************************************************************************/
Produit::Produit(const string& nom, int reference, double prix) :
nom_(nom),
reference_(reference),
prix_(prix)
{ }


/****************************************************************************
 * Fonction:    Produit::obtenirNom
 * Description: retourne le nom du produit
 * Paramètres:  aucun
 * Retour:        nom_ (string)
 ****************************************************************************/
string Produit::obtenirNom() const
{
    return nom_;
}

/****************************************************************************
 * Fonction:    Produit::obtenirReference
 * Description: retourne la reference du produit
 * Paramètres:  aucun
 * Retour:        reference_ (int)
 ****************************************************************************/
int Produit::obtenirReference() const
{
    return reference_;
}

/****************************************************************************
 * Fonction:    Produit::obtenirPrix
 * Description: retourne le prix du produit
 * Paramètres:  aucun
 * Retour:        prix_ (double)
 ****************************************************************************/
double Produit::obtenirPrix() const
{
    return prix_;
}

/****************************************************************************
 * Fonction:    Produit::modifierNom
 * Description: modifier le nom du produit
 * Paramètres:  const string& nom (IN)
 * Retour:        aucun
 ****************************************************************************/
void Produit::modifierNom(const string& nom)
{
    nom_ = nom;
}

/****************************************************************************
 * Fonction:    Produit::modifierReference
 * Description: modifier la reference du produit
 * Paramètres:  int reference (IN)
 * Retour:        aucun
 ****************************************************************************/
void Produit::modifierReference(int reference)
{
    reference_ = reference;
}

/****************************************************************************
 * Fonction:    Produit::modifierPrix
 * Description: modifier le prix du produit
 * Paramètres:  double prix (IN)
 * Retour:        aucun
 ****************************************************************************/
void Produit::modifierPrix(double prix)
{
    prix_ = prix;
}

/****************************************************************************
 * Fonction:    Produit::operator>
 * Description: permet de verifier si un produit est plus cher qu'un autre
 * Paramètres:  const Produit& produit1 (IN)
 * Retour:       bool
 ****************************************************************************/
bool Produit::operator>(const Produit& produit1)const
{
    if(prix_>produit1.prix_)
        return true;
    else return false;
}

/****************************************************************************
 * Fonction:    Produit::operator<
 * Description: permet de verifier si un produit est plus cher qu'un autre
 * Paramètres:  const Produit& produit1 (IN)
 * Retour:       bool
 ****************************************************************************/
bool Produit::operator<(const Produit& produit1)const
{
    if(prix_<produit1.prix_)
        return true;
    else return false;
}

/****************************************************************************
 * Fonction:    Produit::operator==
 * Description: permet de verifier si un produit est equivalent a un autre
 * Paramètres:  const Produit& produit1 (IN)
 * Retour:       bool
 ****************************************************************************/
bool Produit::operator==(const Produit& produit1)const
{
    if(nom_==produit1.nom_ && reference_==produit1.reference_ && prix_==produit1.prix_){
        return true;
    }
    else return false;
}

/****************************************************************************
 * Fonction:    Produit::operator>>
 * Description: permet de verifier de prendre un parametre des attributs
 * Paramètres:  istream& flux (IN) ,Produit* produit1(IN)
 * Retour:       flux
 ****************************************************************************/
istream& operator>>(istream& flux,Produit* produit1)
{
    flux>>produit1->nom_>>produit1->reference_>>produit1->prix_;
    return flux;
}

/****************************************************************************
 * Fonction:    Produit::operator<<
 * Description: permet d'afficher les attributs d'un produit
 * Paramètres:  istream& flux (OUT) ,const Produit& produit1 (IN)
 * Retour:       flux
 ****************************************************************************/
ostream& operator<<(ostream& flux, const Produit& produit1)
{
    flux<<"\t Nom : "<<produit1.obtenirNom()<<"\t Référence : "<<produit1.obtenirReference()<<"\t Prix : "<<produit1.obtenirPrix()<<"€"<<endl;
    return flux;
}

