int dp[2001][2001][2];
class Solution {
public:
    int solve(int i,int j,string &word1,int n1,int both){
        if(i>j)return 0;
        if(i==j)return 1;
        auto &ref=dp[i][j][both];
        if(ref!=-1)return ref;
        //we can take both only if both are equal
        if(word1[i]==word1[j]){
            int n_both=both|(i<n1 && j>=n1);
            return ref=(n_both)?2+solve(i+1,j-1,word1,n1,n_both):0;
        }
        //keep the ith one 
        int left=solve(i,j-1,word1,n1,both);
        int right=solve(i+1,j,word1,n1,both);
        return ref=max(left,right);
        // we want to take i  --keep i 

    }
    int longestPalindrome(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        memset(dp,-1,sizeof(dp));
        string str=word1+word2;
        int ans= solve(0,n1+n2-1,str,n1,0);
        return ans==1?0:ans;
    }
};