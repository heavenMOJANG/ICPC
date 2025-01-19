package course;

import java.io.*;
import java.util.*;

public class group6 {

    private Map<String, String> dictionary;
    private Map<String, String> reverseDictionary;

    public group6() {
        dictionary = new HashMap<>();
        reverseDictionary = new HashMap<>();
    }

    private void buildDictionary(String text) {
        String[] words = text.split("\\s+");
        int index = 1;
        for (String word : words) {
            if (!dictionary.containsKey(word)) {
                String code = encodeIndex(index++);
                dictionary.put(word, code);
                reverseDictionary.put(code, word);
            }
        }
    }

    private String encodeIndex(int index) {
        StringBuilder encoded = new StringBuilder();
        while (index > 0) {
            int remainder = (index - 1) % 62;
            if (remainder < 10) {
                encoded.append((char) ('0' + remainder));
            } else if (remainder < 36) {
                encoded.append((char) ('a' + remainder - 10));
            } else {
                encoded.append((char) ('A' + remainder - 36));
            }
            index = (index - 1) / 62;
        }
        return encoded.reverse().toString();
    }

    public String compress(String text) {
        buildDictionary(text);
        StringBuilder compressedText = new StringBuilder();
        String[] paragraphs = text.split("\n");
        for (String paragraph : paragraphs) {
            String[] words = paragraph.split("\\s+");
            for (String word : words) {
                compressedText.append(dictionary.get(word)).append(" ");
            }
            compressedText.append("\n");
        }
        return compressedText.toString().trim();
    }

    public String decompress(String compressedText) {
        StringBuilder decompressedText = new StringBuilder();
        String[] paragraphs = compressedText.split("\n");
        for (String paragraph : paragraphs) {
            String[] codes = paragraph.split("\\s+");
            for (String code : codes) {
                decompressedText.append(reverseDictionary.get(code)).append(" ");
            }
            decompressedText.append("\n");
        }
        return decompressedText.toString().trim();
    }
   private String readFile(String filePath) throws IOException {
        StringBuilder content = new StringBuilder();
        InputStream in = new FileInputStream(filePath);
        try (BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(in, "UTF-8"))) {
            String line;
            while ((line = bufferedReader.readLine()) != null) {
                content.append(line).append("\n");
            }
        }
        return content.toString().trim();
    }

    private void writeFile(String filePath, String content) throws IOException {
        OutputStream out = new FileOutputStream(filePath);
        try (BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(out, "UTF-8"))) {
            bufferedWriter.write(content.trim());
        }
    }

    public void compressFile(String inputFilePath, String outputFilePath) {
        try {
            String fileContent = readFile(inputFilePath);
            String compressedData = compress(fileContent);
            writeFile(outputFilePath, compressedData);
           // System.out.println("Compressed file content:");
           // System.out.println(compressedData);
        } catch (IOException e) {
           // System.err.println("Error processing file: " + e.getMessage());
            e.printStackTrace();
        }
    }

    public void decompressFile(String compressedFilePath, String outputFilePath) {
        try {
            String fileContent = readFile(compressedFilePath);
            String decompressedData = decompress(fileContent);
            writeFile(outputFilePath, decompressedData);
            //System.out.println("Decompressed file content:");
           // System.out.println(decompressedData);
        } catch (IOException e) {
           // System.err.println("Error processing file: " + e.getMessage());
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        group6 fileProcessor = new group6();
        String inputFilePath = "D:\\cs.txt";
        String compressedFilePath = "D:\\group6compressed.txt";
        fileProcessor.compressFile(inputFilePath, compressedFilePath);

        //System.out.println();

        String decompressedFilePath = "D:\\group6decompressed.txt";
        fileProcessor.decompressFile(compressedFilePath, decompressedFilePath);
    }
}