class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        if(nums.empty()) return false;
        int g = nums[0];
        for(int num : nums){
            g = std::gcd(g, num);
            if(g == 1) return true;
        }
        return g == 1;
    }
};