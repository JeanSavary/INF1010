/********************************************
 * Titre: Travail pratique #5 - Foncteur.h
 * Date: 9 mars 2018
 * Auteurs: SAVARY Jean, PAGE Nicolas
 *******************************************/

#pragma once
#include <map>
#include <set>
#include "ProduitSolde.h"
#include "Produit.h"
#include "Usager.h"

/*
 Attributs :
 - t_;
 Methodes :
 - operator(); Vérifie si deux objets de type T sont égaux
 */
template<typename T>
class FoncteurEgal{
public:
    
    FoncteurEgal(T* t): t_(t)
    {
    }
    
    bool operator()(pair<int,T*> pair){
        return (t_ == pair.second);
    }
    
private:
    T* t_;
    
};

/*
 Attributs :
 - id_;
 Methodes :
 - operator(); Incrementer id_ a chaque appel
 */

class FoncteurGenerateurId{
public:
    FoncteurGenerateurId(): id_(0)
    {
    }
    
    int operator()()
    {
        return id_++;
    }
    
private:
    int id_;
};

/*
 FoncteurDiminuerPourcent
 Ce foncteur est utilisé par le fournisseur et servira à diminuer d’un certain pourcentage le prix d’un produit.
 Attributs :
 - pourcentage_ : est un entier initialisé par paramètre dans le constructeur.
 Méthodes :
 - operator() : prend en paramètre une pair<int, Produit*> et doit réduire de pourcentage_ le prix du produit associé. Faire attention à ne pas appliquer la réduction sur le prix soldé, mais unique sur le prix brut (sans dynamic_cast).
 */

class FoncteurDiminuerPourcent{
public:
    FoncteurDiminuerPourcent(int pourcentage):pourcentage_(pourcentage)
    {}
    
    void operator() (pair<int,Produit*> pair){
        if(typeid(pair.second) != typeid(ProduitSolde*)) {
            pair.second->modifierPrix(pair.second-> Produit::obtenirPrix()*((100-pourcentage_)/100.0));
            
        }
        //else pair.second->modifierPrix(pair.second-> Produit::obtenirPrix()*((100-pourcentage_)/100.0));
    }
    
private:
    int pourcentage_;
};

/*
 FoncteurIntervalle
 Ce foncteur est utilisé par le GestionnaireProduits afin de trouver le Produit de la multimap dont le prix est compris entre borneInf_ et borneSup_.
 Attributs :
 - borneInf_ : est un double initialisé par paramètre dans le constructeur.
 - borneSup_ : est un double initialisé par paramètre dans le constructeur.
 Méthodes :
 operator() : prend en paramètre un pair<int, Produit*> et retourne vrai si le prix du Produit associé à la pair est compris entre les bornes borneInf_ et borneSup_, faux sinon.
 
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


/*
 AjouterProduit
 Ce foncteur permet l’ajout d’un produit dans un conteneur de type multimap.
 Attribut :
 - &multimap_ : de type multimap<int, Produit*> est une agrégation par référence et initialisé par paramètre (par référence) dans le constructeur.
 Méthodes :
 - operator() : prend en paramètre un pointeur de Produit et retourne la multimap par référence avec le produit ajouté.
 
 */
class FoncteurAjouterProduit{
public:
    FoncteurAjouterProduit(multimap<int, Produit*>& multimap): multimap_(multimap)
    {
        
    }
    
    multimap<int, Produit*>& operator() (Produit* produit){
        
        multimap_.insert(make_pair(produit->obtenirReference(),produit));
        
        return multimap_;
    }
    
private:
    multimap<int, Produit*>& multimap_;
    
};

/*
 SupprimerProduit
 Ce foncteur permet la suppression d’un produit dans un conteneur de type multimap.
 Attribut :
 - &multimap_ : de type multimap<int, Produit*> est une agrégation par référence et est initialisé par paramètre (par référence) dans le constructeur.
 Méthode :
 - operator() : prend en paramètre un pointeur de Produit, utilise la fonction find_if de la STL avec le FoncteurEgal comme prédicat, vérifie si le Produit existe et retourne la multimap par référence avec le produit supprimé.
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
            
            multimap_.erase(it);
        }
        
        return multimap_;
    }
    
private:
    multimap<int, Produit*>& multimap_;
    
    
};


/*
 AjouterUsager
 Ce foncteur permet l’ajout d’un usager dans un conteneur de type set.
 Attribut :
 - &set_ : de type set<Usager*> est initialisé par paramètre (par référence) dans le constructeur.
 Méthode :
 - operator() : prend en paramètre un pointeur d’Usager et retourne la set par référence avec le produit ajouté. */
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

/*
 SupprimerUsager
 Ce foncteur permet la suppression d’un usager dans un conteneur de type set.
 Attribut :
 - &set_ : de type set<Usager*> est initialisé par paramètre (par référence) dans le constructeur.
 Méthode :
 - operator() : prend en paramètre un pointeur d’Usager, vérifie que l’Usager existe bien, le supprime et retourne la set par référence avec le produit supprimé.
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

