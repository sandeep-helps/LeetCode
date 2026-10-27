class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid;
        for (int i = 0; i < m; i++) {
            if (m == 1 || n == 1) {
                grid.push_back(string(n, '.'));
            } else if (i % 2 == 0) {
                grid.push_back(string(n, '.'));          // even rows: all free
            } else {
                grid.push_back(string(n - 1, '#') + "."); // odd rows: only rightmost free
            }
        }
        return grid;
    }
};