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
            A(element);
        }

        supprimer(T* element)
        {
            C.S;
        }


    protected:

        C conteneur_;

    private:

        A foncteurAjout_;
        S foncteurSuppression;

};
// TODO : Cr�er la classe GestionnaireGenerique

// TODO : M�thodes :
/*
- ajouter()
- supprime()
- obtenirConteneur()
- pourChaqueElement()
*/