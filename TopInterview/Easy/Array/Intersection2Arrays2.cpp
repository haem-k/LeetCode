class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // intersection of two arrays
        vector<int> result;
//         // M1)
//         // two indices go through vectors and compare elements
//         for(int i=0 ; i<nums1.size() ; i++){
//             for(int j=0 ; j<nums2.size() ; j++){
//                 // compare every element in the other array
//                 if(nums1[i] == nums2[j]){    // 2, 2
//                     // if there is an element, delete it from the array, continue current iteration
//                     result.push_back(nums1[i]);
//                     nums2.erase(nums2.begin() + j);
//                     break;
//                 }
//             }
//         }
        
        // M2)        
        // What if the given array is already sorted? How would you optimize your algorithm?
        // given sorted arrays
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        // two indices to track each element
        int index1 = 0;
        int index2 = 0;
        
        // end iteration when there is no more numbers to compare
        while(index1 < nums1.size() && index2 < nums2.size()){
            // if 
            if(nums1[index1] < nums2[index2]){
                index1++;
            }
            else if(nums1[index1] > nums2[index2]){
                index2++;
            }
            else{
                result.push_back(nums1[index1]);
                index1++;
                index2++;
            }
        }
        
        return result;
        
        // M3)
        // What if nums1's size is smaller compared to nums2's size? Which algorithm is better?
        
        
        // M4)
        // What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once? -> 알고리즘 짤 때 어떻게 반영이 되어야 하나?

    }
};