class Solution {
public:
    bool winnerOfGame(string colors) {
        int ac=0,bc=0, A=0,B=0;
        for (auto c : colors){
            if (c == 'A') A++,B=0;
            else A=0,B++;
            if (A > 2) ac++;
            if (B > 2) bc++;
        }
        
        return ac > bc;
    }
};