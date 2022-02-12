class Solution {
public:
    double angleClock(int h, int m) {
        double m2= m , m1= (h%12)*5 + ((5*m2)/60);
        if (m1 < m2){
            swap(m1,m2);
        }
        double ans = (m1*6-m2*6);
        return min(ans ,360 - ans);
    }
};