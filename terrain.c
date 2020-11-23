#include <stdio.h>
#include "terrain.h"

void highfieldToTerrain(int SIZE, Terrain *terrain, int *vector) {
	int alturas[] = {0, 10, 60, 100};
	int i, j, k;
	for (i = 0; i < SIZE; i++) {
		terrain[i].height = vector[i];
		for (k = 0; k < 4; k++) {
			if (vector[i] <= alturas[k]) {
				switch(k) {
					case 0: terrain[i].type = WATER;
							k = 4;
						break;
					case 1: terrain[i].type = SAND;
							k = 4;
						break;
					case 2: terrain[i].type = FLOREST;
							k = 4;
						break;
					case 3: terrain[i].type = MOUNTAIN;
							k = 4;
						break;
				}
			} else {
				terrain[i].type = SNOW;
			}
		}
	}
}
