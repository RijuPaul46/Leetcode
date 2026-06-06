class Solution {
public:
    
    int solve(int i,vector<pair<int,int>> &arr,int one,int zero,int m,int n,vector<vector<vector<int>>>&dp){
        int len=arr.size();
        if(i==len)return 0;
        if(dp[i][zero][one]!=-1)return dp[i][zero][one];
        int skip= solve(i+1,arr,one ,zero,m,n,dp);
        
        //take 
        int take=-1000000;
        
        if(zero + arr[i].first <= m &&
           one  + arr[i].second <= n) {

         take=1+solve(i+1,arr,one+arr[i].second,zero+arr[i].first,m,n,dp);
        }
        
        return dp[i][zero][one]=max(take,skip);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len=strs.size();
        vector<pair<int,int>> arr(len);
        int t_o=0;
        int t_z=0;
        for(int i=0;i<len;i++){
            string &s=strs[i];
            int zero=0;
            int one=0;
            for(auto &c:s){
                if(c=='0'){zero++;t_z++;}
                else {one++;t_o++;}
            }
            arr[i]={zero,one};
        }
        vector<vector<vector<int>>>dp(len,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(0,arr,0,0,m,n,dp);
    }
};