#include <iostream>
#include <cstdlib>
#include <ctime>

// Déclaration de la matrice globale
char Matric[20][20];
int m,n;
// Fonction pour compter le nombre de '1' dans la matrice

int combienDeUn() {
    int count = 0; // Compteur initialisé à 0
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (Matric[i][j] == '1') {
                count++; // Incrémenter le compteur si le caractère est '1'
            }
        }
    }
    return count;
}

// Fonction pour afficher la matrice et la remplir avec des valeurs aléatoires
void remplirMatrice() {
    std::srand(std::time(0)); // Initialisation de la graine aléatoire
    int range = 30; // 26 lettres + 4 pour le chiffre '1'

    for (int i = 0; i < 6; i++) {
        bool hasOne = false; // Vérifie si la ligne contient au moins un '1'

        for (int j = 0; j < 6; j++) {
            int randomValue = std::rand() % range; // Génère une valeur entre 0 et 29

            // Génération des caractères aléatoires
            if (randomValue < 4) {
                Matric[i][j] = '1'; // Cas pour '1'
                hasOne = true;      // Marque qu'il y a un '1' dans cette ligne
            } else {
                Matric[i][j] = 'A' + (randomValue - 4); // Cas pour 'A' à 'Z'
            }
        }

        // Si la ligne n'a pas de '1', force l'ajout d'un '1'
        if (!hasOne) {
            int randomColumn = std::rand() % 6; // Choisir une colonne aléatoire
            Matric[i][randomColumn] = '1';
        }
    }
}

// Fonction pour afficher la matrice
void afficheMatrice(int n,int m) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            std::cout << " " << Matric[i][j] << " "; // Affichage du caractère
        }
        std::cout << std::endl; // Retour à la ligne après chaque ligne de la matrice
    }
}

void palyer ()


int main() {
    remplirMatrice(); // Remplit la matrice
    afficheMatrice(20,20); // Affiche la matrice

    int m = combienDeUn(); // Compte les '1' dans la matrice
    std::cout << "Le nombre de '1' est : " << m << std::endl;

    return 0;
}

