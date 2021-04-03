class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int n = coordinates[0]-'a' + coordinates[1];
            return n%2==0;
    }
};