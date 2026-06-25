class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string s1=strs.front();
        string s2=strs.back();
          int minl=min( s1.size(),s2.size());
          int i=0;
        while( i<minl && s1[i]==s2[i]){
            i++;
        }
         return s1.substr(0,i);
    }
};