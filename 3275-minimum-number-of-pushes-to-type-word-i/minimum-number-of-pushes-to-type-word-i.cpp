class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int f=n/8;
        int rem=n%8;
        int ans=4*(f)*(f+1)+rem*(f+1);
        return ans;

    }
};