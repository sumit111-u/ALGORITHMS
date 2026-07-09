class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<int,int>p1;
        unordered_map<int,int>p2;
         for( char q:s){
            p1[q]++;
         }
         for( char r:t){
            p2[r]++;
         }
         return  p1==p2;

        

    }
};