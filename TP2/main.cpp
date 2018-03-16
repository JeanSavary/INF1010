/**************************************************
 * Titre: Travail pratique #2 - Main.cpp
 * Date: 25 janvier 2018
 * Auteur: Nicolas PAGE et Jean SAVARY
 **************************************************/

#include "Produit.h"
#include "Rayon.h"
#include "Client.h"
#include "Panier.h"
#include <string>
#include <iostream>

using namespace std;

#define NB_PRODUCTS 15

/**
 *Répondez aux questions ici :

 * 1/ L'opérateur '=' définit pour des classes permet de comparer rapidement deux objets d'une même classe sans avoir à comparer chacun des attributs des objets chaque fois que l'on veut utiliser '='.
 * Le constructeur par copie permet d'instancier rapidement un nouvel objet d'une classe, en copiant l'ensemble des attributs d'un objet déjà existant. Cela évite d'avoir à rentrer l'ensemble des valeurs
 * de chaque paramètre en entrée.
 * 
 * 2/ Il est absolument nécessaire d'implémenter l'opérateur "=" pour une classe si la classe possède beaucoup d'attributs, et si l'on a besoin de souvent comparer deux objets de cette classe.
 * Quant au constructeur par copie il faut l'implémenter à partir du moment où la classe possède des attributs sous forme de pointeurs, afin d'éviter que la copie pointe sur le même objet. Cela
 * constitue une Deep Copy.
 * 
 * 3/ L'opérateur '=' écrase l'ensemble des attributs de l'objet à gauche pour lui appliquer les valeurs des attributs de l'objet de droite. Les deux objets sont alors identiques.
 * En ce qui concerne le constructeur par copie, il est possible de l'implémenter de façon à ce que certains attributs ne soit pas la copie conforme de l'objet qu'il copie. Par exemple,
 * dans ce code, Paul est une copie de Martine, néanmoins il est instancier avec un panier vide. Si on avait utiliser un "=" son panier aurait été celui de Martine et pointerait vers le
 * panier de Martine (Shallow Copy).
 **/

int main()
{
    Produit* unProduit = new Produit();
    // Faire saisir à l'utilisateur les attributs du produit unProduit selon le format de la capture d'écran de l'énoncé
    cout<< "Saisissez les attributs pour un produit (nom, reference, prix) : ";
    cin>>unProduit;
    
    // Afficher le Produit unProduit
    cout<<endl<<"Le produit saisie est :"<<*unProduit<<endl;
    
    // Creation de 15 produits
    Produit * produits[NB_PRODUCTS];
    double echantillonPrix[NB_PRODUCTS] = { 12.56, 50.0, 34.0, 56.0, 77.0, 91.0, 21.0, 34.0, 88.0, 65.0, 42.0, 72.0, 82.0, 53.0, 68.0 };
    
    for (int i = 0; i < NB_PRODUCTS; i++)
        produits[i] = new Produit("p" + to_string(i), i, echantillonPrix[i]);
    
    // Modification du nom, de la référence, du prix du troisieme produit créé
    produits[2]->modifierNom("p20");
    produits[2]->modifierPrix(100);
    produits[2]->modifierReference(31);
    
    cout << "Le produit p20 est moins cher que le produit p1 ? ";
    // Comparer le prix du produit p20 et p1 à l'aide de la surcharge d'un operateur
   if(produits[1]>produits[2])
   {
       cout<< "true" <<endl;
   }
    else  cout<< "false"<<endl;
    // Creation d'un rayon sport
    cout<<endl;
    
    Rayon sport;
    
    // Modification la catégorie  du rayon
    sport.modifierCategorie("sport");
    
    // Ajoutez les 10 premiers produits de dans le rayon créé
    for(int i=0; i<10;i++){
        sport+=*produits[i];
    }
    // Ajoutez encore une fois le produit p0 dans le rayon sport
    sport+=*produits[0];
    // Affichez le contenu du rayon
    cout<<sport<<endl;
    
    // Affichez le nombre de doublons du premier produit dans le rayon sport
    cout<< "Nombre de doublons du produit p0: "<< sport.compterDoublons(*produits[0])<<endl;
    
    cout<<endl;
    // Creation d'un client
    Client martine ("Bellaiche", "Martine", 1111, "H2T3A6", 199004);
    
    // Martine achète les 5 derniers porduits
    for (int i=5; i<10;i++){
        martine.acheter(produits[i]);
    }
    cout<<martine;
    //Copie du client martine dans un autre client puis changment de son nom, prenom et identifiant pour "Paul Martin 689"
    Client paul (martine);

    paul.modifierNom("Martin");
    paul.modifierPrenom("Paul");
    paul.modifierIdentifiant(689);

    cout<< "Test identifiant paul: " << boolalpha << (689 == paul) << endl << endl;
    
    // Paul achete le produit p0
    paul.acheter(produits[0]);
    cout<<paul;
    cout<<martine;
    
    // // Livrez le panier de Paul
    paul.livrerPanier();
    
    // // Affichez le panier de Paul et de Martine
    cout<<paul<<endl;
    cout<<martine<<endl;
    // Afichez le produit le plus cher du panier de martine
    cout<<"Le produit le plus cher que Martine a acheté est : "<<endl<<endl<<"\t Nom : "<<martine.obtenirPanier()->trouverProduitPlusCher()->obtenirNom()<<"\t Référence : "<<martine.obtenirPanier()->trouverProduitPlusCher()->obtenirReference()<<"\t Prix: "<<martine.obtenirPanier()->trouverProduitPlusCher()->obtenirPrix()<<"€"<<endl;
    // Terminer le programme correctement
    delete unProduit;
    for (int i=0; i<15; i++){
        delete produits[i];
        produits[i] = nullptr;
    }
      
}

