package course;
import java.util.*;

public class Test {
	public static void main(String[] Args){
		Rectangle rectangle = new Rectangle("œ∏œﬂ", 9.0, 1.5);
		System.out.println(rectangle.printInfo());
		System.out.println(rectangle.printPerimeter());
		
		Circle circle = new Circle("¥÷œﬂ", 2.0);
		System.out.println(circle.printInfo());
		System.out.println(circle.printPerimeter());
	}
}