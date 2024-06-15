class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<int> idx(capital.size());
        iota(begin(idx),end(idx),0);
        sort(begin(idx),end(idx),[&](auto a, auto b){
            return capital[a]== capital[b]? profits[a]>profits[b] : capital[a]< capital[b]; 
            ;});
        priority_queue<int> q;
        int cap =  w , i =0;

        while (k--){
            while ( i<capital.size() && (capital[idx[i]]  <= cap))      {
                q.push(profits[idx[i]]);i++;

            }
         
            if (!q.empty()) {
                cap +=q.top(); 
                q.pop();
            }else break;
        }
        return cap;
    }
};
