bool valid(vector<int> &s, int r ,int c){
    int n=s.size();
    for (int i=0;i<r; i++){
        if ((s[i]==c)||((r-i)==abs(c-s[i])))
            return false;
    }
    
    return true;
}
void Queens(vector<int> &s, int r ,int &i){
    int n = s.size();
    if (r==n) {i++; return;}
    for (int c=0; c<n; c++){
        if(valid(s,r,c)){
            s[r]=c;
            Queens(s,r+1,i);
            s[r]=-1;
        }
    }
}
class Solution {
public:
    int totalNQueens(int n) {
        vector<int> r(n,0);
        int i=0;
         Queens(r,0,i);
        return i;
    }
};