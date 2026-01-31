class Solution {
public:

void solve(vector<vector<int>>& res, vector<int>& c, int n, int k, int start) {
    if(c.size() == k){
        res.push_back(c);
        return;
    }

    for(int i = start; i <= (n - k + c.size() + 1); i++){
        c.push_back(i);
        solve(res, c, n, k, i + 1);
        c.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> c;
    solve(res, c, n, k, 1);
    return res;
}

};
