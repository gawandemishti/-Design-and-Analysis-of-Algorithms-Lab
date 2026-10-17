#include <stdio.h>
#include <stdlib.h>

// Helper function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }
    
    // Allocate memory for values and weights
    int *values = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }
    
    int *weights = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }
    
    int w;
    scanf("%d", &w);
    
    // Dynamic Programming array to store maximum values for each capacity up to W
    // Using a 1D array optimized from right to left to save space
    int *dp = (int *)calloc(w + 1, sizeof(int));
    
    for (int i = 0; i < n; i++) {
        for (int j = w; j >= weights[i]; j--) {
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }
    
    // Output the maximum value possible within capacity W
    printf("%d\n", dp[w]);
    
    // Free allocated memory
    free(values);
    free(weights);
    free(dp);
    
    return 0;
}

