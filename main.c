#include <stdio.h>
#include <stdlib.h>

#include "imagem.h"
#include "terrain.h"
#include "fileHandler.h"
#include "vectorSorter.h"

#define DEFAULT_SIZE_X 1366
#define DEFAULT_SIZE_Y 768
#define DEFAULT_ROUGHNESS 0.5

pixel **alocar_matriz(int x, int y) {
	pixel **matriz;
	int i;

	matriz = (pixel **)malloc(sizeof(pixel*) * y);

	for (i = 0; i < y; i++) {
		matriz[i] = (pixel *)malloc(sizeof(pixel) * x);
	}

	return matriz;
}

int isSquare(int x, int y) {
	if ((x / 2 + x) / 2 == y) {
		return 1;
	}
	return 0;
}

int isHD(int x, int y) {
	if ((x == 1280 && y == 720) || (x == 1920 && y == 1080)) {
		return 1;
	}
	return 0;	
}

int getStringSize(char *string) {
	int i = 0;
	while(string[i] != '\0') {
		i++;
	}
	return ++i;
}

void erro() {
	printf("Parametros Invalidos!\n");
	printf("Uso: ./terreno -d 0.7 -o terreno.ppm -r x y\n");
}

int main (int argc, char *argv[]) {
	int x = DEFAULT_SIZE_X, y = DEFAULT_SIZE_Y;
	int minus = 0;
	int aqv = 0;
	char *arquivo;
	float k = DEFAULT_ROUGHNESS;
	if (argc > 2) {
		int i = 1, j = 0, size;
		while (i < argc) {
			if (argv[i][j] == '-') {
				j++;
				switch(argv[i][j]) {
					case 'd':
						k = atof(argv[++i]);
						if (k > 0.9 || k == 0.0) {
							erro();
							return 1;
						} 
						i++;
						j = 0;	
						break;
					case 'o':
						size = getStringSize(argv[++i]);
						if (size > 5) {
							if ((argv[i][size-5] == '.') && (argv[i][size-4] == 'p') && (argv[i][size-3] == 'p') && (argv[i][size-2] == 'm')) {
								aqv = 1;
								arquivo = argv[i];
							} else {
								erro();
								return 1;
							} 
						} else {
							erro();
							return 1;
						} 
						j = 0;
						i++; 
						//arquivo = (char*)malloc(sizeof(char) * size);
						break;
					case 'r':
						if (i + 3 <= argc) {
							x = atoi(argv[++i]);
							y = atoi(argv[++i]);
							
							if (isSquare(x, y) || isHD(x,y)) {
								j = 0;
								i++;		
							} else {
								printf("Resolução Incorreta!\n");
								printf("Sintaxe: -r [x] [y]\n");
								printf("Obs: Apenas resolucoes 4:3, HD ou FULLHD\n");
								return 1;
							}
							
						}
						break;
					default:
						erro();
						return 1;
					}
			} else {
				erro();
				return 1;
			}
		}

	} else if (argc == 2) {
		erro();
		return 1;
	} 
	
	if (!aqv) {
		arquivo = (char*)malloc(sizeof(char) * 10);
		arquivo = "imagem.ppm";	
	}
	
	
	
	pixel **imagem = alocar_matriz(x, y);
	int *vector = (int*)malloc(sizeof(int) * x);

	setVector(vector, x);
	setBorders(x, vector, y, k);

	//Terrain *terrain = (Terrain*)malloc(sizeof(Terrain) * x);
	//highfieldToTerrain(y, terrain, vector);

	setBackground(x, y, imagem);
	drawTerrain(x, y, vector, imagem);

	if (criarArquivo(&x, &y, arquivo)) {	
		return 1;
	} else {
		printf("Salvando Arquivo...\n");
	}

	if (saveImage(x, y, imagem, arquivo)) {
		return 1;
	} else {
		printf("Arquivo salvo\n");
	}
	
    return 0;
}
