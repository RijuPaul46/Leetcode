class Solution {
public:
    int dp[1001][1501][2];
    int solve(int i,int rem,int taken,vector<pair<int,int>> &itm){
        int n=itm.size();
        if(i==n || rem<=0)return 0;
        auto &ref=dp[i][rem][taken];
        if(ref!=-1)return ref;
        int take=0;
        if(itm[i].first<=rem){
            take=1+solve(i,rem-itm[i].first,1,itm);
            if(!taken)take+=itm[i].second;
        }
        int skip=solve(i+1,rem,0,itm);
        return ref=max(take,skip);
        
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        //simple dp 
        unordered_map<int,int>freq;
        for(auto &v:items){
            int p=v[0];
            freq[p]++;
        }
        vector<pair<int,int>> itm;
        for(auto &v:items){
            int p=v[1],f=v[0];
            int cnt=0;
            while(f<=1500){
                if(freq.contains(f)){
                // cout<<"f="<<f<<" freq[f]="<<freq[f]<<endl;
                if(f==v[0])cnt+=freq[f]-1;
                else cnt+=freq[f];
                }
                f+=v[0];
            }
            itm.push_back({p,cnt});
        }
        // vector<vector<vector<int>>> dp(n,vector<vector<int>>(1501,vector<int>(2,-1)));
        memset(dp,-1,sizeof(dp));
        return solve(0,budget,0,itm);

        
    }
};