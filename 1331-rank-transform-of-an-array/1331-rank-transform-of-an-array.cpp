class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> brr = arr;
        sort(brr.begin(), brr.end());
        brr.erase(unique(brr.begin(), brr.end()), brr.end());

        for (int &ai : arr) ai = upper_bound(brr.begin(), brr.end(), ai) - brr.begin();
        return arr;
    }
};