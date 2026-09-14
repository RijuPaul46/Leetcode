class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0], y1 = rec1[1];
        int x2 = rec1[2], y2 = rec1[3];

        int a = rec2[0], b = rec2[1];
        int c = rec2[2], d = rec2[3];

        return max(x1, a) < min(x2, c) &&
               max(y1, b) < min(y2, d);
    }
};