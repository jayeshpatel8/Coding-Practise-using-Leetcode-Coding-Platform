class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        
        int l=0, r= maxSum;
        maxSum -=n;
        while (l<r){
            int m =  (l+r+1)/2 , m1 = m-1;
            /*
                m=3
                n=4
                maxSum=6

                [ , , , ]
                m=3,
                [ ,2, 3, 2]
                m1=2 as maxSum-=n,
                [ ,1, 2, 1]
                
                sum = [, 2, 2 , 2] - [ , 1, 0, 1]
                l1 = 1
                r1=  1
                sum = (2 * 3) - (sum(1-l1)) - sum(1-r1);
            */
            size_t l1 = max(0,min(m1-1,index));
            size_t r1 = max(0,min(m1-1,n-index-1));
            size_t sum = m1 * (l1+r1+1)- (l1 * (l1+1))/2 - (r1*(r1+1))/2;
            if ( sum <= maxSum) 
                l = m;
            else 
                r=m-1;

        }
        return l;
    }
};