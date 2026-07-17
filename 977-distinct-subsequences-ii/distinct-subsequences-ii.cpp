#define ll long long
class Solution {
public:
    const ll m=1e9+7;
    // i need distinct .... dp[i]=no of distinct subseq ending at i... 
    // now the problem is appending this char can lead to make duplicate ... How to find it ...find it by storing how many time it is occured as last elements... they were made by some addition .. if we add them again it can generate only duplicate 
    int distinctSubseqII(string s) {
        vector<ll>freq(26,0);
        int n=s.size();
        ll ans=0;
        for(auto &c:s){
            int idx=c-'a';
            ll contri=((ans+1)-freq[idx]+m)%m;
            ans=(ans+contri)%m;
            freq[idx]=(freq[idx]+contri)%m;
        }
        return (int)ans;

    }
};