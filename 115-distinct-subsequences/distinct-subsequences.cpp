class Solution {
public:
    int dp[1001][1001];
    int solve(int i,int j,string &s,string &t){
        int m=s.size();
        int n=t.size();
        if(j==n)return 1;
        if(i==m)return 0;
        auto &ref=dp[i][j];
        if(ref!=-1)return ref;
        int take=0;
        if(s[i]==t[j]){
            take=solve(i+1,j+1,s,t);
        }
        int skip=solve(i+1,j,s,t);
        return ref=take+skip;
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,t);
    } 
}; 
 
