#ifndef TERRAIN_H
#define TERRAIN_H

typedef enum {
    WATER,
    SAND,
    FLOREST,
    MOUNTAIN,
    SNOW
} Type;

typedef struct {
    int height;
    Type type;	
} Terrain;

void highfieldToTerrain(int SIZE, Terrain *terrain, int *vector);

#endif
