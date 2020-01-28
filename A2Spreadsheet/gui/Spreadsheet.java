// CS 635
// Assignment 2
// Jacob Gordon
// Due Oct 10, 2019

// GUI Spreadsheet package
package gui;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Shell;

import org.eclipse.swt.SWT;
import org.eclipse.swt.events.KeyEvent;
import org.eclipse.swt.events.KeyAdapter;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.widgets.Text;
import org.eclipse.wb.swt.SWTResourceManager;
import org.eclipse.swt.widgets.Button;

import interpreter.InterpreterPattern;
import observer.CellSubject;

import memento.*;

public class Spreadsheet {

	private boolean currentView = false; //false = value view, true = equation view
	protected Shell shell;
	private Text labelA;
	private Text labelB;
	private Text labelC;
	private Text labelD;
	private Text labelE;
	private Text labelF;
	private Text labelG;
	private Text labelH;
	private Text labelI;
	
	public CellSubject cellA = new CellSubject();
	public CellSubject cellB = new CellSubject();
	public CellSubject cellC = new CellSubject();
	public CellSubject cellD = new CellSubject();
	public CellSubject cellE = new CellSubject();
	public CellSubject cellF = new CellSubject();
	public CellSubject cellG = new CellSubject();
	public CellSubject cellH = new CellSubject();
	public CellSubject cellI = new CellSubject();
	
	public Button switchView;
	
	Command command = new Command();

	/**
	 * Launch the application.
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			Spreadsheet window = new Spreadsheet();
			window.open();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	/**
	 * Open the window.
	 */
	public void open() {
		Display display = Display.getDefault();
		createContents();
		shell.open();
		shell.layout();
		while (!shell.isDisposed()) {
			if (!display.readAndDispatch()) {
				display.sleep();
			}
		}
	}

	/**
	 * Create contents of the window.
	 */
	protected void createContents() {
		shell = new Shell();
		shell.setSize(786, 224);
		shell.setText("Spreadsheet");
		
		labelA = new Text(shell, SWT.BORDER);
		labelA.setFont(SWTResourceManager.getFont("Segoe UI", 9, SWT.NORMAL));
		labelA.setText("      $A");
		labelA.setEditable(false);
		labelA.setBounds(10, 10, 78, 26);
		
		labelB = new Text(shell, SWT.BORDER);
		labelB.setText("      $B");
		labelB.setEditable(false);
		labelB.setBounds(94, 10, 78, 26);
		
		labelC = new Text(shell, SWT.BORDER);
		labelC.setText("      $C");
		labelC.setEditable(false);
		labelC.setBounds(178, 10, 78, 26);
		
		labelD = new Text(shell, SWT.BORDER);
		labelD.setEditable(false);
		labelD.setText("      $D");
		labelD.setBounds(262, 10, 78, 26);
		
		labelE = new Text(shell, SWT.BORDER);
		labelE.setText("      $E");
		labelE.setEditable(false);
		labelE.setBounds(346, 10, 78, 26);
		
		labelF = new Text(shell, SWT.BORDER);
		labelF.setEditable(false);
		labelF.setText("      $F");
		labelF.setBounds(430, 10, 78, 26);
		
		labelG = new Text(shell, SWT.BORDER);
		labelG.setText("      $G");
		labelG.setEditable(false);
		labelG.setBounds(514, 10, 78, 26);
		
		labelH = new Text(shell, SWT.BORDER);
		labelH.setEditable(false);
		labelH.setText("      $H");
		labelH.setBounds(598, 10, 78, 26);
		
		labelI = new Text(shell, SWT.BORDER);
		labelI.setText("      $I");
		labelI.setEditable(false);
		labelI.setBounds(682, 10, 78, 26);
		
		/*
		 Below is code for each cell in the spreadsheet.
		 Key listener is waiting for enter key press, then the function keyPressed is executed.
		 When this happens, the cells current state is first saved for the undo function.
		 Next evaluateEnterKeyPressed is called, which runs the Interpreter pattern. 
		*/
		
		cellA.cellText = new Text(shell, SWT.BORDER);
		cellA.cellText.addKeyListener(new KeyAdapter() {
			public void keyPressed(KeyEvent enter) {
				if (enter.keyCode == SWT.CR) {
					command.add(cellA.saveStateToMemento('A'));
					evaluateEnterKeyPressed(cellA);
				}
			}
		});
		cellA.cellText.setBounds(10, 45, 78, 65);
		
		cellB.cellText = new Text(shell, SWT.BORDER);
		cellB.cellText.addKeyListener(new KeyAdapter() {
			public void keyPressed(KeyEvent enter) {
				if (enter.keyCode == SWT.CR) {
					command.add(cellB.saveStateToMemento('B'));
					evaluateEnterKeyPressed(cellB);
				}
			}
		});
		cellB.cellText.setBounds(94, 45, 78, 65);
		
		cellC.cellText = new Text(shell, SWT.BORDER);
		cellC.cellText.addKeyListener(new KeyAdapter() {
			public void keyPressed(KeyEvent enter) {
				if (enter.keyCode == SWT.CR) {
					command.add(cellC.saveStateToMemento('C'));
					evaluateEnterKeyPressed(cellC);
				}
			}
		});
		cellC.cellText.setBounds(178, 45, 78, 65);
		
		cellD.cellText = new Text(shell, SWT.BORDER);
		cellD.cellText.addKeyListener(new KeyAdapter() {
			public void keyPressed(KeyEvent enter) {
				if (enter.keyCode == SWT.CR) {
					command.add(cellD.saveStateToMemento('D'));
					evaluateEnterKeyPressed(cellD);
				}
			}
		});
		cellD.cellText.setBounds(262, 45, 78, 65);
		
		cellE.cellText = new Text(shell, SWT.BORDER);
		cellE.cellText.addKeyListener(new KeyAdapter() {
			public void keyPressed(KeyEvent enter) {
				if (enter.keyCode == SWT.CR) {
					command.add(cellE.saveStateToMemento('E'));
					evaluateEnterKeyPressed(cellE);
				}
			}
		});
		cellE.cellText.setBounds(346, 45, 78, 65);
		
		cellF.cellText = new Text(shell, SWT.BORDER);
		cellF.cellText.addKeyListener(new KeyAdapter() {
			public void keyPressed(KeyEvent enter) {
				if (enter.keyCode == SWT.CR) {
					command.add(cellF.saveStateToMemento('F'));
					evaluateEnterKeyPressed(cellF);
				}
			}
		});
		cellF.cellText.setBounds(430, 45, 78, 65);
		
		cellG.cellText = new Text(shell, SWT.BORDER);
		cellG.cellText.addKeyListener(new KeyAdapter() {
			public void keyPressed(KeyEvent enter) {
				if (enter.keyCode == SWT.CR) {
					command.add(cellG.saveStateToMemento('G'));
					evaluateEnterKeyPressed(cellG);
				}
			}
		});
		cellG.cellText.setBounds(514, 45, 78, 65);
		
		cellH.cellText = new Text(shell, SWT.BORDER);
		cellH.cellText.addKeyListener(new KeyAdapter() {
			public void keyPressed(KeyEvent enter) {
				if (enter.keyCode == SWT.CR) {
					command.add(cellH.saveStateToMemento('H'));
					evaluateEnterKeyPressed(cellH);
				}
			}
		});
		cellH.cellText.setBounds(598, 45, 78, 65);
		
		cellI.cellText = new Text(shell, SWT.BORDER);
		cellI.cellText.addKeyListener(new KeyAdapter() {
			public void keyPressed(KeyEvent enter) {
				if (enter.keyCode == SWT.CR) {
					command.add(cellI.saveStateToMemento('I'));
					evaluateEnterKeyPressed(cellI);
				}
			}
		});
		cellI.cellText.setBounds(682, 45, 78, 65);
		
		Button switchView = new Button(shell, SWT.NONE);
		switchView.addSelectionListener( new SelectionAdapter() {
			public void widgetSelected(SelectionEvent e) {
				if (!currentView) {
					cellA.cellText.setText(cellA.cellEquation);
					cellB.cellText.setText(cellB.cellEquation);
					cellC.cellText.setText(cellC.cellEquation);
					cellD.cellText.setText(cellD.cellEquation);
					cellE.cellText.setText(cellE.cellEquation);
					cellF.cellText.setText(cellF.cellEquation);
					cellG.cellText.setText(cellG.cellEquation);
					cellH.cellText.setText(cellH.cellEquation);
					cellI.cellText.setText(cellI.cellEquation);
					currentView = true;
				}
				else {
					cellA.cellText.setText(cellA.cellValue);
					cellB.cellText.setText(cellB.cellValue);
					cellC.cellText.setText(cellC.cellValue);
					cellD.cellText.setText(cellD.cellValue);
					cellE.cellText.setText(cellE.cellValue);
					cellF.cellText.setText(cellF.cellValue);
					cellG.cellText.setText(cellG.cellValue);
					cellH.cellText.setText(cellH.cellValue);
					cellI.cellText.setText(cellI.cellValue);
					currentView = false;
				}
			}
		});
		switchView.setBounds(10, 137, 90, 30);
		switchView.setText("Switch View");
		
		Button undoButton = new Button(shell, SWT.NONE);
		undoButton.addSelectionListener(new SelectionAdapter() {
			public void widgetSelected(SelectionEvent e) {
				Memento undoState;
				
				undoState = command.undo();
				switch(undoState.getStateCell()) {
				case 'A':
					setUndo(cellA, undoState);
					break;
				case 'B':
					setUndo(cellB, undoState);
					break;
				case 'C':
					setUndo(cellC, undoState);
					break;
				case 'D':
					setUndo(cellD, undoState);
					break;
				case 'E':
					setUndo(cellE, undoState);
					break;
				case 'F':
					setUndo(cellF, undoState);
					break;
				case 'G':
					setUndo(cellG, undoState);
					break;
				case 'H':
					setUndo(cellH, undoState);
					break;
				case 'I':
					setUndo(cellI, undoState);
					break;
				default:
					System.out.println("Could not undo.");
				}
			}
		});
		undoButton.setBounds(118, 137, 90, 30);
		undoButton.setText("Undo");

	}
	
	public void setUndo(CellSubject cell, Memento undoState) {
		cell.cellEquation = undoState.getStateEquation();
		cell.cellValue = undoState.getStateValue();
		if (!currentView) {
			cell.cellText.setText(cell.cellEquation);
		}
		else
		{
			cell.cellText.setText(cell.cellValue);
		}
	}
	
	/* 
	 Stores the value entered by user as the cell's equation, then evaluates the input to
	 determine the cell's value. Lastly, the cell notifies observers of the cell's change.
	 */
	
	public void evaluateEnterKeyPressed(CellSubject cell) {
		InterpreterPattern pattern = new InterpreterPattern();
		cell.cellEquation = cell.cellText.getText();
		String equation = cell.cellText.getText();
		String answer = pattern.Interprete(equation, Spreadsheet.this, cell);
		cell.cellText.setText(answer);
		cell.cellValue = cell.cellText.getText();
		cell.notify(Spreadsheet.this);
	}
}
