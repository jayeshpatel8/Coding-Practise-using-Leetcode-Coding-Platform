class Solution {
public:
    int reachNumber(int target) {
        int move=0;
        int sum=0;
        target = abs(target);
        while (target > sum || target%2 != sum %2){
            move++; sum+=move;
        }
        return move;
    }
};

// 2 X  = N * (N+1) 
// 8 =  2 * 3 = 6//  3*4=12