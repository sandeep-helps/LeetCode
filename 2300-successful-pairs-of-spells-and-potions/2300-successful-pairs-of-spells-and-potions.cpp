class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {       
        int n = spells.size();
        int m = potions.size();
        vector<int>ans(n);
        sort(potions.begin(), potions.end());
        for(int i = 0; i<n; i++){
            int left = 0;
            int right = m -1;
            int firstvalid = m;
            while(left<=right){
                int mid = left+(right-left)/2;
                if(1LL * spells[i] * potions[mid] >= success){
                    firstvalid = mid;
                    right = mid-1;   
                }
                else{
                    left = mid+1;
                }
                ans[i] = m - firstvalid;
            }
        }
        return ans;
    }
};