class Solution {
public:


    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>mp;
        vector<int>res;
        for( auto &s :nums){
            mp[s]++;
        }
        for( auto &it : mp){
            pq.push({it.second,it.first});

        }
        while( k>0){
            res.push_back(pq.top().second);
            pq.pop();
            k--;

        }
        return res;
          
    }
};