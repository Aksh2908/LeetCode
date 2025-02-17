class Solution {
public:
    int maxElt(vector<vector<int>> v,int m, int n, int mid){
        int maxi=INT_MIN,idx=-1;
        int i;
        for(i=0;i<m;i++){
            if(v[i][mid]>maxi){
                maxi=v[i][mid];
                idx=i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        int low=0,high=n-1;
        int row,left,right;
        while(low<=high){
            int mid=(low+high)/2;
            row=maxElt(mat,m,n,mid);
            left=(mid-1>=0)?mat[row][mid-1]:-1;
            right=(mid+1<n)?mat[row][mid+1]:-1;
            if(mat[row][mid]>left && mat[row][mid]>right){
                return {row,mid};
            }
            else if(mat[row][mid]<left) high=mid-1;
            else low=mid+1;
        }
        return {-1,-1};
    }
};