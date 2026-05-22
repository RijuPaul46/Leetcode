class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return 0;
        vector<int> diff;
        for(int i=1;i<n;i++){
            int d=nums[i]-nums[i-1];
            diff.push_back(d);
        }
        vector<int>f(n+1);
        f[0]=0;
        f[1]=0;
        f[2]=0;
        for(int i=3;i<=n;i++){
            f[i]=i-2+f[i-1];
        }
        int ans=0;
        int streak=1;
        for(int i=1;i<diff.size();i++){
            if(diff[i]!=diff[i-1]){
                ans+=f[streak+1];
                streak=1;
            }
            else{
                streak++;
            }
        }
        ans+=f[streak+1];
        return ans;
    }
};