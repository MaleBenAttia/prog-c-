#include <iostream>
#include <fstream>
#include <string>

#include "foc.h"
using namespace std;

// Fonction pour lire et afficher les mots d'un fichier
void lireEtAfficherMots(const string &nomFichier, string verif)
{
    int pp;
    pp = 0;
    ifstream fichier(nomFichier); // Ouvrir le fichier en lecture

    if (!fichier)
    {
        cerr << "Erreur : Impossible d'ouvrir le fichier !" << endl;
        return;
    }

    string mot; // Variable pour stocker chaque mot

    while (fichier >> mot)
    { // Lire mot par mot

        if (mot == verif)
        {
            cout << "Mot lu exsiste : " << mot << endl;
        }
        else
        {
            cout << "Mot lu n'exsiste pas  : " << mot << endl;
            pp++;
        }
    }

    cout << "tu as nb de mot : " << pp << endl;
    fichier.close(); // Fermer le fichier
}

void lireEtAfficherMots(const string &nomFichier, int nbligne, int m,int& khrouj)
{

    char Mot[m];
    int index;
    char TAB[nbligne];
    string atwelklema;
    int i = 0;

    vector<string> mots; // Vecteur pour stocker tous les mots du fichier
    string mot;          // Variable pour stocker chaque mot
    vector<string> motsSelectionnes(nbligne);
    ifstream fichier(nomFichier); // Ouvrir le fichier en lecture

    if (!fichier)
    {
        cerr << "Erreur : Impossible d'ouvrir le fichier !" << endl;
        return;
    }

    // Lire tous les mots du fichier et les stocker dans le vecteur
    while (fichier >> mot)
    {
        mots.push_back(mot);
    }

    fichier.close(); // Fermer le fichier
    // Vérifier si le fichier contient au moins 10 mots
    if (mots.size() < 10)
    {
        cerr << "Erreur : Le fichier contient moins de 10 mots !" << endl;
        return;
    }

    // Initialiser le générateur de nombres aléatoires
    srand(static_cast<unsigned int>(time(0)));

    // lena bch nrakhou el kelma
    while (i < nbligne)
    {
        int index = rand() % mots.size();
        if (mots[index].length() <= m-1)
        {
            motsSelectionnes[i] = mots[index];
            cout << "Mot sélectionné : " << motsSelectionnes[i] << endl;
            i++;
        }
    }

    atwelklema = motsSelectionnes[0]; // Initialiser avec le premier mot

    for (int i = 1; i < nbligne; i++)
    {
        if (motsSelectionnes[i].length() > atwelklema.length())
        {
            atwelklema = motsSelectionnes[i]; // Mettre à jour si un mot plus long est trouvé
        }
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Pause d'une seconde
    }

    int k = atwelklema.length();
    // std::this_thread::sleep_for(std::chrono::seconds(4));

    cout << "la plul longe et  :" << atwelklema << "avec n de char " << k << endl;

    for (int i = 0; i < nbligne; i++)
    {
        string motCourant = motsSelectionnes[i];
        for (int j = 0; j < motCourant.length(); j++)
        {
            Matric[i][j] = motCourant[j];
            cout << Matric[i][j] << " ";
        }
        cout << endl;
    }

  remplirMatrice123( nbligne,  m,motsSelectionnes,khrouj);
  afficheMatrice2(nbligne+1, m+1);
  cout<<khrouj;
}






int main()
{
    int m, nbligne;
    do
    {
        cout << "Donnez la taille de la matrice (n x m) : " << endl;
        cin >> nbligne >> m;

        if (nbligne > 100 || m > 100)
        {
            cout << "Erreur : La taille de la matrice ne doit pas dépasser 100 x 100. Veuillez réessayer.\n";
        }
    } while (nbligne > 100 || m > 100);
    string nomFichier = "mehdi.txt"; // Remplacez par le nom de votre fichier
    lireEtAfficherMots(nomFichier, nbligne, m,khrouj);
do
{
     cout << "Donnez la position de départ (n1 et m1) : " <<  endl;
     cin >> n1;
     cin >> m1;

    if (n1 >= nbligne || n1 < 0 || m1 >= m || m1 < 0 )
    {
         cout << "Erreur : La position de départ doit être dans les limites de la matrice. Veuillez réessayer.\n";
    }
    if (Matric[n1][m1] =='1'){
        cout << "opss il y a un mur"<<endl;
    }
} while (n1 >= nbligne || n1 < 0 || m1 >= m || m1 < 0 || Matric[n1][m1] =='1');

int nb1 = combienDeUn(nbligne, m+1); // Compte les '1' dans la matrice
cout << "Le nombre de '1' dans la matrice est : " << nb1 <<  endl;

char abda = Matric[n1][m1]; // Sauvegarde la valeur actuelle de la case
Matric[n1][m1] = '2';       // Marque la position initiale dans la matrice

direction(nbligne, m, n1, m1, 13/*ena lezem nhotou akber kelma fel txt*/, 1, abda);

    return 0;


}
