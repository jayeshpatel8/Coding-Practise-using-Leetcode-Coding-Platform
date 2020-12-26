class Solution {
public:
    int countStudents(vector<int>& st, vector<int>& sa) {
        int N= st.size();
        int c[2]={0,0};
        for (auto i : st){
            c[i]++;
        }
        for (auto i : sa){
            c[i]--;
            if (c[i]<0) return c[0]+c[1]+1;
        }        
        return 0;
    }
};