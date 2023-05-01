class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int p1=0, p2=0;
        for (int i=0; i<player1.size(); i++){
            p1 += player1[i];
            p2 += player2[i];
            if (i-1>=0 && player1[i-1]==10) p1 += player1[i];
            else if (i-2>=0 && player1[i-2]==10) p1 += player1[i];

            if (i-1>=0 && player2[i-1]==10) p2 += player2[i];
            else if (i-2>=0 && player2[i-2]==10) p2 += player2[i];
        }
        if (p1==p2) return 0;
        return (p1 < p2 ) + 1;
    }
};