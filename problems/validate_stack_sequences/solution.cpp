class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
       stack<int>st;
        int j=0, N = pushed.size();
       for (auto i : pushed) {
           if (i == popped[j] ){
               j++;
               //if (j==N) return true;
               while(st.empty() != true && st.top() == popped[j]){
                   j++;st.pop();
               }
           }
           else
               st.push(i);
       }
        return j==N;
    }
};