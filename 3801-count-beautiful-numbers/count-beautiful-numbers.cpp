#define ll long long
int dp[12][2][2][82][2][7][5][4][4];
class Solution {
public:
    
    int solve(int idx,int tight,int ldz,int sum,string &tgt,int a0,int a2,int a3,int a5,int a7){
        int n=tgt.size();
        if(idx==n){
            if(sum>0){
            if(a0)return 1;
            int temp=sum;
            int c2=0,c3=0,c5=0,c7=0;
            while(temp%2==0){c2++;temp/=2;}
            while (temp % 3 == 0) { temp /= 3; c3++; }
            while (temp % 5 == 0) { temp /= 5; c5++; }
            while (temp % 7 == 0) { temp /= 7; c7++; }
            if(temp==1 && a2>=c2 && a3>=c3 && a5>=c5 && a7>=c7)return 1;
            }
             return 0;
        }
        
        if(dp[idx][tight][ldz][sum][a0][a2][a3][a5][a7]!=-1)return dp[idx][tight][ldz][sum][a0][a2][a3][a5][a7];
        int limit=tight?tgt[idx]-'0':9;
        int ans=0;
        for(int i=0;i<=limit;i++){
            int n_tight=tight&(i==limit);
            int n_ldz=ldz&(i==0);
            int n_sum=sum+i;
            int na0=a0|(i==0 &&!ldz);
            int na2=a2;
            int na3=a3;
            int na5=a5;
            int na7=a7;
            if(i==2)na2++;
            if(i==3)na3++;
            if(i==4)na2+=2;
            if(i==5)na5++;
            if(i==6){
                na2++;
                na3++;
            }
            if(i==7)na7++;
            if(i==8)na2+=3;
            if(i==9)na3+=2;
            na2=min(6,na2);
            na3=min(4,na3);
            na5=min(3,na5);
            na7=min(3,na7);
            ans+=solve(idx+1,n_tight,n_ldz,n_sum,tgt,na0,na2,na3,na5,na7);
        }
        return dp[idx][tight][ldz][sum][a0][a2][a3][a5][a7]=ans;
    }
    int beautifulNumbers(int l, int r) {
        memset(dp,-1,sizeof(dp));
        string s1=to_string(l-1);
        int h=solve(0,1,1,0,s1,0,0,0,0,0);
        memset(dp,-1,sizeof(dp));
        string s2=to_string(r);
        int y=solve(0,1,1,0,s2,0,0,0,0,0);
        return y-h;
        
    }
};