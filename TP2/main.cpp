#include <iostream>
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetComplexe.h"

using namespace std;

void AjouterTrajet(Catalogue & catalogue);
void RechercherTrajet(Catalogue & catalogue);
void AfficherTrajet(Catalogue & catalogue);

int main()
{
    int commande = 0;
    Catalogue catalogue = Catalogue();
    cout << "Bienvenue dans ce simulateur de gestion de transports." << endl << endl;
    while(commande != -1)
    {
        cout << "Menu :" << endl
             << "-- (1) Ajouter un trajet au catalogue :" << endl
             << "-- (2) Afficher le catalogue :" << endl
             << "-- (3) Rechercher un parcours dans le catalogue :" << endl
             << "-- (4) Sortir" << endl;
        cin >> commande;
        switch(commande)
        {
        case 1:
            AjouterTrajet(catalogue);
            break;
        case 2:
            AfficherTrajet(catalogue);
            break;
        case 3:
            RechercherTrajet(catalogue);
            break;
        case 4:
            cout << "Fermeture ..." << endl;
            return 0;
        case -1:
            break;
        default:
            cout << "Commande inconnue." << endl;
            break;
        }
    }

    /*Catalogue catalogue = Catalogue();
    TrajetSimple* TS1 = new TrajetSimple("Lyon", "Bordeaux", MoyenTransport::TRAIN); // A CHECK SANS LE NEW ET L'ETOILE
    TrajetSimple* TS2 = new TrajetSimple("Lyon", "Bordeaux", MoyenTransport::AVION);
    TrajetSimple* TC3_1 = new TrajetSimple("Paris", "Marseille", MoyenTransport::AUTO);
    TrajetSimple* TC3_2 = new TrajetSimple("Marseille", "Lyon", MoyenTransport::BATEAU);
    const Trajet* liste[2] = {TC3_1, TC3_2};
    if(TrajetComplexe::listeCorrect(liste, 2, "Paris", "Lyon"))
    {
        TrajetComplexe* TC3 = new TrajetComplexe(liste, 2, "Paris", "Lyon");
        TC3->Afficher();
        catalogue.Ajouter(TC3);
    }
    catalogue.Ajouter(TS1);
    catalogue.Ajouter(TS2);



    //TS1->Afficher();
    catalogue.Afficher();

    cout << endl << endl << endl << endl;

    char* lyon = "Lyon"; // ne pas delete
    char* bordeaux = "Bordeaux";
    catalogue.Rechercher(lyon, bordeaux);
    catalogue.AfficherResRecherche();

    cout << endl << endl << endl << endl;

    char* paris = "Paris";
    catalogue.Rechercher(paris, lyon);
    catalogue.AfficherResRecherche();*/



    return 0;
}

void RechercherTrajet(Catalogue & catalogue)
{
    char villeDep[100],villeArr[100];
    cout << "Ville de départ : ";
    cin >> villeDep;
    cout << "Ville d'arrivée : ";
    cin >> villeArr;
    catalogue.Rechercher(villeDep,villeArr);
    cout << endl << "Résultat de la recherche :" <<endl;
    catalogue.AfficherResRecherche();
    cout << endl;
}

void AjouterTrajetSimple(Catalogue & catalogue)
{
    char *villeDep = new char[40];
    char *villeArr = new char[40];
    unsigned idMoyenTransport;
    cout << "Veuillez saisir la ville de départ" << endl;
    cin >> villeDep;
    cout << "Veuillez saisir la ville d'arrivée" << endl;
    cin >> villeArr;
    cout << "Veuillez choisir le moyen de transport" << endl;
    cout << "(1) AUTO" << endl
         << "(2) TRAIN" << endl
         << "(3) AVION" << endl
         << "(4) BATEAU" << endl;
    cin >> idMoyenTransport;
    TrajetSimple* trajetSimple;
    switch (idMoyenTransport) {
    case 1:
        trajetSimple = new TrajetSimple(villeDep, villeArr, MoyenTransport::AUTO);
        break;
    case 2:
        trajetSimple = new TrajetSimple(villeDep, villeArr, MoyenTransport::TRAIN);
        break;
    case 3:
        trajetSimple = new TrajetSimple(villeDep, villeArr, MoyenTransport::AVION);
        break;
    case 4:
        trajetSimple = new TrajetSimple(villeDep, villeArr, MoyenTransport::BATEAU);
        break;
    default:
        cout << "Erreur" << endl;
        return;
    }
    catalogue.Ajouter(trajetSimple);
}

void AjouterTrajetComplexe(Catalogue & catalogue)
{
    unsigned nbSousTrajets(0);
    while(nbSousTrajets <= 1 || nbSousTrajets >= 10)
    {
        cout << "De combien de sous-trajets se compose votre trajet complexe ? (entre 2 et 9)" << endl;
        cin >> nbSousTrajets;
    }
    char *villeDepGlobal = new char[40];
    char *villeArrGlobal = new char[40];
    cout << "Veuillez saisir la ville de départ du trajet complexe" << endl;
    cin >> villeDepGlobal;
    cout << "Veuillez saisir la ville d'arrivée du trajet complexe" << endl;
    cin >> villeArrGlobal;
    Trajet** liste = new Trajet*[9];
    unsigned idMoyenTransport;
    for(unsigned i(0); i < nbSousTrajets; ++i)
    {
        cout << endl << "Composition du trajet simple composant le trajet complexe :" << endl;
        char *villeDep = new char[40];
        char *villeArr = new char[40];
        cout << "Veuillez saisir la ville de départ" << endl;
        cin >> villeDep;
        cout << "Veuillez saisir la ville d'arrivée" << endl;
        cin >> villeArr;
        cout << "Veuillez choisir le moyen de transport" << endl;
        cout << "(1) AUTO" << endl
             << "(2) TRAIN" << endl
             << "(3) AVION" << endl
             << "(4) BATEAU" << endl;
        cin >> idMoyenTransport;
        TrajetSimple* trajetSimple;
        switch (idMoyenTransport) {
        case 1:
            trajetSimple = new TrajetSimple(villeDep, villeArr, MoyenTransport::AUTO);
            break;
        case 2:
            trajetSimple = new TrajetSimple(villeDep, villeArr, MoyenTransport::TRAIN);
            break;
        case 3:
            trajetSimple = new TrajetSimple(villeDep, villeArr, MoyenTransport::AVION);
            break;
        case 4:
            trajetSimple = new TrajetSimple(villeDep, villeArr, MoyenTransport::BATEAU);
            break;
        default:
            cout << "Erreur" << endl;
            return;
        }
        liste[i] = trajetSimple;
    }
    if(TrajetComplexe::listeCorrect(liste, nbSousTrajets, villeDepGlobal, villeArrGlobal))
    {
        TrajetComplexe* trajetComplexe = new TrajetComplexe(liste, nbSousTrajets, villeDepGlobal, villeArrGlobal);
        catalogue.Ajouter(trajetComplexe);
    } else
    {
        cout << "Le trajet composé est incorrect, il n'a pas été ajouté au catalogue" << endl;
    }
}

void AjouterTrajet(Catalogue & catalogue)
{
    cout << "(1) Trajet Simple" << endl
         << "(2) Trajet Complexe" << endl;
    int commande(0);
    cin >> commande;
    switch (commande) {
    case 1:
        AjouterTrajetSimple(catalogue);
        break;
    case 2:
        AjouterTrajetComplexe(catalogue);
        break;
    default:
        cout << "Erreur" << endl;
        return;

        /*
    TrajetSimple* TS1 = new TrajetSimple("Lyon", "Bordeaux", MoyenTransport::TRAIN);
    TrajetSimple* TS2 = new TrajetSimple("Lyon", "Bordeaux", MoyenTransport::AVION);
    TrajetSimple* TC3_1 = new TrajetSimple("Paris", "Marseille", MoyenTransport::AUTO);
    TrajetSimple* TC3_2 = new TrajetSimple("Marseille", "Lyon", MoyenTransport::BATEAU);
    catalogue.Ajouter(TS1);
    catalogue.Ajouter(TS2);
    const Trajet* liste[2]; // = {TC3_1, TC3_2};
    liste[0] = TC3_1;
    liste[1] = TC3_2;
    if(TrajetComplexe::listeCorrect(liste, 2, "Paris", "Lyon"))
    {
        TrajetComplexe* TC3 = new TrajetComplexe(liste, 2, "Paris", "Lyon");
        catalogue.Ajouter(TC3);
    }
    */
    }
}
void AfficherTrajet(Catalogue & catalogue)
{
    catalogue.Afficher();
}
