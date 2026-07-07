#define ll long long
class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0)return 1ll*0;
        string str=to_string(n);
        string ans="";
        ll sm=0;
        for(auto &c:str){
            if(c-'0'!=0)ans+=c;
            sm+=(c-'0');
        }
        ll num=stoll(ans);
        return sm*num;
        
    }
};