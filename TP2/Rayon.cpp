/********************************************
 * Titre: Travail pratique #2 - Rayon.cpp
 * Date: 25 janvier 2018
 * Auteur: Nicolas PAGE et Jean SAVARY
 *******************************************/

#include "Rayon.h"

/****************************************************************************
 * Fonction:    Rayon::Rayon
 * Description: constructeur par paramètres
 * Paramètres:    const string& cat (IN)
 * Retour:        aucun
 ****************************************************************************/
Rayon::Rayon(const string& cat) :
categorie_(cat)
{
}

/****************************************************************************
 * Fonction:    Rayon::~Rayon
 * Description: destructeur
 * Paramètres:    aucun
 * Retour:        aucun
 ****************************************************************************/
Rayon::~Rayon()
{
    tousProduits_.clear();
}

/****************************************************************************
 * Fonction:    Rayon::obtenirCategorie
 * Description: retourne la categorie du rayon
 * Paramètres:    aucun
 * Retour:        categorie_ (string)
 ****************************************************************************/
string Rayon::obtenirCategorie() const
{
    return categorie_;
}

/****************************************************************************
 * Fonction:    Rayon::obtenirTousProduits
 * Description: retourne tous les produits du rayon
 * Paramètres:    aucun
 * Retour:        tousProduits_ (vector<Produit*>)
 ****************************************************************************/
vector<Produit*> Rayon::obtenirTousProduits() const
{
    return tousProduits_;
}

/****************************************************************************
 * Fonction:    Rayon::obtenirNombreProduits
 * Description: retourne le nombre de produits du rayon
 * Paramètres:    aucun
 * Retour:        tousProduits_.size (int)
 ****************************************************************************/
int Rayon::obtenirNombreProduits() const
{
    return tousProduits_.size();
}

/****************************************************************************
 * Fonction:    Rayon::modifierCategorie
 * Description: modifie la catégorie du rayon
 * Paramètres:    const string& cat (IN)
 * Retour:        aucun
 ****************************************************************************/
void Rayon::modifierCategorie(const string& cat)
{
    categorie_ = cat;
}

/****************************************************************************
 * Fonction:    Rayon::compterDoublons
 * Description: compte le nombre de fois qu'un produit en question apparait dans le rayon
 * Paramètres:    const Produit& produit (IN)
 * Retour:        doublons (int)
 ****************************************************************************/
int Rayon::compterDoublons(const Produit& produit)
{
    int doublons=0;
    for(int i=0;i<tousProduits_.size();i++){
        if(produit==*tousProduits_[i])
            doublons++;
    }
    return doublons;
}

/****************************************************************************
 * Fonction:    Rayon::operator+=
 * Description: permet de rajouter un produit dans le rayon
 * Paramètres:    string &produit (IN)
 * Retour:        *this (soit le rayon)
 ****************************************************************************/
Rayon& Rayon::operator+=(Produit &produit)
{    
    tousProduits_.push_back(&produit);
    return *this;   
}

/****************************************************************************
 * Fonction:    Rayon::operator<<
 * Description: permet d'afficher le contenu du rayon
 * Paramètres: ostream& flux(OUT), const Rayon& rayon (IN)
 * Retour:        flux
 ****************************************************************************/
ostream& operator<<(ostream& flux, const Rayon& rayon)
{
    flux<<"Le rayon "<< rayon.obtenirCategorie()<<":"<<endl;
    for(int i=0; i<rayon.tousProduits_.size();i++){
        flux<<"----> Nom: "<<rayon.tousProduits_[i]->obtenirNom()<< "\t Référence : "<<rayon.tousProduits_[i]->obtenirReference()<<"\t Prix : "<< rayon.tousProduits_[i]->obtenirPrix()<<"€"<<endl;
    }
    return flux;
}



