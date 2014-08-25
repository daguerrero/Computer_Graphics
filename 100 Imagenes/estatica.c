///Programa que crea 100 imagenes FullHD en formato PPM
///Guerrero Romero Daniel Alberto
///Escuela Superior de Computo

///Para abrir la imagen en formato ppm utilizar eog (en gnome o derivados) o kuickshow en KDE

///gcc estatica.c -o estatica (kuickshow FullHD.ppm)

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int col, row, red, green, blue;
	int n=0;
	FILE *imagen;

	char name[16] = "image";

	for (n=0; n<100; n++)
	{
	sprintf(name, "image-%d.ppm", n);

	imagen = fopen(name, "w");
	fprintf(imagen, "P3\n1920 1080\n255\n");

	for (row=0; row<1920; row++)
	{
		for (col=0; col<1080; col++)
		{
			red = rand() % 256;
			green = rand() % 256;
			blue = rand() % 256;

			fprintf(imagen, "%d %d %d ", red, green, blue);
		}

		fprintf(imagen, "\n");
	}
	//fclose(imagen);
}


	return 0;
}