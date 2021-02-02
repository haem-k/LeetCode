
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        
        unordered_map<char, int> str1;
        
        // Initialize unordered map for s
        for(int i=0; i<s.length() ; i++){
            if(str1.find(s[i]) == str1.end()){
                // If there is no such character, initialize
                str1[s[i]] = 1;
            }
            else{
                // If there is a character, increment
                str1[s[i]] += 1;
            }
        }
        
        // Iterate through t to check if there is all characters in str1
        for(int i=0; i<t.length(); i++){
            if(str1.find(t[i]) == str1.end()){
                // If there is no such character, return
                return false;
            }
            else{
                // If there is a character, 
                if(str1[t[i]] == 0)
                    return false;
                
                str1[t[i]] -= 1;
            }
        }
        
        
        for(auto it=str1.begin(); it != str1.end(); it++){
            if(it->second > 0)
                return false;
        }
        
        return true;
    }
};
