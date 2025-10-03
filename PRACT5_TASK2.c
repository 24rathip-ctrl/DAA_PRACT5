#include <stdio.h>
#include <string.h>

#define MAX 100

void findLRS(char str[]) {
    int n = strlen(str);
    int c[MAX][MAX];

    //Matrix Formation
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            c[i][j] = 0;
        }
    }

    //Filling of Matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (str[i - 1] == str[j - 1] && i != j) {
                c[i][j] = 1 + c[i - 1][j - 1];
            } else {
                if (c[i - 1][j] > c[i][j - 1])
                    c[i][j] = c[i - 1][j];
                else
                    c[i][j] = c[i][j - 1];
            }
        }
    }

    printf("Length of LRS: %d\n", c[n][n]);

    //Backtracking 
    int i = n, j = n;
    char lrs[MAX];
    int index = 0;

    while (i > 0 && j > 0) {
        if (str[i - 1] == str[j - 1] && i != j) {
            lrs[index++] = str[i - 1];
            i--;
            j--;
        } else if (c[i - 1][j] > c[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    lrs[index] = '\0';

    printf("LRS: ");
    for (int k = index - 1; k >= 0; k--) {
        printf("%c", lrs[k]);
    }
    printf("\n");
}

int main() {
    char str[] = "AABEBCDD";
    findLRS(str);
    return 0;
}
