class Solution {
public:
    bool isPathCrossing(string path) {
        int l = path.size();

        set<pair<int,int>> s;
        int x=0,y=0;
        s.insert({x,y});
        for (int i=0; i<l; i++){
            if (path[i]=='N')
                y+=1;
            else if (path[i]=='S') y-=1;
            else if (path[i]=='E') x+=1;
            else if (path[i]=='W') x-=1;
            if (s.count({x,y})) return true;
            s.insert({x,y});
        }
        return false;
    }
};