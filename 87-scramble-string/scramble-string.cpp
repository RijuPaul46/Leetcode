class Solution {
public:
    int dp[31][31][31][31];
    bool solve(int si,int ei,int tsi,int tei,string & str,string &tgt){
        int n=str.size();
        if(si==ei){
            return str[si]==tgt[tsi];
        }
        if(dp[si][ei][tsi][tei]!=-1)return dp[si][ei][tsi][tei];
        // if(str.substr(si,ei+1)==tgt.substr(tsi,tei+1))return true;
        for(int i=0;i<ei-si;i++){
            // without swapping
            bool l=solve(si,si+i,tsi,tsi+i,str,tgt);
            if(l){
                bool r=solve(si+i+1,ei,tsi+i+1,tei,str,tgt);
                if(r)return dp[si][ei][tsi][tei]=true;
            }
            // with swapping 
            bool left=solve(si,si+i,tei-i,tei,str,tgt);
            if(left){
                bool r=solve(si+i+1,ei,tsi,tei-1-i,str,tgt);
                if(r)return dp[si][ei][tsi][tei]=true;
            }
        }
        return dp[si][ei][tsi][tei]=false;
    }
    bool isScramble(string s1, string s2) {
        int n=s1.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,n-1,0,n-1,s1,s2);
    }
};