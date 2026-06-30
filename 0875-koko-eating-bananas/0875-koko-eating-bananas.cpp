class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       int left = 1;
       int right = *max_element(piles.begin(), piles.end());
        
       while(left<right){
        int mid = left + (right - left )/2;
        int hr = 0;
        for(int pile : piles){
            hr += (pile+mid-1)/mid;
        }

            if(hr>h){
                left = mid+1; 
            }
            else{
                right = mid;
            }
       }
        return left;    
        
    }
};