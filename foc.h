
#ifndef finc
#define finc
#include <windows.h>
#include <locale>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <cctype> // Pour isalpha()
#include <thread> // Pour std::this_thread::sleep_for
#include <chrono> // Pour std::chrono::seconds
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <ctime>
using namespace std;
vector<string> motsSelectionnes(100);
int x = 0, khrouj = 0;
int T1[10];
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
char Matric3[100][100];
char T[20];
int m, n, choix, n1, m1;

void recopiematrice(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            Matric3[i][j] = Matric[i][j];
        }
    }
}

void countdown(int seconds)
{
    for (int i = seconds; i > 0; i--)
    {
        cout << "Début du jeu dans " << i << "..." << endl;
#ifdef _WIN32
        Sleep(1000); // Pause de 1 seconde (Windows)
#endif
    }
    cout << "C'est parti ! Bonne chance !" << endl;
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
    cout << endl;
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
    recopiematrice(n, m);
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
    recopiematrice(n, m);
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
    recopiematrice(n, m);
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
    recopiematrice(n, m);
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

void afficheTab(char T[], int mac, int step)
{

    cout << "mot courant: ";
    for (int i = 0; i < mac; i++)
    {
        cout << T[i];
    }
    cout << endl;
    cout << "avec nb step= : " << step << endl;
}
void afficheTab1(char T[], int mac)
{

    cout << "mot courant: ";
    for (int i = 0; i < mac; i++)
    {
        cout << T[i];
    }
    cout << endl;
}

void CompMot1(const string &nomFichier, string verif, int &Score, int long1, int niveau)
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

            Score = Score + ((30 * niveau) + long1);
        }
    }

    fichier.close(); // Fermer le fichier
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

    cout << "le mot le plus long est :  " << atwelklema << "  avec un nombre de " << k << " characteres" << endl;
    if (niv1 == 1)
    {

        remplirMatriceN1(nbligne, m, motsSelectionnes, khrouj);
    }

    else if (niv1 == 2)
    {

        remplirMatriceN2(nbligne, m, motsSelectionnes, khrouj);
    }
    else
    {
        remplirMatriceN3(nbligne, m, motsSelectionnes, khrouj);
    }
}

struct Node
{
    int x, y, cost;
    bool operator>(const Node &other) const
    {
        return cost > other.cost;
    }
};

const int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

vector<pair<int, int>> trouverOccurrences(char lettre, int n, int m)
{
    vector<pair<int, int>> positions;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (Matric3[i][j] == lettre)
            {
                positions.push_back({i, j});
            }
        }
    }
    return positions;
}

vector<pair<int, int>> dijkstra(int startX, int startY, int endX, int endY, int n, int m)
{
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    vector<vector<pair<int, int>>> prev(n, vector<pair<int, int>>(m, {-1, -1}));

    pq.push({startX, startY, 0});
    dist[startX][startY] = 0;

    while (!pq.empty())
    {
        Node current = pq.top();
        pq.pop();
        int x = current.x, y = current.y, cost = current.cost;

        if (x == endX && y == endY)
            break;

        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && Matric3[nx][ny] != '1')
            {
                int newCost = cost + 1;
                if (newCost < dist[nx][ny])
                {
                    dist[nx][ny] = newCost;
                    prev[nx][ny] = {x, y};
                    pq.push({nx, ny, newCost});
                }
            }
        }
    }

    vector<pair<int, int>> path;
    for (int x = endX, y = endY; x != -1 && y != -1; tie(x, y) = prev[x][y])
    {
        path.push_back({x, y});
    }
    reverse(path.begin(), path.end());
    return path;
}

void direction(int n, int m, int n1, int m1, int max, int mloul, char loul, int niv)
{
    T[0] = loul;
    char rec, mot, pt;
    int j = 0, i = 0, step = 0, mac = 16, Score = 0, k = 0, t = 1, lon = 0, o = m1, p = n1;
    bool test = 0,vizita=0;
    vector<string> motsCorrespondants;
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

        if (i == 1 && vizita==0 )
        { 
            vizita=1;
            char c = Matric[p][o];

            for (string mot : motsSelectionnes)
            {
                if (mot[0] == c)
                {
                    test = 1;
                    motsCorrespondants.push_back(mot);
                }
                else
                    test = 0;
            }

            if (  test == 0)
            {
                cout << "Aucun mot trouvé avec la lettre " << c << endl;
            }

            else
            {
                string motChoisi = motsCorrespondants[0];
                vector<pair<int, int>> positions = {{p, o}};
                int i12 = 0;
                while (t < (motChoisi.length()))
                {
                    vector<pair<int, int>> positionsMot = trouverOccurrences(motChoisi[t], n, m);

                    if (positionsMot.empty())
                    {
                        cout << "Impossible de trouver un chemin." << endl;
                    }

                    vector<pair<int, int>> chemin = dijkstra(p, o, positionsMot[0].first, positionsMot[0].second, n, m);

                    if (chemin.empty())
                    {
                        cout << "Aucun chemin trouvé vers la lettre du mot." << endl;
                    }
                    else
                    {
                        cout << "Chemin trouvé :" << endl;
                        for (auto [x, y] : chemin)
                        {
                            // cout << "(" << x << ", " << y << ") ";
                            lon++;
                            p = x;
                            o = y;
                        }
                        Matric3[p][o] = 1;
                        lon--;
                        cout << endl;
                    }

                    t++;
                    T1[i12] = lon;
                    i12++;
                    lon = 0;
                }
                cout << "les cours path sont" << endl;
                for (int i = 0; i < i12; i++)
                {
                    cout << T1[i] << endl;
                }
            }
        }

        if (k == 0)
        {
            cout << "Vous etes actuellement à la position : " << "(" << n1 << "," << m1 << ")" << endl;
            afficheTab1(T, mac);
            k++;
        }
        cout << "Choisissez une option (entre 1 et 8) : " << endl;
        menu();
        afficheMatrice2(n, m + 1);
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
                    cout << "Vous êtes maintenant dans la case :  (" << n1 << "," << m1 << ")" << endl;

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

                        CompMot("mehdi.txt", kelma, Score, i, niv);

                        cout << "tu as un Score de  " << Score << endl;

                        /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes*/
                        vizita=0;
                        i = 0;
                        remplirMatrice2(n, m, khrouj);
                        step = 0;
                    }
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
                    cout << "Vous êtes maintenant dans la case :  (" << n1 << "," << m1 << ")" << endl;

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

                        CompMot("mehdi.txt", kelma, Score, i, niv);

                        cout << "tu as un Score de  " << Score << endl;

                        /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes*/
                        step = 0;
                        vizita=0;
                        i = 0;
                        remplirMatrice2(n, m, khrouj);
                    }
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

                    cout << "Vous êtes maintenant dans la case :  (" << n1 << "," << m1 << ")" << endl;
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

                    CompMot("mehdi.txt", kelma, Score, i, niv);

                    cout << "tu as un Score de  " << Score << endl;

                    /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes*/
                    step = 0;
                    vizita=0;
                    i = 0;
                    remplirMatrice2(n, m, khrouj);
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

                    cout << "Vous êtes maintenant dans la case :  (" << n1 << "," << m1 << ")" << endl;
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

                        CompMot("mehdi.txt", kelma, Score, i, niv);

                        cout << "tu as un Score de  " << Score << endl;

                        /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes*/
                        step = 0;
                        vizita=0;
                        i = 0;
                        remplirMatrice2(n, m, khrouj);
                    }
                }
            }
            else if (Matric[n1][m1 + 1] == '*')
            {

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

                    cout << "Vous êtes maintenant dans la case :  (" << n1 << "," << m1 << ")" << endl;
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

                    CompMot("mehdi.txt", kelma, Score, i, niv);

                    cout << "tu as un Score de  " << Score << endl;

                    /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes*/
                    step = 0;
                    vizita=0;
                    i = 0;
                    remplirMatrice2(n, m, khrouj);
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

                    cout << "Vous êtes maintenant dans la case :  (" << n1 << "," << m1 << ")" << endl;

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

                        CompMot("mehdi.txt", kelma, Score, i, niv);

                        cout << "tu as un Score de  " << Score << endl;

                        /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes*/
                        step = 0;
                        vizita=0;
                        i = 0;
                        remplirMatrice2(n, m, khrouj);
                    }
                }
            }
            else if (Matric[n1 - 1][m1 + 1] == '*')
            {
                n1 -= 1;
                m1 += 1;
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

                    cout << "Vous êtes maintenant dans la case :  (" << n1 << "," << m1 << ")" << endl;

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

                        CompMot("mehdi.txt", kelma, Score, i, niv);

                        cout << "tu as un Score de  " << Score << endl;

                        /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes*/
                        step = 0;
                        vizita=0;
                        i = 0;
                        remplirMatrice2(n, m, khrouj);
                    }
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

                    cout << "Vous êtes maintenant dans la case :  (" << n1 << "," << m1 << ")" << endl;

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

                        CompMot("mehdi.txt", kelma, Score, i, niv);

                        cout << "tu as un Score de  " << Score << endl;

                        /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes*/
                        step = 0;
                        vizita=0;
                        i = 0;
                        remplirMatrice2(n, m, khrouj);
                    }
                }
            }
            else if (Matric[n1 + 1][m1 + 1] == '*')
            {
                n1 += 1;
                m1 += 1;
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

        if (Matric[n1][m1] == '*')
        {

            string kelma(T, i); // lena nekhdhou el klma

            cout << "Victoire!" << endl;

            CompMot1("mehdi.txt", kelma, Score, i, niv);

            cout << "Score Final: " << Score << endl;
            i = 222;
            /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes*/

            // lezzem lena bch najmou nokhrjou mel while w najmou narfou kober el kelma
        }
    }
    // lena lezem n3abiw aka les 2 avec des lettres
}

#endif