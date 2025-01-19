package course;
import java.util.*;

public class Student extends Person {
	private double score;
	protected String name;
	public void setScore(double score){
		this.score = score;
	}
	public double getScore(){
		return this.score;
	}
	public Student(String name, double score){
		super(name);
		this.score = score;
	}
	public Student(){
		super("EMPTY_NAME");
		this.score = 0.0;
	}
}
