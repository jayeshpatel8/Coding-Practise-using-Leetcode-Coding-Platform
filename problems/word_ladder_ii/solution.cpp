class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return vector<vector<string>>();
        }
        unordered_map<string, vector<string>> similar_words;
        int word_len = beginWord.size();
        for (string& w : wordList) {
            for (int i = 0; i < word_len; i++) {
                similar_words[w.substr(0, i) + '*' + w.substr(i + 1, word_len)].push_back(w);
            }
        }
        queue<string> q;
        unordered_map<string, int> min_distance;
        unordered_map<string, vector<string>> parent;
        
        q.push(beginWord);
        min_distance[beginWord] = 0;
        int distance = 1;
        bool found = false;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string u = q.front();
                q.pop();
                if (u == endWord) {
                    found = true;
                    break;
                }
                for (int i = 0; i < word_len; i++) {
                    string pattern = u.substr(0, i) + '*' + u.substr(i + 1, word_len);
                    if (!similar_words.count(pattern)) continue;
                    for (string& v : similar_words[pattern]) {
                        if (!min_distance.count(v)) {
                            min_distance[v] = distance;
                            q.push(v);
                        }
                        if (min_distance[v] == distance) {
                            parent[v].push_back(u);
                        }
                    }
                }
            }
            distance++;
        }
        
        vector<vector<string>> ans;
        function<void(string, vector<string>)> backtrack = [&](string cur, vector<string> tmp) {
            tmp.push_back(cur);
            if (cur == beginWord) {
                ans.push_back(vector<string>(tmp.rbegin(), tmp.rend()));
            }
            for (string& w : parent[cur]) {
                backtrack(w, tmp);
            }
            tmp.pop_back();
        };
        if (found) {
            backtrack(endWord, vector<string>());
        }
        return ans;
    }
};

#if 0
class Solution {
public:
    unordered_map<string, set<string>> mp; // For storing the next possible strings
    unordered_map<string, int> visited; // For storing the relative order of traversal
    unordered_map<string, vector<vector<string>>> ans; // For storing the results in form of DP
	
	/* Function for checking if the two strings have a relative difference of 1 char or not */
    bool cmp(string &a, string &b) {
        if(a.size()!=b.size()) return 0;
        int score=0;
        for(int i=0;i<a.size();i++) {
            if(a[i]!=b[i]) score++;
        }
        if(score==1) return 1;
        return 0;
    }
    void dfs(string &word) {
        if(visited.find(word)==visited.end()) return; // Checks if the current word is there in visited array or not.
        for(auto it: mp[word]) {
			// Checks if the relative ordering has a difference of 1
            if(visited[it]==visited[word]+1) { 
                if(ans.find(it)==ans.end()) dfs(it);
				// Constructs a dp to store solutions of subproblems
                for(auto it2: ans[it]) {
                    it2.push_back(word);
                    ans[word].push_back(it2);
                }
            }
        }
        if(ans.find(word)==ans.end()) ans[word]={};
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		// Initializes the dp with the endWord
        ans[endWord] = {{endWord}};
		// Makes an adjacency list for checking the relative ordering
        for(int i=0;i<wordList.size();i++) {
            if(cmp(beginWord, wordList[i])) mp[beginWord].insert(wordList[i]);
            for(int j=0;j<wordList.size();j++) if(cmp(wordList[j], wordList[i])) mp[wordList[j]].insert(wordList[i]);
        }
        queue<string> q;
        q.push(beginWord);
        visited[beginWord]=1;
        bool flag=0;
		// BFS traversal for predicting the relative ordering
        while(!q.empty()) {
            string str = q.front();
            q.pop();
            flag=0;
            for(auto it: mp[str]) if(visited.find(it)==visited.end()) {
                visited[it]=visited[str]+1;
                if(it==endWord) {flag=1; break;}
                q.push(it);
            }
            if(flag==1) break;
        }
        dfs(beginWord);
		// Ans is stored in opposite format so we have to reverse it to obtain the actual answer
        for(auto&it:ans[beginWord]) reverse(it.begin(), it.end());
        return ans[beginWord];
    }

};
#endif