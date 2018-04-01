/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

#include "GestionnaireGenerique.h"

template <typename Usager*, typename set<Usager*>, typename FoncteurAjoutUsager, typename FoncteurSuppressionUsager>
class GestionnaireUsager : public GestionnaireGenerique 
{
    public:
        GestionnaireUsager();



}
// TODO : Cr�er la classe GestionnaireUsager

// TODO : La classe ressemble beaucoup � la classe Gestionnaire
/*
Les m�thodes retrouv�es de la classe Gestionnaire sont :
- double obtenirChiffreAffaires() const;
- void encherir(Client *client, ProduitAuxEncheres *produit, double montant) const;
- void reinitialiser();
- void afficherProfils() const;
*/
//

/********************************************
 * Titre: Travail pratique #5 - GestionnaireUsagers.h
 * Date: 9 mars 2018
 * Auteur: Ryan Hardie
 *******************************************/

#pragma once

#include "GestionnaireGenerique.h"
#include <set>
#include "Foncteur.h"
// TODO : CrÈer la classe GestionnaireUsager

// TODO : La classe ressemble beaucoup ‡ la classe Gestionnaire
/*
 Les mÈthodes retrouvÈes de la classe Gestionnaire sont :
 - double obtenirChiffreAffaires() const;
 - void encherir(Client *client, ProduitAuxEncheres *produit, double montant) const;
 - void reinitialiser();
 - void afficherProfils() const;
 */
class GestionnaireUsagers: public GestionnaireGenerique<Usager, set<Usager*>, FoncteurAjouterUsager, FoncteurSupprimerUsager>
{
public:
    double obtenirChiffreAffaires() const;
    void encherir(Client *client, ProduitAuxEncheres *produit, double montant) const;
    void reinitialiser();
    void afficherLesProfils() const;
};

