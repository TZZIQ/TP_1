/****************************************************************************************
    Auteur  : Ilyasse Qbibi et Daniel Zoughaib
    Date    : 24 janvier 2024
    Session : H2024

    Ce module contient les fonctions de decodage et affichage des mots.
****************************************************************************************/
#include <stdio.h>
#include "a429.h"
#include "utilitaire.h"
#include "icd.h"


void afficher_entete_decodeur()
{
    printf("/************************************************\n");
    printf("* DECODEUR ARINC-429\n*\n");
    printf("* Auteur \t: Ilyasse Qbibi et Daniel Zoughaib\n");
    printf("* Session \t: Hiver 2024\n");
    printf("*\n/************************************************\n\n\n");
    printf("Mot ARINC-429 | Est corompu | Donnee\n");
    printf("--------------|-------------|-----------------------\n");

}

void decoder_mot_a429(unsigned int mot,int *etat_corupt, int *num_mot, double *donne_BNR,
                      int *donne_BCD1,int *donne_BCD2,int *donne_BCD3,int *donne_BCD4)
{
    unsigned int p = 0, ss = 0, num_msg = 0;
    unsigned int entier1 = 0, entier2 = 0, entier3 = 0,entier4 = 0,reel = 0;

    ///sequence de tri de sections binaires du mot obtenu
    p = (mot & 0x80000000);
    p >>= 31;
    ss = (mot & 0x6000000);
    ss >>= 29;
    num_msg = (mot & 0x000000FF);
    entier4 = (mot & 0x1F800000);
    entier4 >>= 23;
    entier3 = (mot & 0x007C0000);
    entier3 >>= 18;
    entier2 = (mot & 0x0003E000);
    entier2 >>= 13;
    entier1 = (mot & 0x001F00);
    entier1 >>= 8;
    reel = (mot & 0x1FFFFF00);
    reel >>= 8;


    *num_mot = decimale_a_octale(num_msg);
    ///le mot est encode sous format BCD
    if (*num_mot == 232 || *num_mot == 255 || *num_mot == 260)
    {
        *donne_BCD1 = entier1;
        *donne_BCD2 = entier2;
        *donne_BCD3 = entier3;
        *donne_BCD4 = entier4;
    }
        ///le mot est encode sous format BNR
    else if (*num_mot == 150 || *num_mot == 252 || *num_mot == 310 || *num_mot == 311)
    {
        ///sert a donner un signe negatif au reel dependament de la valeur des bits ss
        if(ss)
            *donne_BNR *= -1;
        ///sert a incorporer de la resolution
        if(*num_mot == 252)
            *donne_BNR = reel*RESOLUTION_MOT_ALTITUDE;
        else if(*num_mot == 310)
            *donne_BNR = reel*RESOLUTION_MOT_LATITUDE;
        else if(*num_mot == 311)
            *donne_BNR = reel*RESOLUTION_MOT_LONGITUDE;
        else
            *donne_BNR = reel;

    }
    else
        printf("erreur du format du mot, numero mot pas dans registaire\n");
    ///sert a savoir si la donne recu est corompu
    if(calculer_nb_bits_actifs(mot) %2 == 0)
        *etat_corupt = 1;
    else
        *etat_corupt = 0;
}


void afficher_mot_a429(unsigned int mot)
{
    int etat_corupt = 0, num_mot = 0,donne_bcd1 = 0, donne_bcd2 = 0,donne_bcd3 = 0,donne_bcd4 = 0;
    double donne_bnr = 0;

    ///sert a appeler la fonction de decodage et donner les addresses des memoires pour l'affichage
    decoder_mot_a429(mot,&etat_corupt,&num_mot,&donne_bnr,&donne_bcd1,&donne_bcd2,&donne_bcd3,&donne_bcd4);
    ///sert a debuter l'affichage
    printf("0x%08x    |      %i      |",mot,etat_corupt);

    ///sert a afficher le message à afficher selon le mot qu'on recois.
    switch (num_mot) {
        case 150:
            printf("Heure du vol\t\t:");
            afficher_heure((int)donne_bnr);
            break;
        case 232:
            printf("Depart de l'aeroport\t:");
            printf("%c%c%c%c",donne_bcd1 + 'A',donne_bcd2 + 'A',donne_bcd3 + 'A',donne_bcd4 + 'A');
            break;
        case 252:
            printf("Altitude\t\t\t:");
            printf("%.01lf",donne_bnr);
            break;
        case 255:
            printf("Arrive a l'aeroport\t:");
            printf("%c%c%c%c",donne_bcd1 + 'A',donne_bcd2 + 'A',donne_bcd3 + 'A',donne_bcd4 + 'A');
            break;
        case 260:
            printf("Date du vol\t\t:");
            printf("%i/%i/%i",donne_bcd1,donne_bcd2,donne_bcd3);
            break;
        case 310:
            printf("Latitude\t\t\t:");
            printf("%.01lf",donne_bnr);
            break;
        case 311:
            printf("Longitude\t\t\t:");
            printf("%.01lf",donne_bnr);
            break;
    }
    printf("\n");
}