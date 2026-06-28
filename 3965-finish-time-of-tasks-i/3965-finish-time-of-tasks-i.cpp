class Solution {
public:
    long long dfs(int u, vector<vector<int>>& adj, vector<int>& baseTime) {
        if(adj[u].empty())
            return baseTime[u];
        long long mn=LLONG_MAX;
        long long mx=LLONG_MIN;
        for( int v:adj[u]){
            long long child=dfs(v,adj,baseTime);
            mn=min(mn,child);
            mx=max(mx,child);
        }
        return mx+(mx-mn)+baseTime[u];
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime){
         vector<vector<int>> adj(n);
        for( auto &e:edges){
            adj[e[0]].push_back(e[1]);
        }
        return dfs(0,adj,baseTime);
    }
};