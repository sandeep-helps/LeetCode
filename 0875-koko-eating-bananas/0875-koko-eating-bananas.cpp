class Solution {
public:
    bool canEatAll(vector<int>&piles,int mid, int h){
        int actualhour = 0;
        for(int &x : piles){
            actualhour += x / mid;
            if(x % mid != 0){
                actualhour++;
            }
        }
        return actualhour <= h; 
    }
    int minEatingSpeed(vector<int>& piles, int h) {
       int l = 1;
       int r = *max_element(piles.begin(), piles.end());
       while(l<r){
            int mid = l+(r-l)/2;
            if(canEatAll(piles, mid, h)){
                r = mid;
            }
            else{
                l = mid+1;
            }
       }
       return l;
    }
};