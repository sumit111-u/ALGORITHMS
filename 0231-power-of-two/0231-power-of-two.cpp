class Solution {
public:
    bool isPowerOfTwo(int n) {
        // 0 ya negative numbers power of 2 nahi hote
        if (n <= 0) {
            return false;
        }
        
        // Jab tak number 2 se completely divide hota hai, karte raho
        while (n % 2 == 0) {
            n = n / 2;
        }
        
        // Agar end mein 1 bacha, toh true, warna false
        return n == 1;
    }
};