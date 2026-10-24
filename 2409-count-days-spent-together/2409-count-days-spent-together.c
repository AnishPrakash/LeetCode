static int get_day_of_year(const char *date) {
    static const int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month = (date[0] - '0') * 10 + (date[1] - '0');
    int day = (date[3] - '0') * 10 + (date[4] - '0');
    
    int total_days = day;
    for (int i = 0; i < month - 1; ++i) {
        total_days += days_in_month[i];
    }
    return total_days;
}

int countDaysTogether(char *arriveAlice, char *leaveAlice, char *arriveBob, char *leaveBob) {
    int start_alice = get_day_of_year(arriveAlice);
    int end_alice = get_day_of_year(leaveAlice);
    int start_bob = get_day_of_year(arriveBob);
    int end_bob = get_day_of_year(leaveBob);

    int overlap_start = start_alice > start_bob ? start_alice : start_bob;
    int overlap_end = end_alice < end_bob ? end_alice : end_bob;

    if (overlap_start > overlap_end) {
        return 0;
    }
    return overlap_end - overlap_start + 1;
}