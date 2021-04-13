class Solution {
public:
    // M1) with recursion (12ms, 5.8MB)
    bool isPowerOfThree(int n) {
        if(n <= 0)
            return false;
        return dividedByThree(n);
    }
    
    bool dividedByThree(int n){
        if(n == 1)
            return true;
        
        if(n%3 == 0)
            return dividedByThree(n/3);
        else
            return false;
    }
    
    
    
    // M2) with iteration (8ms, 5.9MB)
    bool isPowerOfThree(int n){
        if(n <= 0)
            return false;
        
        while(n != 1){
            if(n%3 != 0)
                return false;
            n /= 3;
        }
        
        return true;
    }
    
    
    
    // M3) without iteration - log (8ms, 6.1MB)
    bool isPowerOfThree(int n){
        // % : integer remainder
        // fmod : returns floating-point remainder 
        if(n <= 0)
            return false;
        
        double log3 = log10(n) / log10(3);
        if(fmod(log3, 1) == 0)
            return true;
        
        return false;
    }
    
    
    
    // M4) without iteration - get maximum powered number and check remainder (16ms, 5.9MB)
    bool isPowerOfThree(int n){
        if(n <= 0)
            return false;
        
        int maxPower=1;
        while(maxPower < INT_MAX/3){
            maxPower = maxPower*3;
        }
        // for(maxPower = 1 ; maxPower<INT_MAX/3 ; maxPower=maxPower*3){}
        
        if(maxPower%n == 0)
            return true;
        return false;
    }
    
    
    
};