class Solution {
public:
    int firstUniqChar(string s) {
        
        // 76ms, 10.7mb
        // map<char, int> uniqChar;
        
        // 56ms, 10.7mb
        unordered_map<char, int> uniqChar;
        
        for(int i=0 ; i<s.length() ; i++){
            if(uniqChar.find(s[i]) == uniqChar.end()){
                // if there is no character, initialize
                uniqChar[s[i]] = 1;
            }
            else{
                // if there is a character, increment the number
                uniqChar[s[i]] += 1;
            }
        }
        
        for(int i=0 ; i<s.length() ; i++){
            if(uniqChar[s[i]] == 1){
                return i;
            }
        }
        
        return -1;
    }
};