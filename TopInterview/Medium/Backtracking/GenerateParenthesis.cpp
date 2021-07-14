
// M1) Does not work this way!!
vector<string> generateParenthesis(int n) {
        vector<string> result;
        
        result = traverseParenthesis(n);
        
        return result;
}
    
vector<string> traverseParenthesis(int n){
    vector<string> result;
    
    if(n == 1){
        result.push_back("()");
        return result;
    }
    
    // generated parenthesis from previous n
    vector<string> previous = traverseParenthesis(n-1);
    int size = previous.size();
    for(int i=0 ; i<size ; i++){
        // if last element
        if(i != size-1){
            string s1 = "()" + previous[i];
            result.push_back(s1);
        }
        string s2 = "(" + previous[i] + ")";
        string s3 = previous[i] + "()";
        result.push_back(s2);
        result.push_back(s3);
    }
    
    return result;
}


// M2) Get away from stack.. Using two integer is enough!!
vector<string> generateParenthesis(int n) {
    vector<string> result;
    
    addParenthesis(result, "", n, 0);
    
    return result;
}

void addParenthesis(vector<string>& result, string str, int leftP, int rightP){
    if(leftP == 0 && rightP == 0){
        result.push_back(str);
        return;
    }
    
    if(rightP > 0)
        addParenthesis(result, str+")", leftP, rightP-1);
    if(leftP > 0)
        addParenthesis(result, str+"(", leftP-1, rightP+1);
    
    return;
}