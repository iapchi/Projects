import java.util.*;
import java.io.*;

/** 
 * A program to generate a histogram of words in a text document.
 * 
 * Given a filename on the command line, this program will output
 * a list of "word: freq" pairs, where "word" is a word appearing in
 * text file and "freq" is the number of occurrences of that word.
 * 
 * The results are printed in alphabetical order, by word.
 * 
 * All words are converted to lower case so "Day" and "day" would
 * count as two occurrences of the word "day".
 *
 */
public class Histogram {
	public static void main(String[] args) {
		if (args.length != 1) {
			System.out.println("Usage: java Histogram <file>");
			return;
		}
		
		WordScanner s = null;
		Map<String,Integer> freq = new TreeMap<String,Integer>();
		try {
			s = new WordScanner(new BufferedReader(new FileReader(args[0])));
			// s.useDelimiter("\\W");  // use with java.util.Scanner to skip all non-letters
			
			// iterate through the words, maintaining a count in the Map
			while (s.hasNext()) {
				String word = s.next().toLowerCase();
				if (freq.containsKey(word)) {
					// only need to bump up the count
					Integer i = freq.get(word);
					freq.put(word, i + 1);					
				} else {
					// insert a new binding
					freq.put(word, 1);
				}
			}			
			
			// iterate through the key-value bindings, printing them out
			PrintWriter w = new PrintWriter(System.out);
			for (Map.Entry<String, Integer> kv : freq.entrySet()) {
				w.printf("%s : %d\n", kv.getKey(), kv.getValue().intValue());
			}
			w.close();
		} catch (FileNotFoundException e) {
			System.out.println("File not found");
		}
	}
}
