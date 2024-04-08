class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int c[2]={};
        for (auto i : students) c[i]++;
        for (auto i : sandwiches){
            c[i]--;
            if (c[i] < 0) return c[0] +c[1] +1;
        }
        return 0;
    }
};
