class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> prefSum(n + 1, 0);
        vector<long long> prefCnt(n + 1, 0);
        vector<long long> prefNum(n + 1, 0);
        vector<long long> pow10(n + 1, 1);

        // Precompute powers of 10
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        // Prefix arrays
        for (int i = 0; i < n; i++) {
            prefSum[i + 1] = prefSum[i];
            prefCnt[i + 1] = prefCnt[i];
            prefNum[i + 1] = prefNum[i];

            int d = s[i] - '0';

            if (d != 0) {
                prefSum[i + 1] += d;
                prefCnt[i + 1]++;
                prefNum[i + 1] = (prefNum[i] * 10 + d) % MOD;
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            long long sum = prefSum[r + 1] - prefSum[l];
            long long cnt = prefCnt[r + 1] - prefCnt[l];

            long long num =
                (prefNum[r + 1] -
                 (prefNum[l] * pow10[cnt]) % MOD + MOD) % MOD;

            ans.push_back((num * sum) % MOD);
        }

        return ans;
    }
};