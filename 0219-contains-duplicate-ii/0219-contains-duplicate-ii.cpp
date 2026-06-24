class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>lastseen;
        for(int i = 0; i<nums.size(); i++){
            if(lastseen.find(nums[i]) != lastseen.end() && i - lastseen[nums[i]] <=k){
                return true;
            }
            lastseen[nums[i]] = i;
        }
        return false;
    }
};