#include <stdio.h>
#include <stdlib.h>

//Type enregistrement pour les deplacements
typedef struct tJeton{

    int nX;
    int nY;

}tJeton;

void initialisation_tab(int tableau[5][5],tJeton cpt_pos);
void affichage_tab(int tableau[5][5]);
void placer_nombre(int tableau[5][5],int* cpt_nb,tJeton cpt_pos);
void deplacement(int tableau[5][5], tJeton* cpt_pos);
int verification (int tableau[5][5],tJeton cpt_pos);



int main(){
    int tableau[5][5];
    int cpt_nb=2;

    tJeton cpt_pos = { 1, 2 };
    initialisation_tab(tableau, cpt_pos);
    affichage_tab(tableau);
    for(size_t i=0; i<24; i++){             //Boucle pour remplire le carre etape par etape
        deplacement(tableau, &cpt_pos);
        placer_nombre(tableau,&cpt_nb,cpt_pos);
        affichage_tab(tableau);
    }
    return 0;
}
//---------------------------------------------------------------------------------------------------------------------------------------------
void initialisation_tab(int tableau[5][5],tJeton cpt_pos){      //fonction pour initialiser le tableau à 0 et placement du 1 initial
    for(size_t x=0; x<5; x++){
        for(size_t y=0; y<5; y++){
            tableau[x][y]=0;
        }
    }
    tableau[cpt_pos.nX][cpt_pos.nY]=1;
}
//---------------------------------------------------------------------------------------------------------------------------------------------
void affichage_tab(int tableau[5][5]){      //fonction pour afficher le tableau
    for(size_t cpt=0; cpt<5; cpt++){
        printf("%02d %02d %02d %02d %02d\n",tableau[cpt][0],tableau[cpt][1],tableau[cpt][2],tableau[cpt][3],tableau[cpt][4]);   //le %02d sert a ecrire avec deux caractère (on complete avec 0)
    }
    printf("\n");
}
//---------------------------------------------------------------------------------------------------------------------------------------------
void placer_nombre(int tableau[5][5],int* cpt_nb,tJeton cpt_pos){       //fonction pour placer le nombre dans la case pointée
    if (verification(tableau, cpt_pos) == 1){
        tableau[cpt_pos.nX][cpt_pos.nY]= *cpt_nb;
        (*cpt_nb)++;
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------------
void deplacement(int tableau[5][5], tJeton* cpt_pos){       //effectue le deplacement dans le tableau
    cpt_pos->nX = (cpt_pos->nX - 1);
    cpt_pos->nY = (cpt_pos->nY + 1);

    if(cpt_pos->nX<0){          //les if sont la pour gerer la sortie du tableau
        cpt_pos->nX= 4;
    }

    if(cpt_pos->nY<0){
        cpt_pos->nY= 4;
    }
    if(cpt_pos->nY>=5){
        cpt_pos->nY= 0;
    }

    if(verification(tableau,*cpt_pos)==0){      //la fonction verification est appellée pour savoir si l'on doit faire le déplacement nord/ouest ou non)
        cpt_pos->nX--;
        cpt_pos->nY--;
    }

    if(cpt_pos->nX<0){          //les if sont la pour gerer la sortie du tableau
        cpt_pos->nX= 4;
    }

    if(cpt_pos->nY<0){
        cpt_pos->nY= 4;
    }
    if(cpt_pos->nY>=5){
        cpt_pos->nY= 0;
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------------
int verification (int tableau[5][5],tJeton cpt_pos){        //verifie si la case pointée est libre ou non
    int test=0;

    if(tableau[cpt_pos.nX][cpt_pos.nY]== 0){
        test=1;
    }
    return test;
}
