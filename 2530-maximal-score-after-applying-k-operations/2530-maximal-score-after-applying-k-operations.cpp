class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        int x=0;
       long long  score=0;
        for( auto it:nums){
            pq.push(it);
            }
            while(k>0){
                x=pq.top();
                score+=pq.top();
                pq.pop();
                pq.push(ceil(x/3.0));
                k--;

            }
            return score;

        
    }
};