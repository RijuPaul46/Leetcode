class Solution {
public:
    int wavi(int n){
        string s=to_string(n);
        if(s.size()<3)return 0;
        int cnt=0;
        for(int i=1;i<s.size()-1;i++){
            int prev=s[i-1]-'0';
            int curr=s[i]-'0';
            int next=s[i+1]-'0';
            if((prev<curr && next<curr) || (curr<prev && curr<next))cnt++;
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int i=max(100,num1);i<=num2;i++){
            ans+=wavi(i);
        }
        return ans;
    }
};