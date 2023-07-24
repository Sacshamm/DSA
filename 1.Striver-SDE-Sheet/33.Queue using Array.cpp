class Queue {

	int front, rear;
	vector<int> arr;
	int n;
	int cnt;

public:
	Queue()
	{
		front = 0;
		rear = 0;
		arr.resize(100001);
		cnt = 0;
		n = arr.size();
	}

	// Enqueue (add) element 'e' at the end of the queue.
	void enqueue(int e)
	{
		// Write your code here.
		if(cnt!=n){	
			arr[rear%n] = e;
			rear++;
			cnt++;
		}
	}

	// Dequeue (retrieve) the element from the front of the queue.
	int dequeue()
	{
		// Write your code here.

		if(rear!=front) {
			int ans = arr[front%n];
			arr[front%n] = -1;
			front++;
			cnt--;
			return ans;
		}
		return -1;
	}
};
