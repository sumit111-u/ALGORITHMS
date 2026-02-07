class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool> &visted) {
        int n = isConnected.size();
        visted[node] = true;
        for (int nr = 0; nr < n; nr++) {
            if (isConnected[node][nr] == 1 && !visted[nr]) {
                dfs(nr, isConnected, visted);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;
        vector<bool> visted(n, false);
        for (int i = 0; i < n; i++) {

            if (!visted[i]) {
                ans++;
                dfs(i, isConnected, visted);
            }
        }
        return ans;
    }
};