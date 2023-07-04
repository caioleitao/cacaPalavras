#include <stdio.h>
#define tamC 50
#define tamP 15
#define qtdP 10
typedef struct {
    char L, C;
} SENTIDO;
int main(){
    int i, j, k, iP, iD;
    char cacapalavras[tamC][tamC], palavra[qtdP][tamP], achei
        sentido[8][3]={"E", "SE", "S", "SW", "W", "NW", "N", "NE"};
    //char deslL[8] = {0,1,1,1,0,-1,-1,-1};
    //char deslC[8] = {1,1,0,-1,-1,-1,0,1};
    SENTIDO desl[8] = {0,1, 1,1, 1,0, 1,-1, 0,-1, -1,-1, -1,0, -1,1}
    for(iP=0;iP<qtdP;iP++)
        for(i=0;i<tamC && !achei; i++)
            for(j=0;j<tamC && !achei;j++)
                if(cacapalavras[i][j]==palavra[iP][0]) {
                    for(iD=0; iD<8 && !achei; iD++){
                        achei = 1; //  1 == true ou 0 == false
                        for(k =1; palavra[iP][k] != '\0' && achei==1; k++)
                            achei = (palavra[iP][k] == cacapalavras[i+k*desl[iD].L][j+k*desl[iD].C]);
                        if(achei==1)
                           printf("Achei %s na posicao (%d, %d), sentido a %s\n", palavra[iP], i+1, j+1, sentido[iD]);
                    }
                }
    return 0;
}
