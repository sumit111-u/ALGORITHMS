class Solution {
public:
    string removeKdigits(string num, int k) {

        int n = num.size();
        stack<char> st;

        st.push(num[0]);

        for(int i = 1; i < n; i++) {

            while(!st.empty() && k > 0 && num[i] < st.top()) {
                st.pop();
                k--;
            }

            st.push(num[i]);
        }

        // if k still left, remove from end
        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // build answer
        string ans = "";

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        // remove leading zeros
        int idx = 0;
        while(idx < ans.size() && ans[idx] == '0') idx++;

        ans = ans.substr(idx);

        if(ans == "") return "0";

        return ans;
    }
};
