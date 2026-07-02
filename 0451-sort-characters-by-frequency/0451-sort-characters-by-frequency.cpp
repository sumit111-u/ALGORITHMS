class Solution {
public:
struct lambda{
        typedef pair<char,int>P;
        bool operator()(P &P1,P&p2){
             return P1.second<p2.second;
        }
};
    string frequencySort(string s) {
        string res="";
       priority_queue<lambda::P,vector<lambda::P>,lambda>pq;
        unordered_map<char,int>mp;
        // frequency update
        for( auto &ch: s){
            mp[ch]++;
        }
        // filll in heap
        for( auto it:mp){
           pq.push({it.first,it.second});
        }
        while(!pq.empty()){
           lambda::P temp=pq.top();
           pq.pop();
            res+=string(temp.second,temp.first);

        }
        return res;
        
    }
};