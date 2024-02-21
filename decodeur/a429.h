
/*
    afficher_entete_decodeur

    Cette fonction fait une entete sur l'interface avec une suite de printf.

    Paramètres:
        - Aucun

    Retour:
        - Aucun mais fait printf*/
void afficher_entete_decodeur();

/*
    decoder_mot_a429

    Cette fonction decode le un entier non signe qui represente un mot recus depuis le port udp.

    Paramètres:
        - mot           : L'entier non signe a evaluer.
        - *etat_corrupt    : Pointeur vers la donne qui contient l'etat de corruption.
        - *num_mot      : Pointeur vers la donne qui contient le numero du mot.
        - *donne_BNR    : Pointeur vers la donne qui contient la valeur du message sous format BNR.
        - *donne_BCD1    : Pointeur vers la donne qui contient la valeur du entier 1 du message sous format BCD.
        - *donne_BCD2    : Pointeur vers la donne qui contient la valeur du entier 2 du message sous format BCD.
        - *donne_BCD3    : Pointeur vers la donne qui contient la valeur du entier 3 du message sous format BCD.
        - *donne_BCD4    : Pointeur vers la donne qui contient la valeur du entier 4 du message sous format BCD.

    Retour:
        - Rien mais fait des ecritures dans les variables avec leurs adresses memoires en parametres*/
void decoder_mot_a429(unsigned int mot,int *etat_corupt,int *num_mot, double *donne_BNR,
                      int *donne_BCD1,int *donne_BCD2,int *donne_BCD3,int *donne_BCD4);
/*
    afficher_mot_a429

    Cette fonction affiche les valeurs decode par la fonction decoder_mot_a429.

    Paramètres:
        - mot : valeure a analyser (valeure recue par le main qui provient du concentrateur)

    Retour:
        - Aucun mais fait des printf*/
void afficher_mot_a429(unsigned int mot);