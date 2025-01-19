package course;

public class Rectangle extends Geometries {
	private double length;
	private double width;
	public Rectangle() {
		this(1.0, 1.0);
	}
	public Rectangle(double length, double width) {
		this("ϸ��", length, width);
	} 
	public Rectangle(String lineType, double length, double width) {
		super(lineType);
		this.length = length;
		this.width = width;
	}
	public void setLength(double length) {
		this.length = length;
	}
	public void setWidth(double width) {
		this.width = width;
	}
	public double getLength() {
		return length;
	}
	public double getWidth() {
		return width;
	}
	public double calcPerimeter(){
		return 2 * (length + width);
	}
	public String printInfo(){
		String s = "�������Ρ� ����  = " + length + " �� ���  = " + width;
		s += "�� �������ͣ� " + getLineType();
		return s;
	}
	public String printPerimeter(){
		String s = "�������Ρ� �ܳ� = " + calcPerimeter();
		return s;
	}
}