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

// Inicializácia jednotkovej matice
void mat_unit(MAT* mat) {
    for (unsigned int i = 0; i < mat->rows; i++) {
        for (unsigned int j = 0; j < mat->cols; j++) {
            ELEM(mat, i, j) = (i == j) ? 1 : 0;
        }
    }
}

// Uloženie matice do binárneho súboru
char mat_save(MAT* mat, char* filename) {
    FILE* file = fopen(filename, "wb");
    if (!file) return 0;

    if (fwrite("M1", sizeof(char), 2, file) != 2 ||
        fwrite(&mat->rows, sizeof(unsigned int), 1, file) != 1 ||
        fwrite(&mat->cols, sizeof(unsigned int), 1, file) != 1 ||
        fwrite(mat->elem, sizeof(int), mat->rows * mat->cols, file) != mat->rows * mat->cols) {
        fclose(file);
        return 0;
    }

    fclose(file);
    return 1;
}

// Uvoľnenie pamäte matice
void mat_destroy(MAT* mat) {
    if (mat) {
        free(mat->elem);
        free(mat);
    }
}

