
#ifndef finc
#define finc

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <cctype> // Pour isalpha()
#include <thread> // Pour std::this_thread::sleep_for
#include <chrono> // Pour std::chrono::seconds

using namespace std;

int x = 0, khrouj = 0;
#define connb (Matric[i][j] == '2' || Matric[i][j] == '3' || Matric[i][j] == '4' || Matric[i][j] == '5' || Matric[i][j] == '6' || Matric[i][j] == '7' || Matric[i][j] == '8' || Matric[i][j] == '9')
#define conYO (rec != 'Y' && rec != 'y' && rec != 'N' && rec != 'n')
#define BLOQ(valeurVoisin) (valeurVoisin < '1' || valeurVoisin > '9')

#define H (Matric[n1 - 1][m1] == '1' || Matric[n1 - 1][m1] == '2' || Matric[n1 - 1][m1] == '3' || \
           Matric[n1 - 1][m1] == '4' || Matric[n1 - 1][m1] == '5' || Matric[n1 - 1][m1] == '6' || \
           Matric[n1 - 1][m1] == '7' || Matric[n1 - 1][m1] == '8' || Matric[n1 - 1][m1] == '9')

#define B (Matric[n1 + 1][m1] == '1' || Matric[n1 + 1][m1] == '2' || Matric[n1 + 1][m1] == '3' || \
           Matric[n1 + 1][m1] == '4' || Matric[n1 + 1][m1] == '5' || Matric[n1 + 1][m1] == '6' || \
           Matric[n1 + 1][m1] == '7' || Matric[n1 + 1][m1] == '8' || Matric[n1 + 1][m1] == '9')

#define G (Matric[n1][m1 - 1] == '1' || Matric[n1][m1 - 1] == '2' || Matric[n1][m1 - 1] == '3' || \
           Matric[n1][m1 - 1] == '4' || Matric[n1][m1 - 1] == '5' || Matric[n1][m1 - 1] == '6' || \
           Matric[n1][m1 - 1] == '7' || Matric[n1][m1 - 1] == '8' || Matric[n1][m1 - 1] == '9')

#define D (Matric[n1][m1 + 1] == '1' || Matric[n1][m1 + 1] == '2' || Matric[n1][m1 + 1] == '3' || \
           Matric[n1][m1 + 1] == '4' || Matric[n1][m1 + 1] == '5' || Matric[n1][m1 + 1] == '6' || \
           Matric[n1][m1 + 1] == '7' || Matric[n1][m1 + 1] == '8' || Matric[n1][m1 + 1] == '9')

#define HG (Matric[n1 - 1][m1 - 1] == '1' || Matric[n1 - 1][m1 - 1] == '2' || Matric[n1 - 1][m1 - 1] == '3' || \
            Matric[n1 - 1][m1 - 1] == '4' || Matric[n1 - 1][m1 - 1] == '5' || Matric[n1 - 1][m1 - 1] == '6' || \
            Matric[n1 - 1][m1 - 1] == '7' || Matric[n1 - 1][m1 - 1] == '8' || Matric[n1 - 1][m1 - 1] == '9')

#define HD (Matric[n1 - 1][m1 + 1] == '1' || Matric[n1 - 1][m1 + 1] == '2' || Matric[n1 - 1][m1 + 1] == '3' || \
            Matric[n1 - 1][m1 + 1] == '4' || Matric[n1 - 1][m1 + 1] == '5' || Matric[n1 - 1][m1 + 1] == '6' || \
            Matric[n1 - 1][m1 + 1] == '7' || Matric[n1 - 1][m1 + 1] == '8' || Matric[n1 - 1][m1 + 1] == '9')

#define BG (Matric[n1 + 1][m1 - 1] == '1' || Matric[n1 + 1][m1 - 1] == '2' || Matric[n1 + 1][m1 - 1] == '3' || \
            Matric[n1 + 1][m1 - 1] == '4' || Matric[n1 + 1][m1 - 1] == '5' || Matric[n1 + 1][m1 - 1] == '6' || \
            Matric[n1 + 1][m1 - 1] == '7' || Matric[n1 + 1][m1 - 1] == '8' || Matric[n1 + 1][m1 - 1] == '9')

#define BD (Matric[n1 + 1][m1 + 1] == '1' || Matric[n1 + 1][m1 + 1] == '2' || Matric[n1 + 1][m1 + 1] == '3' || \
            Matric[n1 + 1][m1 + 1] == '4' || Matric[n1 + 1][m1 + 1] == '5' || Matric[n1 + 1][m1 + 1] == '6' || \
            Matric[n1 + 1][m1 + 1] == '7' || Matric[n1 + 1][m1 + 1] == '8' || Matric[n1 + 1][m1 + 1] == '9')
// Déclaration de la matrice globale
char Matric[100][100];
char Matric1[100][100];
char T[20];
int m, n, choix, n1, m1;

int combienDeUn(int n, int m)
{
    int count = 0; // Compteur initialisé à 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (Matric[i][j] == '1')
            {
                count++; // Incrémenter le compteur si le caractère est '1'
            }
        }
    }
    return count;
}

void menu()
{

    cout << "\n--- Menu de déplacement ---\n";
    cout << "1. Haut\n";
    cout << "2. Bas\n";
    cout << "3. Gauche\n";
    cout << "4. Droite\n";
    cout << "5. Diagonale Haut-Gauche\n";
    cout << "6. Diagonale Haut-Droite\n";
    cout << "7. Diagonale Bas-Gauche\n";
    cout << "8. Diagonale Bas-Droite\n";
    cout << "Choisissez une option (1-8): " << endl;
}

void remplirMatrice(int n, int m)
{

    srand(time(0)); // Initialisation de la graine aléatoire
    int range = 30; // 26 lettres + 4 pour le chiffre '1'

    for (int i = 0; i < n; i++)
    {
        bool hasOne = false; // Vérifie si la ligne contient au moins un '1'

        for (int j = 0; j < m; j++)
        {
            int randomValue = rand() % range; // Génère une valeur entre 0 et 29

            // Génération des caractères aléatoires
            if (randomValue < 4)
            {
                Matric[i][j] = '1'; // Cas pour '1'
                hasOne = true;      // Marque qu'il y a un '1' dans cette ligne
            }
            else
            {
                Matric[i][j] = 'A' + (randomValue - 4); // Cas pour 'A' à 'Z'
            }
        }

        // Si la ligne n'a pas de '1', force l'ajout d'un '1'
        if (!hasOne)
        {
            int randomColumn = rand() % m; // Choisir une colonne aléatoire
            Matric[i][randomColumn] = '1';
        }
    }
}
void afficheMatrice2(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j == m - 1 && Matric[i][j] == '1')
            {
                cout << " ";
            }

            else
            {
                cout << " " << Matric[i][j] << " "; // Affichage du caractère
            }
        }

        // Vérification si le dernier élément de la ligne est '1'

        cout << endl; // Retour à la ligne après chaque ligne de la matrice
    }
}

void remplirMatriceN1(int n, int m, vector<string> motsSelectionnes, int &khrouj)
{
    int randomValue;
    srand(time(0)); // Initialisation de la graine aléatoire
    int range = 30; // 26 lettres (A-Z) + 4 pour le chiffre '1'

    for (int i = 0; i < n; i++)
    {
        string motCourant = motsSelectionnes[i];
        for (int j = 0; j < motCourant.length(); j++)
        {
            Matric[i][j] = motCourant[j];
            // cout << Matric[i][j] << " ";
        }
        //  cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        bool hasOne = false; // Vérifie si la ligne contient au moins un '1'

        for (int j = 0; j < m; j++)
        {
            if (!isalpha(Matric[i][j])) // Remplir uniquement les cases vides
            {
                randomValue = rand() % range; // Génère une valeur entre 0 et 29

                // Génération des caractères aléatoires
                if (randomValue < 4)
                {
                    Matric[i][j] = '1'; // Cas pour '1'
                    hasOne = true;      // Marque qu'il y a un '1' dans cette ligne
                }
                else
                {
                    Matric[i][j] = 'A' + (randomValue - 4); // Cas pour 'A' à 'Z'
                }
            }
        }

        // Si la ligne n'a pas de '1', on force l'ajout d'un '1' quelque part
        if (!hasOne)
        {
            int randomColumn = motsSelectionnes[i].length() + (rand() % (m - motsSelectionnes[i].length()));
            Matric[i][randomColumn] = '1';
        }
    }

    for (int i = 0; i < n; i++)
    {
        Matric[i][m] = '1';
    }
    // Ajouter un `*` à une ligne aléatoire à la dernière colonne
    khrouj = rand() % n;
    Matric[khrouj][m] = '*'; // `m` étant la dernière colonne après les données
    Matric[khrouj][m - 1] = 'A' + m;
}

void remplirMatriceN2(int n, int m, vector<string> motsSelectionnes, int &khrouj)
{
    srand(time(0)); // Initialisation de la graine aléatoire
    int range = 30; // 26 lettres (A-Z) + 4 pour le chiffre '1'
    char Matric1[100][100];

    // Initialisation des matrices

    for (int i = 0; i < n; i++)
    {
        bool hasOne = false; // Vérifie si la ligne contient au moins un '1'

        for (int j = 0; j < m; j++)
        {
            int randomValue = rand() % range; // Génère une valeur entre 0 et 29
            Matric1[i][j] = 'r';
            // Génération des caractères aléatoires
            if (randomValue < 4)
            {
                Matric[i][j] = '1'; // Cas pour '1'
                hasOne = true;      // Marque qu'il y a un '1' dans cette ligne
            }
            else
            {
                Matric[i][j] = 'A' + (randomValue - 4); // Cas pour 'A' à 'Z'
            }
        }

        // Si la ligne n'a pas de '1', force l'ajout d'un '1'
        if (!hasOne)
        {
            int randomColumn = rand() % m; // Choisir une colonne aléatoire
            Matric[i][randomColumn] = '1';
        }
    }

    // Placement des mots
    for (int rep = 0; rep < motsSelectionnes.size(); rep++)
    {
        string mot = motsSelectionnes[rep];
        int k = mot.length();
        int c = 0;
        while (c < k)
        {
            int row = rand() % n;
            int col = rand() % m;

            // Vérifier si la case est disponible
            while (Matric1[row][col] == '1')
            {
                row = rand() % n;
                col = rand() % m;
            }

            Matric[row][col] = mot[c]; // Placement du caractère
            Matric1[row][col] = '1';   // Marquer la case comme occupée
            c++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        Matric[i][m] = '1';
    }
    // Ajouter un `*` à une ligne aléatoire à la dernière colonne
    khrouj = rand() % n;
    Matric[khrouj][m] = '*'; // `m` étant la dernière colonne après les données
    Matric[khrouj][m - 1] = 'A' + m;

    /*
    // Affichage de la matrice Matric
    cout << "Matrice principale : " << endl;
    afficheMatrice2(n + 1, m + 1);

    // Affichage de la matrice Matric1
    cout << "Matrice des indices (1 = mot placé, 0 = vide) : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << " " << Matric1[i][j] << " ";
        }
        cout << endl;
    }*/
}

void remplirMatriceN3(int n, int m, vector<string> motsSelectionnes, int &khrouj)
{
    srand(time(0)); // Initialisation de la graine aléatoire
    int range = 30; // 26 lettres (A-Z) + 4 pour le chiffre '1'
    char Matric1[100][100];

    // Initialisation des matrices

    for (int i = 0; i < n; i++)
    {
        bool hasOne = false; // Vérifie si la ligne contient au moins un '1'

        for (int j = 0; j < m; j++)
        {
            int randomValue = rand() % range; // Génère une valeur entre 0 et 29
            // Génération des caractères aléatoires
            if (randomValue < 4)
            {
                Matric[i][j] = '1'; // Cas pour '1'
                hasOne = true;      // Marque qu'il y a un '1' dans cette ligne
            }
            else
            {
                Matric[i][j] = 'A' + (randomValue - 4); // Cas pour 'A' à 'Z'
            }
        }

        // Si la ligne n'a pas de '1', force l'ajout d'un '1'
        if (!hasOne)
        {
            int randomColumn = rand() % m; // Choisir une colonne aléatoire
            Matric[i][randomColumn] = '1';
        }
    }

    // Placement des mots
    for (int i = 0; i < n; i++)
    {
        string motCourant = motsSelectionnes[i];
        for (int j = 0; j < (motCourant.length()) / 2; j++)
        {
            Matric[i][j] = motCourant[j];
            // cout << Matric[i][j] << " "; // Affichage
        }
        // cout << endl;
    }

    // Remplissage de la seconde moitié en partant du bas
    for (int i = n - 1; i >= 0; i--)
    {
        string motCourant = motsSelectionnes[i];
        for (int j = (motCourant.length()) / 2; j < motCourant.length(); j++)
        {
            int k = n - 1 - i; // Correction de l'index
            Matric[k][j] = motCourant[j];
            // cout << Matric[k][j] << " "; // Affichage corrigé
        }
        // cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        Matric[i][m] = '1';
    }
    // Ajouter un `*` à une ligne aléatoire à la dernière colonne
    khrouj = rand() % n;
    Matric[khrouj][m] = '*'; // `m` étant la dernière colonne après les données
    Matric[khrouj][m - 1] = 'A' + m;
    /*
        cout << "Bara mrigel" << endl;

        // Affichage de la matrice Matric
        cout << "Matrice principale : " << endl;
        afficheMatrice2(n + 1, m + 1);
    */
    // Affichage de la matrice Matric1
}

void remplirMatrice2(int n, int m, int khrouj)
{
    srand(time(0)); // Initialisation de la graine aléatoire
    int range = 30; // 26 lettres + 4 pour le chiffre '1'

    for (int i = 0; i < n; i++)
    {
        

        for (int j = 0; j < m; j++)
        {
            if (connb) // Vérifie si la case contient '2', '3', ..., '9'
            {
                int randomValue = rand() % range; // Génère une valeur entre 0 et 29

                // Génération des caractères aléatoires
                if (randomValue < 4)
                {
                    Matric[i][j] = '1'; // Cas pour '1'
                
                }
                else
                {
                    Matric[i][j] = 'A' + (randomValue - 4); // Cas pour 'A' à 'Z'
                }


            }
        }
    }

}

// Fonction pour afficher la matrice
void afficheMatrice(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << " " << Matric[i][j] << " "; // Affichage du caractère
        }
        cout << endl; // Retour à la ligne après chaque ligne de la matrice
    }
}

void afficheTab(char T[], int mac, int step)
{

    cout << "tu as recuperer le mot : ";
    for (int i = 0; i < mac; i++)
    {
        cout << T[i];
    }
    cout << endl;
    cout << "avec nb step= : " << step << endl;
}
void afficheTab1(char T[], int mac)
{

    cout << "tu as recuperer le mot : ";
    for (int i = 0; i < mac; i++)
    {
        cout << T[i];
    }
    cout << endl;
}

void CompMot(const string &nomFichier, string verif, int &Score, int long1, int niveau)
{
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
            cout << "Mot lu existe : " << mot << endl;
            Score = Score + ((30 * niveau) + long1);
        }
    }

    fichier.close(); // Fermer le fichier
}

void lireEtAfficherMots(const string &nomFichier, int nbligne, int m, int &khrouj, int niv1)
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
        if (mots[index].length() <= m - 1)
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
        //   std::this_thread::sleep_for(std::chrono::seconds(1)); // Pause d'une seconde
    }

    int k = atwelklema.length();
    // std::this_thread::sleep_for(std::chrono::seconds(4));

    cout << "la plul longe et  :  " << atwelklema << "  avec n de char " << k << endl;
    if (niv1 == 0)
    {

        remplirMatriceN1(nbligne, m, motsSelectionnes, khrouj);
    }

    else if (niv1 == 1)
    {

        remplirMatriceN2(nbligne, m, motsSelectionnes, khrouj);
    }
    else
    {
        remplirMatriceN3(nbligne, m, motsSelectionnes, khrouj);
    }
    cout << khrouj << endl;
}

void direction(int n, int m, int n1, int m1, int max, int mloul, char loul, int niv)
{
    T[0] = loul;
    char rec, mot, pt;
    int j = 0, i = 0, step = 0, mac = 16, Score = 0;

    j++;

    if (j == 1)
    {
        i = mloul;
    }
    else
    {
        i = 0;
    }
    step = 0;
    while (i < mac)
    {

        cout << "Choisissez un mouvement (entre 1 et 8) : " << endl;
        menu();
        cout << "Vous etes actuellement à la position : " << Matric[n1][m1] << endl;
        afficheMatrice2(n, m + 1);
        afficheTab(T, mac, step);
        cin >> choix;

        // Validation de l'entrée (entre 1 et 8)
        while (choix < 1 || choix > 8)
        {
            cout << "Oups ! Veuillez entrer une valeur entre 1 et 8 : ";
            menu();
            afficheMatrice(n, m);
            cin >> choix;
        }

        switch (choix)
        {
        case 1: // Haut
            if (n1 - 1 >= 0)
            {
                if (H)
                {
                    cout << "Vous avez choisi de monter (Haut).\nMais il y a un mur.\n";
                }
                else
                {
                    n1 -= 1;
                    step++;

                    do
                    {
                        cout << "Tu veux prendre la valeur (" << Matric[n1][m1] << ") ? Si oui, tape Y. Sinon, tape N : ";
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {
                        T[i] = Matric[n1][m1];
                        i++;
                        Matric[n1][m1] = static_cast<char>((step + 2) + '0');
                    }

                    do
                    {
                        cout << "t7eb tkamel ??  ken ey Y snn N : " << endl;
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {

                        string kelma(T, i); // lena nekhdhou el klma

                        for (int k = 0; k < i; k++)
                        {
                            T[k] = ' ';
                        }

                        cout << "tu as le mot " << kelma << endl;

                        CompMot("mehdi.txt", kelma, Score, i, niv+1);

                        cout << "tu as un Score de  " << Score << endl;

                        std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes

                        i = 0;
                        remplirMatrice2(n, m, khrouj);
                        afficheMatrice(n, m);
                        step = 0;
                    }

                    cout << "Vous êtes maintenant dans la case : " << Matric[n1][m1] << endl;
                }
            }
            else
            {
                cout << "Mouvement impossible (hors de la matrice).\n";
            }
            break;

        case 2: // Bas
            if (n1 + 1 < n)
            {
                if (B)
                {
                    cout << "Vous avez choisi de descendre (Bas).\nMais il y a un mur.\n";
                }
                else
                {
                    n1 += 1;
                    step++;

                    do
                    {
                        cout << "Tu veux prendre la valeur (" << Matric[n1][m1] << ") ? Si oui, tape Y. Sinon, tape N : ";
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {
                        T[i] = Matric[n1][m1];
                        i++;
                        Matric[n1][m1] = static_cast<char>((step + 2) + '0');
                    }

                    do
                    {
                        cout << "t7eb tkamel ??  ken ey Y snn N : " << endl;
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {

                        string kelma(T, i); // lena nekhdhou el klma

                        for (int k = 0; k < i; k++)
                        {
                            T[k] = ' ';
                        }
                        cout << "tu as le mot " << kelma << endl;

                        CompMot("mehdi.txt", kelma, Score, i, niv+1);

                        cout << "tu as un Score de  " << Score << endl;

                        std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes
                        step = 0;
                        i = 0;
                        remplirMatrice2(n, m, khrouj);
                        afficheMatrice(n, m);
                    }

                    cout << "Vous êtes maintenant dans la case : " << Matric[n1][m1] << endl;
                }
            }
            else
            {
                cout << "Mouvement impossible (hors de la matrice).\n";
            }
            break;

        case 3: // Gauche
            if (m1 - 1 >= 0)
            {
                if (G)
                {
                    cout << "Vous avez choisi de bouger à gauche.\nMais il y a un mur.\n";
                }
                else
                {
                    m1 -= 1;
                    step++;

                    do
                    {
                        cout << "Tu veux prendre la valeur (" << Matric[n1][m1] << ") ? Si oui, tape Y. Sinon, tape N : ";
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {
                        T[i] = Matric[n1][m1];
                        i++;
                        Matric[n1][m1] = static_cast<char>((step + 2) + '0');
                    }

                    cout << "Vous êtes maintenant dans la case : " << Matric[n1][m1] << endl;
                }
            }

            do
            {
                cout << "t7eb tkamel ??  ken ey Y snn N : " << endl;
                cin >> rec;

                if (conYO)
                {
                    cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                }
            } while (conYO);

            if (rec == 'Y' || rec == 'y')
            {

                string kelma(T, i); // lena nekhdhou el klma

                for (int k = 0; k < i; k++)
                {
                    T[k] = ' ';
                }

                cout << "tu as le mot " << kelma << endl;

                CompMot("mehdi.txt", kelma, Score, i, niv+1);

                cout << "tu as un Score de  " << Score << endl;

                std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes
                step = 0;
                i = 0;
                remplirMatrice2(n, m, khrouj);
                afficheMatrice(n, m);
            }

            else
            {
                cout << "Mouvement impossible (hors de la matrice).\n";
            }
            break;

        case 4: // Droite
            if (m1 + 1 < m || Matric[n1][m1 + 1] != '*')
            {
                if (D)
                {
                    cout << "Vous avez choisi de bouger à droite.\nMais il y a un mur.\n";
                }
                else
                {
                    m1 += 1;
                    step++;

                    do
                    {
                        cout << "Tu veux prendre la valeur (" << Matric[n1][m1] << ") ? Si oui, tape Y. Sinon, tape N : ";
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {
                        T[i] = Matric[n1][m1];
                        i++;
                        Matric[n1][m1] = static_cast<char>((step + 2) + '0');
                    }

                    cout << "Vous êtes maintenant dans la case : " << Matric[n1][m1] << endl;
                    do
                    {
                        cout << "t7eb tkamel ??  ken ey Y snn N : " << endl;
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {

                        string kelma(T, i); // lena nekhdhou el klma

                        for (int k = 0; k < i; k++)
                        {
                            T[k] = ' ';
                        }

                        cout << "tu as le mot " << kelma << endl;

                        CompMot("mehdi.txt", kelma, Score, i, niv+1);

                        cout << "tu as un Score de  " << Score << endl;

                        std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes
                        step = 0;
                        i = 0;
                        remplirMatrice2(n, m, khrouj);
                        afficheMatrice(n, m);
                    }
                }
            }
            else if (Matric[n1][m1 + 1] == '*')
            {
                cout << "finn";
                m1 += 1;
            }
            else
            {
                cout << "Mouvement impossible (hors de la matrice).\n";
            }
            break;

        case 5: // Diagonale Haut-Gauche
            if (n1 - 1 >= 0 && m1 - 1 >= 0)
            {
                if (HG)
                {
                    cout << "Vous avez choisi de monter en diagonale (Haut-Gauche).\nMais il y a un mur.\n";
                }
                else
                {
                    n1 -= 1;
                    m1 -= 1;
                    step++;

                    do
                    {
                        cout << "Tu veux prendre la valeur (" << Matric[n1][m1] << ") ? Si oui, tape Y. Sinon, tape N : ";
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {
                        T[i] = Matric[n1][m1];
                        i++;
                        Matric[n1][m1] = static_cast<char>((step + 2) + '0');
                    }

                    cout << "Vous êtes maintenant dans la case : " << Matric[n1][m1] << endl;
                }
            }

            do
            {
                cout << "t7eb tkamel ??  ken ey Y snn N : " << endl;
                cin >> rec;

                if (conYO)
                {
                    cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                }
            } while (conYO);

            if (rec == 'Y' || rec == 'y')
            {

                string kelma(T, i); // lena nekhdhou el klma

                for (int k = 0; k < i; k++)
                {
                    T[k] = ' ';
                }

                cout << "tu as le mot " << kelma << "    okkkkkkkkkkkkkkk " << endl;

                CompMot("mehdi.txt", kelma, Score, i, niv+1);

                cout << "tu as un Score de  " << Score << "    okkkkkkkkkkkkkkk " << endl;

                std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes
                step = 0;
                i = 0;
                remplirMatrice2(n, m, khrouj);
                afficheMatrice(n, m);
            }

            else
            {
                cout << "Mouvement impossible (hors de la matrice).\n";
            }
            break;

        case 6: // Diagonale Haut-Droite
            if (n1 - 1 >= 0 && m1 + 1 < m && Matric[n1 - 1][m1 + 1] != '*')
            {
                if (HD)
                {
                    cout << "Vous avez choisi de monter en diagonale (Haut-Droite).\nMais il y a un mur.\n";
                }
                else
                {
                    n1 -= 1;
                    m1 += 1;
                    step++;

                    do
                    {
                        cout << "Tu veux prendre la valeur (" << Matric[n1][m1] << ") ? Si oui, tape Y. Sinon, tape N : ";
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {
                        T[i] = Matric[n1][m1];
                        i++;
                        Matric[n1][m1] = static_cast<char>((step + 2) + '0');
                    }

                    cout << "Vous êtes maintenant dans la case : " << Matric[n1][m1] << endl;

                    do
                    {
                        cout << "t7eb tkamel ??  ken ey Y snn N : " << endl;
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {

                        string kelma(T, i); // lena nekhdhou el klma

                        for (int k = 0; k < i; k++)
                        {
                            T[k] = ' ';
                        }

                        cout << "tu as le mot " << kelma << endl;

                        CompMot("mehdi.txt", kelma, Score, i, niv+1);

                        cout << "tu as un Score de  " << Score << endl;

                        std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes
                        step = 0;
                        i = 0;
                        remplirMatrice2(n, m, khrouj);
                        afficheMatrice(n, m);
                    }
                }
            }
            else if (Matric[n1 - 1][m1 + 1] == '*')
            {
                n1 -= 1;
                m1 += 1;
                cout << "finn";
            }

            else
            {
                cout << "Mouvement impossible (hors de la matrice).\n";
            }
            break;

        case 7: // Diagonale Bas-Gauche
            if (n1 + 1 < n && m1 - 1 >= 0)
            {
                if (BG)
                {
                    cout << "Vous avez choisi de descendre en diagonale (Bas-Gauche).\nMais il y a un mur.\n";
                }
                else
                {
                    n1 += 1;
                    m1 -= 1;
                    step++;

                    do
                    {
                        cout << "Tu veux prendre la valeur (" << Matric[n1][m1] << ") ? Si oui, tape Y. Sinon, tape N : ";
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {
                        T[i] = Matric[n1][m1];
                        i++;
                        Matric[n1][m1] = static_cast<char>((step + 2) + '0');
                    }

                    cout << "Vous êtes maintenant dans la case : " << Matric[n1][m1] << endl;
                }
            }

            do
            {
                cout << "t7eb tkamel ??  ken ey Y snn N : " << endl;
                cin >> rec;

                if (conYO)
                {
                    cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                }
            } while (conYO);

            if (rec == 'Y' || rec == 'y')
            {

                string kelma(T, i); // lena nekhdhou el klma

                for (int k = 0; k < i; k++)
                {
                    T[k] = ' ';
                }

                cout << "tu as le mot " << kelma << endl;

                CompMot("mehdi.txt", kelma, Score, i, niv+1);

                cout << "tu as un Score de  " << Score << endl;

                std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes
                step = 0;
                i = 0;
                remplirMatrice2(n, m, khrouj);
                afficheMatrice(n, m);
            }

            else
            {
                cout << "Mouvement impossible (hors de la matrice).\n";
            }
            break;

        case 8: // Diagonale Bas-Droite
            if (n1 + 1 < n && m1 + 1 < m && Matric[n1 + 1][m1 + 1] != '*')
            {
                if (BD)
                {
                    cout << "Vous avez choisi de descendre en diagonale (Bas-Droite).\nMais il y a un mur.\n";
                }
                else
                {
                    n1 += 1;
                    m1 += 1;
                    step++;

                    do
                    {
                        cout << "Tu veux prendre la valeur (" << Matric[n1][m1] << ") ? Si oui, tape Y. Sinon, tape N : ";
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {
                        T[i] = Matric[n1][m1];
                        i++;
                        Matric[n1][m1] = static_cast<char>((step + 2) + '0');
                    }

                    cout << "Vous êtes maintenant dans la case : " << Matric[n1][m1] << endl;

                    do
                    {
                        cout << "t7eb tkamel ??  ken ey Y snn N : " << endl;
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {

                        string kelma(T, i); // lena nekhdhou el klma

                        for (int k = 0; k < i; k++)
                        {
                            T[k] = ' ';
                        }
                        cout << "tu as le mot " << kelma << endl;

                        CompMot("mehdi.txt", kelma, Score, i, niv+1);

                        cout << "tu as un Score de  " << Score << endl;

                        std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes
                        step = 0;
                        i = 0;
                        remplirMatrice2(n, m, khrouj);
                        afficheMatrice(n, m);
                    }
                }
            }
            else if (Matric[n1 + 1][m1 + 1] == '*')
            {
                n1 += 1;
                m1 += 1;
                cout << "finn";
            }
            else
            {
                cout << "Mouvement impossible (hors de la matrice).\n";
            }
            break;

        default:
            cout << "Aucun mouvement valide sélectionné.\n";
            break;
        }

        afficheTab1(T, mac);

        if (Matric[n1][m1] == '*')
        {

            string kelma(T, i); // lena nekhdhou el klma

            cout << "tu as le mot " << kelma << endl;

            CompMot("mehdi.txt", kelma, Score, i, niv+1);

            cout << "tu as un Score de  " << Score << endl;
            i = 222;
            std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes

            // lezzem lena bch najmou nokhrjou mel while w najmou narfou kober el kelma
        }
    }
    // lena lezem n3abiw aka les 2 avec des lettres
}

#endif