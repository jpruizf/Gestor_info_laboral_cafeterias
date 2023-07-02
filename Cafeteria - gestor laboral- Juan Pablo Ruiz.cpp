#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct{
    char nom[30];
    int cant_hs,dias;
    float valor_hs;
    float sueldo_semana;
    float sueldo_mes;
}info;

struct nodo
{
    info I;
    struct nodo * sig;
};
typedef struct nodo *puntero;
void crear(puntero &xp)
{
    xp=NULL;
}
void insertar_cafeteria(puntero &xp)
{
    puntero nuevo;
    int hs;
    printf("Ingrese cantidad de horas laborales >>");
    scanf("%d", &hs);
    while(hs != 0)
    {
        nuevo = (puntero)malloc(sizeof(struct nodo));
        printf("Ingese el nombre de la cafeteria >>");
        fflush(stdin);
        gets(nuevo->I.nom);
        nuevo->I.cant_hs = hs;
        printf("Ingrese el total de dias laborales >>");
        scanf("%d", &nuevo->I.dias);
        printf("Ingrese el valor de la hora de trabajo >>");
        scanf("%f", &nuevo->I.valor_hs);
        nuevo->sig=xp;
        xp=nuevo;
        printf("Ingrese cantidad de horas laborales (0 Para Finalizar)>>");
        scanf("%d", &hs);
    }


    return;
}
void calculo_semana(puntero xp)
{
    float sueldo_semana = 0.0;
    while(xp != NULL)
    {
        sueldo_semana = ((xp->I.valor_hs * xp->I.cant_hs) * xp->I.dias);
        xp->I.sueldo_semana = sueldo_semana;
        xp = xp->sig;
    }
    return;
}
void calculo_mes(puntero xp)
{
    while(xp != NULL){
        xp->I.sueldo_mes =+ xp->I.sueldo_semana;
        xp = xp->sig;
    }
    return;
}
void informe(puntero xp)
{
    printf("----<Datos registrados de las cafeterias cargadas>----\n");
    while(xp != NULL)
    {
        printf("NOMBRE DE LA CAFETERIA > \n");
        puts(xp->I.nom);
        printf("CANTIDAD DE HORAS LABORALES > {%d}\n",xp->I.cant_hs);
        printf("DIAS LABORALES > {%d}\n",xp->I.dias);
        printf("MESES > 1\n");
        printf("VALOR DE LA HORA LABORAL > {%2.2f}\n",xp->I.valor_hs);
        printf("SUELDO TOTAL POR SEMANA > {%2.2f}\n",xp->I.sueldo_semana);
        printf("SUELDO TOTAL POR MES >{%2.2f}\n",xp->I.sueldo_mes);
        if(xp->I.sueldo_mes > xp->sig->I.sueldo_mes)
        {
            printf("SEGUN LOS DATOS REGISTRADOS LA CAFETERIA MAS CONVENIENTE ES>>\n");
            puts(xp->I.nom);
        }
        xp= xp->sig;
    }
    return;
}
//Algorith principal
int main()
{
    puntero cabeza;
    crear(cabeza);
    insertar_cafeteria(cabeza);
    calculo_semana(cabeza);
    calculo_mes(cabeza);
    informe(cabeza);
}
