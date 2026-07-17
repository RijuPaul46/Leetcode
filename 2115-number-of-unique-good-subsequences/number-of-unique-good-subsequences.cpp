#define ll long long
class Solution {
public:
    // obs1-- must start with 1 ... remove all the leading zero from given string 
    // put 1 first ... then find 
    // my logic-- order matter 001101--- ans is 1,11,101,1101    total sub seq are 2^n  --- delete all of them who has leading zero ... countable ... Now problem simplified to  count how many are duplicate ... ... in how many ways i can generate duplicate subseq ... 001101  duplicate will be (1 1 1), (11 11),(101,101)  64-2^5(leading zero)-(2+1+1)duplicates .. ans is ....

    // why not remove all leading zero  1101 total 2^4=16 (1,1,1),(11,11,11),(101,101)  unique are 1,11,101,1101,111,110,10,.... go to every index ask left zero and one ... ask right 
    // 1101-- write those 15 subseq 1101,101,111,110,11,11,10,1,101,11,10,1,01,0,1
    // binary only 0,1   must help 
    // 2^n= unique+dup+ldz  ldz countable-- go to each 0 ... ask how many are there right to it ... and count .... how to deal with uniqueness ???
    const ll m=1e9+7;
    int numberOfUniqueGoodSubsequences(string str) {
        int n=str.size();
        int i=0;
        bool haszero=false;
        while(i<n && str[i]!='1'){
            if(str[i]=='0')
            haszero=true;
            i++;
        }
        if(i==n)return 1;
        ll one=0;
        ll zero=0;
        ll ans=1;
        for(int j=i+1;j<n;j++){
            if(str[j]=='0')
            haszero=true;
            int val=str[j]-'0';
            if(val==0){
                ll prev_ans=ans;
                ans=(ans+(ans-zero+m)%m)%m;
                zero=prev_ans;
            }
            else {
                ll prev_ans=ans;
                ans=(ans+(ans-one+m)%m)%m;
                one=prev_ans;
            }

        }
        return (int)(ans+haszero);
        
    }
};