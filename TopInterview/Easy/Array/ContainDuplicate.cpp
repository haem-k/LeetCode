class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        if(nums.size() < 1){
            return false;
        }
        
        // return true if any value appears at least twice
        // return false if evey element is distinct
        sort(nums.begin(), nums.end());
        int prevNum = nums[0];
        for(int i=1 ; i<nums.size() ; i++)
        {
            if(nums[i] == prevNum)
                return true;
            prevNum = nums[i];
        }
        
        return false;
    }
};