package course;

public interface IGeometries {
	default void setLineType(String lineType) {
        throw new UnsupportedOperationException("Method setLineType needs to be implemented by the class implementing this interface.");
    }
    default String getLineType() {
        throw new UnsupportedOperationException("Method getLineType needs to be implemented by the class implementing this interface.");
    }
	double calcPerimeter();
	String printPerimeter();
	String printInfo();
	
}
