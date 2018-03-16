#include "Panier.h"

//********************************************
//Constructeur par paramètres
Panier::Panier(int capaciteContenu) : capaciteContenu_(capaciteContenu), nombreContenu_(0), totalAPayer_(0.0){

    contenuPanier_ = new Produit* [capaciteContenu];    
}

//********************************************
//Méthodes d'accès aux attributs
double Panier::obtenirTotalApayer() const {

    return totalAPayer_;
}

int Panier::obtenirNombreContenu() const {

    return nombreContenu_;
}

Produit** Panier::obtenirContenuPanier() const {

    return contenuPanier_;
}

//********************************************
//Méthode d'ajout d'un produit au panier
void Panier::ajouter(Produit* prod) {

    totalAPayer_ += prod->obtenirPrix();
    if (nombreContenu_ < capaciteContenu_) {
        contenuPanier_[nombreContenu_] = prod;
        nombreContenu_ += 1;
    }
    else if (nombreContenu_ >= capaciteContenu_) {

        capaciteContenu_ = capaciteContenu_ * 2;
        Produit** temp = new Produit* [capaciteContenu_];
        for (int i=0; i < nombreContenu_; i++) {
            temp[i] = contenuPanier_[i];
        }
        delete[] contenuPanier_;
        contenuPanier_ = temp;
        contenuPanier_[nombreContenu_] = prod;
        nombreContenu_ += 1;
        }
}

//********************************************
//Méthode vidant le panier après que le client
//ait payé
void Panier::livrer() {

    for (int i=0; i < capaciteContenu_; i++) {
        delete contenuPanier_[i];
        contenuPanier_[i] = nullptr;
    }
  
    nombreContenu_ = 0;
    capaciteContenu_ = 0;
    totalAPayer_ = 0.0;
    
}

//********************************************
//Méthode qui affiche l'état du panier
void Panier::afficher() const {

    if (contenuPanier_ == nullptr) {
        cout<<"Panier vide"<<endl;
    }
    cout << "Nombre d'éléments dans le panier - " << obtenirNombreContenu() <<endl;
    cout << "Total à payer - " << obtenirTotalApayer()<<endl;
    cout << "Contenu du panier : " << endl;
    if (contenuPanier_ != nullptr) {

        for (int i=0; i<nombreContenu_;i++){

            cout << "   - "<<contenuPanier_[i]->obtenirNom() << endl;
        }
    }
    
}
