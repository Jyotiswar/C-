class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestbuy = prices [0];
        int bestsell = 0;
        for( int i = 0 ;i < prices.size(); i++){
            if(prices[i] > bestbuy){
                bestsell = max(bestsell,prices[i] - bestbuy);
            }
            bestbuy = min(bestbuy , prices[i]);
        } 
        return bestsell;
    }
};
