class Solution {
    const string TARGET = "123450";
    const vector<pair<int,int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    
public:
    int slidingPuzzle(vector<vector<int>>& board) {

        string str;
        for(auto r : board) {
            for(int i : r) {
                str += i + '0';
            }
        }
        
        queue<pair<string,int>> q; 
        unordered_set<string> visited;
        
        q.push({str, 0});
        visited.insert(str);
        
        while(!q.empty()) {
            auto [curr, steps] = q.front(); q.pop();
            
            if(curr == TARGET) return steps;
            
            int zero = curr.find('0');
            int x = zero / 3, y = zero % 3;
                        
            for(auto [dx, dy] : dirs) {
                int nx = x + dx;
                int ny = y + dy;
                
                if(nx < 0 || nx >= 2 || ny < 0 || ny >= 3) continue;
                
                string next = curr;
                swap(next[zero], next[nx * 3 + ny]);
                
                if(visited.count(next)) continue;
                
                visited.insert(next);
                q.push({next, steps + 1});
            }
        }
        
        return -1;
    }
};
