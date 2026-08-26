class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=i;j<n;j++){
                if(s[j]=='1')cnt++;
                if(cnt==k){mn=min(mn,j-i+1);break;}
            }
        }
        vector<string>arr;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=i;j<n;j++){
                if(s[j]=='1')cnt++;
                if(cnt==k && j-i+1==mn){
                    string sub=s.substr(i,j-i+1);
                    arr.push_back(sub);
                }
            }
        }
        if(arr.size()==0)return "";
        sort(arr.begin(),arr.end());
        return arr[0];
    }
};