/********************************************
 * Titre: Travail pratique #6 - mainWindow.cpp
 * Date: 19 avril 2018
 * Auteur: Nicolas PAGE et Jean SAVARY
 *******************************************/

#ifndef EXCEPTIONARGUMENTINVALIDE_H
#define EXCEPTIONARGUMENTINVALIDE_H

#include <QException>
#include <QString>

class ExceptionArgumentInvalide : public QException {
public:

    /****************************************************************************
    * Fonction:    ExceptionArgumentInvalide::ExceptionArgumentInvalide()
    * Description: constructeur par parametres
    * Paramètres:  const Qstring& s
    * Retour:        aucun
    ****************************************************************************/
    ExceptionArgumentInvalide(QString s) : s_(s) {}

    /****************************************************************************
    * Fonction:    ExceptionArgumentInvalide::what()
    * Description: méthode virtuelle qui retourne le message d'erreur correspondant à l'erreur générée
    * Paramètres:  aucun
    * Retour:        QString s_
    ****************************************************************************/
    virtual QString what() {return s_;}
    
private:
    QString s_;
};
#endif // EXCEPTIONARGUMENTINVALIDE_H
