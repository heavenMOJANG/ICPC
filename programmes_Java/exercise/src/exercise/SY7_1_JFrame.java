package exercise;

import java.util.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

@SuppressWarnings("serial")
public class SY7_1_JFrame extends Frame {
		public static void main(String[] Args){
			new SY7_1_JFrame();
		}
		
		JTextField text1 = new JTextField(20);
		JTextField text2 = new JTextField(20);
		JTextField text3 = new JTextField(20);
		
		public SY7_1_JFrame() {
			JFrame f = new JFrame("商品计算");
			Dimension d = new Dimension();
			d.setSize(400, 200);
			f.setSize(d);
			f.setBackground(Color.RED);
			Point p = new Point(100, 100);
			
			JPanel jPanel = new JPanel();
			
			JLabel danjia = new JLabel("单价");
			JLabel shuliang = new JLabel("数量");
			JLabel jieguo = new JLabel("结果");
			
			JButton button1 = new JButton("计算");
			
			jPanel.setLayout(new BoxLayout(jPanel, BoxLayout.Y_AXIS));
			
			JPanel panel1 = new JPanel(new FlowLayout(FlowLayout.LEFT));
			panel1.add(danjia);
			panel1.add(text1);
			panel1.setAlignmentX(Component.CENTER_ALIGNMENT);
			jPanel.add(panel1);
			
			JPanel panel2 = new JPanel(new FlowLayout(FlowLayout.LEFT));
			panel2.add(shuliang);
			panel2.add(text2);
			panel2.setAlignmentX(Component.CENTER_ALIGNMENT);
			jPanel.add(panel2);
			
			JPanel panel3 = new JPanel(new FlowLayout(FlowLayout.LEFT));
			panel3.add(jieguo);
			panel3.add(text3);
			panel3.add(button1);
			panel3.setAlignmentX(Component.CENTER_ALIGNMENT);
			jPanel.add(panel3);
			
			f.add(jPanel);
			f.setLocation(p);
			f.setVisible(true);
			
			addWindowListener(new WindowAdapter() {
				public void windowClosing(WindowEvent e) {
					System.exit(0);
				}
			});
			
			button1.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					double price = Double.parseDouble(text1.getText());
					int quantity = Integer.parseInt(text2.getText());
					double total = price * quantity;
					text3.setText(String.valueOf(total));
				}
			});
		}
}
