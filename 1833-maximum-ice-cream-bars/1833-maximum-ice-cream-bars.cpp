class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        long long sum = 0;
        int count = 0;
        for(int i = 0; i<costs.size(); i++){
            sum += costs[i];
            if(sum <= coins){
                count++;
            }
        }
        return count;

    }
};