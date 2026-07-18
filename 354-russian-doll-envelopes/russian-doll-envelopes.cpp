class Solution {
public:
    
    int maxEnvelopes(vector<vector<int>>& env) {
        int n=env.size();
        sort(env.begin(),env.end(),[](const auto &a,const auto &b){
            int a0=a[0];
            int a1=b[0];
            int b0=a[1];
            int b1=b[1];
            if(a0<a1){
                return true;
            }
            else if(a0==a1){
                return b0>b1;
            }
            return false;
        });
        int ans=1;
        vector<int>tails;
        for(int i=0;i<n;i++){
            int h=env[i][1];
            int it=lower_bound(tails.begin(),tails.end(),h)-tails.begin();
            if(it==tails.size()){
                tails.push_back(h);
            }
            else{
                tails[it]=min(tails[it],h);
            }
        }
        ans=tails.size();
        return ans;
    }
};