class Solution {
public:
    
    // M1) Brute Force
    // look for every possible pairs and check if they are palindromic strings
    bool isPalindrome(string s) {
        // check all the characters in the string
        // make each character to lower cases to compare
        // start from begin & end of the string and meet in the middle
        int i=0;
        int j=s.length()-1;
        while(i < j){
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
    
    
    string longestPalindrome(string s) {
        string result;
        
        for(int i=0 ; i<s.size() ; i++){
            for(int j=i ; j<s.size() ; j++){
                string sub = s.substr(i, j-i+1);
                if(isPalindrome(sub) && result.size() < sub.size())
                    result = sub;
                else
                    continue;
            }            
        }
        
        return result;
    }
    
    
    
    ////////////////////////////////////////////////////////////////////////////////
    // M2) Dynamic Programming (136ms, 25.7MB)
    // keep the calculated results and check palindrome starting from the previous results
    string longestPalindrome(string s){
        int n = s.size();
        string result;
        
        // Should start with the first character
        // the for loop does not deal with this case
        result += s[0];

        if(n==0)
            return "";
        
        // Check if valid palindrome for substring (i,j)
        bool dp[n][n];
        // Initialize the value with false
        memset(dp, 0, sizeof(dp));
        
        // One character is always a valid palindrome
        for(int i=0 ; i<n ; i++){
            dp[i][i] = true;
        }
        
        // Check if substrings are palindrome
        for(int i=n-2 ; i>=0 ; i--){
            for(int j=i+1 ; j<n ; j++){
                // Two characters are same
                if(s[i] == s[j]){
                    
                    // If they are consecutive characters
                    // or its substring is a valid palindrome,
                    // this string is also palindrome
                    if(j-i==1 || dp[i+1][j-1]){
                        dp[i][j] = true;
                        
                        if(result.size() < j-i+1)
                            result = s.substr(i, j-i+1);
                    }
                }
            }
        }
        
        return result;
    }
    
};