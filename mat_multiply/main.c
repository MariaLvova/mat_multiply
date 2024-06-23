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

// Vytvorenie matice s náhodnými celými číslami
MAT* mat_create_with_type(unsigned int rows, unsigned int cols) {
    MAT* mat = (MAT*)malloc(sizeof(MAT));
    if (!mat) return NULL;
    mat->rows = rows;
    mat->cols = cols;
    mat->elem = (int*)malloc(rows * cols * sizeof(int));
    if (!mat->elem) {
        free(mat);
        return NULL;
    }
    // Inicializácia matice náhodnými celými číslami
    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++) {
            ELEM(mat, i, j) = rand() % 10; // Náhodné čísla od 0 do 9 (môžete upraviť rozsah podľa potreby)
        }
    }
    return mat;
}

// Inicializácia matice náhodnými číslami
void mat_random(MAT* mat) {
    for (unsigned int i = 0; i < mat->rows; i++) {
        for (unsigned int j = 0; j < mat->cols; j++) {
            ELEM(mat, i, j) = rand() % 10; // Náhodné čísla od 0 do 9 (môžete upraviť rozsah podľa potreby)
        }
    }
}
