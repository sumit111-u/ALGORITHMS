class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0) return false;
        int digits = ((int)Math.log10(x)) + 1;
        System.out.println(digits);
        int fr = (int)Math.pow(10, digits-1);
        System.out.println(fr);
        int ba = 1;

        while(fr >= ba){
            int front = x/fr;
            
            int rem1 = front%10;
            System.out.println(rem1);
            int back = x/ba;
            int rem2 = back%10;
            System.out.println(rem2);
            if(rem1 != rem2){
                return false;
            }
            fr /= 10;
            ba *=10;
        }

        return true;
    }
}