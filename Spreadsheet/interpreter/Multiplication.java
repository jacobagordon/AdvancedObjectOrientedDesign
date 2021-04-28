package interpreter;

public class Multiplication implements PostfixExpression {

	private PostfixExpression leftOperand;
	private PostfixExpression rightOperand;
	
	public Multiplication(PostfixExpression leftOperand, PostfixExpression rightOperand) {
		this.leftOperand = leftOperand;
		this.rightOperand = rightOperand;
	}

	public float evaluate(String values) {
		return leftOperand.evaluate( values ) * rightOperand.evaluate( values );
	}

}
