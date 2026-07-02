class Solution {
public:
    long minOperations(vector<int>& nums, int k) {
        priority_queue<long ,vector<long>,greater<long>>pq;
        long x=0;
        long y=0;
        long count=0;
        // vector<long>res;

         for( auto & it :nums){
            pq.push(it);
         }
         while(pq.size()>=2 && pq.top()<k){
            x=pq.top();
            // res.push_back(x);
            pq.pop();
            y=pq.top();
            // res.push_back(y);
            pq.pop();
            pq.push((min(x, y) * 2 + max(x, y)));
            count++;
            



         }
        return count;
    }
};