/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireProduits.h"


GestionnaireProduits::GestionnaireProduits()
{}

void GestionnaireProduits::reinitialiserClient()
{
    for (multimap<int,Produit*>::iterator it= conteneur_.begin() ; it !=conteneur_.end(); it++) {
        ProduitAuxEncheres *produit = dynamic_cast<ProduitAuxEncheres *>(it->second);
        if (produit) {
            produit->modifierEncherisseur(nullptr);
            produit->modifierPrix(produit->obtenirPrixInitial());
    }
    conteneur_.clear();
    }
    
}

void GestionnaireProduits::reinitialiserFournisseur()
{
    for (multimap<int,Produit*>::iterator it= conteneur_.begin() ; it !=conteneur_.end(); it++) {
        it->second->modifierFournisseur(nullptr);
        }
        conteneur_.clear();
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
    /*
     double montant = 0;
     for (unsigned int i = 0; i < panier_.size(); i++)
     montant += panier_[i]->obtenirPrix();
     return montant;
     */
    
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

Produit* GestionnaireProduits::trouverProduitPlusCher() const
{
    using pairtype = pair<int, Produit*>;
    auto max= max_element(
            conteneur_.begin(),conteneur_.end(),[](const pairtype & p1,const pairtype & p2)
                {
                    return p1.second->obtenirPrix() < p2.second->obtenirPrix();
                }
    );
    return max->second;
}

vector<pair<int,Produit*>> GestionnaireProduits::obtenirProduitsEntre(double borneInf, double borneSup)
{
    vector<pair<int, Produit*>> vecteur;
    copy_if(conteneur_.begin(), conteneur_.end(), back_inserter(vecteur), FoncteurIntervalle(borneInf,borneSup));
    return vecteur;
}



Produit* GestionnaireProduits::obtenirProduitSuivant(Produit* produit)
{
    multimap<int, Produit*>:: iterator it = find_if(conteneur_.begin(),conteneur_.end(),bind(FoncteurEgal<Produit>(produit)));
    it++;
    return it->second;
}




