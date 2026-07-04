class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN;
        int current_sum = 0;
        
        for(int num : nums){
            current_sum = max(num, num+current_sum);
            maxsum = max(maxsum, current_sum);
        }
        
        return maxsum;
    }
};