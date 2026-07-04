class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int>events;
        for(auto &t : trips){
            int passenger = t[0];
            int start = t[1]; 
            int end = t[2];

            events[start] += passenger;
            events[end] -= passenger;
        }
        int passcount = 0;
        for(auto &it : events){
            passcount += it.second;
            if(passcount>capacity){
                return false;
            }
        } 
        return true;  
    }
};