int nearestDrone(int** drones, int dronesSize, int* dronesColSize, int* target, int targetSize) {
    int min_dist = 1000000;
    int ans_idx = -1;
    for (int i = 0; i<dronesSize; i++){
        int dist = abs(drones[i][0] - target[0])+abs(drones[i][1]-target[1]);
        if(dist<=drones[i][2] && dist < min_dist){
            min_dist = dist;
            ans_idx = i;
        }
    }
    return ans_idx;
}