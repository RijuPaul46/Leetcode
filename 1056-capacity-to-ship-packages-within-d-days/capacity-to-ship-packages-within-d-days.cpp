class Solution {
public:
    bool check(vector<int>&arr,vector<int>&pre,int days,int cap){
        int idx=-1;
        int n=pre.size();
        int val=0;
        int cnt=0;
        while(idx<n-1){
            int up=upper_bound(pre.begin(),pre.end(),val+cap)-pre.begin();
            up--;
            if(up==idx)return false;
            cnt++;
            idx=up;
            val=pre[idx];
            
        }
        return cnt<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        vector<int>pre(n);
        pre[0]=weights[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+weights[i];
        }
        int l=*max_element(weights.begin(),weights.end()),h=1e8;
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(check(weights,pre,days,mid)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};