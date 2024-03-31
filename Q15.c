#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int **data;
    int row, col;
    int len;
} sparse_matrix;

sparse_matrix* create_sparse_matrix(int r, int c) {
    sparse_matrix* mat = (sparse_matrix*)malloc(sizeof(sparse_matrix));
    if (mat == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    mat->row = r;
    mat->col = c;
    mat->len = 0;

    mat->data = (int**)malloc(MAX_SIZE * sizeof(int*));
    if (mat->data == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < MAX_SIZE; i++) {
        mat->data[i] = (int*)malloc(3 * sizeof(int));
        if (mat->data[i] == NULL) {
            printf("Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
    }

    return mat;
}

void insert(sparse_matrix* mat, int r, int c, int val) {
    if (mat->len >= MAX_SIZE) {
        printf("Sparse matrix overflow.\n");
        exit(EXIT_FAILURE);
    }
    if (r > mat->row || c > mat->col) {
        printf("Wrong entry.\n");
        exit(EXIT_FAILURE);
    }

    mat->data[mat->len][0] = r;
    mat->data[mat->len][1] = c;
    mat->data[mat->len][2] = val;
    mat->len++;
}

void add(sparse_matrix* a, sparse_matrix* b) {
    if (a->row != b->row || a->col != b->col) {
        printf("Matrices can't be added.\n");
        return;
    }

    int apos = 0, bpos = 0;
    sparse_matrix result = *create_sparse_matrix(a->row, a->col);

    while (apos < a->len && bpos < b->len) {
        if (a->data[apos][0] > b->data[bpos][0] ||
            (a->data[apos][0] == b->data[bpos][0] && a->data[apos][1] > b->data[bpos][1])) {
            insert(&result, b->data[bpos][0], b->data[bpos][1], b->data[bpos][2]);
            bpos++;
        }
        else if (a->data[apos][0] < b->data[bpos][0] ||
                 (a->data[apos][0] == b->data[bpos][0] && a->data[apos][1] < b->data[bpos][1])) {
            insert(&result, a->data[apos][0], a->data[apos][1], a->data[apos][2]);
            apos++;
        } else {
            int addedval = a->data[apos][2] + b->data[bpos][2];
            if (addedval != 0)
                insert(&result, a->data[apos][0], a->data[apos][1], addedval);
            apos++;
            bpos++;
        }
    }

    while (apos < a->len)
        insert(&result, a->data[apos][0], a->data[apos][1], a->data[apos++][2]);

    while (bpos < b->len)
        insert(&result, b->data[bpos][0], b->data[bpos][1], b->data[bpos++][2]);

    printf("\nAddition:\n");
    print(&result);
}

sparse_matrix transpose(sparse_matrix* mat) {
    sparse_matrix result = *create_sparse_matrix(mat->col, mat->row);
    result.len = mat->len;

    int count[mat->col + 1];
    for (int i = 1; i <= mat->col; i++)
        count[i] = 0;

    for (int i = 0; i < mat->len; i++)
        count[mat->data[i][1]]++;

    int index[mat->col + 1];
    index[0] = 0;
    for (int i = 1; i <= mat->col; i++)
        index[i] = index[i - 1] + count[i - 1];

    for (int i = 0; i < mat->len; i++) {
        int rpos = index[mat->data[i][1]]++;
        result.data[rpos][0] = mat->data[i][1];
        result.data[rpos][1] = mat->data[i][0];
        result.data[rpos][2] = mat->data[i][2];
    }

    return result;
}

void multiply(sparse_matrix* a, sparse_matrix* b) {
    if (a->col != b->row) {
        printf("Can't multiply, Invalid dimensions.\n");
        return;
    }

    sparse_matrix bt = transpose(b);

    sparse_matrix result = *create_sparse_matrix(a->row, bt.row);

    for (int apos = 0; apos < a->len;) {
        int r = a->data[apos][0];

        for (int bpos = 0; bpos < bt.len;) {
            int c = bt.data[bpos][0];
            int tempa = apos;
            int tempb = bpos;
            int sum = 0;

            while (tempa < a->len && a->data[tempa][0] == r &&
                   tempb < bt.len && bt.data[tempb][0] == c) {
                if (a->data[tempa][1] < bt.data[tempb][1])
                    tempa++;
                else if (a->data[tempa][1] > bt.data[tempb][1])
                    tempb++;
                else
                    sum += a->data[tempa++][2] * bt.data[tempb++][2];
            }

            if (sum != 0)
                insert(&result, r, c, sum);

            while (bpos < bt.len && bt.data[bpos][0] == c)
                bpos++;
        }
        while (apos < a->len && a->data[apos][0] == r)
            apos++;
    }

    printf("\nMultiplication:\n");
    print(&result);
}

void print(sparse_matrix* mat) {
    printf("\nDimension: %dx%d\n", mat->row, mat->col);
    printf("Sparse Matrix:\nRow\tColumn\tValue\n");

    for (int i = 0; i < mat->len; i++) {
        printf("%d\t%d\t%d\n", mat->data[i][0], mat->data[i][1], mat->data[i][2]);
    }
}

int main() {
    sparse_matrix* a = create_sparse_matrix(4, 4);
    sparse_matrix* b = create_sparse_matrix(4, 4);

    insert(a, 1, 2, 10);
    insert(a, 1, 4, 12);
    insert(a, 3, 3, 5);
    insert(a, 4, 1, 15);
    insert(a, 4, 2, 12);

    insert(b, 1, 3, 8);
    insert(b, 2, 4, 23);
    insert(b, 3, 3, 9);
    insert(b, 4, 1, 20);
    insert(b, 4, 2, 25);

    add(a, b);
    multiply(a, b);

    sparse_matrix a_transpose = transpose(a);
    printf("\nTranspose:\n");
    print(&a_transpose);

    free(a->data);
    free(b->data);
    free(a);
    free(b);

    return 0;
}