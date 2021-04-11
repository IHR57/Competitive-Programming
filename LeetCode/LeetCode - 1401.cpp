class Solution {
public:
    double calDist(int x1, int y1, int x2, int y2)
    {
        return (double) sqrt((double) ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
    }
    
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        double rad = (double) radius;
        if(x_center >= x1 && y_center >= y1 && x_center <= x2 && y_center <= y2)
            return true;
        for(int i = x1; i <= x2; i++){
            double dist = calDist(i, y1, x_center, y_center);
            cout<<i<<" "<<y1<<" "<<dist<<endl;
            if(dist <= rad)
                return true;
        }
        for(int i = x1; i <= x2; i++){
            double dist = calDist(i, y2, x_center, y_center);
            if(dist <= rad)
                return true;
        }
        
        for(int i = y1; i <= y2; i++){
            double dist = calDist(x1, i, x_center, y_center);
            if(dist <= rad)
                return true;
        }
        for(int i = y1; i <= y2; i++){
            double dist = calDist(x2, i, x_center, y_center);
            if(dist <= rad)
                return true;
        }
        
        return false;
    }
};
