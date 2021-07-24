class Solution {
public:
    unordered_set<string> words;
    unordered_map<string, vector<string>> graph;
    unordered_map<string,int> visited;
    vector<vector<string>> ans;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        for (auto s : wordList) words.insert(s);
        if (words.count(endWord) ==0) return {};
        
        BFS(beginWord, endWord);
        DFS(beginWord ,endWord);
        return ans ; 
    }
    void BFS(string& b, string& e){
        queue<string> q;
        q.push(b);
        visited[b]=1;
        while(!q.empty()){
            int sz = q.size();
            bool end=false;
            while (sz--){
                string s = q.front(); q.pop();
                string ts= s;
                for ( auto & ch : s){
                    char tc = ch;
                    for (int c ='a' ; c <='z'; c++){
                        {
                            ch = c;
                            if (words.count(s) ){
                                if (visited.count(s)==0){
                                    visited[s]=visited[ts]+1;
                                    graph[ts].push_back(s);
                                    q.push(s);                                     
                                }
                                else if (visited[s] == visited[ts]+1){                                
                                    graph[ts].push_back(s);
                                }
                                if (s==e) end= true;
                            }
                        }
                    }
                    ch = tc;
                }
            }
            if (end) break;
        }
    }
    void DFS(string& s,string& e, vector<string> st = {}){
        st.push_back(s);
        if (s == e) {
            ans.push_back(st);
        }
        for (auto i : graph[s]){
            DFS(i,e,st);
        }
        st.pop_back();
    }
};