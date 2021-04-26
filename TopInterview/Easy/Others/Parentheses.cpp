class Solution {
public:

    // 0ms, 6.2MB
    bool isValid(string s) {
        stack<char> st;
        
        // Check if given string is in pairs
        if(s.size()%2 == 1)
            return false;
        
        // Check all characters in given string
        for(int i=0 ; i<s.size() ; i++)
        {
            if(st.empty()){
                if(s[i] == ')' || s[i] == '}' || s[i] == ']')
                    return false;
            }
            
            switch(s[i]){
                case '(':
                case '{':
                case '[':
                    st.push(s[i]);
                    break;
                    
                case ')':
                    if(st.top() == '(')
                        st.pop();
                    else
                        return false;
                    break;
                case '}':
                    if(st.top() == '{')
                        st.pop();
                    else
                        return false;
                    break;
                case ']':
                    if(st.top() == '[')
                        st.pop();
                    else
                        return false;
                    break;
            }
        }
        
        
        if(!st.empty())
            return false;
        return true;
    }
};