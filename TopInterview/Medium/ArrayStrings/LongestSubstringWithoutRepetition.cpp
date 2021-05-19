class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        int n = s.size();
        
        // M1) Brute Force (984ms, 264MB)
        if(n==1)
            return 1;
        
        for(int i=0 ; i<n; i++){
            map<char, int> m;
            int substringLen = 0;

            // Check all the substring that starts with s[i]
            for(int j=i ; j<n ; j++){
                map<char, int>::iterator it = m.find(s[j]);
                
                // if there is no hit, add in the map
                if(it == m.end()){
                    substringLen++;
                    m[s[j]] = 1;
                }
                // the character already exists in the map
                else{
                    break;
                }
                
                
                if(substringLen != 0 && substringLen > longest){
                    longest = substringLen;
                }
            }
        }
        
        return longest;
    }
    
    
    int lengthOfLongestSubstring(string s) {
        vector<int> chars(128);

        int left = 0;
        int right = 0;

        int res = 0;
        while (right < s.length()) {
            char r = s[right];
            chars[r]++;

            while (chars[r] > 1) {
                char l = s[left];
                chars[l]--;
                left++;
            }

            res = max(res, right - left + 1);

            right++;
        }

        return res;
    }
};