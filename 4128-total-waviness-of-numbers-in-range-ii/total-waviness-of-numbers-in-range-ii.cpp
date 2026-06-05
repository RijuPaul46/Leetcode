#define ll long long
class Solution {
public:
    const ll M=LLONG_MAX;
    pair<ll,ll> dp[17][10][3][2][2];
    pair<ll,ll> solve(int idx,int prev_digit,int prev_state,int prev_ldz,int tight,string & tgt){
        int n=tgt.size();
        if(idx==n)return {1,0};
        int limit=tight?(tgt[idx]-'0'):9;
        ll ans=0;
        if(dp[idx][prev_digit][prev_state][prev_ldz][tight].first!=-1)return dp[idx][prev_digit][prev_state][prev_ldz][tight];
        ll total_suff=0;
        ll total_wav=0;
        for(int i=0;i<=limit;i++){
            int new_state=0;
            if(!prev_ldz){
            if(i<prev_digit)new_state=2;
            if(i>prev_digit)new_state=1;
            }
            int new_tight=(tight)&&(i==limit);
            int new_ldz=(prev_ldz)&&(i==0);
            ll score=0;
            if(!prev_ldz){
            if(i<prev_digit && prev_state==1)score+=1;
            if(i>prev_digit && prev_state==2)score+=1;
            }
            auto pr=solve(idx+1,i,new_state,new_ldz,new_tight,tgt);
            total_suff=(total_suff+pr.first)%M;
            total_wav=(((score*pr.first)%M+pr.second)%M+total_wav)%M;

        }
        return dp[idx][prev_digit][prev_state][prev_ldz][tight]={total_suff,total_wav};
    }
    long long totalWaviness(long long num1, long long num2) {
        
    fill(&dp[0][0][0][0][0], &dp[0][0][0][0][0] + sizeof(dp) / sizeof(pair<ll, ll>), make_pair(-1LL, -1LL));
        string s1=to_string(num2);
        ll a=solve(0,0,0,1,1,s1).second;
       
    fill(&dp[0][0][0][0][0], &dp[0][0][0][0][0] + sizeof(dp) / sizeof(pair<ll, ll>), make_pair(-1LL, -1LL));
        string s2=to_string(num1-1);
        ll b=solve(0,0,0,1,1,s2).second;
        
        return (a-b)%M;
    }
};