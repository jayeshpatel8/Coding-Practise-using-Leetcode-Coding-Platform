class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {        
        vector<int> next(1,INT_MAX);//sentinel height
        for ( int i=heights.size()-1 ; i>=0; --i){   
            int h = heights[i], cnt = 0;
            while(next.back() < h) 
                next.pop_back(), cnt++;   
    
            heights[i] = cnt + (next.back() != INT_MAX);      
            next.push_back(h);
        }
        return heights;
    }
};