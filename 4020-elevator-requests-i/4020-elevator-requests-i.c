int elevatorRequests(int n, int* requests, int requestsSize) {
    int total_time = 0;
    int current_floor = 0;
    for (int i = 0; i<requestsSize; i++){
        total_time += abs(requests[i] - current_floor);
        current_floor = requests[i];
    }
    return total_time;
}