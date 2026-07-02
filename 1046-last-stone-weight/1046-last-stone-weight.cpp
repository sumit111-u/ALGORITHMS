class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        int x;
        int y;
        int res=0;
        int n =stones.size();
        for( auto it :stones){
            pq.push(it);
        }
        while(pq.size()>1){
            x=pq.top();

            pq.pop();
            y=pq.top();
            pq.pop();
            res=abs(x-y);
            pq.push(res);


        }
        return pq.top();
    
    }
};