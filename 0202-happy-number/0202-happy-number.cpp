class Solution {
public:
int getNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            int digit = n % 10; // Get the last digit
            totalSum += digit * digit;
            n /= 10;            // Remove the last digit
        }
        return totalSum;
    }
    bool isHappy(int n) {
        unordered_set<int>seen;
        
        while(n!=1 && seen.find(n)==seen.end()){
            seen.insert(n);
            n=getNext(n);
           
        }
        return n==1;


    
    }
};