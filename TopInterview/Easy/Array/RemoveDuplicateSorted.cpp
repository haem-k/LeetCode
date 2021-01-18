class Solution {

public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        // use pointer to scan through the vector
        int index = 1;
        int prevNum = nums[0];
        
        // end iteration if pointer reaches the length of the vector
        while(index < nums.size())
        {
            if(nums[index] == prevNum){
                nums.erase(nums.begin() + (index - 1));
            }
            else{
                prevNum = nums[index];
                index++;
            }
        }
               
        return nums.size();
    }
};