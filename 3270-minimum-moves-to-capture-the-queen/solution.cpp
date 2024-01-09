class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        int ans = 2;
        if (a==e ||b==f){

            if (c < min(a,e) || c > max(a,e) ||d <min(b,f) || d> max(b,f))return 1;
        }   
        
        int v = e > c ? 1 : -1, h = f > d ? 1 : -1;
        
        for (; c >0 && c <9 && d >0 && d<9; c+=v , d+=h){
            if (c==a && d==b) return 2;
            if (c==e && d==f) return 1;
        }
        return 2;
    }
};
