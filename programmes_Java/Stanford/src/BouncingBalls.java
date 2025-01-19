import java.util.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import acm.program.*;
import acm.graphics.*;

public class BouncingBalls extends GraphicsProgram{
	private static final int DELAY = 3;
	private ArrayList<Ball> balls = new ArrayList<Ball>();
	public void init(){
		JButton ballButton = new JButton("Add ball");
		add(ballButton, SOUTH);
		addActionListeners();
	}
	public void run(){
		while(true){
			for(Ball ball : balls){
				ball.heartBeat(getWidth(), getHeight());
			}
			pause(DELAY);
		}
	}
	public void actionPerformed(Action e){
		Ball ball = new Ball(getWidth(), getHeight());
		add(ball.getShape());
		balls.add(ball);
	}
}
