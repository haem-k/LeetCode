class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // initialize 
        // min, prev, sum
        int index = 1;
        int min = prices[0];
        int prevPrice = prices[0];
        int sum = 0;
        
        // keep decreasing -> do not buy
        // keep increasing -> do not sell until the end
        while(index < prices.size())
        {
            // prices increase
            if(prices[index] >= prevPrice)
            {
                // if index ends while increasing
                if(index == prices.size()-1)
                    // update sum
                    sum += prices[index] - min;
            }
            else{
                // prices keep decreasing
                if(prevPrice == min){
                    min = prices[index];
                }
                else{
                    // when increasing prices start to decrease, sell to get profit
                    sum += prevPrice - min;   
                    min = prices[index];
                }
            }
            prevPrice = prices[index];
            index++;
        }
        
        // (buy, sell) & (buy, sell) -> max profit
        return sum;
        
    }
};