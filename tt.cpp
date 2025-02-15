#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <ctime>

using namespace std;

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

char Matric[100][100];
char Matric1[100][100];
char  Matric3[100][100];

void recopiematrice(int n,int m){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            Matric3[i][j]= Matric[i][j];
        }
    } }


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
    recopiematrice(n,m);
}
int main()
{
   int T1[10]={0,0,0,0,0,0,0,0};
    int n = 7, m = 7, khrouj, lon = 0, t = 1;
    vector<string> motsSelectionnes = {"MALEK", "ION", "LE"};
    remplirMatriceN3(n, m, motsSelectionnes, khrouj);

    cout << "Matrice principale :" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << Matric[i][j] << " ";
        }
        cout << endl;
    }

    int p, o;
    cout << "Entrer une position (ligne colonne) : ";
    cin >> p >> o;

    if (p < 0 || p >= n || o < 0 || o >= m)
    {
        cout << "Position invalide." << endl;
        return 0;
    }

    char c = Matric[p][o];
    vector<string> motsCorrespondants;
    for (string mot : motsSelectionnes)
    {
        if (mot[0] == c)
        {

            motsCorrespondants.push_back(mot);
        }
    }

    if (motsCorrespondants.empty())
    {
        cout << "Aucun mot trouvé avec la lettre " << c << endl;
        return 0;
    }

    else
    {
        string motChoisi = motsCorrespondants[0];
        vector<pair<int, int>> positions = {{p, o}};
        int i12=0;
         while (t < (motChoisi.length()))
         {
            vector<pair<int, int>> positionsMot = trouverOccurrences(motChoisi[t], n, m);

            if (positionsMot.empty())
            {
                cout << "Impossible de trouver un chemin." << endl;
                return 0;
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
                    p=x;
                    o=y;
                }
                Matric3[p][o]=1;
                lon--;
                cout << endl;
            }
           
            t++;
            T1[i12]=lon;
            i12++;
            lon=0;
        }
cout<<"les cours path sont"<<endl;
        for(int i=0;i<i12;i++){
            cout<< T1[i]<<endl;
            
        }
    }
    return 0;
}
