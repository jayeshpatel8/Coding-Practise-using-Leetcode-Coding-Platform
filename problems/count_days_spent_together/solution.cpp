class Solution {
public:
int d[13]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        
        int a = max(toLong(arriveAlice),toLong(arriveBob));
        int b = min(toLong(leaveAlice),toLong(leaveBob));
        return max(0,b-a+1);
    }
    int toLong(string date) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3));
        for (int i = 0; i < month - 1; i++) {
            day += d[i];
        }
        return day;
    }
};