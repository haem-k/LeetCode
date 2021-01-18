class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // for k, 
        // get the last element of the array 
        // pop the last element
        // insert the last element at the front of the array
        
        // M1)
        while(k > 0){
            int last = nums.back();
            nums.pop_back();
            nums.insert(nums.begin(), last);
            k--;
        }
        
        // M2)
        // two pointers?
    }
};