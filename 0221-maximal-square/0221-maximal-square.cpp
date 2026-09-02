class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size(); 
        int col = matrix[0].size();
        int maxsize = 0;
        vector<vector<int>>dp(row, vector<int>(col, 0));
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(matrix[i][j] == '1'){
                    if(i == 0 || j == 0){
                        dp[i][j] = 1;
                    }
                    else{
                        dp[i][j] = min({
                            dp[i-1][j],
                            dp[i-1][j-1],
                            dp[i][j-1]
                        })+1;
                    }
                    maxsize = max(maxsize, dp[i][j]);
                }
            }
        }
        return maxsize * maxsize;
    }
};