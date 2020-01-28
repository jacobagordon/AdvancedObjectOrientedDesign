// BinarySearchTree.java
package binarySearchTree;

public class BinarySearchTree {
	
	Node root;
	OrderingStrategy treeOrdering;
	
	BinarySearchTree(OrderingStrategy ordering) {
		root = new nullNode();
		treeOrdering = ordering;
	}
	
	void insert(String word) {
		root = treeOrdering.insert(root, word);
	}
}
