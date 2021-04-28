// Observer package
package observer;

import gui.Spreadsheet;
import java.util.ArrayList;
import java.util.List;
import memento.*;

import org.eclipse.swt.widgets.Text;

public class CellSubject {
	public String cellValue = "0";
	public String cellEquation = "0";
	private List<Observer> cells = new ArrayList<>();
	public Text cellText;
	
	public void addObserver(Observer cell) {
		this.cells.add(cell);
	}
	
	public void removeObserver(Observer cell) {
		this.cells.remove(cell);
	}
	
	// notifies observers of update
	public void notify(Spreadsheet sheet) {
		for (Observer cell : cells) {
			cell.update(sheet);
		}
	}
	
	public Memento saveStateToMemento(char cell) {
		return new Memento(this, cell);
	}
	
	public void getStateFromMemento(Memento memento) {
		 cellValue = memento.getStateValue();
		 cellEquation = memento.getStateEquation();
	}
}
