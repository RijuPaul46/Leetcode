class Solution {
public:
    int dp[101][1000];
    int solve(int i,vector<int>& pile,int m){
        int n=pile.size();
        if(i>=n)return 0;
        auto &ref=dp[i][m];
        if(ref!=-1)return ref;
        int mx=2*m;
        int total=INT_MIN;
        int curr=0;
        for(int j=i;j<i+mx && j<n;j++){
            
            curr+=pile[j];
            int x=j-i+1;
            total=max(total,curr-solve(j+1,pile,max(x,m)));

        }
        
        return ref=total;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int diff= solve(0,piles,1);
        int total=0;
        for(auto &x:piles)total+=x;
        return (total+diff)/2;
    }
};