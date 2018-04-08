#include "Fournisseur.h"
#include "Foncteur.h"
#include <iostream>

Fournisseur::Fournisseur()
: Usager()
{
    catalogue_= new GestionnaireProduits();
}

Fournisseur::Fournisseur(const string &nom, const string &prenom, int identifiant,
                         const string &codePostal)
: Usager(nom, prenom, identifiant, codePostal)
{
    catalogue_= new GestionnaireProduits();
}

GestionnaireProduits* Fournisseur::obtenirCatalogue() const
{
    return catalogue_;
}

void Fournisseur::afficherCatalogue() const
{
    catalogue_->afficher();
}

void Fournisseur::afficher() const
{
    Usager::afficher();
    cout << "\t\tcatalogue:\t" << catalogue_->obtenirConteneur().size() << " elements" << endl;
}

void Fournisseur::reinitialiser()
{
    catalogue_->reinitialiserFournisseur();
}

void Fournisseur::ajouterProduit(Produit *produit)
{
    Fournisseur *fournisseur = produit->obtenirFournisseur();
    if (fournisseur != nullptr && fournisseur != this)
        fournisseur->enleverProduit(produit);
    catalogue_->ajouter(produit);
}

void Fournisseur::enleverProduit(Produit *produit)
{
    produit->modifierFournisseur(nullptr);
    catalogue_->supprimer(produit); 
}

Produit* Fournisseur::trouverProduitPlusCher() const
{
    return catalogue_->trouverProduitPlusCher();
}

void Fournisseur::diminuerPrix(int pourcent) const
{
    FoncteurDiminuerPourcent foncteur(pourcent);
    catalogue_->pourChaqueElement(foncteur); //ajuster a STL
}

