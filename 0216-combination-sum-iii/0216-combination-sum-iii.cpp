class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(int start, int k, int sum) {
        // base case: valid combination
        if (k == 0 && sum == 0) {
            ans.push_back(path);
            return;
        }

        // invalid state
        if (k == 0 || sum < 0)
            return;

        for (int i = start; i <= 9; i++) {
            path.push_back(i);          // choose
            dfs(i + 1, k - 1, sum - i); // explore
            path.pop_back();            // backtrack
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, k, n);
        return ans;
    }
};
