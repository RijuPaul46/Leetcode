int dp[1001][1001];
class Solution {
public:
    int solve(int i,int j,string &s, string &t){
        int n1=s.size();
        int n2=t.size();
        auto &ref=dp[i][j];
        if(ref!=-1)return ref;
        if(j>=n2)return 1;
        if(i>=n1)return 0;
        int ans=0;
        if(s[i]==t[j]){
            ans+=solve(i+1,j+1,s,t);
        }
        ans+=solve(i+1,j,s,t);
        return ref=ans;
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,t); 
    }
};