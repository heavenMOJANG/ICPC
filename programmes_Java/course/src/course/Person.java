package course;
import java.util.*;

public class Person {
	private String name;
	public void setName(String name){
		this.name = name;
	}
	public String getName(){
		return this.name;
	}
	public Person(String name){
		this.name = name;
	}
	public Person(){
		this.name = "EMPTY_NAME";
	}
}
