#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    init_file(&file_normale); init_file(&file_urgente);
    FILE *f=fopen("journal_robot.txt","w"); if(f){fprintf(f,"======= Journal Robot =======\n"); fclose(f);}
    float duree_avancer = 5, vitesse_avancer = 1;
    float duree_tourner = 2, vitesse_tourner = 1;
    ajouter_commandes_initiales(duree_avancer,vitesse_avancer,duree_tourner,vitesse_tourner);
    printf("=== Simulation Robot Début ===\n");
    const int MAX_CYCLES=50; int cycle=0;
    Commande c_exec;
    while((!file_vide(&file_normale)||!file_vide(&file_urgente)) && cycle<MAX_CYCLES){
        if(capteur_detecte_obstacle()){
            printf("*** OBSTACLE DETECTE ***\n");
            gerer_obstacle(duree_tourner,vitesse_tourner,duree_avancer,vitesse_avancer);
        }

        if(prendre_prochaine_commande(&c_exec)){
            executer_commande(c_exec);
        }
        cycle++;
    }

    if(cycle>=MAX_CYCLES) printf("=== Simulation arrêtée après %d cycles ===\n",MAX_CYCLES);
    else printf("=== Simulation Robot Terminé ===\n");

    return 0;
}
