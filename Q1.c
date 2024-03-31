#include <stdio.h>

#define ROWS 3 
#define COLS 5 
void calculateTotal(int marks[][COLS], int totals[]) {
    for (int i = 0; i < ROWS; i++) {
        totals[i] = 0;
        for (int j = 0; j < COLS; j++) {
            totals[i] += marks[i][j];
        }
    }
}

void calculateAverage(int marks[][COLS], float averages[]) {
    for (int j = 0; j < COLS; j++) {
        float sum = 0;
        for (int i = 0; i < ROWS; i++) {
            sum += marks[i][j];
        }
        averages[j] = sum / ROWS;
    }
}

int main() {
    int marks[ROWS][COLS];
    int totals[ROWS];
    float averages[COLS];

    printf("Enter marks for %d students in %d subjects:\n", ROWS, COLS);
    for (int i = 0; i < ROWS; i++) {
        printf("Enter marks for student %d: ", i + 1);
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &marks[i][j]);
        }
    }

    calculateTotal(marks, totals);

    calculateAverage(marks, averages);

    printf("\nTotal marks of each student:\n");
    for (int i = 0; i < ROWS; i++) {
        printf("Student %d: %d\n", i + 1, totals[i]);
    }

    printf("\nAverage marks of each subject:\n");
    for (int j = 0; j < COLS; j++) {
        printf("Subject %d: %.2f\n", j + 1, averages[j]);
    }

    return 0;
}