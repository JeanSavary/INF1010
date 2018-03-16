/********************************************
 * Titre: Travail pratique #3 - Panier.cpp
 * Date:
 * Auteur:
 *******************************************/

#include "Panier.h"
using namespace std;

/****************************************************************************
 * Fonction:    Panier::Panier
 * Description: constructeur par parametres
 * ParamËtres:    int idClient (IN)
 * Retour:       aucun
 ****************************************************************************/
Panier::Panier(int idClient): idClient_(idClient)
{

}

/****************************************************************************
 * Fonction:    Panier::~Panier
 * Description: destructeur de panier
 * ParamËtres:    aucun
 * Retour:       aucun
 ****************************************************************************/
Panier::~Panier()
{
    contenuPanier_.clear();
}

/****************************************************************************
 * Fonction:    Panier::obtenirContenuPanier
 * Description: retourne le contenu du panier
 * ParamËtres:    aucun
 * Retour:       vector<Produit*> contenuPanier_
 ****************************************************************************/
vector<Produit*>  Panier::obtenirContenuPanier()const
{
    return contenuPanier_;
}

/****************************************************************************
 * Fonction:    Panier::obtenirNombreContenu
 * Description: retourne le nombre d'objet dans le panier
 * ParamËtres:    aucun
 * Retour:       int contenuPanier_.size()
 ****************************************************************************/
int Panier::obtenirNombreContenu() const
{
    return (int)contenuPanier_.size();
}

/****************************************************************************
 * Fonction:    Panier::obtenirIdClient
 * Description: retourne l'identifiant du client
 * ParamËtres:    aucun
 * Retour:       int idClient_
 ****************************************************************************/
int Panier::obtenirIdClient() const 
{
    return idClient_;
}

/****************************************************************************
 * Fonction:    Panier::obtenirTotalAPayer
 * Description: retourne le total a payer
 * ParamËtres:    aucun
 * Retour:       double totalAPayer_
 ****************************************************************************/
double Panier::obtenirTotalApayer() const 
{
    return totalAPayer_;
}

/****************************************************************************
 * Fonction:    Panier::calculerTotalAPayer
 * Description: calcule le total a payer
 * ParamËtres:    aucun
 * Retour:       double total
 ****************************************************************************/
double Panier::calculerTotalApayer()  const
{
    double total = 0;
    for(int i =0;i< contenuPanier_.size();i++)
    {
        if(contenuPanier_[i]->retournerType()==TypeProduitOrdinaire)
        {
            total += contenuPanier_[i]->obtenirPrix();
        }
        else 
        {
            ProduitAuxEncheres* produitEnchere = static_cast<ProduitAuxEncheres*>(contenuPanier_[i]);
            if (idClient_ == produitEnchere->obtenirIdentifiantClient()) 
            {
                total += produitEnchere->obtenirPrix();
            }
        }
    }  

    return total;
}


/****************************************************************************
 * Fonction:    Panier::modifierTotalAPayer
 * Description: modifie le total a payer
 * ParamËtres:    double totalAPayer (IN)
 * Retour:       aucun
 ****************************************************************************/
void Panier::modifierTotalAPayer(double totalAPayer)
{
    totalAPayer_ = totalAPayer;
}

/****************************************************************************
 * Fonction:    Panier::modifierIdClient
 * Description: modifie l'identifiant du client
 * ParamËtres:    int idClient (IN)
 * Retour:       aucun
 ****************************************************************************/
void Panier::modifierIdClient(int idClient) 
{
    idClient_ = idClient;
}

/****************************************************************************
 * Fonction:    Panier::ajouter
 * Description: ajoute un produit au panier
 * ParamËtres:    Produit * prod  (IN)
 * Retour:       aucun
 ****************************************************************************/
void Panier::ajouter(Produit * prod)
{
    if(prod->retournerType()==TypeProduitOrdinaire)
    {
        ProduitOrdinaire* produitConverti = static_cast<ProduitOrdinaire*> (prod);
        if(produitConverti->obtenirEstTaxable())
        {
            prod->modifierPrix(prod->obtenirPrix()*(1+TAUX_TAXE));
        }  
    } 
    contenuPanier_.push_back(prod);  
}

/****************************************************************************
 * Fonction:    Panier::livrer
 * Description: livre le panier au client, vide son contenu
 * ParamËtres:    aucun
 * Retour:       aucun
 ****************************************************************************/
void Panier::livrer()
{
    totalAPayer_ = 0;
    contenuPanier_.clear();
}

/****************************************************************************
 * Fonction:    Panier::trouverProduitPlusCher
 * Description: trouve le produit le plus cher du panier
 * ParamËtres:    aucun
 * Retour:       Produit* prodPlusChere
 ****************************************************************************/
Produit* Panier::trouverProduitPlusCher()
{
    if (contenuPanier_.empty())
        return nullptr;
    
    Produit* prodPlusChere = contenuPanier_[0];
    for (unsigned int i = 1; i < contenuPanier_.size(); i++)
        if (*contenuPanier_[i] > *prodPlusChere)
            prodPlusChere = contenuPanier_[i];
    
    return prodPlusChere;
}

/****************************************************************************
 * Fonction:    ostream & operator<<
 * Description: permet d'affciher le panier
 * ParamËtres:    ostream & os (IN/OUT) , Panier & panier (IN)
 * Retour:       ostream & os
 ****************************************************************************/
ostream & operator<<(ostream & os,  const Panier & panier)
{

    cout<<"Contenu du panier : " << endl << endl;
    for(int i=0; i< panier.contenuPanier_.size();i++ )
    {
        if(panier.contenuPanier_[i]->retournerType()==TypeProduitOrdinaire) 
        {
            ProduitOrdinaire* afficherProduit=static_cast<ProduitOrdinaire*>(panier.contenuPanier_[i]);
            os<<"\t"<<*afficherProduit;
        }
        else 
        {
            ProduitAuxEncheres* afficherProduit=static_cast<ProduitAuxEncheres*>(panier.contenuPanier_[i]);
            os<<"\t"<<*afficherProduit;
        }
    }
    os<<"\t Total à payer : "<< panier.calculerTotalApayer() << "€"<< endl;
    return os;
}
