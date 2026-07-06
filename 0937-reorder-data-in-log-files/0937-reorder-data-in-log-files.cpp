class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string, string>> let;
        vector<pair<string, string>> dig;

        for (auto i : logs) {
            string s = "";   // identifier
            string t = "";   // content
            bool flag = false;

            for (int j = 0; j < (int)i.size(); j++) {

                if (i[j] == ' ' && flag == false) {
                    flag = true;
                    continue;
                }

                if (flag == false)
                    s += i[j];
                else
                    t += i[j];
            }

            if (isalpha(t[0])) {
                let.push_back({t, s});
            } else {
                dig.push_back({t, s});
            }
        }

        sort(let.begin(), let.end());

        vector<string> ans;

        for (auto i : let) {
            ans.push_back(i.second + " " + i.first);
        }

        for (auto i : dig) {
            ans.push_back(i.second + " " + i.first);
        }

        return ans;
    }
};