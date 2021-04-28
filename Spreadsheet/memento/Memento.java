// Memento/Command for undo package
package memento;

import observer.CellSubject;

public class Memento {
	private String cellEquation;
	private String cellValue;
	private char cell;
	
	public Memento(CellSubject state, char cell) {
		this.cellEquation = state.cellEquation;
		this.cellValue = state.cellValue;
		this.cell = cell;
	}
	
	public String getStateEquation() {
		return cellEquation;
	}
	
	public String getStateValue() {
		return cellValue;
	}
	
	public char getStateCell() {
		return cell;
	}
}
