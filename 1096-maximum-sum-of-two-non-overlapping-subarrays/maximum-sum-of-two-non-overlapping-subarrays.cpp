class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int fl, int sl) {
        int n=nums.size();
        vector<int>suff(n);
        vector<int>pre(n);
        int sm=0;
        for(int r=0;r<n;r++){
            sm+=nums[r];
            if(r>=sl)sm-=nums[r-sl];
            if(r>=sl-1){
                int a=INT_MIN;
            if(r-1>=0)a=pre[r-1];
            pre[r]=max(a,sm);
            }
        }
        sm=0;
        int r=n-1;
        for(int l=n-1;l>=0;l--){
            sm+=nums[l];
            if(l<n-sl){
                sm-=nums[r--];
            }
            if(l<=n-sl){
                int a=INT_MIN;
                if(l+1<n)a=suff[l+1];
                suff[l]=max(a,sm);
            }
        }
        int ans=0;
        sm=0;
        for(int i=0;i<n;i++){
            sm+=nums[i];
            if(i>=fl)sm-=nums[i-fl];
            if(i>=fl-1){
                int left=i-fl+1;
                int a=INT_MIN;
                int b=INT_MIN;
                if(left-1>=0)a=pre[left-1];
                if(i+1<n)b=suff[i+1];
                ans=max(ans,sm+max(a,b));
            }
        }
        return ans;

    }
};