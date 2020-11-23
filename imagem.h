#ifndef IMAGEM_H
#define IMAGEM_H

#include "terrain.h"


typedef struct {
	unsigned int r;
	unsigned int g;
	unsigned int b;
}	pixel;

typedef enum {
	DAWN,
	MORNING,
	DAY,
	AFTERNOON,
	EVENING,
	NIGHT
} daytime;

typedef struct {
	daytime time;
	pixel colorPreset;
} sky;

void setBackground(int x, int y, pixel **imagem);
void drawTerrain(int x, int y, int *vetor, pixel **imagem);

#endif