

#include "foc.h"

int main()
{

    
    do
{
     cout << "Donnez la taille de la matrice (n x m) : " <<  endl;
     cin >> n;
     cin >> m;

    if (n > 100 || m > 100)
    {
         cout << "Erreur : La taille de la matrice ne doit pas dépasser 100 x 100. Veuillez réessayer.\n";
    }
} while (n > 100 || m > 100);

remplirMatrice(n, m); // Remplit la matrice
afficheMatrice(n, m); // Affiche la matrice




int nb1 = combienDeUn(n, m); // Compte les '1' dans la matrice
cout << "Le nombre de '1' dans la matrice est : " << nb1 <<  endl;

do
{
     cout << "Donnez la position de départ (n1 et m1) : " <<  endl;
     cin >> n1;
     cin >> m1;

    if (n1 >= n || n1 < 0 || m1 >= m || m1 < 0 )
    {
         cout << "Erreur : La position de départ doit être dans les limites de la matrice. Veuillez réessayer.\n";
    }
    if (Matric[n1][m1] =='1'){
        cout << "opss il y a un mur"<<endl;
    }
} while (n1 >= n || n1 < 0 || m1 >= m || m1 < 0 || Matric[n1][m1] =='1');

cout << "Vous êtes actuellement à la position : " << Matric[n1][m1] <<  endl;

char abda = Matric[n1][m1]; // Sauvegarde la valeur actuelle de la case
Matric[n1][m1] = '2';       // Marque la position initiale dans la matrice
direction(n, m, n1, m1, 4/*ena lezem nhotou akber kelma fel txt*/, 1, abda); // Appelle la fonction de direction

return 0;

}