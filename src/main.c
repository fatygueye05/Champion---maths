#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct
{
    char nom[50];
    int score;
    time_t date;
}Joueur  ;
int addition();
int Soustraction();
int multiplication();
int Tables_de_multiplication ();
int Division();
int nombre_mystere();
int comparaison();
void lire_fichier()
{
    FILE *fichier = fopen("resultats.txt", "r");
    char ligne[200];

    if (fichier != NULL)
    {
        while (fgets(ligne, 200, fichier) != NULL)
        {
            printf("%s", ligne);
        }

        fclose(fichier);
    }
    else
    {
        printf("Erreur ouverture fichier\n");
    }
}
void sauvegarder(char nom[50],
    int score )
{
    FILE *fichier = fopen("resultats.txt", "w");
    time_t date;

    if (fichier != NULL)
    {
         date = time(NULL);
        fprintf(fichier,  "Nom: %s | Score: %d | Date: %s",
                nom,
                score,
                ctime(&date));
        fclose(fichier);
        printf("Score sauvegarde\n");
    }

    else
    {
        printf("Erreur fichier\n");
    }

}
int main()
{
   int choix = -1;
    int point = 0;
    srand(time(NULL));
    char nom[50];
    point = charger_score(nom);
    printf("Entrez votre nom : ");
    scanf("%s", nom);
    printf("Score actuel : %d\n", point);
    while (choix != 0)

    {
        printf("\n1 : Addition\n");
        printf("2 : Soustraction\n");
        printf("3 : Multiplication\n");
        printf("4 : Tables des multiplications\n");
        printf("5 : Division\n");
        printf("6 : Nombre mystere\n");
        printf("7 : Comparaison\n");
        printf("8 : ecrire_fichier\n");
        printf("9 : Lire fichier\n");
        printf("0 : Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
            case 1:
                addition();
                point++;
                sauvegarder(nom, point);
                break;


            case 2:

   {   Soustraction();
       point++;
    sauvegarder(nom, point);

    break;
}


            case 3:

                 multiplication();
                 point++;
                 sauvegarder(nom, point);
                break;

            case 4:
               Tables_de_multiplication ();
               point++;
               sauvegarder(nom,point);


    break;


        case 5:


              Division ();
              point++;
              sauvegarder(nom,point);
    break;

        case 6:
              nombre_mystere();
              point++;
              sauvegarder(nom,point);

    break;

        case 7 :
            comparaison();
            point++;
            sauvegarder(nom,point);
        break;

        case 8:
 {
   sauvegarder(nom,point);
    break;

 }
      case 9:
    lire_fichier();
    break;
            case 0:
    {

                printf("Merci de votre visite ! \n");

                break;


            default:
                printf("Choix invalide\n");
        }



  }}
    return 0;}

int addition(){
              int a = rand() % 101;
              int b = rand() % 101;
              int reponse;
              int essais=0 ;
              int trouve=0 ;
    printf("Addition\n");
    printf("%d + %d = ?\n", a, b);

    while (essais < 3 && trouve == 0)
  {
    printf("Essai %d : ", essais + 1);
    scanf("%d", &reponse);

    if (reponse == a + b)
    {
        printf("Bravo !\n");
        trouve = 1;
    }
    else
    {
        printf("Faux !\n");
    }

    essais++;
}

if (trouve == 1)
{
    if (essais == 1)

    return 10;
    else if (essais == 2)
        return 5;
    else
        return 1;
}
else
  {
    printf("La bonne reponse est %d\n", a + b);

    return 0;
  }
}
      int Soustraction()
   {

    int a = rand() % 101;
    int b = rand() % 101;
    int reponse;
    int essais=0 ;
    int trouve=0 ;
    if (a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    printf("Soustraction\n");
    printf("%d - %d = ?\n", a, b);

      while (essais < 3 && trouve == 0)
  {
    printf("Essai %d : ", essais + 1);
    scanf("%d", &reponse);

    if (reponse == a - b)
    {
        printf("Bravo !\n");
        trouve = 1;
    }
    else
    {
        printf("Faux !\n");
    }

    essais++;
}

   if (trouve == 1)

    if (essais == 1)

    return 10;
    else if (essais == 2)
        return 5;
    else
        return 1;
    else
    {
        printf("Faux ! La bonne reponse est %d\n", a - b);
    }

   return 0;
   }


       int multiplication()

 {


    int a = rand() % 11;  // 0 à 10
    int b = rand() % 11;  // 0 à 10
    int reponse;
    int essais = 0;
    int trouve = 0;
    printf("Multiplication\n");
    printf("%d x %d = ?\n", a, b);
    while ( essais < 3 && trouve == 0)
    {
    printf("Essais %d: ", essais+1);
    scanf("%d", &reponse);
    if (reponse == a * b)
    {
        printf("Bravo !\n");
        trouve=1;
    }

   if (trouve == 1)
  {
    if (essais == 1)

    return 10;
    else if (essais == 2)
        return 5;
    else
        return 1;
  }
else


        printf("Faux ! La bonne reponse est %d\n", a * b);
        essais++;
  }
  return 0;
 }


     int Tables_de_multiplication()
{
    int n;
    int i;
    int total = 0;

    printf("Entrez la table : ");
    scanf("%d", &n);

    for (i = 1; i <= 10; i++)
    {
        int reponse;
        int essais = 0;
        int trouve = 0;

        printf("%d x %d = ?\n", n, i);

        while (essais < 3 && trouve == 0)
        {
            printf("Essai %d : ", essais + 1);
            scanf("%d", &reponse);

            if (reponse == n * i)
            {
                printf("Bravo !\n");
                trouve = 1;
            }
            else
            {
                printf("Faux !\n");
            }

            essais++;
        }

        if (trouve == 1)
        {
            if (essais == 1)
                total += 10;
            else if (essais == 2)
             total += 5;
            else
             total += 1;
        }
        else
        {
            printf("La bonne reponse est %d\n", n * i);
        }
    }

    if (total > 0)
        printf("Gagne ! Score total = %d\n", total);
    else
        printf("Perdu !\n");

    return total;
}

 int Division()
{
    int b = rand() % 10 + 1;    // 1 à 10 (évite 0)
    int resultat = rand() % 10 + 1;
     int a = b * resultat;
    int reponse;

    int essais = 0;
    int trouve = 0;

    printf("Division\n");
    printf("%d / %d = ?\n", a, b);

    while (essais < 3 && trouve == 0)
    {
        printf("Essai %d : ", essais + 1);
        scanf("%d", &reponse);

        if (reponse == resultat)
        {
            printf("Bravo !\n");
            trouve = 1;
        }
        else
        {
            printf("Faux !\n");
        }

        essais++;
    }

    if (trouve == 1)
    {
        if (essais == 1)
            return 10;
        else if (essais == 2)
         return 5;
        else
         return 1;
    }
    else
    {
        printf("La bonne reponse est %d\n", resultat);
        return 0;
    }
}
    int nombre_mystere()
{
    int nombre = rand() % 100 + 1;
    int reponse;
    int proposition;
    int essais = 0;

    printf("=== Nombre mystere ===\n");

    while (essais < 3)
    {
        printf("Devinez le nombre (1-100) : ");
        scanf("%d", &proposition);
        essais++;
        if (proposition ==nombre)
        {
             printf("Bravo !\n");
              if (essais == 1)
                return 10;
            else if (essais == 2)
                return 5;
            else
                return 1;
        }
        else if (proposition < nombre)
            printf("Plus grand !\n");
        else
            printf("Plus petit !\n");

    }
   printf("Perdu ! Le nombre etait %d\n", nombre);
    return 0
;
}

  int comparaison()
{
    int a = rand() % 100;
    int b = rand() % 100;
    int reponse;

    printf("=== Comparaison ===\n");
    printf("Lequel est plus grand ?\n");
    printf("1 : %d\n", a);
    printf("2 : %d\n", b);

    printf("Votre choix (1 ou 2) : ");
    scanf("%d", &reponse);

    if ((a > b && reponse == 1) || (b > a && reponse == 2))
    {
        printf("Bravo !\n");
        return 10;
    }
    else
    {
        printf("Faux !\n");
        return 0;
    }
}
  int charger_score()
{
    FILE *fichier = fopen("resultats.txt", "r");
    char nom[30];
    char date[50];
    int score ;

    if (fichier != NULL)
    {
        fscanf(fichier, "Nom: %[^|]| Score: %d | Date: %s",nom, &score, date);

        fclose(fichier);
    }

    return score;
}

