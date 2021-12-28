#include <stdio.h>
#include "store.h"
#include <string.h>

static store_t store = {0,0,0,0};

void store_add_def(char *fun_name, int line_number, char *inpname){ /* definicja funkcji */
    int i,j;
    store.def_counter++;
    for(i=0; i<store.fun_counter; i++){
        if(strcmp(store.fun_names[i],fun_name)==0){
            store.def_line[i]=line_number;
            return;
        }
    }
    /* jezeli tu jest teraz, to nie znalazlo takiej funkcji */
    if(store.fun_counter<MAX_FUN_NUMBER){/*sprawdzamy czy jeszcze mozemy dodac cos*/
        strcpy(store.fun_names[store.fun_counter],fun_name);
        store.def_line[store.fun_counter]=line_number; /*definicja tez bedzie tylko jedna*/
        store.fun_counter++;
    }else{
        printf("Braklo miejsca w tablicy\n");
        return;
    }
}

void store_add_proto(char *fun_name, int line_number, char *inpname){ /* prototyp funkcji */
    int i,j;
    store.proto_counter++; /* zakladam, ze ktos nie dodal kilku prototypow tej samej funkcji*/

    if(store.fun_counter<MAX_FUN_NUMBER){/*sprawdzamy czy jeszcze mozemy dodac cos*/
        strcpy(store.fun_names[store.fun_counter],fun_name);
        store.proto_line[store.fun_counter]=line_number; /*prototyp bedzie tylko jeden*/
        store.fun_counter++;
    }else{
        printf("Braklo miejsca w tablicy\n");
        return;
    }
}

void store_add_call(char *fun_name, int line_number, char *inpname){
    int i,j;
    store.call_counter++;
    for(i=0; i<store.fun_counter; i++){
        if(strcmp(store.fun_names[i],fun_name)==0){
            for(j=0;store.call_line[i][j]!=-1 && j<MAX_FUN_NUMBER;j++)
                ;
            if(store.call_line[i][j]==-1)
                store.call_line[i][j]=line_number;
            else{
                printf("Nie ma juz miejsca w tablicy\n");
                return;
            }
            return;
        }
    }
    /* jezeli tu jest teraz, to nie znalazlo takiej funkcji */
    if(store.fun_counter<MAX_FUN_NUMBER){/*sprawdzamy czy jeszcze mozemy dodac cos*/
        strcpy(store.fun_names[store.fun_counter],fun_name);
        store.call_line[store.fun_counter][0]=line_number; /* dajemu od "0", bo to jest pierwsze wywolanie*/
        store.fun_counter++;
    }else{
        printf("Braklo miejsca w tablicy\n");
        return;
    }
}
void store_init(){
    for(int i=0;i<MAX_FUN_NUMBER;i++){
        for(int j=0;j<MAX_FUN_NUMBER;j++){
            store.call_line[i][j]=-1; /*dajemy wszedzie -1 zeby zasygnalizowac ze tam nic nie ma*/
        }
        store.def_line[i]=-1;
        store.proto_line[i]=-1;
    }
}