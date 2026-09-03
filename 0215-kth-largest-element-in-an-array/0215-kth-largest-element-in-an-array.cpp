class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // using min-heap
        priority_queue<int, vector<int>, greater<int>>pq; // maxheap
        for(int num : nums){
            pq.push(num);
            if(pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
    }
};