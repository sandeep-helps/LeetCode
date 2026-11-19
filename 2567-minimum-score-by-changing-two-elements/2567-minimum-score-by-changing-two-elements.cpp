class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int op1 = nums[n-1] - nums[2];
        int op2 = nums[n-2] - nums[1];
        int op3 = nums[n-3] - nums[0];
        return min({op1, op2, op3});
    }
};