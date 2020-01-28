package interpreter;

import org.eclipse.swt.widgets.Text;
import observer.*;
import gui.Spreadsheet;

public class Variable implements PostfixExpression {

	float variableValue;
	
	public Variable( String name, Spreadsheet sheet, CellSubject cell) {
		
		String value;
		
		switch(name.charAt(1)) {
		case 'A':
			CellObserver cellAObserve = new CellObserver(cell);
			sheet.cellA.addObserver(cellAObserve);
			value = getCellText(sheet.cellA.cellText);
			break;
		case 'B':
			CellObserver cellBObserve = new CellObserver(cell);
			sheet.cellB.addObserver(cellBObserve);
			value = getCellText(sheet.cellB.cellText);
			break;
		case 'C':
			CellObserver cellCObserve = new CellObserver(cell);
			sheet.cellC.addObserver(cellCObserve);
			value = getCellText(sheet.cellC.cellText);
			break;
		case 'D':
			CellObserver cellDObserve = new CellObserver(cell);
			sheet.cellD.addObserver(cellDObserve);
			value = getCellText(sheet.cellD.cellText);
			break;
		case 'E':
			CellObserver cellEObserve = new CellObserver(cell);
			sheet.cellE.addObserver(cellEObserve);
			value = getCellText(sheet.cellE.cellText);
			break;
		case 'F':
			CellObserver cellFObserve = new CellObserver(cell);
			sheet.cellF.addObserver(cellFObserve);
			value = getCellText(sheet.cellF.cellText);
			break;
		case 'G':
			CellObserver cellGObserve = new CellObserver(cell);
			sheet.cellG.addObserver(cellGObserve);
			value = getCellText(sheet.cellG.cellText);
			break;
		case 'H':
			CellObserver cellHObserve = new CellObserver(cell);
			sheet.cellH.addObserver(cellHObserve);
			value = getCellText(sheet.cellH.cellText);
			break;
		case 'I':
			CellObserver cellIObserve = new CellObserver(cell);
			sheet.cellI.addObserver(cellIObserve);
			value = getCellText(sheet.cellI.cellText);
			break;
		default:
			System.out.println("Invalid variable " + name + ". Default value to 0.");
			value = "0";
		}
		variableValue = Float.parseFloat(value);
	}
	
	private String getCellText(Text cell) {
		if (cell.getText() != "") {
			return cell.getText();
		}
		else {
			return "0";
		}
	}
	
	public float evaluate(String values) {
		return variableValue;
	}
}
