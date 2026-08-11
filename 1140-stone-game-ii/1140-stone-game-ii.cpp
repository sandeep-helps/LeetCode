class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffixSum(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int m = 1; m <= n; m++) {
                if (i + 2 * m >= n) {
                    dp[i][m] = suffixSum[i];
                } else {
                    for (int x = 1; x <= 2 * m; x++) {
                        if (i + x > n) break;
                        int taken = suffixSum[i] - suffixSum[i + x];
                        int remaining = suffixSum[i + x];
                        int opponentBest = dp[i + x][max(m, x)];
                        int currentTotal = taken + (remaining - opponentBest);
                        dp[i][m] = max(dp[i][m], currentTotal);
                    }
                }
            }
        }
        return dp[0][1];
    }
};