/*
 * Name: Jacob Gordon
 * Class: CS 635
 * Assignment 1
 * Due Sept. 10th, 2019
 */

public class DoublyLinkedQueue {
	
	public ProcessNode beginningNode;
	private ProcessNode endNode;
	
	static class ProcessNode {
		public String processName;
		public String processOwner;
		public int processID;
		public int numberOfThreads;
		public int percentOfUsedCPU;
		public int totalCPUTime;
		public ProcessNode nextNode;
		public ProcessNode previousNode;
		
		
		ProcessNode(int newProcessID) {
			processName = null;
			processOwner = null;
			processID = newProcessID;
			numberOfThreads = 0;
			percentOfUsedCPU = 0;
			totalCPUTime = 0;
			nextNode = null;
			previousNode = null;
		}
	}
	
	// initializes a queue of the given initial size
	public static DoublyLinkedQueue initializeNewQueue(DoublyLinkedQueue queue, int initialSize) {
		
		//allocating first node to start queue
		ProcessNode newProcess = new ProcessNode(-1);
		ProcessNode prevProcess;
		
		queue.beginningNode = new ProcessNode(-1);
		
		queue.beginningNode.nextNode = newProcess;
		newProcess.previousNode = queue.beginningNode;
		
		// allocating empty nodes with processID of -1
		for (int i = 0; i < initialSize - 2; i++) {
			prevProcess = newProcess;
			newProcess = new ProcessNode(-1);
			prevProcess.nextNode = newProcess;
			newProcess.previousNode = prevProcess;
		}
		
		queue.endNode = newProcess;
		
		return queue;
	}
	
	public static DoublyLinkedQueue doubleQueueSize(DoublyLinkedQueue queue, int currentQueueSize) {
		
		// does a process similar to initializeNewQueue, but just adding more empty nodes
		ProcessNode newProcess = new ProcessNode(-1);
		ProcessNode prevProcess;
		
		queue.endNode.nextNode = newProcess;
		newProcess.previousNode = queue.endNode;
		
		for(int i = 0; i < currentQueueSize - 1; i++) {
			prevProcess = newProcess;
			newProcess = new ProcessNode(-1);
			prevProcess.nextNode = newProcess;
			newProcess.previousNode = prevProcess;
		}
		
		queue.endNode = newProcess;
		
		return queue;
	}
	
	public static DoublyLinkedQueue removeProcess(DoublyLinkedQueue queue) {
		
		ProcessNode oldEndProcess = queue.endNode;
		
		// removing first node
		queue.beginningNode = queue.beginningNode.nextNode;
		queue.beginningNode.previousNode = null;
		
		// adds blank node at the end of queue to "replace" deleted first node
		queue.endNode.nextNode = new ProcessNode(-1);
		queue.endNode = queue.endNode.nextNode;
		queue.endNode.previousNode = oldEndProcess;
		
		return queue;
	}
	
	public static DoublyLinkedQueue insertProcess(DoublyLinkedQueue queue, int newProcessID, String newProcessName, String newProcessOwner, int newNumberOfThreads, int newPercentOfUsedCPU, int newTotalCPUTime) {
		
		// defining node with enter values
		ProcessNode newProcess = new ProcessNode(newProcessID);
		newProcess.processName = newProcessName;
		newProcess.processOwner = newProcessOwner;
		newProcess.numberOfThreads = newNumberOfThreads;
		newProcess.percentOfUsedCPU = newPercentOfUsedCPU;
		newProcess.totalCPUTime = newTotalCPUTime;
		ProcessNode findEnd;
		int queueSize = 1;
		
		if (queue.beginningNode.processID == -1) { // empty queue
			newProcess.nextNode = queue.beginningNode.nextNode;
			newProcess.previousNode = queue.beginningNode.previousNode;
			queue.beginningNode = newProcess;
		}
		else { // queue is not empty
			findEnd = queue.beginningNode;
			
			// find current last used node
			while (findEnd.processID != -1) {
				if (findEnd == queue.endNode) { //if no empty nodes are allocated, double queue size
					queue = doubleQueueSize(queue, queueSize);
				}
				queueSize++;
				findEnd = findEnd.nextNode;
			}

			// inserts new node
			findEnd.processID = newProcess.processID;
			findEnd.processName = newProcess.processName;
			findEnd.processOwner = newProcess.processOwner;
			findEnd.numberOfThreads = newProcess.numberOfThreads;
			findEnd.percentOfUsedCPU = newProcess.percentOfUsedCPU;
			findEnd.totalCPUTime = newProcess.totalCPUTime;
		}
		
		return queue;
	}
	
	// bubble sort for integer attributes
	public static void sortIntArray(int queueArray[]) { 
		int length = queueArray.length;
		
		for (int x = 0; x < length - 1; x++) {
			for (int y = 0; y < length - 1 - x; y++) {
				if (queueArray[y] > queueArray[y+1]) {
					int swap = queueArray[y];
					queueArray[y] = queueArray[y+1];
					queueArray[y+1] = swap;
				}
			}
		}
	}
	
	// bubble sort for String attributes
	public static void sortStringArray(String queueArray[]) { 
		int length = queueArray.length;
		
		for (int x = 0; x < length - 1; x++) {
			for (int y = 0; y < length - 1 - x; y++) {
				if (queueArray[y].compareTo(queueArray[y+1]) > 0) {
					String swap = queueArray[y];
					queueArray[y] = queueArray[y+1];
					queueArray[y+1] = swap;
				}
			}
		}
	}
	
	// called if the user wants to print a specific in order a specific attribute from the queue. This ignores queue order
	public static void printProcessListOrdered(DoublyLinkedQueue queue, int displayOrder) { 
		
		ProcessNode copyNode = queue.beginningNode;
		ProcessNode findLength = queue.beginningNode;
		int listLength = 0;
		
		while (findLength.processID != -1) {
			listLength++;
			findLength = findLength.nextNode;
		}
		
		int[] printArrayInt = new int[listLength];
		String[] printArrayString = new String[listLength];
		
		switch(displayOrder) {
			case 1: // ordered by PID
				System.out.println("ORDERED BY PROCESS ID");
				for (int i = 0; i < listLength; i++) {
					printArrayInt[i] = copyNode.processID;
					copyNode = copyNode.nextNode;
				}
				sortIntArray(printArrayInt);
				for (int i = 0; i < listLength; i++) {
					System.out.println(printArrayInt[i]);
				}
				break;
			case 2: // ordered by Process Name
				System.out.println("ORDERED BY PROCESS NAME");
				for (int i = 0; i < listLength; i++) {
					printArrayString[i] = copyNode.processName;
					copyNode = copyNode.nextNode;
				}
				sortStringArray(printArrayString);
				for (int i = 0; i < listLength; i++) {
					System.out.println(printArrayString[i]);
				}
				break;
			case 3: // ordered by Process Owner
				System.out.println("ORDERED BY PROCESS OWNER");
				for (int i = 0; i < listLength; i++) {
					printArrayString[i] = copyNode.processOwner;
					copyNode = copyNode.nextNode;
				}
				sortStringArray(printArrayString);
				for (int i = 0; i < listLength; i++) {
					System.out.println(printArrayString[i]);
				}
				break;
			case 4: // ordered by number of threads
				System.out.println("ORDERED BY NUMBER OF THREADS");
				for (int i = 0; i < listLength; i++) {
					printArrayInt[i] = copyNode.numberOfThreads;
					copyNode = copyNode.nextNode;
				}
				sortIntArray(printArrayInt);
				for (int i = 0; i < listLength; i++) {
					System.out.println(printArrayInt[i]);
				}
				break;
			case 5: // ordered by percent of cpu used
				System.out.println("ORDERED BY CPU USAGE PERCENT");
				for (int i = 0; i < listLength; i++) {
					printArrayInt[i] = copyNode.percentOfUsedCPU;
					copyNode = copyNode.nextNode;
				}
				sortIntArray(printArrayInt);
				for (int i = 0; i < listLength; i++) {
					System.out.println(printArrayInt[i]);
				}
				break;
			case 6: // ordered by total cpu time
				System.out.println("ORDERED BY TOTAL CPU TIME");
				for (int i = 0; i < listLength; i++) {
					printArrayInt[i] = copyNode.totalCPUTime;
					copyNode = copyNode.nextNode;
				}
				sortIntArray(printArrayInt);
				for (int i = 0; i < listLength; i++) {
					System.out.println(printArrayInt[i]);
				}
				break;
			default: // error ordering, most likely invalid number for displayOrder
				System.out.println("ERROR SORTING");
				break;
		}
	}
	
	// this method prints the whole queue in order and shows all attributes
	public static void printProcessList(DoublyLinkedQueue queue) {
		ProcessNode printList = queue.beginningNode;
		
		System.out.println("Queue: PID,  Name,  Owner,  Threads,  CPUPercent,  CPUTime");
		
		while (printList != null) {
			if (printList.processID == -1) {
				break;
			}
			System.out.print(printList.processID + ", ");
			System.out.print(printList.processName + ", ");
			System.out.print(printList.processOwner + ", ");
			System.out.print(printList.numberOfThreads + ", ");
			System.out.print(printList.percentOfUsedCPU + ", ");
			System.out.println(printList.totalCPUTime + ", ");
			
			printList = printList.nextNode;
		}
	}
}
