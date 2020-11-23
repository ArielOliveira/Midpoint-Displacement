#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vectorSorter.h"

#define AVG2(a,b) ((a + b) / 2)

void makeMountain(int right, int left, int *vector, float roughness, int razaoAltura);

float randomizeFloat(float max) {
    float randomN;
        randomN = ((float)rand()/(float)(RAND_MAX) * max);
    return randomN;
}

int randomizeInt(int max) {
    int randomN;
    do {
        randomN = rand() % max;
    } while (randomN > 0);
    return randomN;
}

int sortedValue(int maxHeight) {
	int value;
	value = randomizeInt(maxHeight-1);
	return value;
}

void setVector(int *vector, int size) {
	int i;
	srand(time(NULL));
	for (i = 0; i < size; i++) {
		vector[i] = 0;
	}
}

void setDisplacement(int right, int left, int middle, int *vector, float roughness, int razaoAltura) {

	vector[middle] = AVG2(vector[left], vector[right]);
	vector[middle] += (randomizeFloat(1.0) * razaoAltura * 2) - razaoAltura;

}

void makeMountain(int right, int left, int *vector, float roughness, int razaoAltura) {
	if (right - left > 1 && right > 1) {
		int middle = AVG2(right, left);
		setDisplacement(right, left, middle, vector, roughness, razaoAltura);

		razaoAltura *= roughness;
		makeMountain(right, middle, vector, roughness, razaoAltura);
		
		razaoAltura *= roughness;
		makeMountain(middle, left, vector, roughness, razaoAltura);
	}
} 

void setBorders(int width, int *vector, int height, float roughness) {
	int razaoAltura = height / 4;

	vector[width-1] = height / 2 + (randomizeFloat(1.0) * razaoAltura * 2) - razaoAltura;
	vector[0] = height / 2 + (randomizeFloat(1.0) * razaoAltura * 2) - razaoAltura;

	razaoAltura *= roughness;
	setDisplacement(width-1, 0, width / 2, vector, roughness, razaoAltura);

	razaoAltura *= roughness;
	makeMountain(width / 2, 0, vector, roughness, razaoAltura);

	razaoAltura *= roughness;
	makeMountain(width-1, width / 2, vector, roughness, razaoAltura);

}