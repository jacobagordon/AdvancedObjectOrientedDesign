package memento;

import java.util.Stack;

public class Command {
	private Stack<Memento> undoStack = new Stack<Memento>();

	public void add(Memento state) {
		undoStack.push(state);
	}
	
	public Memento undo( ) {
		return undoStack.pop();
	}
}
