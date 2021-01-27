class Solution {
public:
    uint32_t res=0,R,C;

    
    int minimumEffortPath(vector<vector<int>>& h) {
        C=h[0].size()-1;
        R=h.size()-1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        uint32_t i,j;
        pq.push({0,{0,0}});
        while(i!=R||j!=C){
            auto node = pq.top();pq.pop();
            i =node.second.first;
            j =node.second.second;                         
            uint32_t w=node.first;   
            
            res = max(res,w);
            int x=i-1,y=j;
        
            if(i&&h[x][y]>0) pq.push({abs(h[i][j]-h[x][y]),{x,y}});
            
            x=i,y=j-1;
            if(j&&h[x][y]>0) pq.push({abs(h[i][j]-h[x][y]),{x,y}});       
            x=i+1,y=j;
            
            if(i<R&&h[x][y]>0) pq.push({abs(h[i][j]-h[x][y]),{x,y}});     
            x=i,y=j+1;
            
            if(j<C&&h[x][y]>0) pq.push({abs(h[i][j]-h[x][y]),{x,y}});
            h[i][j]=-h[i][j];
            
        }
        return res;
    }

};