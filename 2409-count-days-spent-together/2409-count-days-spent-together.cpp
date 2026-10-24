class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int exchange[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int i = 1; i <= 12; i++) {
            exchange[i] += exchange[i-1];
        }
        int Alice_arrivedays = exchange[(arriveAlice[0] - '0')*10 + (arriveAlice[1] - '0') - 1] + (arriveAlice[3] - '0')*10 + (arriveAlice[4] - '0');
        int Alice_leavedays = exchange[(leaveAlice[0] - '0')*10 + (leaveAlice[1] - '0') - 1] + (leaveAlice[3] - '0')*10 + (leaveAlice[4] - '0');
        int Bob_arrivedays = exchange[(arriveBob[0] - '0')*10 + (arriveBob[1] - '0') - 1] + (arriveBob[3] - '0')*10 + (arriveBob[4] - '0');
        int Bob_leavedays = exchange[(leaveBob[0] - '0')*10 + (leaveBob[1] - '0') - 1] + (leaveBob[3] - '0')*10 + (leaveBob[4] - '0');
        if (Alice_arrivedays <= Bob_arrivedays) {
            if (Alice_leavedays < Bob_arrivedays) return 0;
            else if (Alice_leavedays <= Bob_leavedays) return Alice_leavedays - Bob_arrivedays +1;
            else return Bob_leavedays - Bob_arrivedays + 1;
        }
        else {
            if (Bob_leavedays < Alice_arrivedays) return 0;
            else if (Bob_leavedays <= Alice_leavedays) return Bob_leavedays - Alice_arrivedays +1;
            else return Alice_leavedays - Alice_arrivedays + 1;
        }
    }
};