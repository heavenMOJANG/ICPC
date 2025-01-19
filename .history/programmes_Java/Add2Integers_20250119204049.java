import java.util.*;

public class Add2Integers extends ConsoleProgram{
    public static void main(String[] args) {
        println("This program adds two numbers.");
        int n1 = readInt("Enter n1: ");
        int n2 = readInt("Enter n2: ");
        int total = n1 + n2;
        println("The total is " + total + ".");
    }
}
