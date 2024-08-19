class Solution {
public:
 
    int minSteps(int n) {
        
        return minSteps(n,1,0);
    }
    int minSteps(int n , int cur, int sel){
        if (n == cur) return 0;
        if (n < cur) return  1001;
        
        
        int step = 10001;
        if(n%cur == 0)
            step = min (step, 2  + minSteps(n,cur+cur,cur));
        if (sel )
            step = min (step, 1  + minSteps(n,cur+sel,sel));
        
        return  step;
    }
};
