class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> vec;
        for(int x : nums1) vec.push_back(x);
        for(int x : nums2) vec.push_back(x);
        
        sort(vec.begin(), vec.end());
        int n = vec.size();
        
        if(n % 2 == 1) {
            return vec[n / 2];
        }
        return (vec[n / 2 - 1] + vec[n / 2]) / 2.0;
    }
};