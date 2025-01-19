package exercise;

import java.io.FileReader;
import java.util.HashMap;
import java.util.Scanner;

public class CityTour implements ITour {
	private String fileName;
	private HashMap<String, String> tourMap = new HashMap<>();
	public CityTour(String fileName) {
		this.fileName = fileName;
		try (Scanner sc = new Scanner(new FileReader(this.fileName))) {
		      while (sc.hasNextLine()) {
		         String line = sc.nextLine();
		         String[] pair = line.split("\\:");
		         tourMap.put(pair[0], pair[1]);
		      }
		   }
		catch(Exception e){
			System.out.println("FILE NOT FOUND");
		}
	}
	@Override
	public String Suggest(String cityName) {
		return tourMap.getOrDefault(cityName, "CITY NOT FOUND");
	}
}
