#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n, head, size, totalMovement = 0;
    
    // Input the number of requests
    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int requests[n+1]; // Extra space for the head

    // Input the request queue
    printf("Enter the requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    // Input the initial head position
    printf("Enter initial head position: ");
    scanf("%d", &head);

    // Input the size of the disk
    printf("Enter total disk size: ");
    scanf("%d", &size);

    // Add initial head position to the request array
    requests[n] = head;
    n++;

    // Sort the request array
    sort(requests, n);

    // Find the position of the head in the sorted array
    int pos;
    for (int i = 0; i < n; i++) {
        if (requests[i] == head) {
            pos = i;
            break;
        }
    }

    // Scan towards the right (to the end of the disk)
    for (int i = pos; i < n; i++) {
        printf("Head moves from %d to %d with movement %d\n", head, requests[i], abs(head - requests[i]));
        totalMovement += abs(head - requests[i]);
        head = requests[i];
    }

    // Jump to the beginning of the disk (assuming 0)
    if (head != size - 1) {
        printf("Head jumps from %d to %d with movement %d\n", head, size-1, abs(head - (size - 1)));
        totalMovement += abs(head - (size - 1));
        head = 0;
        printf("Head jumps from %d to %d with movement %d\n", size-1, 0, abs(0 - head));
        totalMovement += abs(size - 1);
    }

    // Continue scanning towards the right (from 0 to the initial head position - 1)
    for (int i = 0; i < pos; i++) {
        printf("Head moves from %d to %d with movement %d\n", head, requests[i], abs(head - requests[i]));
        totalMovement += abs(head - requests[i]);
        head = requests[i];
    }

    // Print total head movement
    printf("Total head movement = %d\n", totalMovement);

    return 0;
}
