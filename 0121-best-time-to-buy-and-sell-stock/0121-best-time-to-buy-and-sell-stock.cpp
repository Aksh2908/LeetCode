class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i,profit=0,mini=prices[0];
        int maxProfit=0;
        for(i=1;i<prices.size();i++){
            profit=prices[i]-mini;
            maxProfit=max(maxProfit,profit);
            mini=min(mini,prices[i]);
        }
        return maxProfit;
    }
};