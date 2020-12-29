/// Tittle: Exercise1
/// Description: Sort argument values
#include <cstdio>
#include <cstdlib>

void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

int main(int argc, char *argv[]) {
    const int count = argc - 1;
    int numbers[count]; //Sometimes Compiler will have error

    for (int i = 1; i < argc; i++) {
        numbers[i - 1] = strtol(argv[i], nullptr, 0);
    }

    for (int i = 0; i < count; i++) {

        for (int j = 0; j < count - 1 - i; j++) {

            if (numbers[j] > numbers[j + 1]) {

                swap(&numbers[j], &numbers[j + 1]);
            }
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}