#include <stdio.h>
#include <unistd.h> //sleep
#include <stdlib.h> //clscr

void genesis(int mundo[][7]){
    int i;
    int j;
    int z;
    for(z = 0; z < 6; z++){
        mundo[z][0] = 0;
        mundo[0][z] = 0;
        mundo[5][z] = 0;
        mundo[z][6] = 0;
    }
    for(i = 1; i < 5; i++){
        for(j = 1; j < 6; j++){
            scanf("%d",&mundo[i][j]);
        }
    }

}

void exibe(int mundo[][7]){
    int i;
    int j;
    for(i = 0; i < 6; i++){
        for(j = 0; j < 7; j++){
            printf("%d ",mundo[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}



//falta tratar caso das laterais
//conta quantos vizinhos vivos
int get_cia(int mundo[][7], int i, int j){
    int cia = 0;
    if( (i-1) >= 0 && (j-1) >= 0 ){ //tenho 8 vizinhos
        //linha de cima
        if(mundo[i-1][j-1]){
            cia++;
        }
        if(mundo[i-1][j]){
            cia++;
        }
        if(mundo[i-1][j+1]){
            cia++;
        }
        //linha de baixo
        if(mundo[i+1][j-1]){
            cia++;
        }
        if(mundo[i+1][j]){
            cia++;
        }
        if(mundo[i+1][j+1]){
            cia++;
        }
        //coluna de traz
        if(mundo[i][j-1]){
            cia++;
        }
        //coluna da frente
        if(mundo[i][j+1]){
            cia++;
        }
        return cia;
    }

}

//vivo e nenhum vizinho, eu morro
void solidao(int mundo[][7], int cia, int i, int j){
    if(mundo[i][j] == 0){
        return;
    }
    if(cia == 0){
        mundo[i][j] = 0;
        printf("Solidao (%d, %d)\n",i,j);
    }

}

//vivo e  > 3 vizinhos, eu morro
void bh(int mundo[][7], int cia, int i, int j){
    if(mundo[i][j] == 0){
        return;
    }
    if(cia == 0){
        mundo[i][j] = 0;
        printf("Superlotacao \n");
    }
}

void nascimento(int mundo[][7], int cia, int i, int j){
    if(mundo[i][j] == 0 && cia == 3){
        mundo[i][j] = 1;
        printf("Nasceu (%d,%d)\n",i,j);
    }
}

void geracao(int mundo[][7]){
    int i;
    int j;
    int cia = 0;
    for(i = 1; i < 5; i++){
        for(j = 1; j < 6; j++){
            if(i == 1 && j == 1){
                printf("CIA: %d\n",cia);
            }
            cia = get_cia(mundo, i, j);
            //regras da vida
            solidao(mundo, cia, i, j);
            bh(mundo, cia, i, j);
            nascimento(mundo,cia,i,j);
        }
    }
}

int main(){
    int apocalipse;
    int terra[6][7];
    genesis(terra);
    exibe(terra);
    for(apocalipse = 19; apocalipse < 20; apocalipse++){
        //system("clear");
        //sleep(1);
        geracao(terra);
        exibe(terra);
        printf("apocalipse: %d\n",apocalipse);
    }

    printf("Olá Mundo!\n");
}
