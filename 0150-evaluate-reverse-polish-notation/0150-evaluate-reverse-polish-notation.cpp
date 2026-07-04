class Solution {
public:
    int Operator(int a, int b, string token){
        if(token == "+"){
            return a + b;
        }
        else if(token == "-"){
            return a - b;
        }
        else if(token == "*"){
            return a * b;
        }
        else{
            return a / b;
        }
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto &token : tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int result = Operator(a, b, token);
                st.push(result);
            }
            else{
                st.push(stoi(token));
            }
            
        }
        return st.top();
    }
};