class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        for (auto i : asteroids){
            if (i < 0){
                int t = abs(i);
                while (!stack.empty() && stack.back() > 0 && stack.back() < t)
                    stack.pop_back();
                
                if (stack.empty()  || stack.back() < 0) 
                    stack.push_back(i);
                else if (t==stack.back()) 
                    stack.pop_back();
            }
            else 
                stack.push_back(i);
        }
        return stack;
    }
};