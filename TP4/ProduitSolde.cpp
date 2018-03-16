#include "ProduitSolde.h"

ProduitSolde::ProduitSolde(int pourcentageRabais)
: Produit(),
Solde(pourcentageRabais)
{
}

ProduitSolde::ProduitSolde(Fournisseur *fournisseur, const string &nom,
                           int reference, double prix, int pourcentageRabais)
: Produit(fournisseur, nom, reference, prix),
Solde(pourcentageRabais)
{
}

double ProduitSolde::obtenirPrix() const
{
    // TODO
    double prixSolde;
    prixSolde= Produit::obtenirPrix()*((100-obtenirPourcentageRabais())/100);
    return prixSolde;
}

void ProduitSolde::afficher() const
{
    // TODO
    Produit::afficher();
    cout<< "\t rabais: \t" << obtenirPourcentageRabais()<<"%"<<endl;
}

