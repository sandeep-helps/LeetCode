class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int>events;
        for(auto &t : trips){
            int count = t[0];
            int st = t[1];
            int end = t[2];

            events[st] += count;
            events[end] -= count;
        }
        int passcount = 0;
        vector<int>ans;
        for(auto & it : events){
            passcount += it.second;
            if(passcount>capacity){
                return false;
            }
        }
        return true; 
    }
};