class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        vector<int>ans;
        for(int x : nums){
            freq[x]++;
        }
        vector<pair<int,int>>vec;
        for(auto& it : freq){
            vec.push_back({it.second, it.first});
        }
        sort(vec.begin(), vec.end(), greater<pair<int,int>>());
        for(int i = 0; i<k; i++){
            ans.push_back(vec[i].second);
        }
        return ans;
    }
};