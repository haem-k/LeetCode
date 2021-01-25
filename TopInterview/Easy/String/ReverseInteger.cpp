class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        
        while(x != 0){
            // pop the digit
            int digit = x%10;
            x /= 10;

            // before pushing the digit, check if it is within the range of int
            if(rev > INT_MAX/10 || rev == INT_MAX/10 && digit > 7) return 0;
            if(rev < INT_MIN/10 || rev == INT_MIN/10 && digit < -8) return 0;
            
            // push the digit
            rev = rev*10 + digit;

        }
        
        
        return rev;
    }

    
    
};