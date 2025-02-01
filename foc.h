
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
// Fonction pour compter le nombre de '1' dans la matrice

#define BLOQ(valeurVoisin) (valeurVoisin < '1' || valeurVoisin > '9')

int comp(string mot1, string mot2)
{

    if (mot1 == mot2)
    {
        cout << "Les mots sont identiques.\n";
        return 1;
    }

    else
    {
        cout << "Les mots sont différents.\n";
        return 0;
    }
}

// Structure pour représenter un graphe
struct Graph
{
    int V;                   // Nombre de nœuds
    vector<vector<int>> adj; // Liste d'adjacence
};

// Fonction pour convertir une matrice en graphe
Graph matrixToGraph(vector<vector<char>> &matrix, int n, int m)
{

    Graph g;
    g.V = n * m; // Nombre total de nœuds
    g.adj.resize(g.V);

    // Directions pour les déplacements (haut, bas, gauche, droite, diagonales)
    int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

    // Parcourir chaque cellule de la matrice
    for (int i = 0; i < n; ++i)
    {

        for (int j = 0; j < m; ++j)
        {

            int u = i * m + j;
            if (matrix[u / m][u % m] == '1')
            {
            }

            // Parcourir les voisins
            else
            {
                for (int k = 0; k < 8; ++k)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    // Vérifier si le voisin est dans les limites de la matrice
                    if (x >= 0 && x < n && y >= 0 && y < m)
                    {
                        // Vérifier si la case voisine est un obstacle
                        char valeurVoisin = matrix[x][y];
                        if (BLOQ(valeurVoisin))
                        {
                            int v = x * m + y;     // Identifiant unique du voisin
                            g.adj[u].push_back(v); // Ajouter une arête entre u et v
                        }
                    }
                }
            }
        }
    }

    return g;
}

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
// Fonction pour afficher la matrice et la remplir avec des valeurs aléatoires

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

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype> // Pour isalpha

using namespace std;

void remplirMatrice123(int n, int m, vector<string> motsSelectionnes, int &khrouj)
{
    int randomValue;
    srand(time(0)); // Initialisation de la graine aléatoire
    int range = 30; // 26 lettres (A-Z) + 4 pour le chiffre '1'

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

void remplirMatrice1(int n, int m)
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

void remplirMatrice2(int n, int m)
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
            if (connb)
            {
                if (randomValue < 4)
                {
                    Matric[i][j] = '1'; // Cas pour '1'
                    hasOne = true;      // Marque qu'il y a un '1' dans cette ligne
                }
                else
                {
                    Matric[i][j] = 'A' + (randomValue - 4); // Cas pour 'A' à 'Z'
                }

                // Si la ligne n'a pas de '1', force l'ajout d'un '1'
                if (!hasOne)
                {
                    int randomColumn = rand() % m; // Choisir une colonne aléatoire
                    Matric[i][randomColumn] = '1';
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

void lireEtAfficherMots(const string &nomFichier, string verif, int &Score)
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
            cout << "Mot lu exsiste : " << mot << endl;
            Score = +30;
        }

        else
        {
            cout << "NON  : " << mot << endl;
        }
    }

    fichier.close(); // Fermer le fichier
}

void direction(int n, int m, int n1, int m1, int max, int mloul, char loul)
{
    T[0] = loul;
    char rec, mot;
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

        cout << "Choisissez un mouvement (entre 1 et 8) : ";
        menu();
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
                }
            }
            else if (Matric[n1][m1 + 1] = '*')
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
            mac = 1111;
            string kelma(T, i); // lena nekhdhou el klma

            for (int k = 0; k < i; k++)
            {
                T[k] = ' ';
            }

            cout << "tu as le mot " << kelma << "    okkkkkkkkkkkkkkk " << endl;

            lireEtAfficherMots("mehdi.txt", kelma, Score);

            cout << "tu as un Score de  " << Score << "    okkkkkkkkkkkkkkk " << endl;

            std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes

            // lezzem lena bch najmou nokhrjou mel while w najmou narfou kober el kelma
        }
    }
    // lena lezem n3abiw aka les 2 avec des lettres

    afficheTab1(T, mac);
    i = 0;
    remplirMatrice2(n, m);
    afficheMatrice(n, m);

    T[0] = Matric[n1][m1];
    Matric[n1][m1] = '2';
}

#endif