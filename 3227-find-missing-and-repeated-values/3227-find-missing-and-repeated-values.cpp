class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        map<int, int> mpp;
        int sum = 0, total_sum = 0;
        for (auto& row:grid) {
            for (int x:row) {
                mpp[x]++;
            }
        }
        for (auto it:mpp) {
            sum += it.first;  
            total_sum += it.first * it.second; 
        }
        int actual_sum = (n*n * (n*n+1)) / 2;
        return {total_sum-sum, actual_sum-sum};
    }
};