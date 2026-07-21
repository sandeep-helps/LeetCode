class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int n, int m) {
        // Boundary check
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0) {
            return 0;
        }
        // Mark as visited
        grid[i][j] = 0;
        // Return 1 (current cell) + sum of all 4 directions
        return 1 + dfs(grid, i - 1, j, n, m)  // up
                 + dfs(grid, i + 1, j, n, m)  // down
                 + dfs(grid, i, j - 1, n, m)  // left
                 + dfs(grid, i, j + 1, n, m); // right
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int area = dfs(grid, i, j, n, m);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};