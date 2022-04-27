#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    typedef struct
    {
        int hora;
        int minuto;
        int segundo;

    } horario;

    typedef struct
    {
        int dia;
        int mes;
        int ano;

    } data;

    typedef struct
    {
        char texto[50];
    } texto;

    struct comproisso
    {
        // leva para a struct data
        data data;

        //  leva para a struct horario
        horario horario;

        //  leva para a struct texto
        texto texto;
    } comp;

    comp.data.dia = 20;
    comp.data.mes = 3;
    comp.data.ano = 2003;

    comp.horario.hora = 23;
    comp.horario.minuto = 35;
    comp.horario.segundo = 30;

    strcpy(comp.texto.texto, "Preciso fazer tal coisa");

    printf("%i:%i:%i\n", comp.data.dia, comp.data.mes, comp.data.ano);
    printf("%i:%i:%i\n", comp.horario.hora, comp.horario.minuto, comp.horario.segundo);
    printf("%s", comp.texto.texto);

    return 0;
}