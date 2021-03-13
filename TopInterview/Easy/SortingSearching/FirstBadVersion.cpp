// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // 0ms, 5.9MB
        int start = 1;
        int end = n;
        int middle = 0;
        
        if(start == end){
            return start;
        }
        
        while(start < end){
            middle = start + (end - start)/2;
            
            if(isBadVersion(middle) == true)
                // move on to lower part of the array
                end = middle;       
        
                
            // if isBadVersion(end) == false
            else{
                
                if(isBadVersion(middle+1) == true)
                    return middle+1;
                
                // Accepted although mine sets start=middle
                // maybe because I check version of middle+1
                start = middle;
            }
        }
        
        return middle;
        
        
        // M2) Simpler version 0ms, 5.8MB
        /*

        int start = 1;
        int end = n;
        
        if(start == end){
            return start;
        }
        
        while(start < end){
            int middle = start + (end-start)/2;
            
            if(isBadVersion(middle) == true){
                end = middle;
            }
                
            else if(isBadVersion(middle) == false){
                // 'start' should be set as 'middle+1'
                // otherwise, would not check all the numbers
                // testcase: (5, 5)
                start = middle+1;
            }
        }
        
        return start;
        */
        
    }
};