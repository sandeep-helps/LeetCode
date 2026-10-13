class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();      
        // Squares nikalo
        vector<long long> sq(n);
        for(int i = 0; i < n; i++){
            sq[i] = (long long)nums[i] * nums[i];
        }
        // Sort karo
        sort(sq.begin(), sq.end()); 
        int plusCount = (n + 1) / 2;   // bade wale
        int minusCount = n / 2;         // chhote wale
        long long score = 0;
        // Last ke plusCount → plus positions
        for(int i = n - plusCount; i < n; i++){
            score += sq[i];
        }
        // First ke minusCount → minus positions
        for(int i = 0; i < minusCount; i++){
            score -= sq[i];
        }
        return score;
    }
};