class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newintervals) {
        int n = intervals.size();
        vector<vector<int>> result;
        int i = 0;
        while(i < n){
            if(intervals[i][1] < newintervals[0]){
                result.push_back(intervals[i]);
            }else if (intervals[i][0] > newintervals[1]){
                break;
            }
            else{
                newintervals[0] = min(newintervals[0], intervals[i][0]);
                newintervals[1] = max(newintervals[1], intervals[i][1]);
            }
            i++;
        }
        result.push_back(newintervals);
        while(i<n){
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};