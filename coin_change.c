#include <stdio.h>

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int main()
{
    int n, amount;

    printf("Enter number of coins: ");
    scanf("%d", &n);

    int coins[n];

    printf("Enter coin values: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &coins[i]);
    }

    printf("Enter amount: ");
    scanf("%d", &amount);

    int dp[amount + 1];

    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        dp[i] = amount + 1;

        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i)
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    if (dp[amount] > amount)
        printf("Change cannot be made.\n");
    else
        printf("Minimum number of coins = %d\n", dp[amount]);

    return 0;
}