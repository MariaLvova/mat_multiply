#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definícia štruktúry MAT
typedef struct {
    unsigned int rows;
    unsigned int cols;
    int* elem; // Pole pre prvky matice
} MAT;

// Definícia makra na prístup k prvkom matice
#define ELEM(mat, i, j) ((mat)->elem[(i) * (mat)->cols + (j)])
