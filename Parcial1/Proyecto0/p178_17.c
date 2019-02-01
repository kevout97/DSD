#include<stdio.h> 
#include<string.h> 

void generateSquare(int n) 
{ 
	int cuadroMagico[n][n]; 

	memset(cuadroMagico, 0, sizeof(cuadroMagico)); 

	int i = n/2; 
	int j = n-1; 

	for (int num=1; num <= n*n; ) 
	{ 
		if (i==-1 && j==n)
		{ 
			j = n-2; 
			i = 0; 
		} 
		else
		{ 
			if (j == n) 
				j = 0; 

			if (i < 0) 
				i=n-1; 
		} 
		if (cuadroMagico[i][j])
		{ 
			j -= 2; 
			i++; 
			continue; 
		} 
		else
			cuadroMagico[i][j] = num++;

		j++; i--; 
	} 

	printf("El cuadro mágico para n=%d:\nSuma de cada columna %d:\n\n", n, n*(n*n+1)/2); 
	for (i=0; i<n; i++) 
	{ 
		for (j=0; j<n; j++) 
			printf("%3d ", cuadroMagico[i][j]); 
		printf("\n"); 
	} 
} 

int main() 
{ 
    int n;
	printf("Introduzca un valor entre 2-99: \n");
    scanf("%d", &n);
	generateSquare (n); 
	return 0; 
} 
