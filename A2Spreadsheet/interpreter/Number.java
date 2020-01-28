package interpreter;

public class Number implements PostfixExpression {

	float number;
	
	public Number(float inNumber) {
		number = inNumber;
	}
	
	public Number(int inNumber) {
		number = inNumber;
	}
	
	public Number(String inNumber) {
		number = Float.parseFloat(inNumber);
	}
	
	public float evaluate(String values) {
		return number;
	}

}
