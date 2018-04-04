/********************************************
 * Titre: Travail pratique #5 - GestionnaireGenerique.h
 * Date: 9 mars 2018
 * Auteur: Ryan Hardie
 *******************************************/

#pragma once

using namespace std;

template <typename T, typename C, typename A, typename S>
class GestionnaireGenerique {
    
public:
    
   C obtenirConteneur()
    {
        return conteneur_;
    }
    
   void ajouter(T* element)
    {
        A foncteur (conteneur_) ;
        foncteur(element);
    }
    
     void supprimer(T* element)
    {
        S foncteur (conteneur_);
        foncteur(element);
    }
    
    // template <typename Predicate>
  void  pourChaqueElement(A foncteur)
    {
        A<conteneur_> foncteur;
        for_each(conteneur_.begin(), conteneur_.end(),foncteur);
    }
    
    
protected:
    C conteneur_;
    
};



