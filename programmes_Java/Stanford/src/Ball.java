import acm.graphics.GOval;
import acm.program.*;
import acm.util.RandomGenerator;
import java.awt.*;

public class Ball extends GraphicsProgram{
	private GOval shape = null;
	private double dx = 0.0;
	private double dy = 0.0;
	private static final int BALL_SIZE = 2;
	public Ball(int screenWidth,int screenHeight){
		RandomGenerator rg = RandomGenerator.getInstance();
		double x = rg.nextInt(screenWidth - BALL_SIZE);
		double y = rg.nextInt(screenHeight - BALL_SIZE);
		shape = new GOval(x, y, BALL_SIZE, BALL_SIZE);
		shape.setFilled(true);
		shape.setColor(Color.BLUE);
		dx = getRandomSpeed();
		dy = getRandomSpeed();
	}
	public void heartBeat(int screenWidth,int screenHeight){
		shape.move(dx, dy);
		reflectOffWalls(screenWidth, screenHeight);
	}
	private void reflectOffWalls(int sWidth, int sHeight){
		if(shape.getY() < 0) dy *= -1;
		if(shape.getY() > sHeight - BALL_SIZE) dy *= -1;
		if(shape.getX() < 0) dx *= -1;
		if(shape.getX() > sWidth - BALL_SIZE) dx *= -1;
	}
	public GOval getShape(){
		return shape;
	}
	private double getRandomSpeed(){
		RandomGenerator rg = RandomGenerator.getInstance();
		double speed = rg.nextDouble(1, 3);
		if(rg.nextBoolean()) speed *= -1;
		return speed;
	}
}
