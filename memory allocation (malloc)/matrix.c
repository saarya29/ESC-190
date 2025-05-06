#include <stdio.h>
#include <stdlib.h>

// Define your matrix structure
struct matrix {
    size_t row;
    size_t column;
    int **element;
};

void create_matrix(struct matrix **M, size_t row, size_t column, int values[]) {
    *M = (struct matrix *)malloc(sizeof(struct matrix));
    (*M)->row = row;
    (*M)->column = column;
    (*M)->element = (int **)malloc(row * sizeof(int *));

    for (size_t i = 0; i < row; i++) {
        (*M)->element[i] = (int *)malloc(column * sizeof(int));
    }

    size_t index = 0;
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < column; j++) {
            if (values == NULL) {
                (*M)->element[i][j] = 0;
            } else {
                (*M)->element[i][j] = values[index++];'""""'
            }
        }
    }
}

int getElem(struct matrix *M, int i, int j) {
    return M->element[i][j];
}

void setElem(struct matrix *M, int i, int j, int values[]) {
    size_t index = 0;
    for (size_t x = 0; x < M->row; x++) {
        for (size_t y = 0; y < M->column; y++) {
            M->element[x][y] = values[index++];
        }
    }
}

void setElem2(struct matrix *M, int i, int j, int value) {
    M->element[i][j] = value;
}

void summation(struct matrix *M, struct matrix *M2, struct matrix **empty) {
    size_t row = M->row;
    size_t column = M->column;
    create_matrix(empty, row, column, NULL);

    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < column; j++) {
            int sum = getElem(M, i, j) + getElem(M2, i, j);
            setElem2(*empty, i, j, sum);
        }
    }
}

void print_matrix(struct matrix *M) {
    for (size_t i = 0; i < M->row; i++) {
        for (size_t j = 0; j < M->column; j++) {
            printf("%d ", M->element[i][j]);
        }
        printf("\n");
    }
}

void free_matrix(struct matrix *M) {
    for (size_t i = 0; i < M->row; i++) {
        free(M->element[i]);
    }
    free(M->element);
    free(M);
}

int main() {
    struct matrix *M;
    struct matrix *M2;
    struct matrix *empty;
    int values1[] = {4, 8, 4, 1, 1, 2, 3, 0, 3};
    int values2[] = {2, 2, 1, 2, 3, 4, 4, 9, 0};

    create_matrix(&M, 3, 3, values1);
    create_matrix(&M2, 3, 3, values2);
    summation(M, M2, &empty);

    printf("Resulting matrix:\n");
    print_matrix(empty);

    free_matrix(M);
    free_matrix(M2);
    free_matrix(empty);

    return 0;
}
