class SpecialQueue {
    Queue<Integer> q = new LinkedList<Integer>();
	int max = Integer.MIN_VALUE;
	int min = Integer.MAX_VALUE;
	
	public SpecialQueue() {
		// Define Data Structures
	}

	public void enqueue(int x) {
		// Insert element into the queue
		if (x>max) {
			max = x;
		}
		if (x<min) {
			min = x;
		}
		q.add(x);
	}

	public void dequeue() {
		// Remove element from the queue
		int removeElement = q.remove();
		if (q.isEmpty()) {
			max = Integer.MIN_VALUE;
			min = Integer.MAX_VALUE;
			return;
		}
		if (removeElement == min) {
			min = Integer.MAX_VALUE;
			q.forEach(value -> {
				if (value < min) {
					min = value;
				}
			});
		}
		if (removeElement == max) {
			max = Integer.MIN_VALUE;
			q.forEach(value -> {
				if (value > max) {
					max = value;
				}
			});
		}
	}

	public int getFront() {
		// Get front element
		return q.peek();
	}

	public int getMin() {
		// Get minimum element
		return min;
	}

	public int getMax() {
		// Get maximum element
		return max;
	}
}
