class Solution {
public:
    int minimumSum(int num) {
        int d[4]={};
        for ( int i=0,m =10; i<4; i++){
            d[i] = num % m;
            num /= 10;
        }
        
        if (d[0] > d[1]) swap(d[0],d[1]);
        if (d[2] > d[3]) swap(d[2],d[3]);
        if (d[0] > d[2]) swap(d[0],d[2]);
        if (d[1] > d[2]) swap(d[1],d[2]);
        if (d[1] > d[3]) swap(d[1],d[3]);
            
           return (d[0]*10) + (d[1]* 10) +  d[2] +d[3];
    }
};