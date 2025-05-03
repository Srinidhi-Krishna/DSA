//Lab 10 Q3

#include <stdio.h>
#define SIZE 100

class MaxHeap {
    int heap[SIZE];
    int size;

    public:
    MaxHeap() {
        size = 0;
    }

    void insert(int val);
    int deleteMax();
    void display();
    void search(int val);
    void heapSort();
    int isEmpty();
};

//Main Function
int main() {
    MaxHeap heap;
    int choice, value;

    do {
        printf("\n  Menu\n");
        printf("1. Insert\n");
        printf("2. Delete Max\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. Sort (Heap Sort)\n");
        printf("6. Exit\n");

        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                heap.insert(value);
                break;
            case 2: {
                int max = heap.deleteMax();
                if (max != -1)
                    printf("Deleted max element: %d\n", max);
                break;
            }
            case 3:
                heap.display();
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                heap.search(value);
                break;
            case 5:
                heap.heapSort();
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}

//Function to insert a value into the MaxHeap
void MaxHeap::insert(int val) {
    if (size >= SIZE) {
        printf("Heap is full!\n");
        return;
    }
    int i = size;
    heap[size++] = val;

    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
    printf("%d inserted into the heap.\n", val);
}

//Function to delete a value from the MaxHeap
int MaxHeap::deleteMax() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return -1;
    }

    int max = heap[0];
    heap[0] = heap[--size];

    int i = 0;
    while (2 * i + 1 < size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            int temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;
            i = largest;
        } else {
            break;
        }
    }

    return max;
}

//Function to display the MaxHeap
void MaxHeap::display() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return;
    }

    printf("Heap elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

//Function to search in the MaxHeap
void MaxHeap::search(int val) {
    for (int i = 0; i < size; i++) {
        if (heap[i] == val) {
            printf("%d found in the heap at index %d.\n", val, i);
            return;
        }
    }
    printf("%d not found in the heap.\n", val);
}

//Function to perform HeapSort
void MaxHeap::heapSort() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return;
    }

    int n = size;

    // In-place sorting: repeatedly move max to the end and heapify root
    for (int i = n - 1; i > 0; i--) {
        // Swap max element (root) with last element
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;

        // Heapify the reduced heap (0 to i-1)
        int j = 0;
        while (2 * j + 1 < i) {
            int left = 2 * j + 1;
            int right = 2 * j + 2;
            int largest = j;

            if (left < i && heap[left] > heap[largest])
                largest = left;
            if (right < i && heap[right] > heap[largest])
                largest = right;

            if (largest != j) {
                int t = heap[j];
                heap[j] = heap[largest];
                heap[largest] = t;
                j = largest;
            } else {
                break;
            }
        }
    }

    printf("Heap has been sorted (ascending): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");

    // Reset size since heap structure is now invalid
    size = 0;
}

//Function to check if the Heap is empty or not
int MaxHeap::isEmpty() {
    return size == 0;
}

