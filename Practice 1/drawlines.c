/*
Nombre: Guerrero Romero Daniel Alberto
Materia: Computer Graphics
Programa: Algoritmos para dibujar lineas (Naive, DDA, Bresenhan)
*/

#include <stdio.h>

float X1=0, X2=5, Y1=1, Y2=4, m, swap, b;

float Ys[1000];

int main(){

	m = (Y2 - Y1) / (X2 - X1);

	printf("Slope %f\n",m);

	if(m>1){
		/*SWAP*/
		printf("SWAP\n");
		swap = X1;
		X1 = Y1;
		Y1 = swap;

		swap = X2;
		X2 = Y2;
		Y2 = swap;

	}
	else if(m<0 && m>-1){
		/*FLIP*/
		printf("FLIP\n");
		X1 = X1*-1;
		X2 = X2*-1;
	}

	else if(m>0 && m<1){
		/*NADA*/
		printf("NADA\n");
	}
	else if(m<-1){
		/*SWAP Y FLIP*/
		printf("SWAP Y FLIP\n");
		swap = X1;
		X1 = Y1;
		Y1 = swap;

		swap = X2;
		X2 = Y2;
		Y2 = swap;
		/*FLIP*/
		X1 = X1*-1;
		X2 = X2*-1;
	}

	m = (Y2 - Y1) / (X2 - X1);
	printf("NUEVA SLOPE %f\n", m);


	/*NAIVE APROACH*/

	printf("NAIVE APROACH\n");

	Ys[0]=Y1;

	b = (Y1 - (m*X1));

	int n=1;

	printf("B: %f\n", b);
	for (X1; X1 < X2; X1++){
		Ys[n] =	(m*X1) + (b);
		printf("valores de Y%d: %f\n", n, Ys[n]);
		n++; 		
	}



	return 0;
}