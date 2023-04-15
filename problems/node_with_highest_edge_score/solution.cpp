class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int N = edges.size() ,ans = 0;
        vector<unsigned int> score(N);
        for (int i=0; i<edges.size(); i++){
            score[edges[i]] +=i;
        }   

        return max_element(begin(score),end(score))-begin(score);
    }
};