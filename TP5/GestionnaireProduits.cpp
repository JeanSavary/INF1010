/********************************************
 * Titre: Travail pratique #5 - GestionnaireProduits.cpp
 * Date: 9 mars 2018
 * Auteurs: SAVARY Jean, PAGE Nicolas
 *******************************************/

#include "GestionnaireProduits.h"
#include "ProduitAuxEncheres.h"

GestionnaireProduits::GestionnaireProduits()
{
}

GestionnaireProduits::~GestionnaireProduits()
{
    if (conteneur_.size() > 0)
    {
        conteneur_.clear();
    }
}

void GestionnaireProduits::reinitialiserClient()
{
    for (auto it= conteneur_.begin() ; it !=conteneur_.end(); it++)
    {
        ProduitAuxEncheres* produit = dynamic_cast<ProduitAuxEncheres*>(it->second);
        if (produit)
        {
            produit->modifierEncherisseur(nullptr);
            produit->modifierPrix(produit->obtenirPrixInitial());
        }
    }
    
    if (conteneur_.size() > 0)
    {
        conteneur_.clear();
    }
    
}

void GestionnaireProduits::reinitialiserFournisseur()
{
    for (auto it= conteneur_.begin() ; it !=conteneur_.end(); it++)
    {
        it->second->modifierFournisseur(nullptr);
    }
    
    if (conteneur_.size() > 0)
    {
        conteneur_.clear();
    }
    
}

void GestionnaireProduits::afficher() const
{
    for(pair<int, Produit*> pair:conteneur_) {
        pair.second->afficher();
    }
}

double GestionnaireProduits::obtenirTotalAPayer() const
{
    double montant = 0;
    for(pair<int, Produit*> pair:conteneur_) {
        montant+= pair.second->obtenirPrix();
    }
    return montant;
    
}

double GestionnaireProduits::obtenirTotalAPayerPremium() const
{
    double montant = 0;
    for(pair<int, Produit*> pair:conteneur_) {
        double prix = pair.second->obtenirPrix();
        montant += prix < 5 ? 0 : prix - 5;
    }
    return montant;
    
}


/*
 trouverProduitPlusCher() : retourne le Produit ayant le prix le plus élevé dans la
 multimap de produits. 
 */
Produit* GestionnaireProduits::trouverProduitPlusCher() const
{
    using pairtype = pair<int, Produit*>;
   
    if (conteneur_.size()==0)
        return nullptr;
    
    auto max= max_element(
                          conteneur_.begin(),conteneur_.end(),[](const pairtype & p1,const pairtype & p2)
                          {
                              return p1.second->obtenirPrix() < p2.second->obtenirPrix();
                          }
                          );
    return max->second;
}

/*obtenirProduitsEntre(): prend deux paramètres de type double qui représenteront les bornes de l’intervale. 
Cette méthode retourne un vector contenant les paires pair<int, Produit*> dont les prix des produits associés 
sont compris dans cet intervalle.*/

vector<pair<int,Produit*>> GestionnaireProduits::obtenirProduitsEntre(double borneInf, double borneSup)
{
    vector<pair<int, Produit*>> vecteur;
    copy_if(conteneur_.begin(), conteneur_.end(), back_inserter(vecteur), FoncteurIntervalle(borneInf,borneSup));
    return vecteur;
}

/*
 obtenirProduitSuivant() : prend en paramètre un pointeur de Produit et retourne le pointeur de Produit ayant 
 une référence strictement supérieure.
 */

Produit* GestionnaireProduits::obtenirProduitSuivant(Produit* produit)
{
    
    multimap<int, Produit*>:: iterator it = find_if(conteneur_.begin(),conteneur_.end(),bind(greater<pair<int, Produit*>>(),std::placeholders::_1,make_pair(produit->obtenirReference(), produit)));
    return (it->second);
}




