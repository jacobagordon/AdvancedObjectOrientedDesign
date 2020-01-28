package binarySearchTree;

// This printing visitor implements the required printing as outlined
// in the assignment ie (value  (left) (right) )
public class PreOrder implements PrintingVisitor {

	StringBuilder treeRepresentation;
	@Override
	public String printTree(BinarySearchTree tree) {
		treeRepresentation = new StringBuilder();
		treeRepresentation.append("(");
		tree.root.print(this);
		treeRepresentation.append(")");
		return treeRepresentation.toString();
	}

	@Override
	public void printNode(stringNode node) {
		treeRepresentation.append(node.toString() + " (");
		node.left.print(this);
		treeRepresentation.append(") (");
		node.right.print(this);
		treeRepresentation.append(")");
	}
	
	@Override
	public void printNode(nullNode node) {
		// do nothing
	}
	
	@Override
	public void printNode(Node node) {
		
	}
}
