class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=0,maxprofit=0;
        for(int i=1; i<prices.size();i++){
            if(prices[i]<prices[buy]){
                buy=i;
            }
            else{
                maxprofit=max(maxprofit,prices[i]-prices[buy]);
            }
        }
    return maxprofit;
    }
};