class Solution {
public:
    bool checkGoodInteger(int n) {
        string s = to_string(n);
        int p = s.size();

        int digitsum = 0;
        int squaresum = 0;

        for (int i = 0; i < p; i++) {
            int digit = s[i] - '0';
            digitsum += digit;
            squaresum += digit * digit;
        }

        return (squaresum - digitsum >= 50);
        
    }
};