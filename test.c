/****************************************************************************************
    Auteur  : Ilyasse Qbibi et Daniel Zoughaib
    Date    : 24 janvier 2024
    Session : H2024

    Ce module contient ..-!!-..!.!-!-!..!..- du decodeur.
****************************************************************************************/


/// declaration des libraries utilisees dans le programme
#include <stdlib.h>
#include <stdio.h>
#include "configuration.h"
#include "decodeur/utilitaire.h"


/// defintion des constates


/// definition des fonctions
void afficher_entete_test();


/// le module est exectue uniquement en mode test
#if MODE_TEST


void afficher_heure_test()
{
    printf("afficher_heure_test\n\n\n");

    printf("la valeur d'entree est\t:%i\n", 0);
    printf("la valeur predite  est\t:00h00m00s\n");
    printf("la valeur obtenue  est\t:");
    afficher_heure(0);
    printf("\n\n");

    printf("la valeur d'entree est\t:%i\n", 59);
    printf("la valeur predite  est\t:00h00m59s\n");
    printf("la valeur obtenue  est\t:");
    afficher_heure(59);
    printf("\n\n");

    printf("la valeur d'entree est\t:%i\n", 61);
    printf("la valeur predite  est\t:00h01m01s\n");
    printf("la valeur obtenue  est\t:");
    afficher_heure(61);
    printf("\n\n");

    printf("la valeur d'entree est\t:%i\n", 3661);
    printf("la valeur predite  est\t:01h01m01s\n");
    printf("la valeur obtenue  est\t:");
    afficher_heure(3661);
    printf("\n\n");

    printf("la valeur d'entree est\t:%i\n", 32949);
    printf("la valeur predite  est\t:09h09m09s\n");
    printf("la valeur obtenue  est\t:");
    afficher_heure(32949);
    printf("\n\n");

    printf("la valeur d'entree est\t:%i\n", 86399 );
    printf("la valeur predite  est\t:23h59m59s\n");
    printf("la valeur obtenue  est\t:");
    afficher_heure(86399 );
    printf("\n\n");
}


void decimale_a_octale_test()
{
    printf("decimale_a_octale_test\n\n\n");

    printf("la valeur d'entree est\t:%i\n", 1);
    printf("la valeur predite  est\t:%i\n", 1);
    printf("la valeur obtenue  est\t:%i\n\n", decimale_a_octale(1));

    printf("la valeur d'entree est\t:%i\n", 8);
    printf("la valeur predite  est\t:%i\n", 10);
    printf("la valeur obtenue  est\t:%i\n\n", decimale_a_octale(8));

    printf("la valeur d'entree est\t:%i\n", 15);
    printf("la valeur predite  est\t:%i\n", 17);
    printf("la valeur obtenue  est\t:%i\n\n", decimale_a_octale(15));

    printf("la valeur d'entree est\t:%i\n", 64);
    printf("la valeur predite  est\t:%i\n", 100);
    printf("la valeur obtenue  est\t:%i\n\n", decimale_a_octale(64));

    printf("la valeur d'entree est\t:%i\n", 104);
    printf("la valeur predite  est\t:%i\n", 150);
    printf("la valeur obtenue  est\t:%i\n\n", decimale_a_octale(104));

    printf("la valeur d'entree est\t:%i\n", 209);
    printf("la valeur predite  est\t:%i\n", 321);
    printf("la valeur obtenue  est\t:%i\n\n", decimale_a_octale(209));
}


void calculer_nb_bits_actifs_test()
{
    printf("calculer_nb_bits_actifs_test\n\n\n");

    printf("la valeur d'entree est\t:0x%08x\n", 0x00000000);
    printf("la valeur predite  est\t:%i\n", 0);
    printf("la valeur obtenue  est\t:%i\n\n", calculer_nb_bits_actifs(0x00000000));

    printf("la valeur d'entree est\t:0x%08x\n", 0x00000001);
    printf("la valeur predite  est\t:%i\n", 1);
    printf("la valeur obtenue  est\t:%i\n\n", calculer_nb_bits_actifs(0x00000001));

    printf("la valeur d'entree est\t:0x%08x\n", 0x80000000);
    printf("la valeur predite  est\t:%i\n", 1);
    printf("la valeur obtenue  est\t:%i\n\n", calculer_nb_bits_actifs(0x80000000));

    printf("la valeur d'entree est\t:0x%08x\n", 0x12345678);
    printf("la valeur predite  est\t:%i\n", 13);
    printf("la valeur obtenue  est\t:%i\n\n", calculer_nb_bits_actifs(0x12345678));

    printf("la valeur d'entree est\t:0x%08x\n", 0xFFFFFFFF);
    printf("la valeur predite  est\t:%i\n", 32);
    printf("la valeur obtenue  est\t:%i\n\n", calculer_nb_bits_actifs(0xFFFFFFFF));
}


void afficher_bits_test()
{
    printf("afficher_bits_test\n\n\n");

    printf("la valeur d'entree est\t:0x%08x\n", 0x12345678);
    printf("le bit de depart est\t:%i\n", 0);
    printf("le bit de fin est\t:%i\n", 31);
    printf("la valeur predite  est\t:(0x12345678) : 0001 0010 0011 0100 0101 0110 0111 1000\n");
    printf("la valeur obtenue  est\t:");
    afficher_bits(0x12345678,0,31);
    printf("\n\n");

    printf("la valeur d'entree est\t:0x%08x\n", 0x9ABCDEF0);
    printf("le bit de depart est\t:%i\n", 0);
    printf("le bit de fin est\t:%i\n", 31);
    printf("la valeur predite  est\t:(0x9ABCDEF0) : 1001 1010 1011 1100 1101 1110 1111 0000\n");
    printf("la valeur obtenue  est\t:");
    afficher_bits(0x9ABCDEF0,0,31);
    printf("\n\n");

    printf("la valeur d'entree est\t:0x%08x\n", 0xA3CF8643);
    printf("le bit de depart est\t:%i\n", 4);
    printf("le bit de fin est\t:%i\n", 15);
    printf("la valeur predite  est\t:(0xA3CF8643) : 1000 0110 0100\n");
    printf("la valeur obtenue  est\t:");
    afficher_bits(0xA3CF8643,4,15);
    printf("\n\n");

    printf("la valeur d'entree est\t:0x%08x\n", 0xA3CF8643);
    printf("le bit de depart est\t:%i\n", 31);
    printf("le bit de fin est\t:%i\n", 31);
    printf("la valeur predite  est\t:(0xA3CF8643) : 1\n");
    printf("la valeur obtenue  est\t:");
    afficher_bits(0xA3CF8643,31,31);
    printf("\n\n");

    printf("la valeur d'entree est\t:0x%08x\n", 0xA3CF8643);
    printf("le bit de depart est\t:%i\n", 0);
    printf("le bit de fin est\t:%i\n", 0);
    printf("la valeur predite  est\t:(0xA3CF8643) : 1\n");
    printf("la valeur obtenue  est\t:");
    afficher_bits(0xA3CF8643,0,0);
    printf("\n\n");

}

int main(void)
{
    printf("/************************************************\n");
    printf("* DECODEUR ARINC-429 :: Mode Test\n*\n");
    printf("* Auteur \t: Ilyasse Qbibi et Daniel Zoughaib\n");
    printf("* Session \t: Hiver 2024\n");
    printf("*\n/************************************************\n");
    afficher_bits_test();
    return EXIT_SUCCESS;
}
#endif