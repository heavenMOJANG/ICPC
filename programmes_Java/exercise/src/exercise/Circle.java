package exercise;

public class Circle implements IGeometries{
	private String lineType="ϸ��";
	private double radius;
	public Circle() {
		this(1.0);
	}
	public Circle(double radius) {
		this.radius = radius;
	}
	public Circle(String lineType, double radius){
		this.lineType = lineType;
		this.radius = radius;
	}
	public void setRadius(double radius) {
		this.radius = radius;
	}
	public double getRadius() {
		return this.radius;
	}
	@Override
	public void setLineType(String lineType){
		this.lineType = lineType;
	}
	@Override
	public String getLineType(){
		return this.lineType;
	}
	@Override
	public double calcPerimeter(){
		return 2 * Math.PI * radius;
	}
	@Override
	public String printPerimeter(){
		String s = "��Բ�Ρ� �ܳ� = " + calcPerimeter();
		return s;
	}
	@Override
	public String printInfo(){
		String s = "��Բ�Ρ� ����  = " + this.radius;
		return s;
	}

}
