class Solution {
public:
    bool isPalindrome(string s) {
        // check all the characters in the string
        // make each character to lower cases to compare
        // start from begin & end of the string and meet in the middle
        int i=0;
        int j=s.length()-1;
        while(i < j){
            // if current character is not alphabet
            if(!isCharValid(s[i])){
                i++;
                continue;
            }
            if(!isCharValid(s[j])){
                j--;
                continue;
            }
            
            // compare the alphabet
            if(tolower(s[i]) != tolower(s[j]))
                return false;
            else{
                i++;
                j--;
            }
        }
        
        return true;
    }
    
    bool isCharValid(char c){
        if(isalpha(c) || isdigit(c))
            return true;
        else
            return false;
    }
};