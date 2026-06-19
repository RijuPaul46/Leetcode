class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int altitude=0;
        int highest=0;
        for(int i=0;i<n;i++){
            altitude+=gain[i];
            highest=max(highest,altitude);
        }
        return highest;
    }
};