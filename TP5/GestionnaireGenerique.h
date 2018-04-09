/********************************************
 * Titre: Travail pratique #5 - GestionnaireGenerique.h
 * Date: 9 mars 2018
 * Auteur: Ryan Hardie
 *******************************************/

#pragma once
template <typename T, typename C, typename A, typename S>
class GestionnaireGenerique {
    
public:
    /*
     Cette fonction retourne le conteneur du gestionnaire
     soit une multimap<int, Produit*> ou un set<Usager*>
     */
    C obtenirConteneur()
    {
        return conteneur_;
    }
    
    /*
     cette fonction ajoute un element au conteneur a l'aide d'un foncteur
     */
    void ajouter(T* element)
    {
        A foncteur (conteneur_) ;
        foncteur(element);
    }
    
    /*
     cette fonction supprime un element du conteneur a l'aide d'un foncteur
     */
    void supprimer(T* element)
    {
        S foncteur (conteneur_);
        foncteur(element);
    }
    
    /*
     cette fonction parcours chaque elements du conteneur et applique l'operation du foncteur en parametre
     */
    template <typename Predicate>
    void  pourChaqueElement(Predicate foncteur)
    {
        for_each(conteneur_.begin(), conteneur_.end(),foncteur);
    }
    
    
protected:
    C conteneur_;
    
};



