int minPenalty(int period, int* lights, int lightsSize, int* arrivalTime, int arrivalTimeSize) {
    int max_light = 0;
    for (int i =0; i<lightsSize; i++){
        if(lights[i]>max_light){
            max_light = lights[i];
        }
    }
    int max_wait = 0;
    for (int i = 0; i<arrivalTimeSize; i++){
        int r = arrivalTime[i] % period;
        if(r>=max_light){
            int wait = period-r;
            if(wait>max_wait){
                max_wait = wait;
            }
        }
    }
    return max_wait;
}