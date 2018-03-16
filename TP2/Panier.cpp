/********************************************
 * Titre: Travail pratique #2 - Panier.cpp
 * Date: 25 janvier 2018
 * Auteur: Nicolas PAGE et Jean  SAVARY
 *******************************************/

#include "Panier.h"
#include <vector>

/****************************************************************************
 * Fonction:    Panier::Panier
 * Description: constructeur par defaut
 * Paramètres:    aucun
 * Retour:        aucun
 ****************************************************************************/
Panier::Panier() :
contenuPanier_(vector<Produit*>(0)),
totalAPayer_(0)
{
}

/****************************************************************************
 * Fonction:    Panier::~Panier
 * Description: destructeur
 * Paramètres:    aucun
 * Retour:        aucun
 ****************************************************************************/
Panier::~Panier()
{
    contenuPanier_.clear();  
}

/****************************************************************************
 * Fonction:    Panier::obtenirContenuPanier
 * Description: retourne le contenu du panier
 * Paramètres:  aucun
 * Retour:        contenuPanier_ (vector<Produit*>)
 ****************************************************************************/
vector <Produit*> Panier::obtenirContenuPanier()const
{
    return contenuPanier_;
}

/****************************************************************************
 * Fonction:    Panier::obtenirTotalApayer
 * Description: retourne le total a payer pour le  panier
 * Paramètres:  aucun
 * Retour:        totalAPayer_ (double)
 ****************************************************************************/
double Panier::obtenirTotalApayer() const
{
    return totalAPayer_;
}

/****************************************************************************
 * Fonction:    Panier::modifierTotalAPayer
 * Description: modifie le total a payer
 * Paramètres:  double totalAPayer (IN)
 * Retour:        aucun
 ****************************************************************************/
void Panier::modifierTotalAPayer(double totalAPayer)
{
    totalAPayer_ = totalAPayer;
}

/****************************************************************************
 * Fonction:    Panier::ajouter
 * Description: ajoute un produit au panier et incrmente le total a payer
 * Paramètres:  Produit * prod (IN)
 * Retour:        aucun
 ****************************************************************************/
void Panier::ajouter(Produit * prod)
{
    contenuPanier_.push_back(prod);
    totalAPayer_ += prod->obtenirPrix();
}

/****************************************************************************
 * Fonction:    Panier::livrer
 * Description: vide le contenu du panier et met le total a payer a zero
 * Paramètres:  aucun
 * Retour:        aucun
 ****************************************************************************/
void Panier::livrer()
{
    contenuPanier_.clear();
    totalAPayer_=0;
}

/****************************************************************************
 * Fonction:    Panier::trouverProduitPlusCHer
 * Description: trouve le produit le plus cher dans le panier
 * Paramètres:  aucun
 * Retour:        produitMax (Produit*)
 ****************************************************************************/
Produit* Panier::trouverProduitPlusCher()
{
    Produit* produitMax = new Produit();
    for (int i=0; i<contenuPanier_.size();i++){
        if (*contenuPanier_[i] > *produitMax) {
            *produitMax = *contenuPanier_[i];
        }
    }
    return produitMax;
}

/****************************************************************************
 * Fonction:    Panier::operator<<
 * Description: permet d'afficher le panier
 * Paramètres:  ostream& flux (OUT), const Panier& panier (IN)
 * Retour:        flux
 ****************************************************************************/
ostream& operator<<(ostream& flux, const Panier& panier) {
    flux<<"\t Nombre de produits : "<<panier.obtenirContenuPanier().size()<<endl;
    flux<<"\t Contenu du panier : " <<endl<<endl;
    for(int i=0; i<panier.obtenirContenuPanier().size();i++){
        Produit* prod = panier.obtenirContenuPanier()[i];
        flux<<"\t\t Produit = "<<prod->obtenirNom()<<"\t Référence = "<<prod->obtenirReference()<<"\t Prix = "<<prod->obtenirPrix()<<"€"<<endl;
    }
    flux<<endl<<"\t Total à payer : " <<panier.obtenirTotalApayer()<< "€"<<endl;
    return flux;
}
