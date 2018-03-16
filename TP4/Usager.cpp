#include "Usager.h"
#include <iostream>

Usager::Usager(const string &nom, const string &prenom, int identifiant,
               const string &codePostal)
: nom_(nom),
prenom_(prenom),
identifiant_(identifiant),
codePostal_(codePostal)
{
}

string Usager::obtenirNom() const
{
    return nom_;
}

string Usager::obtenirPrenom() const
{
    return prenom_;
}

int Usager::obtenirIdentifiant() const
{
    return identifiant_;
}

string Usager::obtenirCodePostal() const
{
    return codePostal_;
}

double Usager::obtenirTotalAPayer() const
{
    
    double total = 0;
    return total;
}

/****************************************************************************
 * Fonction: Usager::afficherProfil()
 * Description: affiche les informations de base d'un usager
 * ParamËtres: aucun
 * Retour: aucun
 ****************************************************************************/
void Usager::afficherProfil() const
{
    
    cout << "Usager : " << obtenirPrenom() << " " << obtenirNom() << endl <<endl;
    cout << "\t Identifiant : " << obtenirIdentifiant() << endl;
    cout << "\t Code postal  : " << obtenirCodePostal() << endl;
} 

void Usager::modifierNom(const string &nom)
{
    nom_ = nom;
}

void Usager::modifierPrenom(const string &prenom)
{
    prenom_ = prenom;
}

void Usager::modifierIdentifiant(int identifiant)
{
    identifiant_ = identifiant;
}

void Usager::modifierCodePostal(const string &codePostal)
{
    codePostal_ = codePostal;
}

