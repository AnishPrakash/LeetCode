typedef struct {
    int weight;
    int index;
} Server;

typedef struct {
    long long time;
    int weight;
    int index;
} Busy;

typedef struct {
    Server* arr;
    int size;
} IdleHeap;

typedef struct {
    Busy* arr;
    int size;
} BusyHeap;

void swap_server(Server* a, Server* b) {
    Server temp = *a;
    *a = *b;
    *b = temp;
}

void swap_busy(Busy* a, Busy* b) {
    Busy temp = *a;
    *a = *b;
    *b = temp;
}

void push_idle(IdleHeap* h, int weight, int index) {
    int i = h->size++;
    h->arr[i].weight = weight;
    h->arr[i].index = index;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (h->arr[parent].weight > h->arr[i].weight || 
            (h->arr[parent].weight == h->arr[i].weight && h->arr[parent].index > h->arr[i].index)) {
            swap_server(&h->arr[parent], &h->arr[i]);
            i = parent;
        } else {
            break;
        }
    }
}

Server pop_idle(IdleHeap* h) {
    Server root = h->arr[0];
    h->arr[0] = h->arr[--h->size];
    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < h->size) {
            if (h->arr[left].weight < h->arr[smallest].weight || 
                (h->arr[left].weight == h->arr[smallest].weight && h->arr[left].index < h->arr[smallest].index)) {
                smallest = left;
            }
        }
        if (right < h->size) {
            if (h->arr[right].weight < h->arr[smallest].weight || 
                (h->arr[right].weight == h->arr[smallest].weight && h->arr[right].index < h->arr[smallest].index)) {
                smallest = right;
            }
        }
        if (smallest != i) {
            swap_server(&h->arr[i], &h->arr[smallest]);
            i = smallest;
        } else {
            break;
        }
    }
    return root;
}

void push_busy(BusyHeap* h, long long time, int weight, int index) {
    int i = h->size++;
    h->arr[i].time = time;
    h->arr[i].weight = weight;
    h->arr[i].index = index;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (h->arr[parent].time > h->arr[i].time || 
            (h->arr[parent].time == h->arr[i].time && h->arr[parent].weight > h->arr[i].weight) ||
            (h->arr[parent].time == h->arr[i].time && h->arr[parent].weight == h->arr[i].weight && h->arr[parent].index > h->arr[i].index)) {
            swap_busy(&h->arr[parent], &h->arr[i]);
            i = parent;
        } else {
            break;
        }
    }
}

Busy pop_busy(BusyHeap* h) {
    Busy root = h->arr[0];
    h->arr[0] = h->arr[--h->size];
    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < h->size) {
            if (h->arr[left].time < h->arr[smallest].time ||
                (h->arr[left].time == h->arr[smallest].time && h->arr[left].weight < h->arr[smallest].weight) ||
                (h->arr[left].time == h->arr[smallest].time && h->arr[left].weight == h->arr[smallest].weight && h->arr[left].index < h->arr[smallest].index)) {
                smallest = left;
            }
        }
        if (right < h->size) {
            if (h->arr[right].time < h->arr[smallest].time ||
                (h->arr[right].time == h->arr[smallest].time && h->arr[right].weight < h->arr[smallest].weight) ||
                (h->arr[right].time == h->arr[smallest].time && h->arr[right].weight == h->arr[smallest].weight && h->arr[right].index < h->arr[smallest].index)) {
                smallest = right;
            }
        }
        if (smallest != i) {
            swap_busy(&h->arr[i], &h->arr[smallest]);
            i = smallest;
        } else {
            break;
        }
    }
    return root;
}

int* assignTasks(int* servers, int serversSize, int* tasks, int tasksSize, int* returnSize) {
    *returnSize = tasksSize;
    int* ans = (int*)malloc(tasksSize * sizeof(int));
    
    IdleHeap idle;
    idle.arr = (Server*)malloc(serversSize * sizeof(Server));
    idle.size = 0;
    
    BusyHeap busy;
    busy.arr = (Busy*)malloc(serversSize * sizeof(Busy));
    busy.size = 0;
    
    for (int i = 0; i < serversSize; i++) {
        push_idle(&idle, servers[i], i);
    }
    
    long long current_time = 0;
    for (int j = 0; j < tasksSize; j++) {
        if (current_time < j) {
            current_time = j;
        }
        if (idle.size == 0 && busy.size > 0) {
            current_time = busy.arr[0].time;
        }
        while (busy.size > 0 && busy.arr[0].time <= current_time) {
            Busy b = pop_busy(&busy);
            push_idle(&idle, b.weight, b.index);
        }
        
        Server s = pop_idle(&idle);
        ans[j] = s.index;
        push_busy(&busy, current_time + tasks[j], s.weight, s.index);
    }
    
    free(idle.arr);
    free(busy.arr);
    return ans;
}