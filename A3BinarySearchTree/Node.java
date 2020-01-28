// Node.java
package binarySearchTree;

public abstract class Node {
	String value;
	Node left, right;
	public abstract String toString();
	public abstract void print(PrintingVisitor printer);
	public abstract boolean isNull();
}

class stringNode extends Node {
	public stringNode(String word) {
		value = word;
		left = right = new nullNode();
	}
	
	@Override
	public String toString() {
		return value;
	}
	
	@Override
	public void print(PrintingVisitor printer) {
		printer.printNode(this);
	}
	
	@Override
	public boolean isNull() {
		return false;
	}
}

class nullNode extends Node {
	public nullNode() {
		value = null;
		left = right = null;
	}
	
	@Override
	public String toString() {
		return "";
	}
	
	@Override
	public void print(PrintingVisitor printer) {
		printer.printNode(this);
	}
	
	@Override
	public boolean isNull() {
		return true;
	}
}
