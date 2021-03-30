class Solution {
public:
    
    // M1) Brute Force, O(n^2)
//     int maxProfit(vector<int>& prices) {
//         vector<int> profit;
//         profit.push_back(0);
//         int max_profit=0;
        
//         for(int i=1 ; i<prices.size() ; i++){
//             profit.push_back(0);
            
//             for(int j=0 ; j<i ; j++){
//                 if(prices[i]-prices[j] > profit[j]){
//                     profit[j] = prices[i]-prices[j];
//                 }
//             }
//         }
        
//         // return maximum value in profit
//         return *max_element(profit.begin(), profit.end());
//     }
    
    
    // M2) Save minimum & max profit
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1)
            return 0;
        
        int max_profit=0;
        int min_price=prices[0];
        
        for(int i=1 ; i<prices.size() ; i++){
            if(prices[i-1] < prices[i])
                max_profit = max(prices[i]-min_price, max_profit);
            else
                min_price = min(prices[i], min_price);
        }
        
        return max_profit;
    }
};
