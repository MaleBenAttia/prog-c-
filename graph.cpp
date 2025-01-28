
#include "foc.h"




int main() {
    do {
        cout << "Donnez la taille de la matrice (n x m) : " << endl;
        cin >> n;
        cin >> m;

        if (n > 100 || m > 100) {
            cout << "Erreur : La taille de la matrice ne doit pas dépasser 100 x 100. Veuillez réessayer.\n";
        }
    } while (n > 100 || m > 100);

    remplirMatrice(n, m); // Remplit la matrice
    afficheMatrice(n, m); // Affiche la matrice

    // Conversion de char[100][100] en vector<vector<char>>
    vector<vector<char>> matriceVector(n, vector<char>(m)); // Crée un vector de taille n x m

    // Copie des données de Matric dans matriceVector
    for (int i = 0; i < n; ++i) {

        for (int j = 0; j < m; ++j) {
            matriceVector[i][j] = Matric[i][j];
        }
    }

    // Convertir la matrice en graphe
    Graph g = matrixToGraph(matriceVector, n, m);

    // Afficher le contenu des cases du graphe
    for (int u = 0; u < g.V; ++u) {

        /*if (matriceVector[u / m][u % m]=='1')
        {
            cout<< "murrrrr";
             cout << endl;
        }

        else {*/

        cout << "Contenu de la case " << u << " (" << u / m << ", " << u % m << ") : " 
             << matriceVector[u / m][u % m] << " est connecte a : ";
        
        for (int v : g.adj[u]) {
            cout << "(" << v / m << ", " << v % m << ") : " << matriceVector[v / m][v % m] << "et ";
        }
        cout << endl;
       // }
    }

    return 0;
}
