#include <stdio.h>
#include <limits.h>

int coinChange(int coins[], int numCoins, int amount) {
    int dp[amount + 1];
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;
    }

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < numCoins; j++) {
            if (coins[j] <= i) {
                int sub_res = dp[i - coins[j]];
                if (sub_res != INT_MAX && sub_res + 1 < dp[i]) {
                    dp[i] = sub_res + 1;
                }
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    int numCoins, amount;
    printf("Enter the numbers of coin:");
    scanf("%d", &numCoins);
    int coins[numCoins];
    printf("Enter the coins : ");
    for (int i = 0; i < numCoins; i++) {
        scanf("%d", &coins[i]);
    }
    printf("Enter the amount to make change for: ");
    scanf("%d", &amount);
    int minCoins = coinChange(coins, numCoins, amount);
    printf("Minimum number of coins required to make change for %d Tk: %d\n", amount, minCoins);

    return 0;
}
