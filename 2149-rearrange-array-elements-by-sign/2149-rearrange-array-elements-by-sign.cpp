class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>neg;
        vector<int>pos;

        for(int x : nums){
            if(x < 0){
                neg.push_back(x);
            }
            else{
                pos.push_back(x);
            }
        }
        int n = max(neg.size(), pos.size());
        vector<int>ans;
        for(int i = 0; i<n; i++){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;
    }
};