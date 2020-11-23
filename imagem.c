#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "imagem.h"

void drawPixel(pixel cores, int x, int y, pixel **imagem) {
		imagem[y][x] = cores;
}

int setSeaLevel(int x, int y, pixel **imagem) {
	int i, j, level = 0;
	srand(time(NULL));
	pixel cores = {0, 51, 51};
	while (level == 0) {
		level = rand() % y;	
	}
	
	level = (level + y) / 2;
	for (i = level; i < y; i++) {
		for (j = 0; j < x; j++) {
			drawPixel(cores, j, i, imagem);
		}
	}
	return level;
}

void setBackground(int x, int y, pixel **imagem) {
	int level = setSeaLevel(x, y, imagem);
	int i, j;
	float divide = (float)level / 255;
	pixel cores = {0,0,255};
	for (i = 0; i < level; i++) {
		for (j = 0; j < x; j++) {
			cores.g = (i / divide);
			drawPixel(cores, j, i, imagem);
		}
	}

}

void drawTerrain(int x, int y, int *vetor, pixel **imagem) {
	pixel cores[] = {{51, 25, 0}, {0, 102, 0}};
	int i, j = 0;
	for (i = 0; i < x; i++) {		
		for (j = vetor[i]; j < y; j++) {
			drawPixel(cores[0], i, j, imagem);
			if (j <= vetor[i] + 16) {
				drawPixel(cores[1], i, j, imagem);
			}
		}
		
	}
}
