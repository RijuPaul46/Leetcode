class Solution {
public:
    int maxProduct(int n) {
        vector<int>digit;
        while(n>0){
            digit.push_back(n%10);
            n/=10;
        }
        sort(digit.begin(),digit.end());
        int x=digit.size()-1;
        return digit[x]*digit[x-1];
    }
};