class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int radius=0;
        for(auto & hs:houses){
            auto it = lower_bound(heaters.begin(), heaters.end(), hs);

            int right = INT_MAX;
            int left  = INT_MAX;

            if (it != heaters.end())
                right = *it - hs;

            if (it != heaters.begin()) {
                --it;
                left = hs - *it;
            }

            radius = max(radius, min(left, right));

        }
        return radius;


    }
};