class Solution {
public:
    int myAtoi(string s) {
        // declare pointer
        int i = 0;
        
        // number of characters
        int num = s.size();
        
        // number info
        int sign = 1;
        int decimal = 0;
        int result = 0;
        
        // check for leading whitespace
        while(i < num){
            char current = s[i];
            
            if(current != ' ')
                break;
            else
                i++;
        }
        
        
        
        
        // +, -, number, letter
        if(s[i] == '+')
            i++;
        else if(s[i] == '-'){
            sign = -1;
            i++;
        }
        else if(s[i] < '0' || s[i] > '9'){
            return 0;
        }
        
        
        
        
        // check for numbers
        while(i < num){
            char current = s[i];
            
            // check for decimals
            if(current == '.'){
                decimal--;    
            }
            // return if no digits are found
            else if(current < '0' || current > '9'){
                return result;
            }
            // check for digits
            else{
                int digit = current - '0';
                
                if(decimal < 0){
                    result = result + pow(10, decimal)*digit;
                    decimal--;
                }
                else{
                    // before pushing the digit, check if it is within the range of int
                    if(result > INT_MAX/10 || result == INT_MAX/10 && digit*sign > 7) return INT_MAX;
                    if(result < INT_MIN/10 || result == INT_MIN/10 && digit*sign < -8) return INT_MIN;
                    
                    result = result * 10 + digit*sign;
                }
                
            }
            
            
            i++;
                
        }
        
        return result;
        
    }
};