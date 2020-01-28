import java.util.HashMap;

public class FontFactory {
	
	private HashMap<String, Font> usedFonts = new HashMap<String, Font>();

	public Font getFont(Font font) {
		Font currentFont = (Font)usedFonts.get(font.fontName);
		
		if (currentFont == null) {
			currentFont = new Font(font.fontName, font.pointSize, font.style);
			
			usedFonts.put(font.fontName, currentFont);
		}
		else if (currentFont.pointSize != font.pointSize || !currentFont.style.contentEquals(font.style)) {
			currentFont = new Font(font.fontName, font.pointSize, font.style);
				
			usedFonts.put(font.fontName, currentFont);
		}
		return currentFont;
	}
}
