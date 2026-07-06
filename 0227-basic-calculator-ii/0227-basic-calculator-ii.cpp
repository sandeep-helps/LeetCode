class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        stack<int> st;
        int curr_num = 0;
        char last_operator = '+';
        
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            
            if (isdigit(ch)) {
                curr_num = curr_num * 10 + (ch - '0');
            }
            
            if (!isdigit(ch) && ch != ' ' || i == n - 1) {
                if (ch == ' ' && i != n - 1) continue;
                
                if (last_operator == '+') {
                    st.push(curr_num);
                }
                else if (last_operator == '-') {
                    st.push(-curr_num);
                }
                else if (last_operator == '*') {
                    int top = st.top();
                    st.pop();
                    st.push(top * curr_num);
                }
                else if (last_operator == '/') {
                    int top = st.top();
                    st.pop();
                    st.push(top / curr_num);
                }
                
                if (!isdigit(ch)) {
                    last_operator = ch;
                }
                curr_num = 0;
            }
        }
        
        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};  // ✅ This is correct

// The issue might be one of these: