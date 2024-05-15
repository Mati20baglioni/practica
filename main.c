#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "time.h"
#include "string.h"
const int dim=10;
const int f=5;
const int c=7;

///PROTOTIPADOS:
int CargarPila(Pila*);
int EncontrarMenorPila(Pila*);
void OrdenamientoSeleccion(Pila*);
int SumarPilaPar(Pila*,int*);
int Suma_Pila(Pila*);
float PromedioPila(Pila*,int);
int CargarArreglo(int [dim]);
void MostrarArreglo(int [dim],int);
int CargarArregloLimitado(int [dim],int*);
void MostrarArregloB(int [dim],int );
int Capicua(int [dim],int );
int SumarArreglo(int [dim],int ,int*,int* );
int BuscarNumero(int [dim],int ,int* ,int );
void invertirArreglo(int [dim],int );
int EncontrarMenor(int [dim],int );
void LLenarMatrizEnteros(int [f][c]);
void MostrarMatrizEnteros(int [f][c]);


int main()
{
    int op,menor,validos,suma,flag,numero=0;
    float promedio;
    int contador,elementos;
    char control='s';
    Pila Uno;
    inicpila(&Uno);
    int A[dim];
    int B[dim];
    int dia,Pares,Impares,cantidad;
    int Matriz[f][c];
    char Strings[f][c];

    ///MENU
    printf("(1)Cargar y Mostrar Pila\n");
    printf("(2)Encontrar Menor en la Pila\n");
    printf("(3)Ordenamiento por seleccion\n");
    printf("(4)Sumar pares de la pila y devolver contador\n");
    printf("(5)Promedio Pila\n");
    printf("(6)Cargar Arreglo y Mostrarlo\n");
    printf("(7)Cargar Arreglo Limitado a 5 numeros max por dia por 7 dias max\n");
    printf("(8)Determinar si es Capicua\n");
    printf("(9)Sumar todos los elementos y devolver por punteros la cantidad de pares e impares cargados\n");
    printf("(10)Buscar numero en el Arreglo\n");
    printf("(11)Invertir Arreglo\n");
    printf("(12)Encontrar Menor\n");
    printf("(13)Cargar una Matriz de Enteros\n");
    printf("(14)Inicializar Matriz en Cero\n");
    printf("(15)Cargar Strings\n");
    printf("(16)Encontrar Posicion del Menor\n");
    printf("(17)Ordenamiento por Seleccion\n");
    printf("(18)  \n");
    printf("(19)  \n");
    printf("(20)  \n");

    do
    {
        printf("QUE FUNCION DESEA UTILIZAR:\n");
        scanf("%i",&op);
        switch(op)
            {
            case 1:
                contador=CargarPila(&Uno);
                printf("cantidad de elementos cargados:%i\n",contador);
                break;
            case 2:
                menor=EncontrarMenorPila(&Uno);
                printf("el menor elemento de la pila es:%i\n",menor);
                break;
            case 3:
                OrdenamientoSeleccion(&Uno);
                break;
            case 4:
                contador=0;
                suma=SumarPilaPar(&Uno,&contador);
                printf("la sumatorio de los elementos pares de la pila es:%i\n",suma);
                printf("el numero de elementos pares es:%i\n",contador);
                break;
            case 5:
                promedio=0;
                promedio=PromedioPila(&Uno,contador);
                printf("el promedio de la pila es:%.2f\n",promedio);
                break;
            case 6:
                validos=CargarArreglo(A);
                printf("validos cargados:%i\n",validos);
                MostrarArreglo(A,validos);
                break;
            case 7:
                dia=0;
                validos=CargarArregloLimitado(B,&dia);
                printf("validos cargados:%i\n",validos);
                MostrarArregloB(B,validos);
                printf("dias cargados:%i\n",dia);
                break;
            case 8:
                flag=Capicua(A,validos);
                if(flag==1)
                {
                    printf("el arreglo es capicua\n");
                }
                else
                {
                    printf("el arreglo NO es capicua\n");
                }
                break;
            case 9:
                Pares=0;
                Impares=0;
                suma=SumarArreglo(A,validos,&Pares,&Impares);
                printf("la suma total es:%i\n",suma);
                printf("la cantidad de pares cargados es:%i\n",Pares);
                printf("la cantidad de impares cargados es:%i\n",Impares);
                break;
            case 10:
                cantidad=0;
                printf("buscar numero:\n");
                scanf("%i",&numero);
                flag=BuscarNumero(A,validos,&cantidad,numero);
                if(flag==1)
                {
                    printf("numero encontrado %i veces\n",cantidad);
                }
                else
                {
                    printf("numero no encontrado\n");
                }
                break;
            case 11:
                invertirArreglo(A,validos);
                MostrarArreglo(A,validos);
                break;
            case 12:
                menor=EncontrarMenor(A,validos);
                printf("menor:%i\n",menor);
                break;
            case 13:
                LLenarMatrizEnteros(Matriz);
                MostrarMatrizEnteros(Matriz);
                break;
            case 14:
                InicializarMatrizEnCeros(Matriz);
                MostrarMatrizEnteros(Matriz);
                break;
            case 15:
                validos=CargarStrings(Strings);
                MostrarStrings(Strings,validos);
                break;
            case 16:
                menor=EncontrarMenorPos(Strings,validos);
                printf("el menor es:%i\n",menor);
                break;
            case 17:
                ordenarPorSeleccion(Strings,validos);
                MostrarStrings(Strings,validos);
                break;
            case 18:
                break;
            case 19:
                break;
            case 20:
                break;

                default:
                    printf("INGRESE UNA FUNCION VALIDA:\n");
                    scanf("%i",&op);
            }
            printf("DESEA UTILIZAR OTRA FUNCION:\n");
            fflush(stdin);
            scanf("%c",&control);
    }while(control=='s');
    return 0;
}

int CargarPila(Pila* Uno)
{
    int contador=0;
    char control='s';
    do
    {
        leer(Uno);
        contador++;
        printf("continuar(s/n)\n");
        fflush(stdin);
        scanf("%c",&control);

    }while(control=='s');
    mostrar(Uno);
    return contador;
}
int EncontrarMenorPila(Pila* Uno)
{
    Pila aux,menor;
    inicpila(&aux);
    inicpila(&menor);
    if(!pilavacia(Uno))
    {
        apilar(&menor,desapilar(Uno));
    }
    while(!pilavacia(Uno))
    {
        if(tope(Uno)<tope(&menor))
        {
            apilar(&aux,desapilar(&menor));
            apilar(&menor,desapilar(Uno));
        }
        else
        {
            apilar(&aux,desapilar(Uno));
        }
    }
    while(!pilavacia(&aux))
    {
        apilar(Uno,desapilar(&aux));
    }
    return tope(&menor);

}
void OrdenamientoSeleccion(Pila* Desordenada)
{
    Pila Ordenada;
    inicpila(&Ordenada);
    while(!pilavacia(Desordenada))
    {
        apilar(&Ordenada,EncontrarMenorPila(Desordenada));
    }
    mostrar(&Ordenada);
}
int SumarPilaPar(Pila* Cargada, int* contador)
{
    Pila impar;
    Pila Par;
    inicpila(&Par);
    inicpila(&impar);
    int suma = 0;
    while (!pilavacia(Cargada))
    {
        if (tope(Cargada) % 2 == 0)
        {
            *contador = *contador + 1;
            suma += tope(Cargada);
            apilar(&Par, desapilar(Cargada));
        }
        else
        {
            apilar(&impar, desapilar(Cargada));
        }
    }
    return suma;
}
int Suma_Pila(Pila *Cargada)
{
    Pila aux;
    inicpila(&aux);
    int suma=0;
    while(!pilavacia(Cargada))
    {
        suma += tope(Cargada);
        apilar(&aux,desapilar(Cargada));
    }
     while(!pilavacia(&aux))
    {
        apilar(Cargada,desapilar(&aux));
    }

    return suma;
}
float PromedioPila(Pila* Cargada,int contador)
{
    int suma=Suma_Pila(Cargada);
    float Promedio=(float)suma/contador;
    return Promedio;
}
int CargarArreglo(int ArregloA[dim])
{
    char control='s';
    int validos=0;
    do
    {
        printf("ingresa un numero:\n");
        scanf("%i",&ArregloA[validos]);
        validos++;
        printf("continuar (s/n)\n");
        fflush(stdin);
        scanf("%c",&control);
    }while(control=='s'&& validos<dim);
    return validos;
}
void MostrarArreglo(int ArregloCargado[dim],int validos)
{
    for(int i=0;i<validos;i++)
    {
        printf("|%i|",ArregloCargado[i]);
    }
    printf("\n\n");
}
int CargarArregloLimitado(int ArregloB[dim],int* dia)
{
    char control='s';
    int contador;
    int validos=0;
   do
    {
        for(contador=0;contador<5;contador++)
        {
            printf("ingrese un numero:\n");
            scanf("%i",&ArregloB[validos]);
            validos++;
        }
        if(validos%5==0)
            {
               (*dia)=*dia+1;
            }
        printf("continuar (s/n)\n");
        fflush(stdin);
        scanf("%c",&control);
    }while(control=='s' && validos<35);
    return validos;

}
void MostrarArregloB(int ArregloCargadoB[dim], int validos)
 {
    int contador = 0;
    for (int i = 0; i < validos; i++)
    {
        printf("|%i|", ArregloCargadoB[i]);
        contador++;
        if (contador == 5)
        {
            printf("| |");
            contador = 0;
        }
    }
    printf("\n\n");
}
int Capicua(int Arreglo[dim],int validos)
{
    int flag=1;
    int i=0;
    int j=validos-1;
    while(i<j)
    {
        if(Arreglo[i]==Arreglo[j])
        {
            j--;
            i++;
        }
        else
        {
            flag=0;
            break;
        }
    }
    return flag;
}
int SumarArreglo(int arreglo[dim],int validos,int* Pares,int* Impares)
{
    int i=0;
    int suma=0;
    while(i<validos)
    {
        if(arreglo[i]%2==0)
        {
            (*Pares)=*Pares+1;
        }
        else
        {
            (*Impares)=*Impares+1;
        }
        suma+=arreglo[i];
        i++;
    }
    return suma;

}
int BuscarNumero(int arreglo[dim],int validos,int* cantidad,int numero)
{
   int i=0;
   int flag=0;
   while(i<validos)
   {
       if(arreglo[i]==numero)
       {
           (*cantidad)=*cantidad+1;
           flag=1;
       }
       i++;
   }
   return flag;
}
void invertirArreglo(int arregloA[dim],int validos)
{
    int i=0;
    int j=validos-1;
    int intercambio;
    while(i<j)
    {
      intercambio=arregloA[i];
      arregloA[i]=arregloA[j];
      arregloA[j]=intercambio;
      i++;
      j--;
    }

}
int EncontrarMenor(int arregloA[], int validos)
{
    int i;
    int menor = arregloA[0];

    for (i = 1; i < validos; i++)
    {
        if (menor > arregloA[i])
        {
            menor = arregloA[i];
        }
    }
    return menor;
}
void LLenarMatrizEnteros(int MatrizA[f][c])
{
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("ingrese un numero para fila %i y columna %i\n",i+1,j+1);
            scanf("%i",&MatrizA[i][j]);
        }
    }

}
void MostrarMatrizEnteros(int MatrizA[f][c])
{
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<c;j++)
        {
           printf("|%i|",MatrizA[i][j]);

        }
        printf("\n");
    }
}
void InicializarMatrizEnCeros(int MatrizA[f][c])
{

        for(int i=0;i<f;i++)
        {
            for(int j=0;j<c;j++)
            {

                MatrizA[i][j]=0;
            }
        }
}
int CargarStrings(char Strings[f][c])
{
  int i=0;
  char control='s';
  do
    {
        printf("ingrese un nombre:\n");
        fflush(stdin);
        scanf("%s",Strings[i]);
        i++;
        printf("continuar s/n:\n");
        fflush(stdin);
        scanf("%c",&control);
    }while(control=='s' && i<f);
    return i;
}
void MostrarStrings(char Strings[f][c],int validos)
{
    for(int i=0;i<validos;i++)
    {
        printf("|%s|",Strings[i]);
        printf("\n");
    }
    printf("\n");
}
int EncontrarMenorPos(char Strings[][c], int validos)
{
    int poscMenor = 0;
    for (int i = 1; i < validos; i++)
    {
        if (strcmp(Strings[i], Strings[poscMenor]) < 0)
        {
            poscMenor = i;
        }
    }
    return poscMenor;
}

void ordenarPorSeleccion(char matriz[f][c], int validos)
{
    for (int i = 0; i < validos - 1; i++)
    {
        int poscM = i;
        for (int j = i + 1; j < validos; j++)
        {
            if (strcmp(matriz[j], matriz[poscM]) < 0)
            {
                poscM = j;
            }
        }
        if (poscM != i)
        {
            // Intercambiar matriz[i] con matriz[poscM]
            char aux[c];
            strcpy(aux, matriz[i]);
            strcpy(matriz[i], matriz[poscM]);
            strcpy(matriz[poscM], aux);
        }
    }
}


