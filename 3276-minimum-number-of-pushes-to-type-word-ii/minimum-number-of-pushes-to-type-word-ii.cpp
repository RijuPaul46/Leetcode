class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        vector<int>freq(26);
        for(auto&c:word)freq[c-'a']++;
        vector<int> arr;
        for(int i=0;i<26;i++){
            if(freq[i]>0)arr.push_back(freq[i]);
        }
        sort(arr.rbegin(),arr.rend());
        int press=0;
        for(int i=0;i<arr.size();i++){
            int mul=(i/8) +1;
            press+=mul*arr[i];
            // cout<<"mul ,press= "<<mul<<" "<<press<<endl;
        }
        return press;
    }
};