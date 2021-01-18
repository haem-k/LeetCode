class Solution {
public:
    int singleNumber(vector<int>& nums) {
//         if(nums.size() == 1){
//             return nums[0];
//         }
        
//         sort(nums.begin(), nums.end());
        
//         int pair = nums[0];
//         for(int i=1; i<nums.size() ; i++){
//             // found pair
//             if(nums[i] == pair)
//                 pair = 0;
//             // did not match
//             else if(pair != 0){
//                 return pair;
//             }
//             else{
//                 pair = nums[i];
//             }
//         }
        
//         return pair;
        
//         // M2) Hash Table
//         unordered_map<int, int> intmap;
        
//         for(int i=0 ; i<nums.size() ; i++){
//             intmap[nums[i]] += 1;
//         }
        
//         for(auto it : intmap){
//             if(it.second == 1){
//                 return it.first;
//             }
                
//         }
//         return -1;
        
//         // M3) Math
//         int sum = 0;
//         int uniqueSum = 0;
        
//         for(int i=0 ; i<nums.size() ; i++){
//             sum += nums[i];        
//         }
        
//         sort(nums.begin(), nums.end());
//         // unique should be used in sorted arrays!! 
//         nums.erase(unique(nums.begin(), nums.end()), nums.end());
//         for(int i=0 ; i<nums.size() ; i++){
//             uniqueSum += nums[i];        
//         }
//         return uniqueSum*2 - sum;
        
        
        // M4) XOR - if same return 0, if different return 1
        int result = 0;
        
        for(int iter: nums){
            // 
            result ^= iter;
        }
        return result;
        
    }
};