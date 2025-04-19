class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int i=0,j=n-1;
        while(i<m && j>=0){
            int pivot=matrix[i][j];
            if(pivot==target) return true;
            else if(pivot>target) j--;
            else i++;
        }
        return false;
    }
};