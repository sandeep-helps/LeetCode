class Solution {
public:
    int peri = 0;
    void dfs(vector<vector<int>>&grid, int i ,int j ,int n ,int m){
        if(i < 0|| j<0|| i>=m || j>= n || grid[i][j] == 0){
            peri++;
            return;
        }
        if(grid[i][j] == -1){
            return;
        }
        grid[i][j] = -1;
        dfs(grid, i+1, j , n , m);
        dfs(grid, i-1, j , n , m);
        dfs(grid, i, j+1 , n , m);
        dfs(grid, i, j-1 , n , m);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    dfs(grid, i , j , n , m);
                    return peri;
                }
            }
        }
        return -1;
    }
};