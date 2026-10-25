class Solution {
public:
    bool check(vector<int>&arr){
        for(int i=0;i<3;i++){
            if(arr[i]==0)return false;
        }
        return true;
    }
    int numberOfSubstrings(string s) {
        // for each index as ending index ... find the smallest index such that condition satisfy 
        // if i-1 already have x subarray .. then i will have +x 
        int n=s.size();
        int l=0;
        vector<int> arr(3,0);
        int cnt=0;
        for(int r=0;r<n;r++){
            if(s[r]=='a')arr[0]++;
            if(s[r]=='b')arr[1]++;
            if(s[r]=='c')arr[2]++;
            while(check(arr) && l<r){
                int idx=s[l]-'a';
                if(idx<3)arr[idx]--;
                l++;
            }
            cnt+=l;
        }
        return cnt;

    }
};