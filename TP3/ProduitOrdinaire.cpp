/********************************************
 * Titre: Travail pratique #3 - ProduitOrdinaire.cpp
 * Date: 16 février 2018
 * Auteur: Nicolas PAGE et Jean SAVARY
 *******************************************/

#include <string>
#include <iostream>
#include "ProduitOrdinaire.h"
#include "Fournisseur.h"
using namespace std;

/****************************************************************************
 * Fonction:    ProduitOrdinaire::ProduitOrdinaire
 * Description: constructeur par parametres
 * Paramètres:  Fournisseur& fournisseur, const string& nom, int reference, double prix, TypeProduit type, bool estTaxable
 * Retour:      aucun
 ****************************************************************************/
ProduitOrdinaire::ProduitOrdinaire(Fournisseur& fournisseur, const string& nom, int reference, double prix, TypeProduit type, bool estTaxable) : 
Produit(fournisseur, nom, reference, prix, type), estTaxable_(estTaxable)
{

}

/****************************************************************************
 * Fonction:    ProduitOrdinaire::obtenirEstTaxable
 * Description: accès à l'attribut estTaxable
 * Paramètres:  aucun
 * Retour:      bool estTaxable_
 ****************************************************************************/
bool ProduitOrdinaire::obtenirEstTaxable() const 
{
    return estTaxable_;
}

/****************************************************************************
 * Fonction:    ProduitOrdinaire::modifierEstTaxable
 * Description: modification de l'attribut estTaxable
 * Paramètres:  bool estTaxable
 * Retour:      aucun
 ****************************************************************************/
void ProduitOrdinaire::modifierEstTaxable(bool estTaxable) 
{
    estTaxable_ = estTaxable;
}

/****************************************************************************
 * Fonction:    operator>>
 * Description: surcharge de l'opérateur >> pour initialiser les attributs du produit ordinaire avec les inputs
 * Paramètres:  istream& is, ProduitOrdinaire& produit
 * Retour:      istream& is
 ****************************************************************************/
istream& operator>>(istream& is, ProduitOrdinaire& produit) 
{
    Produit produitConverti = static_cast<Produit> (produit);
    is >> produitConverti;
    cout << "Le produit est-il taxable (true/false) ? : ";
    is >> produit.estTaxable_;
    cout << endl;
    return is;
}

/****************************************************************************
 * Fonction:    operator<<
 * Description: surcharge de l'opérateur << pour afficher les informations sur le produit ordinaire
 * Paramètres:  ostream& os, const ProduitOrdinaire& produit
 * Retour:      ostream& os
 ****************************************************************************/
ostream& operator<<(ostream& os, const ProduitOrdinaire& produit)
{
    Produit produitConverti = static_cast<Produit> (produit);
    os << produitConverti;
    if(produit.obtenirEstTaxable()==true)
    {
        os << "\t Taxable : True " << endl;
    }
    else 
    {
        os << "\t Taxable : False " << endl;
    }
	return os;
}
