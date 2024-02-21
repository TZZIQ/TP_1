/****************************************************************************************
    Auteur  : Ilyasse Qbibi et Daniel Zoughaib
    Date    : 24 janvier 2024
    Session : H2024

    Ce module contient les appels de fonction de decodage en boucle.
****************************************************************************************/

#include <stdlib.h>
#include "configuration.h"
#include "decodeur/a429.h"
#include "decodeur/utilitaire.h"
#include "udp/port_udp.h"







#if MODE_APPLICATION
int main(void)
{
    ///declaration et initalisation des variables locales
    int valeur_recue = 0, taille_recue = 0, valeur_precedente = 0;
    afficher_entete_decodeur();
    ///initalise le port lie au concentrateur de donne et prend le id du port
    int id_port = initialiser_port_udp(55001);
    ///boucle infinie
    while(1)
        {
            ///la fonction ecrit le mot dans la memoire de l'addresse fournie en parametre
            recevoir_port_udp(id_port,&valeur_recue,32);
            ///pour ne pas afficher le meme mot plusieurs fois
            if(valeur_recue != valeur_precedente)
            {
                ///appel une fonction qui fait l'affichage du mot
                afficher_mot_a429(valeur_recue);
            }
            ///utilise par le if a la ligne 33
            valeur_precedente = valeur_recue;
        }
    return EXIT_SUCCESS;
}
#endif