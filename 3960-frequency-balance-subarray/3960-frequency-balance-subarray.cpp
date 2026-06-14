class Solution {
public:
    int getLength(vector<int>& nums) {
        int len = 0;
        int n = nums.size();

        // freq[key] = frequency of that value in current subarray
        map<int, int> freq;

        // revFreq[key] = how many elements have freq = key, thus key is frequency of some element
        map<int, int> revFreq;

        for (int i = 0; i < n; i++) {
            freq.clear();
            revFreq.clear();

            for (int j = i; j < n; j++) {

                // If current value already exists, remove its old frequency

                if (freq.find(nums[j]) != freq.end()) {
                    revFreq[freq[nums[j]]]--;

                    if (revFreq[freq[nums[j]]] == 0) {
                        revFreq.erase(freq[nums[j]]);
                    }
                }

                // Increase frequency of current value.
                freq[nums[j]]++;

                // Add the updated frequency into revFreq.
                revFreq[freq[nums[j]]]++;

                /*
                    Frequency balanced conditions:
                    1. All elements same thus (freq.size() == 1)
                    2. f and 2*f (revFreq.size() == 2 &&
                     revFreq.begin()->first * 2 == revFreq.rbegin()->first)
                */
                if ((revFreq.size() == 2 &&
                     revFreq.begin()->first * 2 == revFreq.rbegin()->first) ||
                    (revFreq.size() == 1 && freq.size() == 1)) {

                    len = max(len, j - i + 1);
                }
            }
        }

        return len;
    }
};