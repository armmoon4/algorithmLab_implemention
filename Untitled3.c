#include <stdio.h>
#include <string.h>

// Function to find the maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the length of the LCS
int lcs_length(char *X, char *Y, int m, int n) {
    int L[m + 1][n + 1];
    int i, j;

    // Build the LCS table
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    return L[m][n];
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X);
    int n = strlen(Y);

    int lcs_len = lcs_length(X, Y, m, n);
    printf("Length of LCS: %d\n", lcs_len);

    return 0;
}
