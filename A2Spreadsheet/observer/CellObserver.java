package observer;

import gui.Spreadsheet;

public class CellObserver implements Observer {

	CellSubject assignedCell;
	
	public CellObserver(CellSubject cell) {
		assignedCell = cell;
	}
	
	@Override
	public void update(Spreadsheet sheet) {
		assignedCell.cellEquation = assignedCell.cellText.getText();
		sheet.evaluateEnterKeyPressed(assignedCell);
		assignedCell.cellValue = assignedCell.cellText.getText();
	}
}
