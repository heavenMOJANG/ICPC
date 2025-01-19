package course;

public abstract class Geometries {
	private String lineType = "Ï¸Ïß";
	protected Geometries(){	
	}
	protected Geometries(String lineType){
		this.lineType = lineType;
	}
	public void setLineType(String lineType){
		this.lineType = lineType;
	}
	public String getLineType(){
		return this.lineType;
	}
	public abstract double calcPerimeter();
	public abstract String printInfo();
}
