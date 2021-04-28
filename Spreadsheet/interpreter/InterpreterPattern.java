// Interpreter pattern package
package interpreter;

import java.util.Stack;
import observer.*;
import gui.Spreadsheet;

public class InterpreterPattern {
	
	public String Interprete(String equation, Spreadsheet sheet, CellSubject cell) {
		Stack<PostfixExpression> stack = new Stack<PostfixExpression>();
		
		String[] tokens = equation.split(" ");
		for (String currentToken : tokens) {
			if (isOperator(currentToken)) {
				PostfixExpression rightExpression = stack.pop();
				PostfixExpression leftExpression = stack.pop();
				PostfixExpression operator = getOperator(currentToken, leftExpression, rightExpression);
				float result = operator.evaluate(equation);
				stack.push(new Number(result));
			}
			else if (isSinLog(currentToken)) {
				PostfixExpression expression = stack.pop();
				PostfixExpression operator = getOperator(currentToken, expression, expression);
				float result = operator.evaluate(equation);
				stack.push(new Number(result));
				
			}
			else if (isVariable(currentToken)){
				PostfixExpression variable = new Variable(currentToken, sheet, cell);
				stack.push(variable);
			}
			else {
				PostfixExpression number = new Number(currentToken);
				stack.push(number);
			}
		}
		PostfixExpression answer = stack.pop();
		float ans = answer.evaluate(equation);
		return Float.toString(ans);
	}
	
	public static boolean isOperator(String currentToken) {
		if (currentToken.contentEquals("+") || currentToken.contentEquals("-") || currentToken.contentEquals("/") || currentToken.contentEquals("*"))
			return true;
		else
			return false;
	}
	
	public static boolean isSinLog(String currentToken) {
		if (currentToken.contentEquals("log") || currentToken.contentEquals("sin"))
			return true;
		else
			return false;
	}
	
	public static boolean isVariable(String currentToken) {
		if (currentToken.charAt(0) == '$')
			return true;
		else
			return false;
	}
	
	public static PostfixExpression getOperator(String currentToken, PostfixExpression left, PostfixExpression right) {
		switch(currentToken) {
		case "+":
			return new Addition(left, right);
		case "-":
			return new Subtraction(left, right);
		case "*":
			return new Multiplication(left, right);
		case "/":
			return new Division(left, right);
		case "log":
			return new Log(left);
		case "sin":
			return new Sin(left);
		}
		return null;
	}
	

}
