import acm.program.*;
import java.awt.event.ActionEvent;
import javax.swing.*;

public class MouseTrackerSoln extends ConsoleProgram{
	JTextField field = new JTextField(10);
	public void actionPerformed(ActionEvent e){
		if(e.getActionCommand().equals("Press me"))
			println("Hello, "+field.getText());
	}
	public void run(){
		add(field, NORTH);
		field.getText();
		field.setText("Marry me");
		JLabel label = new JLabel("Name");
		JButton button = new JButton("Press me");
		add(button, NORTH);
		addActionListeners();
	}
}