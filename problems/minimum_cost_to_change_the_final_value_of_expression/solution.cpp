class Solution {
public:
    int minOperationsToFlip(string exp) {
        /* 0 & 0 = 1 + min (L,R)
           0 & 1 = 1
           1 & 1  = min(L,R) 
           0 | 0 =  min(l,r)
           0 | 1 =  1
           1 | 1  = 1 + min(l,r)
        */
        vector<vector<array<char,2>>> st(1);
        
        for ( auto ch : exp){
            if (ch == '('){
                st.push_back(vector<array<char,2>>());
            }
            else if (ch == ')'){
                auto p  = eval(st.back(),st.back().size()-1);
                st.pop_back();
                st.back().push_back(p);
            }
            else{
                st.back().push_back({ch,1});
            }
        }
        return eval(st.back(),st.back().size()-1)[1];
    }
    array<char,2> eval(vector<array<char,2>> & exp, int i){
        if (i == 0) return exp[0];
        auto left = eval(exp, i-2), right = exp[i];
        int val1 = left[0] -'0',val2 = right[0]-'0', cost1 = left[1], cost2 =right[1], op = exp[i-1][0], cost=1;
        if (op == '|'){
            if (val1 == val2) cost = (val1 == 1) + min(cost1, cost2);
            return {(char)((val1 | val2) + '0'),(char)cost};
        }
        {
            if (val1 == val2) cost = (val1 == 0) + min(cost1, cost2);
            return {(char)((val1 & val2) + '0'),(char)cost};
        }        
    }
};