class Solution {
public:
    int hammingWeight(int n) {
        unsigned int count=0;
       while(n){
       n= n&(n-1);
        count++;

       }
       return count;
    }
};