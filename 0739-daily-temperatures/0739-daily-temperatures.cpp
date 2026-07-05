class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int>st;
        vector<int>ans(n,0);
        for(int i = 0; i<n; i++){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                int preDay = st.top();
                st.pop();
                ans[preDay] =  i - preDay;
            }
            st.push(i);
        }
        return ans;
    }
};