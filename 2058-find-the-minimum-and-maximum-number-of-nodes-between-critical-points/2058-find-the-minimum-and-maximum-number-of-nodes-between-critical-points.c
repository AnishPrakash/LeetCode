int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = -1;
    result[1] = -1;

    if (!head || !head->next || !head->next->next) {
        return result;
    }

    int firstIndex = -1;
    int prevIndex = -1;
    int minDistance = INT_MAX;

    struct ListNode* prev = head;
    struct ListNode* curr = head->next;
    int currentIndex = 1;

    while (curr->next) {
        if ((curr->val > prev->val && curr->val > curr->next->val) ||
            (curr->val < prev->val && curr->val < curr->next->val)) {
            
            if (firstIndex == -1) {
                firstIndex = currentIndex;
            } else {
                int dist = currentIndex - prevIndex;
                if (dist < minDistance) {
                    minDistance = dist;
                }
            }
            prevIndex = currentIndex;
        }
        prev = curr;
        curr = curr->next;
        currentIndex++;
    }

    if (firstIndex != -1 && prevIndex != firstIndex) {
        result[0] = minDistance;
        result[1] = prevIndex - firstIndex;
    }

    return result;
}