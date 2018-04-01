/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once
#include <map>
#include "GestionnaireGenerique.h"
#include "Foncteur.h"
#include "Produit.h"

template <typename Produit*, typename multimap<int, Produit*>, typename FoncteurAjouterProduit() , typename FoncteurSupprimerProduit()>
class GestionnaireProduits : public GestionnaireGenerique
{
    public:

        GestionnaireProduits(); //initialisation du conteneur
        void reinitialiserClient();
        void reinitialiserFournisseur();
        void afficher() const;
        double obtenirTotalAPayer() const;
        double obtenirTotalAPayerPremium() const;



};
// TODO : Cr�er la classe GestionnaireProduits

// TODO : M�thodes :
/*
- reinitialiserClient();
- reinitialiserFournisseur();
- afficher();
- obtenirTotalAPayer();
- obtenirTotalApayerPremium();
- trouverProduitPlusCher();
- obtenirProduitsEntre();
- obtenirProduitSuivant();
*/