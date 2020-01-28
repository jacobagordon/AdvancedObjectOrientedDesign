package interpreter;

public class Division implements PostfixExpression {

	private PostfixExpression leftOperand;
	private PostfixExpression rightOperand;
	
	public Division(PostfixExpression leftOperand, PostfixExpression rightOperand) {
		this.leftOperand = leftOperand;
		this.rightOperand = rightOperand;
	}
	
	public float evaluate(String values) {
		return leftOperand.evaluate( values ) / rightOperand.evaluate( values );
	}

}
