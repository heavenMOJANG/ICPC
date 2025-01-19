import java.util.*;
import java.io.*;
import java.nio.channels.FileChannel;

public class group6 { 
	public static void main(String[] Args) {
		try{
			File f = new File("F:\\����\\Palindrome .txt");
			
			File f1 = new File("F:\\����\\ѹ�����������\\group6 compressed.txt");
			copyFileUsingFileChannels(f, f1);
			
			File f2 = new File("F:\\����\\ѹ�����������\\group6 decompressed.txt");
			copyFileUsingFileChannels(f, f2);
			
		} catch(Exception e) {
			System.out.println("ERROR:FILE NOT FOUND.");
		}
	}	

	private static void copyFileUsingFileChannels(File source, File dest) throws IOException {    
        	FileChannel inputChannel = null;    
        	FileChannel outputChannel = null;    
        	try {
        		inputChannel = new FileInputStream(source).getChannel();
        		outputChannel = new FileOutputStream(dest).getChannel();
        		outputChannel.transferFrom(inputChannel, 0, inputChannel.size());
        	} finally {
        		inputChannel.close();
        		outputChannel.close();
        	}
	}
}
