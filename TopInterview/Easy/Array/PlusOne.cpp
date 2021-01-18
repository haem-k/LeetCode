class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int index = digits.size() - 1;
        digits[index] += 1;
        
        while(index >= 0)
        {
            // need to add 1 to higher digit if it is 10
            if(digits[index] == 10){
                digits[index] = 0;
                if(index == 0){
                    // particularly for this case, digit at index should be first set to zero
                    // because inserting will change the index  
                    digits.insert(digits.begin(), 1);
                }
                else{
                    digits[index-1] += 1;

                }
            }
            else{
                return digits;
            }
            index--;
        }
        
        return digits;
    }
};