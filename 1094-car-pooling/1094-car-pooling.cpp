class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>diff(1001, 0);
        for(auto &t : trips){
            int passenger = t[0];
            int start = t[1]; 
            int end = t[2];
            diff[start] += passenger;
            diff[end] -= passenger;
        }
        int cumsum = 0;
        for(int i = 0; i<1001; i++){
            cumsum += diff[i];
            if(cumsum > capacity){
                return false;
            }
        } 
        return true;  
    }
};