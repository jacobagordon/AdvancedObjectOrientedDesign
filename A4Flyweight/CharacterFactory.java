import java.util.HashMap;

public class CharacterFactory {
	
	private HashMap<Character, Charact> usedCharacters = new HashMap<Character, Charact>();
	
	public Charact getChar(char unicode) {
		Charact currentChar = (Charact)usedCharacters.get(unicode);
		
		if(currentChar == null) {
			currentChar = new Charact(unicode);
			
			usedCharacters.put(unicode, currentChar);
		}
		return currentChar;
	}
}
