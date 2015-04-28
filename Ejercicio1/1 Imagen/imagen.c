///Programa que crea una imagen FullHD en formato PPM con colores aleatorios
///Guerrero Romero Daniel Alberto
///Escuela Superior de Computo
///Para abrir la imagen en formato ppm utilizar eog (en gnome o derivados) o kuickshow en KDE
#include <stdio.h>
#include <stdlib.h>

int main(){

	int col, row, red, green, blue;
	FILE *imagen;
	imagen = fopen("ImagenFULLHD.ppm", "w");
	fprintf(imagen, "P3\n1920 1080\n255\n");

	for (row=0; row<1920; row++){
		for (col=0; col<1080; col++){
			red = rand() % 256;
			green = rand() % 256;
			blue = rand() % 256;

			fprintf(imagen, "%d %d %d ", red, green, blue);
		}
		fprintf(imagen, "\n");
	}
	return 0;
}
