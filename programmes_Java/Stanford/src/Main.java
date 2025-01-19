import java.util.*;

public class Main {
	
	public static void main(String[] Args){
		HashMap<String, Integer> phoneBook = new HashMap<String, Integer>();
		phoneBook.put("Chenlei", 83173560);
		phoneBook.put("HuJuxin", 88137420);
		phoneBook.put("BaoRong", 81370523);
		
		for(String key : phoneBook.keySet()){
			System.out.println(phoneBook.get(key));
		}
	}
}