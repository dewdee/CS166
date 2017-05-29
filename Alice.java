import java.util.*;
import java.util.Map.Entry;

public class Alice{
	public static void main(String[] args){
		Scanner reader = new Scanner(System.in);
		System.out.println("Enter the ciphertext: ");
		String ciphertext = reader.nextLine().toUpperCase().replaceAll(" ", "");
		String plaintext = "";
		
		//frequency table holds the frequency of each char from ciphertext
		Map<Character, Integer> frequencyTable = new HashMap<Character, Integer>();
		//print the frequency analysis
		analyze(ciphertext, frequencyTable);
		
		System.out.println("Enter a key: ");
		String key = reader.nextLine().toUpperCase().replaceAll(" ", "");
		plaintext = decrypt(ciphertext, key);
		
		reader.close();
		System.out.println(plaintext);
	}
	public static void analyze(String ciphertext, Map<Character, Integer> frequencyTable){
		//initialize our frequency table, it will input the alphabet in order anyways so we can just initialize char here

		for(char ch = 'A'; ch <= 'Z'; ch++)
			frequencyTable.put(ch, 0); 
		for(int i = 0; i < ciphertext.length(); i++){
			Character c = ciphertext.charAt(i);
			Integer f = frequencyTable.get(c);
			
			frequencyTable.put(c, f + 1);
		}

		//sort our frequency table by count descending
		Set<Entry<Character, Integer>> set = frequencyTable.entrySet();
		List<Entry<Character, Integer>> list = new ArrayList<Entry<Character, Integer>>(set);
		Collections.sort(list, new Comparator<Map.Entry<Character, Integer>>(){
			@Override
			public int compare(Entry<Character, Integer> o1, Entry<Character, Integer> o2) {
				return(o2.getValue()).compareTo(o1.getValue());
			}
		});
		
		//create the key
		for(Map.Entry<Character, Integer> entry : list){
			System.out.println(entry.getKey() + " ==> " + entry.getValue());
		}
	}
	public static String decrypt(String ciphertext, String key){
		String plaintext = "";
		String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		
		StringBuilder sb = new StringBuilder("");
		for(int i = 0; i < ciphertext.length(); i++){
			for(int j = 0; j < 26; j++){
				//compare the key to the ciphertext and then add the corresponding plaintext character
				if (key.charAt(j) == ciphertext.charAt(i)){
                    sb.append(alphabet.charAt(j));
                    break;
				}
			}
		}
		plaintext = sb.toString();
		
		return plaintext;
	}
}