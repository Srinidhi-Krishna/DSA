#include <stdio.h>
#include <string.h>

int check(char *word, char arr1[][15], char arr2[][15], int num) {
    int count = 0;
    for (int i = 0; i < num; i++) {
        if (strcmp(word, arr1[i]) == 0) {
            count++;
        }
    }
    for (int i = 0; i < num; i++) {
        if (strcmp(word, arr2[i]) == 0) {
            count++;
        }
    }
    return count;
}

void game(int num) {
    char arr1[num][15], arr2[num][15], arr3[num][15];

    for (int i = 0; i < num; i++) {
        scanf("%s", arr1[i]);
    }
    for (int i = 0; i < num; i++) {
        scanf("%s", arr2[i]);
    }
    for (int i = 0; i < num; i++) {
        scanf("%s", arr3[i]);
    }

    int p1 = 0, p2 = 0, p3 = 0;

    for (int i = 0; i < num; i++) {
        int point = check(arr1[i], arr2, arr3, num);
        if (point == 0) {
            p1 += 3;
        } else if (point == 1) {
            p1 += 1;
        }
    }

    for (int i = 0; i < num; i++) {
        int point = check(arr2[i], arr1, arr3, num);
        if (point == 0) {
            p2 += 3;
        } else if (point == 1) {
            p2 += 1;
        }
    }

    for (int i = 0; i < num; i++) {
        int point = check(arr3[i], arr1, arr2, num);
        if (point == 0) {
            p3 += 3;
        } else if (point == 1) {
            p3 += 1;
        }
    }

    printf("%d %d %d\n", p1, p2, p3);
}

int main() {
    int test;
    scanf("%d", &test);
    while (test--) {
        int num;
        scanf("%d", &num);
        game(num);
    }
    return 0;
}
