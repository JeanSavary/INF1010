/********************************************
 * Titre: Travail pratique #6 - mainWindow.cpp
 * Date: 19 avril 2018
 * Auteur: Nicolas PAGE et Jean SAVARY
 *******************************************/

#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QStyle>
#include <QKeySequence>
#include <QDebug>
#include <QPushButton>
#include <QMessageBox>
#include <QRadioButton>
#include <QButtonGroup>
#include <QComboBox>
#include <QSlider>
#include <QListWidget>
#include <QListWidgetItem>
#include <QLineEdit>
#include <QLabel>
#include <QFrame>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include <typeinfo>
#include <string>

#include "mainwindow.h"
#include "Gestionnaire.h"
#include "Usager.h"
#include "Fournisseur.h"
#include "ClientPremium.h"
#include "ExceptionArgumentInvalide.h"

using namespace std;

Q_DECLARE_METATYPE(Usager*)

/****************************************************************************
* Fonction:    MainWindow::MainWindow()
* Description: constructeur par paramètres de la fenêtre principale
* Paramètres:  Gestionnaire* gestionnaire, QWidget *parent
* Retour:        aucun
****************************************************************************/
MainWindow::MainWindow(Gestionnaire* gestionnaire, QWidget *parent) :
    QMainWindow(parent)
{
    gestionnaire_ = gestionnaire;
    setup();
}

/****************************************************************************
* Fonction:    MainWindow::~MainWindow()
* Description: destructeur de la fenêtre principale, supprime les éléments (usagers) créés en local
* Paramètres:  Gestionnaire* gestionnaire, QWidget *parent
* Retour:        aucun
****************************************************************************/
MainWindow::~MainWindow() {
    while (!ajoute_.empty()) {
        delete ajoute_.back();
        ajoute_.pop_back();
    }
}

/****************************************************************************
* Fonction:    MainWindow::set(..)
* Description: ensemble de méthodes permettant de réaliser l'UI de notre application
****************************************************************************/
void MainWindow::setup() {
    indexCourantDuFiltre_ = 0;
    setMenu();
    setUI();
    setConnections();
    chargerUsagers();
}

void MainWindow::setConnections()
{
   connect(gestionnaire_, SIGNAL(usagerAjoute(Usager*)), this, SLOT(usagerAEteAjoute(Usager*)));
   connect(gestionnaire_, SIGNAL(usagerSupprime(Usager*)), this, SLOT(usagerAEteSupprime(Usager*)));
}

void MainWindow::setMenu() {

    // On crée un bouton 'Exit'
    QAction* exit = new QAction(tr("&Quitter"), this);

    // On ajoute un raccourci clavier qui simulera l'appui sur ce bouton (Ctrl+Q)
    exit->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q));

    // On connecte le clic sur ce bouton avec l'action de clore le programme
    connect(exit, SIGNAL(triggered()), this, SLOT(close()));

    // On crée un nouveau menu 'File'
    QMenu* fileMenu = menuBar()->addMenu(tr("&Fichier"));

    // Dans lequel on ajoute notre bouton 'Exit'
    fileMenu->addAction(exit);
}

void MainWindow::setUI() {

    // Le sélecteur pour filtrer ce que l'on souhaite dans la liste (QComboBox*)

    QComboBox* showCombobox = new QComboBox(this);
    showCombobox ->addItem("Tout Afficher"); //index 0
    showCombobox ->addItem("Afficher Clients Reguliers"); //index 1
    showCombobox ->addItem("Afficher Clients Premiums"); // index 2
    showCombobox ->addItem("Afficher Fournisseurs"); //index 3
    connect(showCombobox, SIGNAL(currentIndexChanged(int)),this, SLOT(filtrerListe(int)));

    // La liste des usagers
    listUsager = new QListWidget(this);
    listUsager->setSortingEnabled(true);
    connect(listUsager, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(selectionnerUsager(QListWidgetItem*)));

    // Le bouton pour supprimer tout le monde
    QPushButton* boutonSupprimerTousLesUsagers = new QPushButton(this);
    boutonSupprimerTousLesUsagers->setText("Supprimer Tous Les Usagers");
    connect(boutonSupprimerTousLesUsagers, SIGNAL(clicked()), this, SLOT(supprimerTousLesUsagers()));

    // Le bouton pour remettre à zéro la vue et ajouter un nouvel employé
    QPushButton* boutonAjouterUsager = new QPushButton(this);
    boutonAjouterUsager->setText("Ajout d'un usager");
    connect(boutonAjouterUsager, SIGNAL(clicked()), this, SLOT(nettoyerVue()));

    // Le premier layout, pour la colonne de gauche, dans lequel on insère les
    // éléments que l'on veut dans l'ordre dans lequel on veut qu'ils apparaissent
    QVBoxLayout* listLayout = new QVBoxLayout;
    // à faire ajouter  le sélecteur
    listLayout->addWidget(showCombobox);
    listLayout->addWidget(listUsager);
    listLayout->addWidget(boutonSupprimerTousLesUsagers);
    listLayout->addWidget(boutonAjouterUsager);

    // Champ pour le nom
    QLabel* nomLabel = new QLabel;
    nomLabel->setText("Nom:");
    editeurNom= new QLineEdit;

    QHBoxLayout* nomLayout = new QHBoxLayout;
    nomLayout->addWidget(nomLabel);
    nomLayout->addWidget(editeurNom);

    // Champ pour le prenom
    QLabel* prenomLabel = new QLabel;
    prenomLabel->setText("Prenom:");
    editeurPrenom = new QLineEdit;

    QHBoxLayout* prenomLayout = new QHBoxLayout;
    prenomLayout->addWidget(prenomLabel);
    prenomLayout->addWidget(editeurPrenom);

    //Champ pour l'identifiant avec validateur int entre 0 et 100 000
    QLabel* idLabel = new QLabel;
    idLabel->setText("Identifiant:");
    editeurIdentifiant = new QLineEdit();

    QValidator *validatorId = new QIntValidator(0,100000,this);
    editeurIdentifiant-> setValidator(validatorId);

    QHBoxLayout* idLayout = new QHBoxLayout;
    idLayout->addWidget(idLabel);
    idLayout->addWidget(editeurIdentifiant);

    // Champ pour le code postal
    QLabel* codePLabel = new QLabel;
    codePLabel->setText("Code Postal:");
    editeurCodePostal = new QLineEdit;

    QHBoxLayout* codePLayout = new QHBoxLayout;
    codePLayout->addWidget(codePLabel);
    codePLayout->addWidget(editeurCodePostal);

    //Champ pour JoursRestant de ClientPremium avec validateur int entre 0 et 1000
    QLabel* joursLabel = new QLabel;
    joursLabel->setText("Jours Restants:");
    editeurJoursRestants = new QLineEdit;

    QValidator *validatorJours = new QIntValidator(0,1000,this);
    editeurJoursRestants->setValidator(validatorJours);

    QHBoxLayout* joursLayout = new QHBoxLayout;
    joursLayout->addWidget(joursLabel);
    joursLayout->addWidget(editeurJoursRestants);

    // Boutons radio
    QRadioButton* clientPremiumBoutonRadio = new QRadioButton("&ClientPremium", this);
    clientPremiumBoutonRadio->setChecked(true);
    boutonRadioTypeUsager.push_back(clientPremiumBoutonRadio);

    QRadioButton* clientRegulierBoutonRadio = new QRadioButton("&Client", this);
    boutonRadioTypeUsager.push_back(clientRegulierBoutonRadio);

    QRadioButton* fournisseurBoutonRadio = new QRadioButton("&Fournisseur", this);
    boutonRadioTypeUsager.push_back(fournisseurBoutonRadio);

    QButtonGroup* typeUsagerGroupeBoutons = new QButtonGroup;
    typeUsagerGroupeBoutons->addButton(clientPremiumBoutonRadio);
    typeUsagerGroupeBoutons->addButton(clientRegulierBoutonRadio);
    typeUsagerGroupeBoutons->addButton(fournisseurBoutonRadio);
    connect(typeUsagerGroupeBoutons, SIGNAL(buttonClicked(int)),
            this, SLOT(changerTypeUsager(int)));

    QHBoxLayout* typeUsagerLayout = new QHBoxLayout;
    typeUsagerLayout->addWidget(clientPremiumBoutonRadio);
    typeUsagerLayout->addWidget(clientRegulierBoutonRadio);
    typeUsagerLayout->addWidget(fournisseurBoutonRadio);

    // Trait horizontal de séparation
    QFrame* horizontalFrameLine = new QFrame;
    horizontalFrameLine->setFrameShape(QFrame::HLine);

    // Bouton pour supprimer l'usager sélectionné dans la liste

    boutonSupprimer = new QPushButton(this);
    boutonSupprimer->setText("Supprimer");
    connect(boutonSupprimer, SIGNAL(clicked()),
            this, SLOT(supprimerUsagerSelectionne()));

    // Bouton pour ajouter l'usager dont on
    // vient d'entrer les informations
    boutonAjouter = new QPushButton(this);
    boutonAjouter->setText("Ajouter");
    connect(boutonAjouter, SIGNAL(clicked()),
            this, SLOT(ajouterUsager()));

    // Organisation horizontale des boutons
    QHBoxLayout* ajouterSupprimerLayout = new QHBoxLayout;
    ajouterSupprimerLayout->addWidget(boutonAjouter);
    ajouterSupprimerLayout->addWidget(boutonSupprimer);


    // Organisation pour la colonne de droite
    // ajouter les 3 champs: identifiant, code postal, joursRestants
    QVBoxLayout* displayLayout = new QVBoxLayout;
    displayLayout->addLayout(nomLayout);
    displayLayout->addLayout(prenomLayout);
    displayLayout->addLayout(idLayout);
    displayLayout->addLayout(codePLayout);
    displayLayout->addLayout(joursLayout);
    displayLayout->addLayout(typeUsagerLayout);
    displayLayout->addWidget(horizontalFrameLine);
    displayLayout->addLayout(ajouterSupprimerLayout);

    // Trait vertical de séparation
    QFrame* verticalFrameLine = new QFrame;
    verticalFrameLine->setFrameShape(QFrame::VLine);

    // Organisation horizontale
    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->addLayout(listLayout);
    mainLayout->addWidget(verticalFrameLine);
    mainLayout->addLayout(displayLayout);

    // On crée un nouveau Widget, et on définit son
    // layout pour celui que l'on vient de créer
    QWidget* widget = new QWidget;
    widget->setLayout(mainLayout);

    // Puis on définit ce widget comme le widget
    // centrale de notre classe
    setCentralWidget(widget);

    // Enfin, on met à jour le titre de la fenêtre
    string title = "Gestionnaire de polebay!";
    setWindowTitle(title.c_str());
}

/****************************************************************************
* Fonction:    MainWindow::afficherMessage()
* Description: crée une fenêtre de type popUp
* Paramètres:  QString msg
* Retour:      aucun
****************************************************************************/
void MainWindow::afficherMessage(QString msg) {
    QMessageBox msgBox;
    msgBox.setText(msg);
    msgBox.exec();
}

/****************************************************************************
* Fonction:    MainWindow::chargerUsagers()
* Description: permet de charger tous les usagers connus
* Paramètres:  aucun
* Retour:      aucun
****************************************************************************/
void MainWindow::chargerUsagers() {
    // On s'assure que la liste est vide
    listUsager->clear();
    // Puis, pour tous les usagers
    int max = gestionnaire_->obtenirNombreUsager();
    for (int i = 0; i < max; i++) {
        // On récupère le pointeur vers l'employé
        Usager* usager = gestionnaire_->obtenirUsager(i);
        if (usager == nullptr) {
            continue;
        }
        // Et on l'ajoute en tant qu'item de la liste:
        // le nom et prenom sera affiché, et le pointeur sera contenu
        QListWidgetItem* item = new QListWidgetItem(
            QString::fromStdString(usager->obtenirNom()) + ", " + QString::fromStdString(usager->obtenirPrenom()), listUsager);
        item->setData(Qt::UserRole, QVariant::fromValue<Usager*>(usager));
        item->setHidden(filtrerMasque(usager));
    }
}

/****************************************************************************
* Fonction:    MainWindow::filtrerMasque()
* Description: retourne un booléen en fonction du type d'usager choisi
* Paramètres:  Usager* usager
* Retour:      bool
****************************************************************************/
bool MainWindow::filtrerMasque(Usager* usager) {
    switch (indexCourantDuFiltre_) {
    case 1:
        return (typeid(*usager) != typeid(Client));
    case 2:
        return (typeid(*usager) != typeid(ClientPremium));
    case 3:
        return (typeid(*usager) != typeid(Fournisseur));
    case 0:
    default:
        return false;
    }
}

/****************************************************************************
* Fonction:    MainWindow::filtrerListe()
* Description: affiche les usagers d'un certain type selon l'index en paramètre
* Paramètres:  int index
* Retour:      aucun
****************************************************************************/
void MainWindow::filtrerListe(int index) {
     indexCourantDuFiltre_ = index;
     for (int i= 0 ; i<listUsager->count();++i ) {
     QListWidgetItem *item = listUsager->item(i);
     Usager* usager = item->data(Qt::UserRole).value<Usager*>();
     item->setHidden(filtrerMasque(usager));
     }
}

/****************************************************************************
* Fonction:    MainWindow::selectionnerUsager()
* Description: affiche les informations de l'usager sélectionné dans la liste (widget)
* Paramètres:  QListWidgetItem* item
* Retour:      aucun
****************************************************************************/
void MainWindow::selectionnerUsager(QListWidgetItem* item) {
    Usager* usager = item->data(Qt::UserRole).value<Usager*>();

    //Tous les champs sont mis à disabled et affiche l'information de l'usager sélectionné
    editeurNom->setDisabled(true);
    editeurNom->setText(QString::fromStdString(usager->obtenirNom()));
    editeurPrenom->setDisabled(true);
    editeurPrenom->setText(QString::fromStdString(usager->obtenirPrenom()));
    editeurIdentifiant->setDisabled(true);
    editeurIdentifiant->setText(QString::number(usager->obtenirIdentifiant()));
    editeurCodePostal->setDisabled(true);
    editeurCodePostal->setText(QString::fromStdString(usager->obtenirCodePostal()));
    //Affiche les jours restants s'il s'agit d'un ClientPremium, sinon on affiche "-"
    /*À Faire*/
    editeurJoursRestants->setDisabled(true);
    if(typeid(*usager)==typeid(ClientPremium)){
        ClientPremium *clientPrem = dynamic_cast<ClientPremium *>(usager);
        editeurJoursRestants->setText(QString::number(clientPrem->obtenirJoursRestants()));
        }// faire cast
    else editeurJoursRestants->setText("-");


    //On met a checked le type d'usager qui est sélectionné
    list<QRadioButton*>::iterator end = boutonRadioTypeUsager.end();
    for (list<QRadioButton*>::iterator it = boutonRadioTypeUsager.begin(); it != end; it++) {
        (*it)->setDisabled(true);

        bool checked = false;

        if ((typeid(*usager) == typeid(Client) && (*it)->text().endsWith("Client"))
             || (typeid(*usager) == typeid(ClientPremium) && (*it)->text().endsWith("ClientPremium"))
             || (typeid(*usager) == typeid(Fournisseur) && (*it)->text().endsWith("Fournisseur"))) {
                checked = true;
        }
        (*it)->setChecked(checked);
    }

    boutonAjouter->setDisabled(true);
    boutonSupprimer->setDisabled(false);
}

/****************************************************************************
* Fonction:    MainWindow::nettoyerVue()
* Description: réinitialise la vue avant d'ajouter un nouvel usager
* Paramètres:  aucun
* Retour:      aucun
****************************************************************************/
void MainWindow::nettoyerVue() {
    editeurNom->setDisabled(false);
    editeurNom->setText("");

    editeurPrenom->setDisabled(false);
    editeurPrenom->setText("");

    editeurIdentifiant->setDisabled(false);
    editeurIdentifiant->setText("");

    editeurCodePostal->setDisabled(false);
    editeurCodePostal->setText("");

    editeurJoursRestants->setDisabled(false);
    editeurJoursRestants->setText("");

    //Par défaut le boutons radios est à ClientPremium
    list<QRadioButton*>::iterator end = boutonRadioTypeUsager.end();
    for (list<QRadioButton*>::iterator it = boutonRadioTypeUsager.begin(); it != end; it++) {
        (*it)->setDisabled(false);
        if ((*it)->text().endsWith("ClientPremium")) {
            (*it)->setChecked(true);
        }
    }

    listUsager->clearSelection();
    boutonAjouter->setDisabled(false);
    boutonSupprimer->setDisabled(true);
    editeurNom->setFocus();
}

/****************************************************************************
* Fonction:    MainWindow::changerTypeUsager()
* Description: active le champ 'Jour restants' en fonction du type d'usager (activé seulement pour les clients premium)
* Paramètres:  aucun
* Retour:      aucun
****************************************************************************/
void MainWindow::changerTypeUsager(int index) {
    if (index == -2) {
        editeurJoursRestants->setDisabled(false);
    } else {
        editeurJoursRestants->setDisabled(true);
    }
}

/****************************************************************************
* Fonction:    MainWindow::supprimerTousLesUsagers()
* Description: supprime tous les usagers de la liste
* Paramètres:  aucun
* Retour:      aucun
****************************************************************************/
void MainWindow::supprimerTousLesUsagers() {
    vector<Usager*> supprimer; //creation d'un vecteur ou on mettra les usagers a supprimer
    for (int i=0;i<listUsager->count();++i){
    QListWidgetItem *item = listUsager-> item(i);
    supprimer.push_back(item->data(Qt::UserRole).value<Usager*>());
    }
    for (Usager* usager:supprimer){
        gestionnaire_->supprimerUsager(usager);
    }
}

/****************************************************************************
* Fonction:    MainWindow::supprimerUsagerSelectionne()
* Description: supprime l'usager selectionné
* Paramètres:  aucun
* Retour:      aucun
****************************************************************************/
void MainWindow::supprimerUsagerSelectionne() {
    vector<Usager*> supprimer;
    for(QListWidgetItem *item : listUsager->selectedItems()){
        supprimer.push_back(item->data(Qt::UserRole).value<Usager*>());
    }
    for (Usager* usager:supprimer){
        gestionnaire_->supprimerUsager(usager);
    }
}

/****************************************************************************
* Fonction:    MainWindow::ajouterUsager()
* Description: ajoute un nouvel usager dans la liste
* Paramètres:  aucun
* Retour:      aucun
****************************************************************************/
void MainWindow::ajouterUsager() {

    Usager* nouvelUsager;

    //On trouve le bon type d'usager selon le bouton radio sélectionné
    QRadioButton* typeUsager = 0;
    list<QRadioButton*>::iterator end= boutonRadioTypeUsager.end();
    for(auto it= boutonRadioTypeUsager.begin();it !=end;it++){
        if((*it)->isChecked()){
            typeUsager=*it;
            break;
        }
    }

    // On créé le bon type d'usager selon le cas
    //Vérification que tous les champs ont été complétés

     try {

            if ( editeurNom->text().isEmpty())
            {
                throw ExceptionArgumentInvalide( QString::fromStdString("Erreur : Le champ nom est invalide"));
            }
    
            if ( editeurPrenom->text().isEmpty())
            {
                throw ExceptionArgumentInvalide(QString::fromStdString( "Erreur : Le champ prénom est invalide"));
            }

            if ( editeurIdentifiant->text().isEmpty())
            {
                throw ExceptionArgumentInvalide( QString::fromStdString("Erreur : Le champ identifiant est invalide"));
            }

            if (editeurCodePostal->text().isEmpty())
            {
                throw ExceptionArgumentInvalide(QString::fromStdString( "Erreur : Le champ code postal est invalide"));
            }

            if ( editeurJoursRestants->text().isEmpty() && typeUsager->text().endsWith("ClientPremium"))
            {
                throw ExceptionArgumentInvalide( QString::fromStdString("Erreur : Le champ jour restants est invalide"));
            }
        }
        catch (ExceptionArgumentInvalide& e)
        {
            afficherMessage(e.what());
            return;
        }


    if (typeUsager->text().endsWith("ClientPremium"))
    {
        nouvelUsager= new ClientPremium(editeurNom->text().toStdString(),
                                        editeurPrenom->text().toStdString(),
                                        editeurIdentifiant->text().toInt(),
                                        editeurCodePostal->text().toStdString(),
                                        editeurJoursRestants->text().toDouble());
    }
    else if(typeUsager->text().endsWith("Client") )
    {
        nouvelUsager = new Client(editeurNom->text().toStdString(),
                                  editeurPrenom->text().toStdString(),
                                  editeurIdentifiant->text().toInt(),
                                  editeurCodePostal->text().toStdString());
    }
    else
    {
        nouvelUsager=new Fournisseur(editeurNom->text().toStdString(),
                                     editeurPrenom->text().toStdString(),
                                     editeurIdentifiant->text().toInt(),
                                     editeurCodePostal->text().toStdString());
    }

    // On ajoute le nouvel usager créé au gestionnaire
     gestionnaire_->ajouterUsager(nouvelUsager);
     
    // Mais on le stocke aussi localement dans l'attribut ajoute_ pour pouvoir le supprimer plus tard
    ajoute_.push_back(nouvelUsager);
}

/****************************************************************************
* Fonction:    MainWindow::usagerAEteAjoute()
* Description: mets à jour la vue après avoir ajouté un nouvel usager
* Paramètres:  Usager* u
* Retour:      aucun
****************************************************************************/
void MainWindow::usagerAEteAjoute(Usager* u) {
    QListWidgetItem* item = new QListWidgetItem(
    QString::fromStdString(u->obtenirNom()) + ", " + QString::fromStdString(u->obtenirPrenom()), listUsager);
    item->setData(Qt::UserRole, QVariant::fromValue<Usager*>(u));
    item->setHidden(filtrerMasque(u));
}

/****************************************************************************
* Fonction:    MainWindow::usagerAEteSupprime()
* Description: mise à jour de la vue après avoir supprimé un usager
* Paramètres:  Usager* u
* Retour:      aucun
****************************************************************************/
void MainWindow::usagerAEteSupprime(Usager* u) {
    // On cherche dans notre QlistWidget l'usager pour lequel le
    // signal a été envoyé, afin de l'en retirer
    for (int i = 0; i < listUsager->count(); ++i) {
        QListWidgetItem *item = listUsager->item(i);
        Usager* usager = item->data(Qt::UserRole).value<Usager*>();
        if (usager == u) {
            // delete sur un QlistWidget item va automatiquement le retirer de la liste

            delete item;
            // Si l'usager faisait partie de ceux créés localement, on veut le supprimer.
            auto it = std::find(ajoute_.begin(), ajoute_.end(), u);
            if (it != ajoute_.end()) {
                delete *it;
                ajoute_.erase(it);
            }
            break;
        }
    }
    // On remet à zéro l'affichage du panneau de gauche étant
    // donné que l'usager sélectionné a été supprimé
    nettoyerVue();
}
