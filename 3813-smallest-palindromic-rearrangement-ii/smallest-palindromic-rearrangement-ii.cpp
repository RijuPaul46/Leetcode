#define ll long long
class Solution {
public:
    ll nCr(ll n,ll r,ll k){
        r=min(r,n-r);
        ll ans=1;
        for(int i=1;i<=r;i++){
            ans*=(n-r+i);
            ans/=i;
            if(ans>k)return k;
        }
        return ans;
    }
    string smallestPalindrome(string s, int k) {
        ll len=s.size();
        vector<int>freq(26);
        for(int i=0;i<len/2;i++){
            freq[s[i]-'a']++;
        }
        string str="";
        ll n=len/2;
        ll total=1;
        for(int i=0;i<26;i++){
            if(freq[i]>0){
            total*=nCr(n,freq[i],k);
            if(total>k)break;
            n-=freq[i];
            }
            
        }
        if(total<k)return str;
        n=len/2;
        for(int i=0;i<len/2;i++){
            for(int j=0;j<26;j++){
                if(freq[j]>0){
                    freq[j]--;
                    ll ways=1;
                    ll temp=n-i-1;
                    for(int l=0;l<26;l++){
                        if(freq[l]>0){
                            ways*=nCr(temp,freq[l],k);
                            temp-=freq[l];
                            if(ways>=k)break;
                        }
                    }
                    if(ways<k){k-=ways;freq[j]++;}
                    else{
                        str+=(char)(j+'a');
                        break;
                    }
                }
            }
        }
        string rev=str;
        reverse(rev.begin(),rev.end());
        if(len%2==1) return str+s[len/2]+rev;
        return str+rev;

    }
};