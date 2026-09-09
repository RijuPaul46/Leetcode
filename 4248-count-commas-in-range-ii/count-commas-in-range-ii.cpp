#define ll long long
class Solution {
public:

    long long countCommas(long long n) {
        ll d=0;
        ll temp=n;
        while(temp>0){
            d++;
            temp/=10;
        }
        if(d<4)return 0;
        ll ans=0;
        for(int i=4;i<d;i++){
            ans=ans+9*pow(10,i-1)*((i-1)/3);
        }
        ans+=((d-1)/3)*(n-pow(10,d-1)+1);
        return ans;

    }
};