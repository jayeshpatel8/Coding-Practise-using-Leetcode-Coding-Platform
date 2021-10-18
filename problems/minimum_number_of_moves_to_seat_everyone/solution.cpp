class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), end(seats));
        sort(students.begin(), end(students));
        int diff=0;
        for ( int i=0; i<seats.size(); i++ ){
            diff += abs(seats[i] - students[i]);
        }
        return diff;
    }
};