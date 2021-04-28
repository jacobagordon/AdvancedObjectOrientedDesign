// ReverseLexicographical.java
package binarySearchTree;

public class ReverseLexicographical implements OrderingStrategy {

	@Override
	public Node insert(Node root, String word) {
		
		word = new StringBuilder(word).reverse().toString();
		
		if (root.isNull()) {
			root = new stringNode(word);
			return root;
		}
		
		if (word.compareToIgnoreCase(root.toString()) < 0) {
			root.left = insert(root.left, word);
		}
		else if (word.compareToIgnoreCase(root.toString()) > 0) {
			root.right = insert(root.right, word);
		}
		
		return root;
	}

}
