#include <stdio.h>
#include <string.h>

int main() {
    char X[100], Y[100];

    printf("Enter the first string: ");
    scanf("%s", X);

    printf("Enter the second string: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    int L[m + 1][n + 1];
    char D[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
                D[i][j] = '0';
            } else if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
                D[i][j] = 'D';
            } else if (L[i - 1][j] >= L[i][j - 1]) {
                L[i][j] = L[i - 1][j];
                D[i][j] = 'U';
            } else {
                L[i][j] = L[i][j - 1];
                D[i][j] = 'L';
            }
        }
    }

    int lengthLCS = L[m][n];
    char lcs[lengthLCS + 1];
    lcs[lengthLCS] = '\0';

    int i = m, j = n, k = lengthLCS - 1;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[k--] = X[i - 1];
            i--;
            j--;
        } else if (L[i - 1][j] >= L[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("\nLCS: %s\n", lcs);
    printf("LCS Length (Cost): %d\n", lengthLCS);

    printf("\nCost Matrix:\n");
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%2d ", L[i][j]);
        }
        printf("\n");
    }

    return 0;
}
