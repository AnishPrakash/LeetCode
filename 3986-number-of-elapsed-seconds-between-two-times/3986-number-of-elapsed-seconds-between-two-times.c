int timeToSeconds(char* timeStr) {
    int h = (timeStr[0] - '0') * 10 + (timeStr[1] - '0');
    int m = (timeStr[3] - '0') * 10 + (timeStr[4] - '0');
    int s = (timeStr[6] - '0') * 10 + (timeStr[7] - '0');
    return h * 3600 + m * 60 + s;
}

int secondsBetweenTimes(char* startTime, char* endTime) {
    return timeToSeconds(endTime) - timeToSeconds(startTime);
}