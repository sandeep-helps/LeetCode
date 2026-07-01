class Solution {
public:
    int ispossible(vector<int>&nums, int mid){
        int count = 1;
        int tempsum = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(tempsum+nums[i] <= mid){
                tempsum += nums[i]; 
            }
            else{
                count++;
                tempsum = nums[i];
            }
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        if(nums.empty()){
            return 0;
        }
        int left = 0;
        int right = 0;
        int ans = 0;
        for(int x : nums){
            left = *max_element(nums.begin(), nums.end());
            right += x;
        }
        while(left<=right){
            int mid = left+(right-left)/2;
            if(ispossible(nums, mid) <= k){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }
};