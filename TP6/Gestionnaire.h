/********************************************
 * Titre: Travail pratique #6 - mainWindow.h
 * Date: 19 avril 2018
 * Auteur: Nicolas PAGE et Jean SAVARY
 *******************************************/

#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include <vector>
#include "Usager.h"
#include "Client.h"

#include <QObject>

using namespace std;

class Gestionnaire: public QObject
{
    Q_OBJECT

  public:
    vector<Usager*> obtenirUsagers() const;
    int obtenirNombreUsager() const;
    Usager* obtenirUsager(int index);

    void ajouterUsager(Usager* usager);
    void supprimerUsager(Usager* usager);

  //Définition des signaux 
  signals:
    void usagerAjoute(Usager* usager);
    void usagerSupprime(Usager* usager);

  private:
    vector<Usager*> usagers_;
};

#endif
