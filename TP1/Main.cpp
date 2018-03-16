/**************************************************
* Titre: Travail pratique #1 - Main.cpp
* Date: 20 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA
**************************************************/

#include "Produit.h"
#include "Rayon.h"
#include "Client.h"
#include "Panier.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	//C'est à vous de voir si vous devez allouer dynamiquement ou non les élèments

	//1-  Creez 15 objets du classe produit
    Produit** produits = new Produit*[15];
	for (int i=0; i<15; i++) {
		produits[i] = new Produit();
	}
   
	//2-  Modifiez le nom, la référence, le prix de  troisieme objet Produit créé
    //   afficher les attributs de cet objet Produit
	cout<<"--------------------------"<<endl;
	produits[2]->afficher();
	cout<<"--------------------------"<<endl;
    produits[2]->modifierNom("telephone");
	produits[2]->modifierPrix(100); 
	produits[2]->modifierReference(13);
	produits[2]->afficher();
	cout<<"--------------------------"<<endl;
	//3-  Creez un objet du classe rayon à l'aide du constructeur par défaut
	Rayon* rayon = new Rayon();
	rayon->afficher();
	cout<<"--------------------------"<<endl;
	//4-  Modifiez la catégorie  du rayon
	rayon->modifierCategorie("Sport");
	rayon->afficher();
	cout<<"--------------------------"<<endl;
    // 5- Ajouter 6 produits de  votre choix dans le rayon créé
	for (int i=0; i<6;i++){
		rayon->ajouterProduit(produits[i]);
	}
    // // 6- afficher le contenu du rayon
	rayon->afficher();
  	cout<<"--------------------------"<<endl;
	//7-  Creez un objet de classe client à l'aide du constructeur
	Client* client1 = new Client("Smith","Paul",1,"H4G 2J4",198405);

	//8-  afficher l'etat des attributs du client
	cout<<"Nom - " << client1->obtenirNom()<<endl;
	cout<<"Prenom - " << client1->obtenirPrenom()<<endl;
	cout<<"Identifiant - " << client1->obtenirIdentifiant()<<endl;
	cout<<"Code Postal - " << client1->obtenirCodePostal()<<endl;
	cout<<"Date - " << client1->obtenirDateNaissance() <<endl;
	cout<<"--------------------------"<<endl;
	//9-   Le client achete 9 produits
	
	for (int i=0; i<9;i++){
		client1->acheter(produits[i]);
	}

	//10- Afficher le contenu du panier du client
	client1->afficherPanier();
	cout<<"--------------------------"<<endl;
    //11- livrer le panier du client
	//12- afficher le contenu du panier du client
	client1->livrerPanier();
	client1->afficherPanier();
    cout<<"--------------------------"<<endl;
	
	//test nouvel achat
	client1->acheter(produits[1]);
	client1->afficherPanier();
	cout<<"--------------------------"<<endl;
	client1->livrerPanier();
	client1->afficherPanier();
	cout<<"--------------------------"<<endl;

	//-----------------
	//13-  terminer le programme correctement
	delete client1;
	delete rayon;
	delete[] produits;

	//********************************************
	//Question 1 : le lien entre Client et Panier est un lien de composition.
	//En effet le panier est un attribut du client, ainsi la classe client crée l'objet panier. 
	//De plus, le panier ne peut exister sans le client, donc si le client est détruit, le panier sera également détruit.

	//********************************************
	//Question 2 : le lien entre Panier et Produit est un lien d'aggregation.
	//En effet Rayon ne crée pas de produit, ainsi si le Rayon est détruit, le produit ne sera pas détruit.
	
    return 0;
}
