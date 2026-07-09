class Solution {
public:

// no ofnodes n 
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool>ans;
        vector<int>g(n);
        int cnt=0;
        for( int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>maxDiff){
                cnt++;
            }
            g[i]=cnt;
        }
        for( auto & it: queries){
            int u=it[0];
            int v=it[1];
            ans.push_back(g[u]==g[v]);
        }

return  ans;
    }
};