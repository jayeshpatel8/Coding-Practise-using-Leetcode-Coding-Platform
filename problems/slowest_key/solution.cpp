class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int time=releaseTimes[0], ans=keysPressed[0];
        for (int i=1; i<keysPressed.size(); i++){
            int diff = releaseTimes[i]-releaseTimes[i-1];
            if(diff == time){
                if (ans < keysPressed[i])
                    ans = keysPressed[i];
            }
            else if ((diff > time)){
                time = diff, ans = keysPressed[i];
            }
        }
        return ans;
    }
};