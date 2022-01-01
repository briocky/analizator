
#define MAX_FUN_NUMBER 1000

typedef struct {
    int def_counter; /*liczniki*/
    int proto_counter;
    int call_counter;
    int fun_counter;/* pokazuje ilosc funkcji (roznych)w  programie*/

    char *fun_names[MAX_FUN_NUMBER]; /* nazwy funkcji w programie */

    int def_line[MAX_FUN_NUMBER]; /* kazdy element tej tablicy odpowiada za trzymanie informacji o linii w ktorej definicja funkcji wystapila */
    int proto_line[MAX_FUN_NUMBER]; /*analogicznie*/
    int call_line[MAX_FUN_NUMBER][MAX_FUN_NUMBER]; /*tu tablica 2wym, bo moze byc duzo wywolan danej funkcji */
}store_t;

void store_add_def(char *fun_name, int line_number, char *inpname);

void store_add_proto(char *fun_name, int line_number, char *inpname);

void store_add_call(char *fun_name, int line_number, char *inpname);

void store_init();

void wypisz();