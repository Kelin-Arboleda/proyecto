#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h> 
#define fil 3
#define col 3

void Llenar_Matriz(int [fil][col]);
int LlenarAutomatica(int [fil][col]);
int LlenarTeclado(int [fil][col]);
void contenido_menu();
void menu(int matriz[fil][col]);

int MostrarMatriz(int matriz[fil][col]);
int MatrizTranspuesta(int [fil][col]);
int DeterminanteMatriz(int [fil][col]);
int MultiplicacionPorEscalar(int [fil][col]);
int PotenciaMatriz(int [fil][col]);
int MatrizA_Mas_MatrizB(int matriz[fil][col], int matriz1[fil][col]);
int MatrizA_Menos_MatrizB(int matriz[fil][col], int matriz1[fil][col]);
int MatrizA_Por_MatrizB(int matriz[fil][col], int matriz1[fil][col]);
void salir();


int main() {
	int matriz[fil][col];
	Llenar_Matriz(matriz);
	menu(matriz);
	return 0;
}
void Llenar_Matriz(int matriz[fil][col]){
	int opcion;
	do{
		printf("\t\tBIENVENIDO");
	    printf("\n 1. Llenar Matriz Automaticamente");
	    printf("\n 2. Llenar Matriz Manualmente");
		printf("\n 3. Salir");  
		printf("\n Ingrese La Opcion Deseada: ");
		scanf("%d", &opcion);	
		switch(opcion){
		case 1: LlenarAutomatica(matriz);
			break;
		case 2:  LlenarTeclado(matriz);	
			break;
		case 3: exit(0);
			break;
		default: Llenar_Matriz(matriz);
            break;		
	}
		system("pause");  
	}while(opcion < 0 || opcion > 3);
}	

int LlenarAutomatica(int matriz[fil][col]){
	srand(time(0));
	 int f, c;
       for (f = 0; f < fil; f++){
         for (c = 0; c < col; c++){
            matriz[f][c]=rand()%(20);
            printf("\t%d",matriz[f][c]);
         }
       printf("\n");
    }
    return 0;
}

int LlenarTeclado(int matriz[fil][col]){
	  int f, c;
    for(f = 0; f < fil; f++){
        for(c = 0; c < col; c++){
           printf("Ingrese un numero  en la posicion [%d][%d]: ", f,c);
           scanf("%d", &matriz[f][c]);
           printf("%d",matriz[f][c]);
        }
        printf("\n");
    }
    return (matriz[f][c]);
}
void contenido_menu(int opcion){
    printf("  |---------------------CALCULADORA DE MATRICES--------------------|\n");
    printf("  |                                  |                             |\n");
    printf("  |   1. Mostrar Matriz.             |   6. Matriz A + Matriz B    |\n");
    printf("  |   2. Matriz Transpuesta.         |   7. Matriz A - Matriz B    |\n");
    printf("  |   3. Determinante de Matriz.     |   8. Matriz A * Matriz B    |\n");
    printf("  |   4. Multiplicacion Por Escalar. |   0. Salir.                 |\n");
    printf("  |   5. Potencia de Matriz.         |                             |\n");
    printf("  |----------------------------------------------------------------|\n");
    printf("  |                       KELIN ARBOLEDA DAVILA                    |\n");
    printf("  |----------------------------------------------------------------|\n");
}
void menu(){
    int opcion;
    char ese;
    int contador = 0;
    int matriz[fil][col];
    int matriz1[fil][col];
    do{
       system("cls");
       contenido_menu(opcion);
       if(contador > 0){
            printf("\n Opcion invalida, es un numero del 0 al 8");
       }
       printf("\nIngrese la opcion deseada: ");
       scanf("%d", &opcion);
       contador += 1;
    }while(opcion > 9 || opcion < 0);
    switch(opcion){
        case 1: MostrarMatriz(matriz);
            break;
        case 2: MatrizTranspuesta(matriz);
            break;
        case 3: DeterminanteMatriz(matriz);
            break;
        case 4: MultiplicacionPorEscalar(matriz);
            break;
        case 5: PotenciaMatriz(matriz);
            break;
        case 6: MatrizA_Mas_MatrizB(matriz, matriz1);
            break;
        case 7: MatrizA_Menos_MatrizB(matriz, matriz1);
            break;
        case 8: MatrizA_Por_MatrizB(matriz, matriz1);
            break;
        case 0: exit(0);
            break;
        default: menu();
            break;
    }
    printf("\nPresione una letra para continuar: ");
    scanf(" %c", &ese);
    menu();
}

int MostrarMatriz( int matriz[fil][col]){
	Llenar_Matriz( matriz);
	int f, c;
    for(f = 0; f < fil; f++){
        for(c = 0; c < col; c++){
            printf("%d ", matriz[f][c]);
        }
        printf("\n");
    }
    return 0;
}

int MatrizTranspuesta(int matriz[fil][col]){
	int f, c;
	int matriz_transpuesta[fil][col];
	printf("matriz transpuesta \n");
    for(f = 0; f < fil; f++) {
        for(c = 0; c < col; c++) {
        	matriz_transpuesta[f][c] = matriz[c][f];
        }
    }
    MostrarMatriz(matriz_transpuesta);
    return 0;
}

int DeterminanteMatriz(int [fil][col]){
	
}

int MultiplicacionPorEscalar(int matriz[fil][col]){
	int f, c, numero;
	int escalar[fil][col];
	printf("\n ingrese el numero para multiplicar la matriz: ");
	scanf("%d", &numero);
	printf("\n la multiplicacion de la matriz por el numero es:");
   for(f = 0; f < fil; f++){
		for(c = 0; c < col; c++){
			escalar[fil][col] = matriz[f][c] * numero;
			printf("%d", escalar[f][c]);
       } 
	  printf("\n");        
   }
   return 0;
}

int PotenciaMatriz(int matriz[fil][col]){
	int f, c, potencia, resultado_pow[fil][col];
	do{
	printf("\n ingrese la potencia a elevar la matriz: ");
	scanf("%d", &potencia);
	}while(potencia >= 2 && potencia <= 3);	
		for (int f = 0; f < fil; f++){ 
			for (int c = 0; c < col; c++){
				resultado_pow[fil][col] = pow (matriz[f][c], potencia); 
				printf("%d", resultado_pow[f][c]);
			}
			printf("\n");
		}
	return 0;
}

int MatrizA_Mas_MatrizB(int matriz[fil][col]){
	int f, c;
    int matriz1[fil][col];
	int suma_matriz[fil][col];
	printf("      PRIMERA MATRIZ \n");
    MostrarMatriz(matriz);
	printf("      SEGUNDA MATRIZ \n");
    for(f = 0; f < fil; f++) {
        for(c = 0; c < col; c++) {
            printf ("ingrese el valor en la posicion [%d][%d] ",f,c);
            scanf ("%d", & matriz1[f][c]);
        }
    }
      for(f = 0; f < fil; f++) {
        for(c = 0; c < col; c++) {
             printf ("%d", matriz1[f][c]);
        }
        printf("\n");
    }
     printf("\n ESTA ES LA SUMA DE LAS 2 MATRICES \n");
    for(f = 0; f < fil; f++) {
        for(c = 0; c < col; c++) {
            suma_matriz[fil][col] = matriz[f][c] + matriz1[f][c];
            printf("%d", suma_matriz[f][c]);
        }
        printf("\n");
    }
    return 0;
}

int MatrizA_Menos_MatrizB(int matriz[fil][col]){
	int f, c, matriz1[fil][col];
	int resta_matriz[f][c];
	printf("      PRIMERA MATRIZ \n");
	MostrarMatriz(matriz);
	printf("      SEGUNDA MATRIZ \n");
    for(f = 0; f < fil; f++) {
        for(c = 0; c < col; c++) {
            printf ("ingrese el valor en la posicion [%d][%d] ",f,c);
            scanf ("%d", & matriz1[f][c]);
        }
    }
      for(f = 0; f < fil; f++) {
        for(c = 0; c < col; c++) {
             printf ("%d",matriz1[f][c]);
        }
        printf("\n");
    }
     printf("\n ESTA ES LA RESTA DE LAS 2 MATRICES \n");
    for(f = 0; f < fil; f++) {
        for(c = 0; c < col; c++) {
            resta_matriz[fil][col] = matriz[f][c] - matriz1[f][c];
            printf("%d",resta_matriz[f][c]);
        }
        printf("\n");
    }
    return 0;
}

int MatrizA_Por_MatrizB(int matriz[fil][col]){
	int f, c, matriz1[fil][col]; 
	int producto_matriz[fil][col];
	printf("      PRIMERA MATRIZ \n");
	MostrarMatriz(matriz);
	printf("      SEGUNDA MATRIZ \n");
    for(f = 0; f < fil; f++) {
        for(c = 0; c < col; c++) {
            printf ("ingrese el valor en la posicion [%d][%d] ",f,c);
            scanf ("%d", &matriz1[f][c]);
        }
    }
      for(f = 0; f < fil; f++) {
        for(c = 0; c < col; c++) {
             printf ("%d", matriz1[f][c]);
        }
        printf("\n");
    }
     printf("\n ESTE ES EL PRODUCTO DE LAS 2 MATRICES \n");
    for(f = 0; f < fil; f++) {
        for(c = 0; c < col; c++) {
            producto_matriz[fil][col] = matriz[f][c] * matriz1[f][c];
            printf("%d",producto_matriz[f][c]);
        }
        printf("\n");
    }
    return 0;
}
