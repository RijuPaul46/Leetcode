#define ll long long
class Solution {
public:
    char processStr(string s, long long k) {
        int n=s.size();
        vector<ll>len(n);
        ll length=0;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch=='*'){
                if(length>0){
                 length--;
                }
            }
            else if(ch=='#'){
                length*=2;
            }
            else if(ch=='%'){
            }
            else length++;
            len[i]=length;
        }
        for(int i=n-1;i>=0;i--){
            if(k>len[i]-1)return '.';
            else if(s[i]=='#'){
                if(i-1>=0)k=k%len[i-1];
            }
            else if(s[i]=='%')k=len[i]-1-k;
            else if(s[i]!='*' && k==len[i]-1)return s[i];
        }
        return '.';
    }
};