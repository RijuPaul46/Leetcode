class Solution {
public:
    int solve(string & moves,int i,int x,vector<vector<int>>&dp){
        int n=moves.size();
        if(i==n)return abs(x);
        if(dp[i][x+n]!=-1)return dp[i][x+n];
        char c=moves[i];  
        if(c=='R'){
            return dp[i][x+n]=solve(moves,i+1,x+1,dp);
        }
        else if(c=='L'){
            int l=solve(moves,i+1,x-1,dp);
            return dp[i][x+n]=l;
        }
        int r=solve(moves,i+1,x+1,dp);
        int l=solve(moves,i+1,x-1,dp);
        return dp[i][x+n]=max(r,l);
        
    }
    int furthestDistanceFromOrigin(string moves) {
        // i from 0 to n
        // x can be from -n to +n
        // shift by +n  --- 0 to 2n
        int n=moves.size();
        vector<vector<int>>dp(n,vector<int>(2*n+1,-1));
        return solve(moves,0,0,dp);
       

    }
};