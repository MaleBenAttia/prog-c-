#include <iostream>
#include <cstdlib>
#include <ctime>
#define conYO (rec != 'Y' && rec != 'y' && rec != 'N' && rec != 'n')
// Déclaration de la matrice globale
char Matric[100][100];
char T[20];
int m, n, choix, n1, m1;
// Fonction pour compter le nombre de '1' dans la matrice

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

    std::cout << "\n--- Menu de déplacement ---\n";
    std::cout << "1. Haut\n";
    std::cout << "2. Bas\n";
    std::cout << "3. Gauche\n";
    std::cout << "4. Droite\n";
    std::cout << "5. Diagonale Haut-Gauche\n";
    std::cout << "6. Diagonale Haut-Droite\n";
    std::cout << "7. Diagonale Bas-Gauche\n";
    std::cout << "8. Diagonale Bas-Droite\n";
    std::cout << "Choisissez une option (1-8): " << std::endl;
}
// Fonction pour afficher la matrice et la remplir avec des valeurs aléatoires
void remplirMatrice(int n, int m)
{

    std::srand(std::time(0)); // Initialisation de la graine aléatoire
    int range = 30;           // 26 lettres + 4 pour le chiffre '1'

    for (int i = 0; i < n; i++)
    {
        bool hasOne = false; // Vérifie si la ligne contient au moins un '1'

        for (int j = 0; j < m; j++)
        {
            int randomValue = std::rand() % range; // Génère une valeur entre 0 et 29

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
            int randomColumn = std::rand() % 6; // Choisir une colonne aléatoire
            Matric[i][randomColumn] = '1';
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
            std::cout << " " << Matric[i][j] << " "; // Affichage du caractère
        }
        std::cout << std::endl; // Retour à la ligne après chaque ligne de la matrice
    }
}

void afficheTab(char T[],int mac,int step){

 std::cout << "tu as recuperer le mot : ";
    for (int i = 0; i < mac; i++)
    {
        std::cout << T[i];
    }
     std::cout << std::endl ;
    std::cout << "avec nb step= : " << step << std::endl ;


}
void direction(int n, int m, int n1, int m1, int max,int mloul,char loul)
{
    char rec;
    T[0]=loul;
    int i = mloul;
    int step= 0;
    int mac=6;
    while (i < mac)
    {
        std::cout << "Choisissez un mouvement (entre 1 et 8) : ";
        menu();
        afficheMatrice(n, m);
        afficheTab(T,mac,step);
        std::cin >> choix;

        // Validation de l'entrée (entre 1 et 8)
        while (choix < 1 || choix > 8)
        {
            std::cout << "Oups ! Veuillez entrer une valeur entre 1 et 8 : ";
            menu();
            afficheMatrice(n, m);
            std::cin >> choix;
        }
        // Gestion des choix avec switch

        // Gestion des choix de mouvement
switch (choix)
{
    case 1: // Haut
        if (n1 - 1 >= 0)
        {
            if (Matric[n1 - 1][m1] == '1')
            {
                std::cout << "Vous avez choisi de monter (Haut).\nMais il y a un mur.\n";
            }
            else
            {
                n1 -= 1; 
                step++;

                do
                {
                    std::cout << "Tu veux prendre la valeur (" << Matric[n1][m1] << ") ? Si oui, tape Y. Sinon, tape N : ";
                    std::cin >> rec;

                    if (conYO)
                    {
                        std::cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                    }
                } while (conYO);

                if (rec == 'Y' || rec == 'y')
                {
                    T[i] = Matric[n1][m1];
                    i++;
                }

                std::cout << "Vous êtes maintenant dans la case : " << Matric[n1][m1] << std::endl;
            }
        }
        else
        {
            std::cout << "Mouvement impossible (hors de la matrice).\n";
        }
        break;

    case 2: // Bas
        if (n1 + 1 < n)
        {
            if (Matric[n1 + 1][m1] == '1')
            {
                std::cout << "Vous avez choisi de descendre (Bas).\nMais il y a un mur.\n";
            }
            else
            {
                n1 += 1;
                step++;

                do
                {
                    std::cout << "Tu veux prendre la valeur (" << Matric[n1][m1] << ") ? Si oui, tape Y. Sinon, tape N : ";
                    std::cin >> rec;

                    if (conYO)
                    {
                        std::cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                    }
                } while (conYO);

                if (rec == 'Y' || rec == 'y')
                {
                    T[i] = Matric[n1][m1];
                    i++;
                }

                std::cout << "Vous êtes maintenant dans la case : " << Matric[n1][m1] << std::endl;
            }
        }
        else
        {
            std::cout << "Mouvement impossible (hors de la matrice).\n";
        }
        break;

    case 3: // Gauche
        if (m1 - 1 >= 0)
        {
            if (Matric[n1][m1 - 1] == '1')
            {
                std::cout << "Vous avez choisi de bouger à gauche.\nMais il y a un mur.\n";
            }
            else
            {
                m1 -= 1;
                step++;

                do
                {
                    std::cout << "Tu veux prendre la valeur (" << Matric[n1][m1] << ") ? Si oui, tape Y. Sinon, tape N : ";
                    std::cin >> rec;

                    if (conYO)
                    {
                        std::cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                    }
                } while (conYO);

                if (rec == 'Y' || rec == 'y')
                {
                    T[i] = Matric[n1][m1];
                    i++;
                }

                std::cout << "Vous êtes maintenant dans la case : " << Matric[n1][m1] << std::endl;
            }
        }
        else
        {
            std::cout << "Mouvement impossible (hors de la matrice).\n";
        }
        break;

    case 4: // Droite
        if (m1 + 1 < m)
        {
            if (Matric[n1][m1 + 1] == '1')
            {
                std::cout << "Vous avez choisi de bouger à droite.\nMais il y a un mur.\n";
            }
            else
            {
                m1 += 1;
                step++;

                do
                {
                    std::cout << "Tu veux prendre la valeur (" << Matric[n1][m1] << ") ? Si oui, tape Y. Sinon, tape N : ";
                    std::cin >> rec;

                    if (conYO)
                    {
                        std::cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                    }
                } while (conYO);

                if (rec == 'Y' || rec == 'y')
                {
                    T[i] = Matric[n1][m1];
                    i++;
                }

                std::cout << "Vous êtes maintenant dans la case : " << Matric[n1][m1] << std::endl;
            }
        }
        else
        {
            std::cout << "Mouvement impossible (hors de la matrice).\n";
        }
        break;

    case 5: // Diagonale Haut-Gauche
        if (n1 - 1 >= 0 && m1 - 1 >= 0)
        {
            if (Matric[n1 - 1][m1 - 1] == '1')
            {
                std::cout << "Vous avez choisi de monter en diagonale (Haut-Gauche).\nMais il y a un mur.\n";
            }
            else
            {
                n1 -= 1;
                m1 -= 1;
                step++;

                do
                {
                    std::cout << "Tu veux prendre la valeur (" << Matric[n1][m1] << ") ? Si oui, tape Y. Sinon, tape N : ";
                    std::cin >> rec;

                    if (conYO)
                    {
                        std::cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                    }
                } while (conYO);

                if (rec == 'Y' || rec == 'y')
                {
                    T[i] = Matric[n1][m1];
                    i++;
                }

                std::cout << "Vous êtes maintenant dans la case : " << Matric[n1][m1] << std::endl;
            }
        }
        else
        {
            std::cout << "Mouvement impossible (hors de la matrice).\n";
        }
        break;

    case 6: // Diagonale Haut-Droite
        if (n1 - 1 >= 0 && m1 + 1 < m)
        {
            if (Matric[n1 - 1][m1 + 1] == '1')
            {
                std::cout << "Vous avez choisi de monter en diagonale (Haut-Droite).\nMais il y a un mur.\n";
            }
            else
            {
                n1 -= 1;
                m1 += 1;
                step++;

                do
                {
                    std::cout << "Tu veux prendre la valeur (" << Matric[n1][m1] << ") ? Si oui, tape Y. Sinon, tape N : ";
                    std::cin >> rec;

                    if (conYO)
                    {
                        std::cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                    }
                } while (conYO);

                if (rec == 'Y' || rec == 'y')
                {
                    T[i] = Matric[n1][m1];
                    i++;
                }

                std::cout << "Vous êtes maintenant dans la case : " << Matric[n1][m1] << std::endl;
            }
        }
        else
        {
            std::cout << "Mouvement impossible (hors de la matrice).\n";
        }
        break;

    case 7: // Diagonale Bas-Gauche
        if (n1 + 1 < n && m1 - 1 >= 0)
        {
            if (Matric[n1 + 1][m1 - 1] == '1')
            {
                std::cout << "Vous avez choisi de descendre en diagonale (Bas-Gauche).\nMais il y a un mur.\n";
            }
            else
            {
                n1 += 1;
                m1 -= 1;
                step++;

                do
                {
                    std::cout << "Tu veux prendre la valeur (" << Matric[n1][m1] << ") ? Si oui, tape Y. Sinon, tape N : ";
                    std::cin >> rec;

                    if (conYO)
                    {
                        std::cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                    }
                } while (conYO);

                if (rec == 'Y' || rec == 'y')
                {
                    T[i] = Matric[n1][m1];
                    i++;
                }

                std::cout << "Vous êtes maintenant dans la case : " << Matric[n1][m1] << std::endl;
            }
        }
        else
        {
            std::cout << "Mouvement impossible (hors de la matrice).\n";
        }
        break;

    case 8: // Diagonale Bas-Droite
        if (n1 + 1 < n && m1 + 1 < m)
        {
            if (Matric[n1 + 1][m1 + 1] == '1')
            {
                std::cout << "Vous avez choisi de descendre en diagonale (Bas-Droite).\nMais il y a un mur.\n";
            }
            else
            {
                n1 += 1;
                m1 += 1;
                step++;

                do
                {
                    std::cout << "Tu veux prendre la valeur (" << Matric[n1][m1] << ") ? Si oui, tape Y. Sinon, tape N : ";
                    std::cin >> rec;

                    if (conYO)
                    {
                        std::cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                    }
                } while (conYO);

                if (rec == 'Y' || rec == 'y')
                {
                    T[i] = Matric[n1][m1];
                    i++;
                }

                std::cout << "Vous êtes maintenant dans la case : " << Matric[n1][m1] << std::endl;
            }
        }
        else
        {
            std::cout << "Mouvement impossible (hors de la matrice).\n";
        }
        break;

    default:
        std::cout << "Aucun mouvement valide sélectionné.\n";
        break;
}
    }
    std::cout << "tu as recuperer le mot : ";
    for (int i = 0; i < 6; i++)
    {
        std::cout << T[i];
    }
}

int main()
{
    do
    {
        std::cout << "doner la taile de matrice " << std::endl;

        std::cin >> n;
        std::cin >> m;
    } while (n > 100 | m > 100);

    remplirMatrice(n, m); // Remplit la matrice
    afficheMatrice(n, m); // Affiche la matrice

    int nb1 = combienDeUn(n, m); // Compte les '1' dans la matrice
    std::cout << "Le nombre de '1' est : " << nb1 << std::endl;

    do
    {
        std::cout << "doner le place pour commencer le n et m" << std::endl;
        std::cin >> n1;
        std::cin >> m1;
    } while (n1 > n || n1 < 0 || m1 > m || m1 < 0);
    std::cout << "tu es a la posistion: " << Matric[n1][m1] << std::endl;
char abda=Matric[n1][m1];
    direction(n, m, n1, m1, 4,1,abda);
    return 0;
}
