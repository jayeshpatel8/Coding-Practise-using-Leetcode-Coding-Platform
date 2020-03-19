class Solution {
public:
 
    int largestRectangleArea(vector<int>& heights) {
   
        stack<int> s;
        heights.push_back(0);
        int res=0;
        for (int i=0; i< heights.size(); i++){  
            while (!s.empty() && heights[s.top()]>heights[i]){
                int h = heights[s.top()];
                s.pop();
                int w = s.empty()? i:i-s.top()-1;
                res = max(res, h*w);
                
            }        
            s.push(i);
        }
        return res;
      
    }
};