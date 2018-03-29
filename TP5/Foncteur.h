/********************************************
 * Titre: Travail pratique #5 - Foncteur.h
 * Date: 9 mars 2018
 * Auteur: Ryan Hardie
 *******************************************/

#pragma once
#include <map>
// TODO : Cr�er le FoncteurEgal
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

// TODO : Cr�er le FoncteurGenerateurId
/*
 Attributs :
 - id_;
 M�thodes :
 - operator(); Incr�menter id_ � chaque appel
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


// TODO : Cr�er le FoncteurDiminuerPourcent
/*
 Attributs :
 - pourcentage_;
 M�thodes :
 - operator(); Calule le nouveau prix du Produit de la pair pass� en param�tre et le modifie
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


// TODO : Cr�er le FoncteurIntervalle
/*
 Attributs :
 - borneInf_;
 - borneSup_;
 M�thodes :
 - operator(); V�rifie que le Produit associ� � la pair pass� en param�tre est compris entre les bornes borneInf_ et borneSup_ (retourne un bool�en)
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

// TODO : Cr�er le Foncteur AjouterProduit
/*
 Attributs :
 - &multimap_;
 M�thodes :
 - operator(); Ajoute dans la multimap la pair pass� par param�tre et retourne la multimap_;
 */
class FoncteurAjouterProduit{
public:
    FoncteurAjouterProduit(multimap<int, Produit*>& multimap): multimap_(multimap)
    {}
    
    multimap<int, Produit*>& operator() (Produit* produit){
        int valeurInt;
        for(multimap<int, Produit*>::iterator it = multimap_.begin(); it != multimap_.end(); it++)
        {
            if(it->second == produit)
            {
                valeurInt = it->first;
            }
            
            else valeurInt = it-> first + 1;
        }
        
        multimap_.insert(pair<int, Produit*>(valeurInt,produit));
        
        return multimap_;
    }
    
private:
    multimap<int, Produit*> multimap_;
    
};


// TODO : Cr�er le Foncteur SupprimerProduit
/*
 Attributs :
 - &multimap_;
 M�thodes :
 - operator(); Utilise la fonction find_if avec le FoncteurEgal. Si le Produit existe,
 on supprime le Produit et on retourne la multimap_,
 sinon on retourne juste la multimap_ sans supprimer l'�l�ment.
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

//TODO : Cr�er le Foncteur AjouterUsager
/*
 Attributs :
 - &set;
 M�thodes :
 - operateur(); Trouve l'Usager dans le set_, s'il existe on le supprime et on retourne le set_, sinon on retourne juste directement le set_.
 */
class FoncteurAjouterUsager{
public:
    
private:
    
    
};



>>>>>>> bc6dd71b601e8c1e13dcdb0eaea6f44aae185c82
