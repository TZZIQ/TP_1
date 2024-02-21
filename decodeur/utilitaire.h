
/*
    afficher_heure

    Cette fonction permet de transformer un nombre de secondes en format hh:mm:ss(heure minutes secondes).

    Paramètres:
        - secodes : Le nombre de secondes comptees.

    Retour:
        - ne retourne rien mais fait un printf
*/
void afficher_heure(int nbr_secondes_recus);
/*
    decimale_a_octale

    Cette fonction permet convertir un nombre de base 10(decimale) en une base 8(octale).

    Paramètres:
        - nombre_base10 : le nombre decimal

    Retour:
        - la valeur de l'entier en base octale .
*/
unsigned int decimale_a_octale(unsigned int nombre_base10);
/*
    calculer_nb_bits_actifs

    Cette fonction permet de calculer le nombre de bits actifs (a 1) dans un entier non-signe de 32 bits.

    Paramètres:
        - valeur, l'entier qu'on veut analyser.

    Retour:
        - Le nombre de bits qui sont a 1
*/
unsigned int calculer_nb_bits_actifs(unsigned int valeur);
/*
    afficher_bits

    Cette fonction permet d'afficher les bits d'un entier non-signe de 32 bits.

    Paramètres:
        - valeur, l'entier qu'on veut analyser.
        - LSB, la position du bit avec le plus petit poid qu'on veut afficher.
        - MSB, la position du bit avec le plus grand poid qu'on veut afficher.

    Retour:
        - Rien mais fait un printf
*/
void afficher_bits(unsigned int valeur, unsigned int LSB, unsigned int MSB);