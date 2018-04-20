/********************************************
 * Titre: Travail pratique #6 - Gestionnaire.cpp
 * Date: 19 avril 2018
 * Auteur: Nicolas PAGE et Jean SAVARY
 *******************************************/

#include <algorithm>
#include "Gestionnaire.h"

vector<Usager *> Gestionnaire::obtenirUsagers() const
{
    return usagers_;
}

int Gestionnaire::obtenirNombreUsager() const
{
    return usagers_.size();
}

Usager* Gestionnaire::obtenirUsager(int index)
{
    return usagers_.at(index);
}

/****************************************************************************
* Fonction:    Gestionnaire::ajouterUsager()
* Description: permet d'ajouter un usager à la liste d'usagers et d'émettre le signal usargerAjout()
* Paramètres:  Usager* usager
* Retour:        aucun
****************************************************************************/
void Gestionnaire::ajouterUsager(Usager* usager)
{
    for (unsigned int i = 0; i < usagers_.size(); i++)
        if (usagers_[i] == usager)
            return;
    usagers_.push_back(usager);
    emit usagerAjoute(usager);
}

/****************************************************************************
* Fonction:    Gestionnaire::supprimerUsager()
* Description: permet de supprimer un usager à la liste d'usagers et d'émettre le signal usargerSupprime()
* Paramètres:  Usager* usager
* Retour:        aucun
****************************************************************************/
void Gestionnaire::supprimerUsager(Usager* usager)
{
    auto it = find(usagers_.begin(), usagers_.end(), usager);

    if (it != usagers_.end()) {
        Usager* u = *it;
        usagers_.erase(it);
        emit usagerSupprime(u);
    }
}
