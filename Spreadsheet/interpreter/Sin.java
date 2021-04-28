package interpreter;

public class Sin implements PostfixExpression {
	private PostfixExpression operand;
	
	public Sin(PostfixExpression operand) {
		this.operand = operand;
	}
	
	public float evaluate(String values) {
		return (float) Math.sin(operand.evaluate(values));
	}

}
