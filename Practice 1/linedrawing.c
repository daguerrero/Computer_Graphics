#include <stdio.h>

int Round(float num)
{
	int ent, dec;
	ent = num;
	dec = (num - ent) * 10;
	if(dec>4)
	{ ent++; }
	return ent;
}

void CreateImage(FILE *image)
{
	int row, col;
	fprintf(image, "P3\n1920 1080\n255\n");
	for(row=0; row<1080; row++)
	{
		for(col=0; col<1920; col++)
			fprintf(image, "255 255 255 ");
		fprintf(image, "\n");
	}
	/*fprintf(image, "P3\n6 6\n255\n");
	for(row=0; row<6; row++)
	{
		for(col=0; col<6; col++)
			fprintf(image, "255 255 255 ");
		fprintf(image, "\n");
	}
	return;*/
}

void Swap(float *x1, float *y1, float *x2, float *y2)
{
	float swap;
	swap = *x1;
	*x1 = *y1;
	*y1 = swap;
	swap = *x2;
	*x2 = *y2;
	*y2 = swap;
	return;
}

void NaiveApproach(float X1, float Y1, float X2, float Y2, float m)
{
	float b, y;
	int Ys[1000], Xs[1000], n=1, offset;
	FILE *fImage;
	fImage = fopen("line.ppm", "w");
	CreateImage(fImage);
	Xs[0] = X1;
	Ys[0] = Y1;
	offset = 17 + (Xs[0] * 12) + (161 * (1080 - Ys[0]));
	//offset = 11 + (Xs[0] * 12) + (73 * (5 - Ys[0]));
	fseek(fImage, offset, SEEK_SET);
	fprintf(fImage, "100 100 100");
	b = (Y1 - (m * X1));
	for (X1++; X1 < X2; X1++)
	{
		y = (m * X1) + b;
		Xs[n] = X1;
		Ys[n] = Round(y);
		offset = 17 + (Xs[0] * 12) + (161 * (1080 - Ys[0]));
		//offset = 11 + (Xs[n] * 12) + (73 * (5 - Ys[n]));
		fseek(fImage, offset, SEEK_SET);
		fprintf(fImage, "100 100 100");
		n++;
	}
	Xs[n] = X2;
	Ys[n] = Y2;
	offset = 11 + (Xs[n] * 12) + (73 * (5 - Ys[n]));
	fseek(fImage, offset, SEEK_SET);
	fprintf(fImage, "100 100 100");
	fclose(fImage);
	return;
}

void DDA(float X1, float Y1, float X2, float Y2, float m){
	float y;
	int Ys[2000], Xs[2000], n=1;
	Xs[0] = X1;
	Ys[0] = Y1;

	y = Ys[0] + m;
	////DEBUG PITERO
	for (X1++; X1 < X2; X1++){
		

	}
}

int main(int argc, char *argv[])
{
	float X1, X2, Y1, Y2, m;
	X1 = atoi(argv[1]);
	Y1 = atoi(argv[2]);
	X2 = atoi(argv[3]);
	Y2 = atoi(argv[4]);
	m = (Y2 - Y1) / (X2 - X1);
	if(m>1)
	{
		/*SWAP*/
		Swap(&X1, &Y1, &X2, &Y2);
		NaiveApproach(X1, Y1, X2, Y2, m);
		Swap(&X1, &Y1, &X2, &Y2);
	}
	else if(m<0 && m>-1)
	{
		/*FLIP*/
		X1 = X1 * -1;
		X2 = X2 * -1;
		NaiveApproach(X1, Y1, X2, Y2, m);
		X1 = X1 * -1;
		X2 = X2 * -1;
	}
	else if(m<-1)
	{
		/*SWAP Y FLIP*/
		Swap(&X1, &Y1, &X2, &Y2);
		X1 = X1 * -1;
		X2 = X2 * -1;
		NaiveApproach(X1, Y1, X2, Y2, m);
		Swap(&X1, &Y1, &X2, &Y2);
		X1 = X1 * -1;
		X2 = X2 * -1;
	}
	else
		NaiveApproach(X1, Y1, X2, Y2, m);
	return 0;
}