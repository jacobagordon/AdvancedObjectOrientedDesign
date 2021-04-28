package interpreter;

public class Log implements PostfixExpression {
	private PostfixExpression operand;
	
	public Log(PostfixExpression operand) {
		this.operand = operand;
	}
	
	public float evaluate(String values) {
		return (float) Math.log(operand.evaluate(values));
	}
}
