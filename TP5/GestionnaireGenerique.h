/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

template <typename T, typename C, typename A, typename S>
class GestionnaireGenerique {

    public:

        obtenirConteneur() 
        {
            return conteneur_;
        }

        ajouter(T* element)
        {
            A(conteneur_)(element);
        }

        supprimer(T* element)
        {
            S(conteneur_)(element);
        }

        // template <typename Predicate>
        pourChaqueElement(A foncteur)
        {
            for_each(conteneur_::begin(), conteneur_::end(),A(conteneur_)());
        }


    protected:

        C conteneur_;

};


