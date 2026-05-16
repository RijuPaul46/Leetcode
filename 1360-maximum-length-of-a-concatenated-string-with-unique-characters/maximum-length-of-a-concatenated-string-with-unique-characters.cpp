class Solution {
public:
    // bool unique(string &str){
    //     vector<int>arr(26);
    //     for(int i=0;i<str.size();i++){
    //         int idx=str[i]-'a';
    //         if(arr[idx]>0)return false;
    //         else arr[idx]++;
    //     }
    //     return true;
    // }
    int solve(int i,vector<string>& arr,vector<bool> &present){
        if(i>=arr.size())return 0;
        string str=arr[i];
        bool canTake=true;
        int take=0;
        vector<bool> prs=present;
        for(int j=0;j<str.size();j++){
            int idx=str[j]-'a';
            if(!prs[idx]){
                prs[idx]=true;
            }
            else{
                canTake=false;
                break;
            }
        }
        if(canTake){take=str.size()+solve(i+1,arr,prs);
        
        }
         
        int skip=solve(i+1,arr,present);
        return max(take,skip);
    }
    int maxLength(vector<string>& arr) {
        vector<bool> lt(26,false);
        return solve(0,arr,lt);
        
    }
};