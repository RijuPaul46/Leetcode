#define db double 
class Solution {
public:
    db dist(int a,int b,int x,int y){
        return sqrt((a-x)*(a-x)+(b-y)*(b-y));
    }
    bool checkOverlap(int radius, int x, int y, int x1, int y1, int x2, int y2) {
        // any point on the perimeter of rectangle ... 
        // if it is <=r then overlap 
        // case 2: if whole circle inside //
        // what if overlapping region do not contain any integer
        if(x<=x1){
            if(y<y1){
                db d=dist(x1,y1,x,y);
                return d<=radius;
            }
            if(y>y2){
                db d=dist(x1,y2,x,y);
                return d<=radius;
            }
            return (x1-x)<=radius;
        }
        if(x>=x2){
            if(y<y1){
                db d=dist(x2,y1,x,y);
                return d<=radius;
            }
            if(y>y2){
                db d=dist(x2,y2,x,y);
                return d<=radius;
            }
            return (x-x2)<=radius;
        }
        if(y<y2 && y>y1)return true;
        int d=min(abs(y-y1),abs(y-y2));
        return d<=radius;

    }
};