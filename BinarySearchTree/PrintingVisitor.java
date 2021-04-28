// PrintingVisitor.java
package binarySearchTree;

public interface PrintingVisitor {
	public String printTree(BinarySearchTree tree);
	public void printNode(stringNode node);
	public void printNode(nullNode node);
	public void printNode(Node node);
}
