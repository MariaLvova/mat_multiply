# Operácie s maticami v jazyku C

Tento program v jazyku C demonštruje základné operácie s maticami, vrátane vytvorenia, inicializácie, násobenia a uvoľnenia matíc pomocou dynamického alokovania pamäti.


# Úloha 9.1.17: Násobenie matíc v jazyku C

Uloha 9.1.17: Okrem ˇstandardnej funkcionality naprogramujte aj funkciu

• char mat_multiply(MAT *a, mat *b, mat *c);

ktorá vypočíta súčin matíc a a b a výsledok uloží do matice c. Funkcia očakáva, že matica c je správneho typu. V prípade problémov sa funkcia st’ažuje cez návratovú hodnotu.

Tento program v jazyku C demonštruje základné operácie s maticami, vrátane vytvorenia, inicializácie, násobenia a uvoľnenia matíc pomocou dynamického alokovania pamäti.

## Súbory

- **main.c**: Obsahuje hlavný program demonštrujúci operácie s maticami.
- **matrix.h**: Hlavičkový súbor obsahujúci definíciu štruktúry matice a prototypy funkcií.
- **matrix.c**: Zdrojový súbor implementujúci funkcie na prácu s maticami.

## Štruktúra matice

Matica je reprezentovaná štruktúrou `MAT`:

```c
typedef struct {
    unsigned int rows;
    unsigned int cols;
    int* elem; // Pole pre prvky matice
} MAT;
```

## Funkcie

### `MAT* mat_create_with_type(unsigned int rows, unsigned int cols)`

Vytvorí maticu s danými rozmermi `rows` x `cols` a inicializuje jej prvky náhodnými celými číslami.

### `void mat_random(MAT* mat)`

Inicializuje prvky existujúcej matice `mat` náhodnými celými číslami.

### `void mat_unit(MAT* mat)`

Inicializuje prvky existujúcej matice `mat` ako jednotkovú maticu (diagonálne prvky sú 1, ostatné sú 0).

### `char mat_save(MAT* mat, char* filename)`

Uloží maticu `mat` do binárneho súboru špecifikovaného parametrom `filename`. Formát súboru začína reťazcom "M1", nasledovaným rozmermi a prvkami matice.

### `void mat_destroy(MAT* mat)`

Uvoľní dynamicky alokovanú pamäť použitú pre maticu `mat`.

### `void mat_print(MAT* mat)`

Vypíše maticu `mat` na štandardný výstup vo formátovanom tvare.

### `char mat_multiply(MAT* a, MAT* b, MAT* c)`

Násobí matice `a` a `b` a výsledok uloží do matice `c`. Vráti `1` pri úspechu, `0` ak sú rozmery matíc nekompatibilné.

## Použitie

Pre použitie týchto funkcií začlenite súbor `matrix.h` do vášho C programu a počas kompilácie pridajte odkaz na `matrix.c`.

### Príklad použitia

Predpokladajme, že máme nasledujúci kód v `main.c`, ktorý násobí dve matice:

```c
#include "matrix.h"

int main() {
    // Inicializácia generátora náhodných čísel
    srand(time(NULL));

    // Vytvorenie matíc A, B, C
    MAT* A = mat_create_with_type(3, 3);
    MAT* B = mat_create_with_type(3, 3);
    MAT* C = mat_create_with_type(3, 3);

    // Výpis matic A a B
    printf("Matica A:\n");
    mat_print(A);
    printf("\nMatica B:\n");
    mat_print(B);

    // Vypočítanie súčinu matíc A * B = C
    if (mat_multiply(A, B, C)) {
        printf("\nVýsledná matica C = A * B:\n");
        mat_print(C);
    } else {
        printf("\nNásobenie matíc zlyhalo kvôli nekompatibilným rozmerom.\n");
    }

    // Uvoľnenie pamäte
    mat_destroy(A);
    mat_destroy(B);
    mat_destroy(C);

    return 0;
}
```

V tomto príklade sa vytvoria matice A, B a C s rozmermi 3x3. Matici A a B sa inicializujú náhodnými hodnotami. Potom sa vypočíta ich súčin A * B a výsledok sa vypíše na obrazovku pomocou funkcie `mat_print`.
