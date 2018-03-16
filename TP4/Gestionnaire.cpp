#include "Gestionnaire.h"

vector<Usager *> Gestionnaire::obtenirUsagers() const
{
    return usagers_;
}

/****************************************************************************
 * Fonction:  Gestionnaire::afficherLesProfils()
 * Description: affiche le profil des usagers en utilisant la méthode afficherProfil() des classes
 * Client ou Fournisseur.
 * ParamËtres: aucun
 * Retour: double chiffreAffaire
 ****************************************************************************/
void Gestionnaire::afficherLesProfils() const
{
    if (usagers_.size() > 0)
    {
        for(int i=0; i< usagers_.size(); i++)
        {
            cout<<endl;
            usagers_[i]->afficherProfil(); // ici la liaison est dynamique car la fonction afficherProfil() a été déclarée virtuelle
        }
    }
    
}
/****************************************************************************
 * Fonction:  Gestionnaire::obtenirChiffreAffaires()
 * Description: calcule le total a payer de chaque usager
 * ParamËtres: aucun
 * Retour: double chiffreAffaire
 ****************************************************************************/
double Gestionnaire::obtenirChiffreAffaires() const
{
    
    double chiffreAffaire = 0 ;
    for(int i=0 ; i< usagers_.size(); i++){
        chiffreAffaire += usagers_[i]->obtenirTotalAPayer();//la méthode obtenirTotalAPayer a été déclarée virtuelle donc la liaison est ici dynamique
    }
    return chiffreAffaire;
}

/****************************************************************************
 * Fonction:  Gestionnaire::ajouterUsager
 * Description: ajoute un usager au vecteur d'usager
 * ParamËtres: Usager *usager
 * Retour: aucun
 ****************************************************************************/
void Gestionnaire::ajouterUsager(Usager *usager)
{
    
    bool estDansUsagers = false;
    for(int i =0 ; i < usagers_.size(); i++)
    {
        if(&usagers_[i] == &usager){
            estDansUsagers = true;
        }
    }
    
    if(estDansUsagers == false)
    {
        usagers_.push_back(usager);
    }
    
}
/****************************************************************************
 * Fonction:  Gestionnaire::reinitialiser()
 * Description: appelle les fonctions virtuelles reinitialiser() des éléments du
 * vecteur usagers_ 
 * Paramètres: aucun
 * Retour: aucun
 ****************************************************************************/
void Gestionnaire::reinitialiser()
{
   
    for (int i=0; i < usagers_.size(); i++) 
    {
        usagers_[i]->reinitialiser(); //liaison dynamique qui appellera la méthode virtuelle "reinitialiser()" de Fournisseur ou Client
    }
}

/****************************************************************************
 * Fonction:  Gestionnaire::encherir
 * Description: modifie l'enchérisseur si son montant est plus elevee que le prix courant du produit
 * ParamËtres: Client *client, ProduitAuxEncheres *produit, double montant
 * Retour: aucun
 ****************************************************************************/
void Gestionnaire::encherir(Client *client, ProduitAuxEncheres *produit, double montant)
{
    
    if (montant > produit->obtenirPrix() && produit->obtenirEncherisseur() != client)
    {
        produit->mettreAJourEnchere(client, montant);
    }
}

