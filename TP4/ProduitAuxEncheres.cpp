#include "ProduitAuxEncheres.h"

ProduitAuxEncheres::ProduitAuxEncheres(double prix)
: Produit(),
prixInitial_(prix),
encherisseur_(nullptr)
{
}

ProduitAuxEncheres::ProduitAuxEncheres(Fournisseur *fournisseur, const string &nom,
                                       int reference, double prix)
: Produit(fournisseur, nom, reference, prix),
prixInitial_(prix),
encherisseur_(nullptr)
{
}

double ProduitAuxEncheres::obtenirPrixInitial() const
{
    return prixInitial_;
}

Client* ProduitAuxEncheres::obtenirEncherisseur() const
{
    return encherisseur_;
}
/****************************************************************************
 * Fonction:  ProduitAuxEncheres::afficher()
 * Description: affiche les informations du produit
 * ParamËtres: aucun
 * Retour: aucun
 ****************************************************************************/
void ProduitAuxEncheres::afficher() const
{

    Produit::afficher(); //on tire profit de l'héritage
    cout<< "\t prix initial: \t" << obtenirPrixInitial()<< endl;
    cout<< "\t encherisseur: \t" << encherisseur_->obtenirNom()<<endl;
    
}

void ProduitAuxEncheres::modifierPrixInitial(double prixInitial)
{
    prixInitial_ = prixInitial;
}

/****************************************************************************
 * Fonction:  ProduitAuxEncheres::mettreAJourEnchere
 * Description: vérifie que le nouvel enchérisseur n'est pas lui ayant la dernière mise sur le produit et modifie le prix du produit
 * ParamËtres: Client* encherisseur, double nouveauPrix
 * Retour: aucun
 ****************************************************************************/
void ProduitAuxEncheres::mettreAJourEnchere(Client* encherisseur, double nouveauPrix)
{
    
    modifierPrix(nouveauPrix);
    if (encherisseur_ != nullptr) 
    {
        encherisseur_->enleverProduit(this);
       
    }  
    *encherisseur_ = *encherisseur; //utilisation de l'opérateur = de la classe Client.
    encherisseur_->ajouterProduit(this);
        
}

