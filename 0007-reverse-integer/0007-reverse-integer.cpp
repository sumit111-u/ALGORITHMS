class Solution {
public:
    int reverse(int x) {
        long ans = 0;
        long temp = 0;

        if (x < 0) {
            temp = -(long)x;

            while (temp > 0) {
                int digit = temp % 10;
                ans = ans + digit;
                ans = ans * 10;
                temp = temp / 10;
            }

            ans /= 10;

            if (ans > INT_MAX)
                return 0;

            return -(int)ans;
        }
        else {
            while (x > 0) {
                int digit = x % 10;
                ans = ans + digit;
                ans = ans * 10;
                x = x / 10;
            }

            ans /= 10;

            if (ans > INT_MAX)
                return 0;

            return (int)ans;
        }
    }
};