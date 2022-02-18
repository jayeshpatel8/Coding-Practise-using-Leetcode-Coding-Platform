class Solution {
public:
    string best;
    string removeKdigits(string num, int k) {
        int N = num.size(); 
     if (k >= N) return "0";
        string st;
        int i=0;
        for (; i<N ; i++){
            while (!st.empty() && num[i] < st.back() && k  ){
                st.pop_back(); k--;
            }
            if (num[i] !='0' || !st.empty())
                st+=num[i];
        }
        while(k-- && !st.empty())
            st.pop_back();

        return st.empty() ? "0" : st;
    }

};