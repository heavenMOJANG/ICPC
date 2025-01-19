package course;

public class Circle extends Geometries {
	private double radius;
	public Circle() {
		this(1.0);
	}
	public Circle(double radius) {
		this("ϸ��", radius);
	} 
	public Circle(String lineType, double radius) {
		super(lineType);
		this.radius = radius;
	}
	public void setRadius(double radius) {
		this.radius = radius;
	}
	public double getRadius() {
		return this.radius;
	}
	public double calcPerimeter(){
		return 2 * Math.PI * radius;
	}
	public String printInfo(){
		String s = "��Բ�Ρ� ����  = " + this.radius;
		s += "�� �������ͣ� " + getLineType();
		return s;
	}
	public String printPerimeter(){
		String s = "��Բ�Ρ� �ܳ� = " + calcPerimeter();
		return s;
	}
}