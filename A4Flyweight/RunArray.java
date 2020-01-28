import java.util.Arrays;

public class RunArray {
	Font[] array;
	FontFactory fontFlyweight;
	
	RunArray() {
		this.array = new Font[0];
		fontFlyweight = new FontFactory();
	}
	
	public void addRun(int start, int length, Font font) {
		this.array = Arrays.copyOf(array, array.length + length);
		
		for (int i = start; i < array.length; i++) {
			this.array[i] = fontFlyweight.getFont(font);
		}
	}
	
	public void appendRun(int length, Font font) {
		
		int oldLength = array.length;
		this.array = Arrays.copyOf(array, array.length + length);
		
		for (int i = oldLength; i < array.length; i++) {
			array[i] = fontFlyweight.getFont(font);
		}
	}
	
	public void printArray() {
		for(int i = 0; i < array.length; i++) {
			System.out.println("Font Name: " + this.array[i].fontName + " Size: " + this.array[i].pointSize + " Style: " + this.array[i].style);
		}
	}
}
