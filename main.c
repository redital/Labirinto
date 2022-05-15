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

    //---------------------------------------------------------------------------------------------
    //---------------------------------Selezione livello-------------------------------------------
    //---------------------------------------------------------------------------------------------
    
    //Leggo il file con la lista dei livelli 
    //(si potrebbe pensare di bypassare questo passaggio leggendo direttamente la lista dei file nella directory)
    printf("-------LABIRINTO---------\nSelezionare il livello di difficolta'\n\n_______________________\n\n");
    lista=fopen("lista livelli","r" );
    if (lista==NULL){
        printf("ERRORE");
        return 1;
    }
    else{
        // si potrebbe scrivere una funzione print_file con questo codice
        while (flag==0){
            fgets(s,N,lista);
            printf("%s",s);
            if(feof(lista)){
                flag++;
            }
        }
    }
    fclose(lista);
    flag=0; // con la funzione questo passaggio non occorre

    //Aqcuisisco la scelta del giocatore
    printf("\n\n_______________________\n\n\nDigitare il numero a sinistra nella lista\n");
    scanf("%d",&livello);

    //Se il giocatore sceglie il tutorial, stampo una la spiegazione dei comandi di gioco
    if (livello==0){ 
        printf("\n\n");
        istruzioni=fopen("istruzioni","r" );
        if (istruzioni==NULL){
            printf("ERRORE");
            return 2;
        }
        else{
        // si potrebbe scrivere una funzione print_file con questo codice
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
        flag=0; // con la funzione questo passaggio non occorre
    }

    //---------------------------------------------------------------------------------------------
    //-----------------------------Stampo la mappa di gioco----------------------------------------
    //---------------------------------------------------------------------------------------------
    
    selezione[8]=livello +48;
    //printf("%s\n",selezione);
    //printf("\n%d",strlen(selezione));
    fp=fopen(selezione,"r" );
    if (fp==NULL){
        printf("ERRORE");
        return -1;
    }
    else{
        // non so, si potrebbe scrivere una funzione print_file con questo codice?
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

    //---------------------------------------------------------------------------------------------
    //-----------------------------------Gioco effettivo-------------------------------------------
    //---------------------------------------------------------------------------------------------
    
    //Cerco la posizione attuale del giocatore
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
    //Acquisisco il comando del giocatore (codifica WASD)
    scanf("%*c%c",&comando);
    printf("%c\n",comando);
    if(comando=='d'){//d=destra
        k++;
    }
    else{
        if(comando=='a'){//a=sinistra
            k--;
        }
        else{
            if(comando=='w'){//w=avanti
                i--;
            }
            else{
                if(comando=='s'){//s=indietro
                    i++;
                }
                else{
                    printf("comando invalido\n");
                }
            }
        }
    }
    
    if(mat[i-1][k-1]==' '){//se la nuova posizione è libera
        mat[y-1][x-1]=' ';//libero la posizione attuale del giocatore
        x=k;
        y=i;
        mat[y-1][x-1]=pos;//aggiorno la posizione del giocaotore
    }
    else{
        if(mat[i-1][k-1]=='\n'){//se esce dai bordi e trova una andata a capo, il giocatore è uscito dal labirito ed ha vinto
            printf("HAI VINTO\n");
            vessillo++;//si potrebbe sostituire con una return 0, cambia poco, dovrei comunuqe mettere un while(True) al posto di while(vessillo==0)
        }
        else{
            printf("mossa non consentita\n");//se la nuova posizione non è libera, la mossa non è valida
        }
    }
    //ristampo la mappa con la posizione del giocatore aggiornata
    for(i=0;i<nmax+1 && vessillo==0;i++){
        printf("%s",mat[i]);
    }
    }
    return 0;
}
