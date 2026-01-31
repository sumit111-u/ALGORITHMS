class Solution {
public:

    int length(vector<int>& v) {
        if (v.empty()) return 0;

        vector<int> tails;

        for (int x : v) {
            auto it = lower_bound(tails.begin(), tails.end(), x);

            if (it == tails.end()) {
                tails.push_back(x);
            } else {
                *it = x;
            }
        }

        return tails.size();
    }

    int longestSubsequence(vector<int>& nums) {

        int maxLen = 0;

        for (int k = 0; k <= 30; ++k) {
            vector<int> filtered;

            for (int num : nums) {
                if ((num >> k) & 1) {
                    filtered.push_back(num);
                }
            }

            maxLen = max(maxLen, length(filtered));
        }

        return maxLen;
    }
};
