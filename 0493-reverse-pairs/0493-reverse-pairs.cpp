class Solution {
private:
    void merge(vector<int>& nums, int low, int mid, int high){
        int left=low,right=mid+1;
        vector<int> ans;

        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                ans.push_back(nums[left]);
                left++;
            }
            else{
                ans.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            ans.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            ans.push_back(nums[right]);
            right++;
        }

        for(int i=low;i<=high;i++){
            nums[i]=ans[i-low];
        }
    }

    int countPairs(vector<int>& nums, int low, int mid,int high){
        int cnt=0;
        int right=mid+1;

        while(low<=mid){
            while(right<=high && (long long)nums[low]>(long long)2*nums[right]){
                right++;
            }
            cnt+=(right-mid-1);
            low++;
        }

        return cnt;
    }

    int mergeSort(vector<int>& nums, int low, int high){
        int cnt=0;
        if(low>=high) return cnt;
        int mid=(low+high)/2;
        cnt+=mergeSort(nums,low,mid);
        cnt+=mergeSort(nums,mid+1,high);
        cnt+=countPairs(nums,low,mid,high);
        merge(nums,low,mid,high);
        return cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergeSort(nums,0,n-1);
    }
};