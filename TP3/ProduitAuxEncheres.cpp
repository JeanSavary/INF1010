/********************************************
 * Titre: Travail pratique #3 - ProduitAuxEncheres.cpp
 * Date: 16 février 2018
 * Auteur: Nicolas PAGE et Jean SAVARY
 *******************************************/

#include "ProduitAuxEncheres.h"

/****************************************************************************
 * Fonction:    ProduitAuxEncheres::ProduitAuxEncheres
 * Description: constructeur par parametres
 * Paramètres:  Fournisseur& fournisseur, const string& nom, int reference, double prix, TypeProduit type, double prixBase, int identifiantClient
 * Retour:      aucun
 ****************************************************************************/
ProduitAuxEncheres::ProduitAuxEncheres(Fournisseur& fournisseur, const string& nom, int reference, double prix, TypeProduit type, double prixBase, int identifiantClient) :
Produit(fournisseur, nom, reference, prix, type), prixBase_(prixBase), identifiantClient_(identifiantClient)
{

}

/****************************************************************************
 * Fonction:    ProduitAuxEncheres::obtenirIdentifiantClient
 * Description: accès à l'attribut identifiantClient_
 * Paramètres:  aucun
 * Retour:      int identifiantClient_
 ****************************************************************************/
int ProduitAuxEncheres::obtenirIdentifiantClient() const 
{
    return identifiantClient_;
}

/****************************************************************************
 * Fonction:    ProduitAuxEncheres::obtenirPrixBase
 * Description: accès à l'attribut prixBase_
 * Paramètres:  aucun
 * Retour:      double prixBase_
 ****************************************************************************/
double ProduitAuxEncheres::obtenirPrixBase() const 
{
    return prixBase_;
}

/****************************************************************************
 * Fonction:    ProduitAuxEncheres::modifierIdentifiantClient
 * Description: modification de l'attribut prixBase_
 * Paramètres:  int identifiantClient
 * Retour:      aucun
 ****************************************************************************/
void ProduitAuxEncheres::modifierIdentifiantClient(int identifiantClient)
{
    identifiantClient_ = identifiantClient;
}

/****************************************************************************
 * Fonction:    ProduitAuxEncheres::modifierPrixBase
 * Description: modification de l'attribut prixBase_
 * Paramètres:  int identifiantClient
 * Retour:      aucun
 ****************************************************************************/
void ProduitAuxEncheres::modifierPrixBase(double prixBase)
{
    prixBase_ = prixBase;
}

/****************************************************************************
 * Fonction:   operator>>
 * Description: surcharge de l'opérateur >> pour initialiser les attributs du produit aux encheres avec les inputs
 * Paramètres:  istream& is, ProduitAuxEncheres& produit
 * Retour:      istream& is
 ****************************************************************************/
istream& operator>>(istream& is, ProduitAuxEncheres& produit)
{
    Produit produitConverti = static_cast<Produit> (produit);
    is >> produit;
    cout << "Entrer le prix de base : ";
    is >> produit.prixBase_;
    cout << endl << "Entrer l'identifiant du client ayant misé le plus : ";
    is >> produit.identifiantClient_;
    return is;
}

/****************************************************************************
 * Fonction:   operator<<
 * Description: surcharge de l'opérateur << pour afficher les informations sur le produit ordinaire
 * Paramètres:  ostream& os, const ProduitAuxEncheres& produit
 * Retour:      ostream& os
 ****************************************************************************/
ostream& operator<<(ostream& os, const ProduitAuxEncheres& produit)
{
    Produit produitConverti = static_cast<Produit> (produit);
    os << produitConverti;
    os << "\t Prix de base : " << produit.obtenirPrixBase() << endl;
    os << "\t Identifiant meilleur offreur : " << produit.obtenirIdentifiantClient() << endl << endl;
    return os;
}