#define ll long long
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        ll mas=mass;
        int n=asteroids.size();
        sort(asteroids.begin(),asteroids.end());
        for(int i=0;i<n;i++){
            if(asteroids[i]>mas)return false;
            else mas+=asteroids[i];
        }
        return true;
    }
};