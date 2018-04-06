/********************************************
 * Titre: Travail pratique #5 - Foncteur.h
 * Date: 9 mars 2018
 * Auteur: Ryan Hardie
 *******************************************/

#pragma once
#include <map>
#include <set>
#include "ProduitSolde.h"
#include "Produit.h"
#include "Usager.h"
// TODO : Creer le FoncteurEgal
template<typename T>
class FoncteurEgal{
public:
    
    FoncteurEgal(T* t): t_(t)
    {}
    
    bool operator()(pair<int,T*> pair){
        return (t_ == pair.second);
    }
    
private:
    T* t_;
    
};

// TODO : Creer le FoncteurGenerateurId
/*
 Attributs :
 - id_;
 Methodes :
 - operator(); Incrementer id_ a chaque appel
 */

class FoncteurGenerateurId{
public:
    FoncteurGenerateurId(): id_(0)
    {}
    
        
    
   int operator()()
    {
       return id_++;
        
    }
    
    
private:
    int id_;
    
};


// TODO : Creer le FoncteurDiminuerPourcent
/*
 Attributs :
 - pourcentage_;
 Methodes :
 - operator(); Calule le nouveau prix du Produit de la pair passe en parametre et le modifie
 */

class FoncteurDiminuerPourcent{
public:
    FoncteurDiminuerPourcent(int pourcentage):pourcentage_(pourcentage)
    {}
    
    void operator() (pair<int,Produit*> pair){
        if(typeid(pair.second) == typeid(ProduitSolde)) {}
        else pair.second->modifierPrix(pair.second-> obtenirPrix()*((100-pourcentage_)/100.0));
    }
    
private:
    int pourcentage_;
};


// TODO : Creer le FoncteurIntervalle
/*
 Attributs :
 - borneInf_;
 - borneSup_;
 Methodes :
 - operator(); Verifie que le Produit associe e la pair passe en parametre est compris entre les bornes borneInf_ et borneSup_ (retourne un booleen)
 */
class FoncteurIntervalle{
public:
    FoncteurIntervalle(double borneInf,double borneSup):borneInf_(borneInf),borneSup_(borneSup)
    {}
    
    bool operator() (pair<int,Produit*> pair){
        if(pair.second->obtenirPrix()>=borneInf_ && pair.second->obtenirPrix()<=borneSup_)
            return true;
        else
            return false;
    }
    
private:
    double borneInf_;
    double borneSup_;
};

// TODO : Creer le Foncteur AjouterProduit
/*
 Attributs :
 - &multimap_;
 Methodes :
 - operator(); Ajoute dans la multimap la pair passe par parametre et retourne la multimap_;
 */
class FoncteurAjouterProduit{
public:
    FoncteurAjouterProduit(multimap<int, Produit*>& multimap): multimap_(multimap)
    {}
    
    multimap<int, Produit*>& operator() (Produit* produit){
        
        multimap_.insert(make_pair(produit->obtenirReference(),produit));
        
        return multimap_;
    }
    
private:
    multimap<int, Produit*>& multimap_;
    
};


// TODO : Creer le Foncteur SupprimerProduit
/*
 Attributs :
 - &multimap_;
 Methodes :
 - operator(); Utilise la fonction find_if avec le FoncteurEgal. Si le Produit existe,
 on supprime le Produit et on retourne la multimap_,
 sinon on retourne juste la multimap_ sans supprimer l'element.
 */
class FoncteurSupprimerProduit{
public:
    FoncteurSupprimerProduit(multimap<int, Produit*>& multimap): multimap_(multimap)
    {}
    
    multimap<int, Produit*>& operator() (Produit* produit)
    {
        FoncteurEgal<Produit> foncteur (produit);
        auto it= find_if(multimap_.begin(),multimap_.end(),foncteur);
        
        if(it != multimap_.end()){
            multimap_.erase(multimap_.find(produit->obtenirPrix()));
        }
        
        return multimap_;
    }
    
private:
    multimap<int, Produit*>& multimap_;
    
    
};

//TODO : Creer le Foncteur AjouterUsager
/*
 Attributs :
 - &set;
 Methodes :
 - operateur(); prend en parametres un pointeur d'Usager et retourne le set par reference avec l'Usager ajoute.
 */
class FoncteurAjouterUsager{
public:
    FoncteurAjouterUsager(set<Usager*>& set):set_(set)
    {}
    
    set<Usager*>& operator() (Usager* usager)
    {
        pair<set<Usager*>::iterator, bool> ajout;
        ajout=set_.insert(usager);
        return set_;
    }
    
private:
    set<Usager*>& set_;
    
};

//TODO : Creer le Foncteur SupprimerUsager
/*
 Attributs :
 - &set;
 Methodes :
 - operateur(); Trouve l'Usager dans le set_, s'il existe on le supprime et on retourne le set_, sinon on retourne juste directement le set_.
 */
class FoncteurSupprimerUsager{
public:
    FoncteurSupprimerUsager(set<Usager*>& set):set_(set)
    {}
    
    set<Usager*>& operator() (Usager* usager)
    {
        set<Usager*>::iterator it;
        it = find(set_.begin(),set_.end(),usager);
        if(*it != nullptr){
            set_.erase(it);
        }
        
        return set_;
    }
    
private:
    set<Usager*>& set_;
    
};

