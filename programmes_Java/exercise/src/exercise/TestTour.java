package exercise;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class TestTour {
	CityTour cityTour = new CityTour("D:\\programmes_Java\\exercise\\src\\exercise\\cities.txt");
	
	public static void main(String[] Args){
		new TestTour();
	}
	
	JTextField text1 = new JTextField(20);
	JTextField text2 = new JTextField(20);
	
	public TestTour(){
		JFrame f = new JFrame("CITY & TOUR ATTRACTIONS");
		Dimension d = new Dimension();
		d.setSize(400, 200);
		f.setSize(d);
		f.setBackground(Color.RED);
		Point p = new Point(100, 100);
		JPanel jPanel = new JPanel();
		JLabel labelCity = new JLabel("City");
		JLabel labelFood = new JLabel("tourist atractions");
		JButton buttonQuery = new JButton("OK");
		jPanel.setLayout(new BoxLayout(jPanel, BoxLayout.Y_AXIS));
		JPanel panel1 = new JPanel(new FlowLayout(FlowLayout.RIGHT));
		panel1.add(labelCity);
		panel1.add(text1);
		jPanel.add(panel1);
		JPanel panel2 = new JPanel(new FlowLayout(FlowLayout.RIGHT));
		panel2.add(labelFood);
		panel2.add(text2);
		panel2.add(buttonQuery);
		jPanel.add(panel2);
		f.add(jPanel);
		f.setLocation(p);
		f.setVisible(true);
		f.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				System.exit(0);
			}
		});
		buttonQuery.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String cityName = text1.getText();
				text2.setText(cityTour.Suggest(cityName));
			}
		});
	}
}
