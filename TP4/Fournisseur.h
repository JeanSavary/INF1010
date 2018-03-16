#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <string>
#include <vector>
#include "Usager.h"
#include "Produit.h"

using namespace std;

class Fournisseur : public Usager
{
public:
    Fournisseur();
    Fournisseur(const string &nom, const string &prenom, int identifiant, const string &codePostal);
    
    vector<Produit *> obtenirCatalogue() const;
    void afficherCatalogue() const;
    virtual void afficherProfil() const;
    
    virtual void reinitialiser();
    virtual void ajouterProduit(Produit *produit);
    virtual void enleverProduit(Produit *produit);
    
private:
    vector<Produit *> catalogue_;
};

#endif

