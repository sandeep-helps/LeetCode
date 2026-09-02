class Solution {
public:

    vector<int> getNSR(vector<int>& height) {
        int n = height.size();
        vector<int> NSR(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && height[st.top()] >= height[i]) {
                st.pop();
            }

            if(st.empty()) {
                NSR[i] = n;
            }
            else {
                NSR[i] = st.top();
            }

            st.push(i);
        }

        return NSR;
    }


    vector<int> getNSL(vector<int>& height) {
        int n = height.size();
        vector<int> NSL(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && height[st.top()] >= height[i]) {
                st.pop();
            }

            if(st.empty()) {
                NSL[i] = -1;
            }
            else {
                NSL[i] = st.top();
            }

            st.push(i);
        }

        return NSL;
    }


    int findMaxArea(vector<int>& height) {

        int n = height.size();

        vector<int> NSR = getNSR(height);
        vector<int> NSL = getNSL(height);

        int maxarea = 0;

        for(int i = 0; i < n; i++) {

            int width = NSR[i] - NSL[i] - 1;

            int area = width * height[i];

            maxarea = max(maxarea, area);
        }

        return maxarea;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {

        if(matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> height(n, 0);

        int maxarea = 0;

        for(int row = 0; row < m; row++) {

            // Build histogram
            for(int col = 0; col < n; col++) {

                if(matrix[row][col] == '1') {
                    height[col]++;
                }
                else {
                    height[col] = 0;
                }
            }

            // Find largest rectangle in histogram
            maxarea = max(maxarea, findMaxArea(height));
        }

        return maxarea;
    }
};