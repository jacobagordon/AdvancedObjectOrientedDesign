package binarySearchTree;

// example output: ( (left) (right) value )
public class PostOrder implements PrintingVisitor {

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
		treeRepresentation.append("(");
		node.left.print(this);
		treeRepresentation.append(") (");
		node.right.print(this);
		treeRepresentation.append( ") " + node.toString());
	}

	@Override
	public void printNode(nullNode node) {
		// do nothing
	}

	@Override
	public void printNode(Node node) {

	}

}
