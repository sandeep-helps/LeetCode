class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         int n = nums.size();
        k = k % n;  // IMPORTANT: handle large k
        vector<int> result(n);
        // Rotate right by k positions
        for(int i = 0; i < n; i++) {
            result[(i + k) % n] = nums[i];
        }
        // Assign back to original array
        nums = result;
    }
};
