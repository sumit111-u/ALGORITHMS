class Solution {
public:
    vector<string> res;

    bool valid(string curr) {
        stack<char> st;   // local stack (important!)

        for (char ch : curr) {
            if (ch == '(') {
                st.push(ch);
            } 
            else { // ch == ')'
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    return false; // invalid closing
                }
            }
        }
        return st.empty();
    }

    void solve(string &curr, int n) {
        if (curr.length() == 2 * n) {
            if (valid(curr)) {
                res.push_back(curr);
            }
            return;
        }

        curr.push_back('(');
        solve(curr, n);
        curr.pop_back();

        curr.push_back(')');
        solve(curr, n);
        curr.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        string curr = "";
        solve(curr, n);
        return res;
    }
};
