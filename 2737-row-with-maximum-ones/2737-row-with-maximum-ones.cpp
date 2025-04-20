class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxRow=0,maxOnes=0;
        int i,j,m=mat.size(),n=mat[0].size();
        for(i=0;i<m;i++){
            int ones=0;
            for(j=0;j<n;j++){
                ones+=mat[i][j];
            }
            if(ones>maxOnes){
                maxOnes=ones;
                maxRow=i;
            }
        }
        return {maxRow,maxOnes};
    }
};