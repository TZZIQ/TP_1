/****************************************************************************************
    Auteur  : Ilyasse Qbibi et Daniel Zoughaib
    Date    : 24 janvier 2024
    Session : H2024

    Ce module contient ..-!!-..!.!-!-!..!..- du decodeur.
****************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "configuration.h"
#include "decodeur/a429.h"
#include "decodeur/utilitaire.h"
#include "udp/port_udp.h"

void afficher_mot_a4299(unsigned int mot);
void afficher_mot_a4299(unsigned int mot)
{

}

#if MODE_APPLICATION
int main(void)
{
    afficher_entete_decodeur();
    initialiser_port_udp(5501);
    recevoir_port_udp(5501,)
    ///pour que le cycle ne finit pas????
    main();
    return EXIT_SUCCESS;

}
#endif