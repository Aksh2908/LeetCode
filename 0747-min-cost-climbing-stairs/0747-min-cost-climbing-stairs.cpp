class Solution {
private:
    int solve(vector<int>& cost, int n){
        int prev1=cost[0];
        int prev=cost[1];
        int curr=INT_MAX;
        for(int i=2;i<n;i++){
            curr=min(prev,prev1)+cost[i];
            prev1=prev;
            prev=curr;
        }
        curr=min(prev,prev1);
        return curr;
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        return solve(cost,n);
    }
};