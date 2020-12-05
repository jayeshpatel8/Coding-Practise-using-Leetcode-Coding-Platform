
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        // slop of line remains constant for any two point on line
        // slop  = (change in y) /  (change in x)
        
        int n = points.size();
        if (n<3) return n;
        int maxofall=0;
        int i=0;
        if (points[0][0]==0 && points[0][1]==0) {
            points.push_back({0,0});
            i++;n++;
            
        }
        for (; i<n-1; i++){

            unordered_map<double ,int> slop;
            int maxPoint=0;
            int same=0, xsame=0;
            for (int j=i+1; j<n; j++){
                //if (i==j) continue;
               // if (points[i][0] ==0 && points[i][1]==0 ) {continue;
                  //  points[i][0]=points[i][1]=1; 
               //}
                
                int x = points[j][0] - points[i][0];
                if (x==0) xsame++;
                 {
                    int y = points[j][1] - points[i][1];
                    if (x==0 && y==0) same++;
                    else{

                        maxPoint = max (maxPoint, 1 + slop[ ((double)y )/ x ]++);
                    }
                }
            }
            
            maxofall = max(maxPoint+same, maxofall);
            if (xsame > maxofall) maxofall = xsame;
            if (maxofall == n-1) break;
            slop.clear();
        }
        return maxofall+1;
    }
};