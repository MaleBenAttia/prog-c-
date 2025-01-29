#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Fonction pour lire et afficher les mots d'un fichier
void lireEtAfficherMots(const string& nomFichier,string verif) {
    int pp;
    pp=0;
    ifstream fichier(nomFichier); // Ouvrir le fichier en lecture

    if (!fichier) {
        cerr << "Erreur : Impossible d'ouvrir le fichier !" << endl;
        return;
    }

    string mot; // Variable pour stocker chaque mot
     
    while (fichier >> mot) { // Lire mot par mot
   
    if (mot==verif){
  cout << "Mot lu exsiste : " << mot << endl;

    }
    else {
        cout << "Mot lu n'exsiste pas  : " << mot << endl;
 pp++ ;
    }
     

    }

 cout << "tu as nb de mot : " << pp << endl;
    fichier.close(); // Fermer le fichier

}


void lireEtAfficherLignes(const string& nomFichier) {

    int i ;
    ifstream fichier(nomFichier); // Ouvrir le fichier en lecture

    if (!fichier) {
        cerr << "Erreur : Impossible d'ouvrir le fichier !" << endl;
        return;
    }

    string ligne; // Variable pour stocker chaque ligne
    while (getline(fichier, ligne)) { // Lire ligne par ligne
    string kelma = ligne;
     
        cout << "Ligne lue : " << kelma<<i << endl;
       
    }

    fichier.close(); // Fermer le fichier
}




int main() {
    string nomFichier = "mehdi.txt"; // Nom du fichier
    lireEtAfficherMots(nomFichier,"malek") ; // Appel de la fonction
    return 0;
}
