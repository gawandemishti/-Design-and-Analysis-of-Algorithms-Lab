#include <stdio.h>
#include <string.h>

#define INF 1e9
#define MAX_N 16

int N;
int cost[MAX_N][MAX_N];
int dp[1 << MAX_N][MAX_N];

// Recursive function with memoization to find the minimum TSP cost
int solve(int mask, int u) {
    // Base case: If all cities have been visited, return the cost to go back to city 0
    if (mask == (1 << N) - 1) {
        if (cost[u][0] == -1) return INF;
        return cost[u][0];
    }

    // Return the cached result if already calculated
    if (dp[mask][u] != -1) {
        return dp[mask][u];
    }

    int min_cost = INF;

    // Try visiting all other unvisited cities
    for (int v = 0; v < N; v++) {
        // Check if city 'v' is not visited and a direct road exists
        if (!(mask & (1 << v)) && cost[u][v] != -1) {
            int current_cost = cost[u][v] + solve(mask | (1 << v), v);
            if (current_cost < min_cost) {
                min_cost = current_cost;
            }
        }
    }

    return dp[mask][u] = min_cost;
}

int main() {
    // Read the number of cities
    if (scanf("%d", &N) != 1) return 0;

    // Read the cost matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // Initialize DP memoization table with -1
    memset(dp, -1, sizeof(dp));

    // Start the tour from city 0 (mask = 1 means only city 0 is visited initially)
    int result = solve(1, 0);

    // Print the optimal total cost
    printf("%d\n", result);

    return 0;
}

