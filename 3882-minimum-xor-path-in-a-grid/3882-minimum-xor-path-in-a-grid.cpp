class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // dp[i][j][x] = true agar (0,0) se (i,j) tak XOR value x possible hai
        // XOR range 0 se 1023 tak (kyunki grid[i][j] <= 1023)
        vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(1024, false)));
        
        // Start cell
        dp[0][0][grid[0][0]] = true;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) continue; // start cell skip
                
                for(int x = 0; x < 1024; x++){
                    bool possible = false;
                    
                    // Upar se aaye (i-1, j)
                    if(i > 0 && dp[i-1][j][x]) {
                        possible = true;
                    }
                    // Left se aaye (i, j-1)
                    if(j > 0 && dp[i][j-1][x]) {
                        possible = true;
                    }
                    
                    if(possible) {
                        // Current cell ka value XOR karo
                        dp[i][j][x ^ grid[i][j]] = true;
                    }
                }
            }
        }
        
        // Bottom-right cell pe minimum XOR value dhundho
        for(int x = 0; x < 1024; x++){
            if(dp[m-1][n-1][x]) {
                return x;
            }
        }
        return -1; // Kabhi nahi aayega, bas safety ke liye
    }
};