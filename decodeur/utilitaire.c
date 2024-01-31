/****************************************************************************************
    Auteur  : Ilyasse Qbibi et Daniel Zoughaib
    Date    : 24 janvier 2024
    Session : H2024

    Ce module contient ..-!!-..!.!-!-!..!..- du decodeur.
****************************************************************************************/


/// declaration des libraries utilisees dans le programme
#include <stdlib.h>
#include <stdio.h>


/// defintion des constates



/// la fonction affiche le nombre de seconde a l'entree sous format hh:mm:ss
void afficher_heure(int nbr_secondes_recus)
{
    int heure = nbr_secondes_recus/3600;
    int min  = ((nbr_secondes_recus)-(heure * 3600)) / 60;
    int seconde = ((nbr_secondes_recus)-(heure * 3600)-(min*60));
    printf("%02ih%02im%02is\n",heure,min,seconde);
}


///transforme un nombre exprime en base decimale vers une base octale
unsigned int decimale_a_octale(unsigned int nombre_base10)
{
    unsigned int facteur = 1,reste = 0, nombre_base8 = 0;
    ///On calcul l'equivalent d'un nombre decimal en octale
    while(nombre_base10 != 0)
    {
        reste = nombre_base10 %8;
        nombre_base8 = nombre_base8 + (facteur * reste);
        nombre_base10 = (nombre_base10 - reste)/8;
        ///sert a avancer d'une case pour mettre le prochain chiffre
        facteur *= 10;
    }
    return nombre_base8;
}


///calcule le nombres de bits set a 1 dans un int de 32 bits
unsigned int calculer_nb_bits_actifs(unsigned int valeur)
{
      int bits_actif = 0;
      ///boucle qui passe a travers les 32 bits du int
      for(int i = 0; i < 32; i++)
      {
          ///sert a determiner si le LSB de valeur est a 1
          if(valeur & 0x00000001)
          {
            bits_actif++;
          }
          valeur >>= 1;
      }
      return bits_actif;
}

///affiche la valeurs des bits d'un entier non signe avec une plage variable
void afficher_bits(unsigned int valeur, unsigned int LSB, unsigned int MSB)
{
    unsigned int masque = 0x80000000, resultat = 0;
    printf("(0x%08x) : ", valeur);
    ///boucle pour passer du MSB jusquau LSB
    for(int i = 31; i >= 0; i--)
    {
        resultat = (valeur & masque);
        resultat  >>= i;
        if (i <= MSB && i >= LSB)
        {
            printf("%x", resultat);
            ///sert a mettre des espaces entres 4 bits
            if((i) %4 == 0)
            {
                printf(" ");
            }

        }
        ///sert a "selectionner" les autres bits du la valeur a analyser
        masque >>= 1;
    }
}
