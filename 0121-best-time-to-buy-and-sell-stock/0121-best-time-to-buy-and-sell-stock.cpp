class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i,profit=0,mini=prices[0];
        int cost=0;
        for(i=1;i<prices.size();i++){
            cost=prices[i]-mini;
            profit=max(profit,cost);
            mini=min(mini,prices[i]);
        }
        return profit;
    }
};