/********************************************
 * Titre: Travail pratique #5 - Foncteur.h
 * Date: 9 mars 2018
 * Auteur: Ryan Hardie
 *******************************************/

#pragma once
#include <map>
#include <set>
// TODO : CrÈer le FoncteurEgal
template<typename T>
class FoncteurEgal{
public:
    FoncteurEgal()
    {}
    
    FoncteurEgal(T* t): t_(t)
    {}
    
    bool operator()(pair<int,T*> &pair){
        return t_ == pair.second;
    }
    
private:
    T* t_;
    
};

// TODO : CrÈer le FoncteurGenerateurId
/*
 Attributs :
 - id_;
 MÈthodes :
 - operator(); IncrÈmenter id_ ‡ chaque appel
 */

class FoncteurGenerateurId{
public:
    FoncteurGenerateurId()
    {
        id_=0;
    }
    
    void operator() ()
    {
        id_++;
    }
    
    
private:
    int id_;
    
};


// TODO : CrÈer le FoncteurDiminuerPourcent
/*
 Attributs :
 - pourcentage_;
 MÈthodes :
 - operator(); Calule le nouveau prix du Produit de la pair passÈ en paramËtre et le modifie
 */

class FoncteurDiminuerPourcent{
public:
    FoncteurDiminuerPourcent(int pourcentage):pourcentage_(pourcentage)
    {}
    
    void operator() (pair<int,Produit*> &pair){
        if(typeid(pair.second) == typeid(ProduitSolde)) {}
        else pair.second->modifierPrix(pair.second-> obtenirPrix()*((100-pourcentage_)/100.0));
    }
    
private:
    int pourcentage_;
};


// TODO : CrÈer le FoncteurIntervalle
/*
 Attributs :
 - borneInf_;
 - borneSup_;
 MÈthodes :
 - operator(); VÈrifie que le Produit associÈ ‡ la pair passÈ en paramËtre est compris entre les bornes borneInf_ et borneSup_ (retourne un boolÈen)
 */
class FoncteurIntervalle{
public:
    FoncteurIntervalle(double borneInf,double borneSup):borneInf_(borneInf),borneSup_(borneSup)
    {}
    
    bool operator() (pair<int,Produit*> &pair){
        if(pair.second->obtenirPrix()>=borneInf_ && pair.second->obtenirPrix()<=borneSup_)
        {
            return true;
        }
        else return false;
    }
    
private:
    double borneInf_;
    double borneSup_;
};

// TODO : CrÈer le Foncteur AjouterProduit
/*
 Attributs :
 - &multimap_;
 MÈthodes :
 - operator(); Ajoute dans la multimap la pair passÈ par paramËtre et retourne la multimap_;
 */
class FoncteurAjouterProduit{
public:
    FoncteurAjouterProduit(multimap<int, Produit*>& multimap): multimap_(multimap)
    {}
    
    multimap<int, Produit*>& operator() (Produit* produit){
        int valeurInt=0;
        int tmp=0;
        for(multimap<int, Produit*>::iterator it = multimap_.begin(); it != multimap_.end(); it++)
        {
            if(it->second != produit)
            {
                tmp = it->first;
                if(valeurInt<tmp)
                {
                    valeurInt=tmp;
                }
            }
            
            else
            {
                valeurInt = it->first;
                break;
            }
        }
        
        multimap_.insert(pair<int, Produit*>(valeurInt,produit));
        
        return multimap_;
    }
    
private:
    multimap<int, Produit*> multimap_;
    
};


// TODO : CrÈer le Foncteur SupprimerProduit
/*
 Attributs :
 - &multimap_;
 MÈthodes :
 - operator(); Utilise la fonction find_if avec le FoncteurEgal. Si le Produit existe,
 on supprime le Produit et on retourne la multimap_,
 sinon on retourne juste la multimap_ sans supprimer l'ÈlÈment.
 */
class FoncteurSupprimerProduit{
public:
    FoncteurSupprimerProduit(multimap<int, Produit*>& multimap): multimap_(multimap)
    {}
    
    multimap<int, Produit*>& operator() (Produit* produit)
    {
        multimap<int, Produit*>::iterator it= find_if(multimap_.begin(),multimap_.end(),FoncteurEgal<Produit*>(&produit));
        if((it->second) != nullptr){
            multimap_.erase(it);
        }
        
        return multimap_;
    }
    
private:
    multimap<int, Produit*> multimap_;
    
    
};

//TODO : CrÈer le Foncteur AjouterUsager
/*
 Attributs :
 - &set;
 MÈthodes :
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
    set<Usager*> set_;
    
};

//TODO : CrÈer le Foncteur SupprimerUsager
/*
 Attributs :
 - &set;
 MÈthodes :
 - operateur(); Trouve l'Usager dans le set_, s'il existe on le supprime et on retourne le set_, sinon on retourne juste directement le set_.
 */
class FoncteurSupprimerUsager{
public:
    FoncteurSupprimerUsager(set<Usager*>& set):set_(set)
    {}
    
    set<Usager*>& operator() (Usager* usager)
    {
        set<Usager*>::iterator it;
        it = set_.find(usager);
        if((*it) != nullptr){
            set_.erase(it);
        }
        
        return set_;
    }
    
private:
    set<Usager*> set_;
    
};



