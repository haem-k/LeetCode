class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroNum = 0;
        int index = 0;
        while(index < nums.size()){
            if(nums[index] == 0){
                zeroNum++;
                nums.erase(nums.begin()+index);
            }
            else{
                index++;
            }
        }
        nums.insert(nums.begin()+nums.size(), zeroNum, 0);
        
    }
};