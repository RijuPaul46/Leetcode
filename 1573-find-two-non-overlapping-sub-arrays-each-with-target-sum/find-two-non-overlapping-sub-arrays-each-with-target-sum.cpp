class Solution {
public:

    int minSumOfLengths(vector<int>& arr, int target) {
        // i need min length of subarray of sum=tgt ending at i-1
        // and starting at i .... then starting at i
        int mn=INT_MAX;
        int n=arr.size();
        vector<int>pre(n+1),suff(n+1);
        pre[0]=INT_MAX;
        int i=0,j=0;
        int sm=0;
        while(j<n){
            sm+=arr[j];
            while(sm>target && i<j){
                sm-=arr[i++];
            }
            if(sm==target){
                mn=min(mn,j-i+1);
            }
            pre[j+1]=mn;
            j++;
        }
        i=n-1,j=n-1;
        mn=INT_MAX;
        sm=0;
        while(i>=0){
            sm+=arr[i];
            while(sm>target && j>i){
                sm-=arr[j--];
            }
            if(sm==target){
                mn=min(mn,j-i+1);
            }
            suff[i--]=mn;
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(pre[i]!=INT_MAX && suff[i]!=INT_MAX)
            ans=min(ans,pre[i]+suff[i]);
        }
        return ans==INT_MAX?-1:ans;
    }
};