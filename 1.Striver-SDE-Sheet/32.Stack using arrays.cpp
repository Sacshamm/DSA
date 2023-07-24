class Stack {
    int toppos;
    int *arr;
    int size;

public:
    Stack(int capacity) {
        this->toppos = -1;
        this->size = capacity;
        arr = new int[capacity];
    }

    //increment top and assign value only if top<size
    void push(int num) {
        if (size - toppos > 1) {
            toppos++;
            arr[toppos] = num;
        } else {
            return;
        }
    }

    //store current ele and decrement top only if top>=0
    int pop() {
        if (toppos >= 0) {
            int ans = arr[toppos];
            toppos--;
            return arr[ans];
        } else {
            return -1;
        }
    }

    //return top ele
    int top() {
        if (toppos >= 0) {
            return arr[toppos];
        } else {
            return -1;
        }
    }

    int isEmpty() {
        if (toppos == -1)
            return 1;
        else
            return 0;
    }

    int isFull() {
        if (toppos == size - 1)
            return 1;
        else
            return 0;
    }
};
