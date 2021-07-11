class Solution {
public:
    int N,M;
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        M = maze.size(), N = maze[0].size();
        maze[entrance[0]][entrance[1]]=0;
        queue<array<int,3>> q;
        q.push({entrance[0],entrance[1],0});
        //int cnt=0;
        int ro[4]={1,-1,0,0};
        int co[4]={0,0,-1,1};
        while(!q.empty()){
            //int sz = q.size();
            
            //while(sz-->0)
            {
                auto [i,j,s] = q.front(); q.pop();
                for (int k=0; k<4; k++){
                    {
                        int r1=i+ro[k],c1=j+co[k];
                        if (r1 >=0 && r1<M && c1 >=0 && c1<N && maze[r1][c1]=='.'){
                            maze[r1][c1]='+';
                            if (r1==0 || r1== M-1 || c1 ==0 || c1==N-1) return s+1;
                            q.push({r1, c1,s+1});
                        }
                    }
                }
            }
           // cnt++;
        }
        return -1;
        
    }
};