class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        if(n==1)return s;
        vector<int>freq(26);
        for(int i=0;i<n/2;i++){
            int idx=s[i]-'a';
            freq[idx]++;
        }
        string str="";
        for(int i=0;i<26;i++){
            while(freq[i]>0){str+=char(i+'a');freq[i]--;}
        }
        string rev=str;
        reverse(rev.begin(),rev.end());
        if(n%2==1){
            string ans=str+s[n/2]+rev;
            return ans;
        }
        return str+rev;
    }
};