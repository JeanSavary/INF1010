/********************************************
 * Titre: Travail pratique #3 - Fournisseur.cpp
 * Date:
 * Auteur:
 *******************************************/
#include "Fournisseur.h"

/****************************************************************************
 * Fonction:    Fournisseur:: Fournisseur
 * Description: constructeur par paramètres d'un fournisseur
 * ParamËtres:    const string&  nom (IN), const string& prenom (IN) , int identifiant (IN), const string& codePostal (IN)
 * Retour:        aucun
 ****************************************************************************/
Fournisseur:: Fournisseur(const string&  nom, const string& prenom, int identifiant, const string& codePostal): Usager(nom, prenom,  identifiant, codePostal)
    {
        for(int i=0; i<NIVEAUX_SATISFACTION;i++){
            satisfaction_.niveaux_[i]=0; 
        }
    } 

/****************************************************************************
 * Fonction:    Fournisseur:: obtenirCatalogue
 * Description: retourne le contenu du catalogue
 * ParamËtres:    aucun
 * Retour:        vector <Produit*> contenuCatalogue_
 ****************************************************************************/
vector<Produit*> Fournisseur::obtenirCatalogue() const
{
    return contenuCatalogue_;
}

/****************************************************************************
 * Fonction:    Fournisseur:: obtenirSatisfaction
 * Description: retourne la satisfaction du client
 * ParamËtres:    aucun
 * Retour:        Satisfaction satisfaction_
 ****************************************************************************/
Satisfaction Fournisseur::obtenirSatisfaction() const
{
    return satisfaction_;
}

/****************************************************************************
 * Fonction:    Fournisseur:: modifierSatisfaction
 * Description: modifie la satisfaction du client
 * ParamËtres:    Satisfaction satisfaction (IN)
 * Retour:        aucun
 ****************************************************************************/
void Fournisseur::modifierSatisfaction(Satisfaction satisfaction)
{
    satisfaction_=satisfaction;
}

/****************************************************************************
 * Fonction:    Fournisseur::noter
 * Description: incremente un niveaux d'appreciation
 * ParamËtres:    int appreciation (IN)
 * Retour:        aucun
 ****************************************************************************/
void Fournisseur::noter(int appreciation)
{
    satisfaction_.niveaux_[appreciation-1]+=1; //on considere que l'appeciation est une note de 1 a 5
}
/****************************************************************************
 * Fonction:    Fournisseur::ajouterProduit
 * Description: ajoute un produit au catalogue
 * ParamËtres:    Produit* produit (IN)
 * Retour:        aucun
 ****************************************************************************/
void Fournisseur::ajouterProduit(Produit* produit)
{
    contenuCatalogue_.push_back(produit);
}

/****************************************************************************
 * Fonction:    Fournisseur::enleverProduit
 * Description: enleve un produit au catalogue
 * ParamËtres:    Produit* produit (IN)
 * Retour:        aucun
 ****************************************************************************/
void Fournisseur::enleverProduit(Produit* produit)
{
    for(int i=0;i<contenuCatalogue_.size();i++)
    {
        if(contenuCatalogue_[i] == produit)
        {
            contenuCatalogue_[i] = nullptr;
            contenuCatalogue_[i] = contenuCatalogue_[contenuCatalogue_.size()-1];
            contenuCatalogue_.pop_back();
        }
    }
    
}

/****************************************************************************
 * Fonction:    Fournisseur::operator=
 * Description: copie les attributs d'un fournisseurs dans un autre
 * ParamËtres:    Fournisseur& fournisseur (IN/OUT)
 * Retour:        Fournisseur& fournisseur
 ****************************************************************************/
 Fournisseur& Fournisseur::operator=(const Fournisseur& fournisseur)
{
    
    Usager usagerConverti= static_cast<Usager>(fournisseur);
    Usager usagerInitial= static_cast<Usager>(*this);
    usagerInitial=usagerConverti;
    satisfaction_=fournisseur.satisfaction_;
   
    return *this;
}

/****************************************************************************
 * Fonction:    ostream& operator<<
 * Description: permet d'afficher un fournisseur
 * ParamËtres:    ostream & os (IN/OUT), Fournisseur& fournisseur (IN)
 * Retour:       ostream & os
 ****************************************************************************/
ostream& operator<<(ostream & os, Fournisseur& fournisseur)
{
    Usager usagerAfficher=static_cast<Usager>(fournisseur);
    os <<usagerAfficher;
    os<<"\t - Satisfaction du client :"<<endl<<endl
    <<"\t\t 1 : "<<fournisseur.satisfaction_.niveaux_[0]<<endl
    <<"\t\t 2 : "<< fournisseur.satisfaction_.niveaux_[1]<<endl
    <<"\t\t 3 : "<< fournisseur.satisfaction_.niveaux_[2]<<endl
    <<"\t\t 4 : "<< fournisseur.satisfaction_.niveaux_[3]<<endl
    <<"\t\t 5 : "<< fournisseur.satisfaction_.niveaux_[4]<<endl;
    
    return os;
}












