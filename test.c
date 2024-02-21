/****************************************************************************************
    Auteur  : Ilyasse Qbibi et Daniel Zoughaib
    Date    : 24 janvier 2024
    Session : H2024

    Ce module contient les tests du decodeur.
****************************************************************************************/


/// declaration des libraries utilisees dans le programme
#include <stdlib.h>
#include <stdio.h>
#include "configuration.h"
#include "decodeur/utilitaire.h"
#include "decodeur/a429.h"
#include "decodeur/icd.h"

void afficher_entete_test()
{

}


/// le module est exectue uniquement en mode test
#if MODE_TEST


afficher_entete_decodeur()
{
    printf("/************************************************\n");
    printf("* DECODEUR ARINC-429 :: Mode Test\n*\n");
    printf("* Auteur \t: Ilyasse Qbibi et Daniel Zoughaib\n");
    printf("* Session \t: Hiver 2024\n");
    printf("*\n/************************************************\n");
    printf("Mot ARINC-429 | Est corompu | Donnee\n");
    printf("--------------|-------------|-----------------------\n");
}

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

void decoder_mot_test()
{
    int etat_corupt = 0, num_mot = 0,donne_bcd1 = 0, donne_bcd2 = 0,donne_bcd3 = 0,donne_bcd4 = 0;
    double donne_bnr = 0;

    printf("decoder mot test\n\n\n");

    decoder_mot_a429(0x85D3029A, &etat_corupt,&num_mot,&donne_bnr,&donne_bcd1,&donne_bcd2,&donne_bcd3,&donne_bcd4);
    printf("La valeur d'entree est\t:0x%08x\n", 0x85D3029A);
    printf("Est corrompu : la valeur predite  est\t:%i\n", 0);
    printf("Est corrompu : la valeur obtenue  est\t:%i\n", etat_corupt);
    printf("Numero mot : la valeur predite  est\t:%i\n", 232);
    printf("Numero mot : la valeur obtenue  est\t:%i\n", num_mot);
    printf("Donne bnr : la valeur predite  est\t:DC\n");
    printf("Donne bnr : la valeur obtenue  est\t:%.06lf\n", donne_bnr);
    printf("Donne bcd1 : la valeur predite  est\t:%i\n", 2);
    printf("Donne bcd1 : la valeur obtenue  est\t:%i\n", donne_bcd1);
    printf("Donne bcd2 : la valeur predite  est\t:%i\n", 24);
    printf("Donne bcd2 : la valeur obtenue  est\t:%i\n", donne_bcd2);
    printf("Donne bcd3 : la valeur predite  est\t:%i\n", 20);
    printf("Donne bcd3 : la valeur obtenue  est\t:%i\n", donne_bcd3);
    printf("Donne bcd4 : la valeur predite  est\t:%i\n", 11);
    printf("Donne bcd4 : la valeur obtenue  est\t:%i\n\n\n", donne_bcd4);

    etat_corupt = 0, num_mot = 0,donne_bcd1 = 0, donne_bcd2 = 0,donne_bcd3 = 0,donne_bcd4 = 0;
    donne_bnr = 0;

    decoder_mot_a429(0x003C90B0, &etat_corupt,&num_mot,&donne_bnr,&donne_bcd1,&donne_bcd2,&donne_bcd3,&donne_bcd4);
    printf("La valeur d'entree est\t:0x%08x\n", 0x003C90B0);
    printf("Est corrompu : la valeur predite  est\t:%i\n", 0);
    printf("Est corrompu : la valeur obtenue  est\t:%i\n", etat_corupt);
    printf("Numero mot : la valeur predite  est\t:%i\n", 260);
    printf("Numero mot : la valeur obtenue  est\t:%i\n", num_mot);
    printf("Donne bnr : la valeur predite  est\t:DC\n");
    printf("Donne bnr : la valeur obtenue  est\t:%.06lf\n", donne_bnr);
    printf("Donne bcd1 : la valeur predite  est\t:%i\n", 16);
    printf("Donne bcd1 : la valeur obtenue  est\t:%i\n", donne_bcd1);
    printf("Donne bcd2 : la valeur predite  est\t:%i\n", 4);
    printf("Donne bcd2 : la valeur obtenue  est\t:%i\n", donne_bcd2);
    printf("Donne bcd3 : la valeur predite  est\t:%i\n", 15);
    printf("Donne bcd3 : la valeur obtenue  est\t:%i\n", donne_bcd3);
    printf("Donne bcd4 : la valeur predite  est\t:%i\n", 0);
    printf("Donne bcd4 : la valeur obtenue  est\t:%i\n\n\n", donne_bcd4);

    etat_corupt = 0, num_mot = 0,donne_bcd1 = 0, donne_bcd2 = 0,donne_bcd3 = 0,donne_bcd4 = 0;
    donne_bnr = 0;

    decoder_mot_a429(0x812EAF68, &etat_corupt,&num_mot,&donne_bnr,&donne_bcd1,&donne_bcd2,&donne_bcd3,&donne_bcd4);
    printf("La valeur d'entree est\t:0x%08x\n", 0x812EAF68);
    printf("Est corrompu : la valeur predite  est\t:%i\n", 0);
    printf("Est corrompu : la valeur obtenue  est\t:%i\n", etat_corupt);
    printf("Numero mot : la valeur predite  est\t:%i\n", 150);
    printf("Numero mot : la valeur obtenue  est\t:%i\n", num_mot);
    printf("Donne bnr : la valeur predite  est\t:%.06lf\n",77487.000000);
    printf("Donne bnr : la valeur obtenue  est\t:%.06lf\n", donne_bnr);
    printf("Donne bcd1 : la valeur predite  est\t:DC\n");
    printf("Donne bcd1 : la valeur obtenue  est\t:%i\n", donne_bcd1);
    printf("Donne bcd2 : la valeur predite  est\t:DC\n");
    printf("Donne bcd2 : la valeur obtenue  est\t:%i\n", donne_bcd2);
    printf("Donne bcd2 : la valeur predite  est\t:DC\n");
    printf("Donne bcd3 : la valeur obtenue  est\t:%i\n", donne_bcd3);
    printf("Donne bcd2 : la valeur predite  est\t:DC\n");
    printf("Donne bcd4 : la valeur obtenue  est\t:%i\n\n\n", donne_bcd4);

    etat_corupt = 0, num_mot = 0,donne_bcd1 = 0, donne_bcd2 = 0,donne_bcd3 = 0,donne_bcd4 = 0;
    donne_bnr = 0;

    decoder_mot_a429(0x83D2E3C8, &etat_corupt,&num_mot,&donne_bnr,&donne_bcd1,&donne_bcd2,&donne_bcd3,&donne_bcd4);
    printf("La valeur d'entree est\t:0x%08x\n", 0x83D2E3C8);
    printf("Est corrompu : la valeur predite  est\t:%i\n", 0);
    printf("Est corrompu : la valeur obtenue  est\t:%i\n", etat_corupt);
    printf("Numero mot : la valeur predite  est\t:%i\n", 310);
    printf("Numero mot : la valeur obtenue  est\t:%i\n", num_mot);
    printf("Donne bnr : la valeur predite  est\t:%.06lf\n",43.102340);
    printf("Donne bnr : la valeur obtenue  est\t:%.06lf\n", donne_bnr*RESOLUTION_MOT_LONGITUDE);
    printf("Donne bcd1 : la valeur predite  est\t:DC\n");
    printf("Donne bcd1 : la valeur obtenue  est\t:%i\n", donne_bcd1);
    printf("Donne bcd2 : la valeur predite  est\t:DC\n");
    printf("Donne bcd2 : la valeur obtenue  est\t:%i\n", donne_bcd2);
    printf("Donne bcd2 : la valeur predite  est\t:DC\n");
    printf("Donne bcd3 : la valeur obtenue  est\t:%i\n", donne_bcd3);
    printf("Donne bcd2 : la valeur predite  est\t:DC\n");
    printf("Donne bcd4 : la valeur obtenue  est\t:%i\n\n\n", donne_bcd4);

    etat_corupt = 0, num_mot = 0,donne_bcd1 = 0, donne_bcd2 = 0,donne_bcd3 = 0,donne_bcd4 = 0;
    donne_bnr = 0;

    decoder_mot_a429(0x00261AAA, &etat_corupt,&num_mot,&donne_bnr,&donne_bcd1,&donne_bcd2,&donne_bcd3,&donne_bcd4);
    printf("La valeur d'entree est\t:0x%08x\n", 0x00261AAA);
    printf("Est corrompu : la valeur predite  est\t:%i\n", 1);
    printf("Est corrompu : la valeur obtenue  est\t:%i\n", etat_corupt);
    printf("Numero mot : la valeur predite  est\t:%i\n", 252);
    printf("Numero mot : la valeur obtenue  est\t:%i\n", num_mot);
    printf("Donne bnr : la valeur predite  est\t:%.06lf\n",9754.000000);
    printf("Donne bnr : la valeur obtenue  est\t:%.06lf\n", donne_bnr);
    printf("Donne bcd1 : la valeur predite  est\t:DC\n");
    printf("Donne bcd1 : la valeur obtenue  est\t:%i\n", donne_bcd1);
    printf("Donne bcd2 : la valeur predite  est\t:DC\n");
    printf("Donne bcd2 : la valeur obtenue  est\t:%i\n", donne_bcd2);
    printf("Donne bcd2 : la valeur predite  est\t:DC\n");
    printf("Donne bcd3 : la valeur obtenue  est\t:%i\n", donne_bcd3);
    printf("Donne bcd2 : la valeur predite  est\t:DC\n");
    printf("Donne bcd4 : la valeur obtenue  est\t:%i\n\n\n", donne_bcd4);

}

void afficher_mot_a429_test()
{
    afficher_mot_a429(0x85D3029A);
    afficher_mot_a429(0x003C90B0);
    afficher_mot_a429(0x812EAF68);
    afficher_mot_a429(0x83D2E3C8);
    afficher_mot_a429(0x00261AAA);
}

int main(void)
{
    afficher_entete_decodeur();
    afficher_mot_a429_test();
    return EXIT_SUCCESS;
}
#endif
