#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 200

int main(){
    FILE * fp;
    FILE * lista;
    FILE * istruzioni;
    char selezione[12]="livello ",pos='@',s[N];
    char mat[N][N],comando;
    int livello,flag=0,vessillo=0,i,k,x,y,nmax;
    //selezione livello
    printf("-------LABIRINTO---------\nSelezionare il livello di difficolta'\n\n_______________________\n\n");
    lista=fopen("lista livelli","r" );
    if (lista==NULL){
        printf("ERRORE");
        return 1;
    }
    else{
        while (flag==0){
            fgets(s,N,lista);
            printf("%s",s);
            if(feof(lista)){
                flag++;
            }
        }
    }
    fclose(lista);
    flag=0;
    printf("\n\n_______________________\n\n\nDigitare il numero a sinistra nella lista\n");
    scanf("%d",&livello);
    if (livello==0){
        printf("\n\n");
        istruzioni=fopen("istruzioni","r" );
        if (istruzioni==NULL){
            printf("ERRORE");
            return 2;
        }
        else{
            while (flag==0){
                fgets(s,N,istruzioni);
            printf("%s",s);
            if(feof(istruzioni)){
                flag++;
            }
        }
    }
    fclose(istruzioni);
    printf("\n\n");
    flag=0;
    }
    selezione[8]=livello +48;
    //printf("%s\n",selezione);
    //printf("\n%d",strlen(selezione));
    fp=fopen(selezione,"r" );
    if (fp==NULL){
        printf("ERRORE");
        return -1;
    }
    else{
        for(i=0;i<N && flag==0;i++){
        //while (flag==0){
            fgets(mat[i],N,fp);
            printf("%s",mat[i]);
            if(feof(fp)){
                flag++;
                nmax=i;
            }
        }
    }
    fclose(fp);
    while(vessillo==0){
    flag=0;
    for (i=0;i<N && flag==0;i++){
        for(k=0;k<N && flag==0;k++){
            if(mat[i][k]==pos){
                flag++;
            }
        }
    }
    x=k;
    y=i;
    scanf("%*c%c",&comando);
    printf("%c\n",comando);
    if(comando=='d'){
        k++;
    }
    else{
        if(comando=='a'){
            k--;
        }
        else{
            if(comando=='w'){
                i--;
            }
            else{
                if(comando=='s'){
                    i++;
                }
                else{
                    printf("comando invalido\n");
                }
            }
        }
    }
    if(mat[i-1][k-1]==' '){
        mat[y-1][x-1]=' ';
        x=k;
        y=i;
        mat[y-1][x-1]=pos;
    }
    else{
        if(mat[i-1][k-1]=='\n'){
            printf("HAI VINTO\n");
            vessillo++;
        }
        else{
            printf("mossa non consentita\n");
        }
    }
    for(i=0;i<nmax+1;i++){
        printf("%s",mat[i]);
    }
    }
    return 0;
}
