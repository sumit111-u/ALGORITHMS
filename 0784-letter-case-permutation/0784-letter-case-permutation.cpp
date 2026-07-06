class Solution {
public:
    
  void solve(string s, int idx,vector<string>&ans){
    if( idx==s.size()){
        ans.push_back(s);
        return ;
        
    }
    if(isdigit(s[idx])){
        solve(s,idx+1,ans);
    }
    else{
        s[idx]=tolower(s[idx]);
        solve( s,idx+1,ans);
        s[idx]=toupper(s[idx]);
        solve(s,idx+1,ans);
    }
}
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        solve(s,0,ans);
         return ans;
    }
};