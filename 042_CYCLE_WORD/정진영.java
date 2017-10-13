import java.util.Scanner;
import java.util.*;
public class Main {
    public static void isRotation(HashSet<String> hs, String word) {
		StringBuilder sb;
		int len = word.length();
		for(String str : hs) {
			sb = new StringBuilder(str);
			for(int i = 0; i < len; i++) {
				  if(word.equals(sb.toString()))
		                return;
		            else {
		            	sb= sb.append(sb.charAt(0)).deleteCharAt(0);
					}
			}
		}
		hs.add(word); //해시셋의 단어들과 일치하지 않으면 해당단어 저장
	}
    
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
        int number = scan.nextInt();
        String[] input = new String[50];
        HashSet<String> hs = new HashSet<>();
        for(int i = 0; i < number; i++) {
            input[i] = scan.next();
        }
        hs.add(input[0]);
        for(int i = 1; i < number; i++) {
            isRotation(hs, input[i]); 
        }
		System.out.println(hs.size());
	}
}
/*
 이것은 왜 안돌아가는지 모르겠다ㅠ
import java.util.*;
public class Practice1 {
    public static void isRotation(HashSet<String> hs, String word) {
		StringBuilder sb;
		
		for(String str : hs) {
			sb = new StringBuilder(str);
			sb = sb.append(sb);
			if(sb.indexOf(word) != -1){
				return;
			}
		}
		hs.add(word); //해시셋의 단어들과 일치하지 않으면 해당단어 저장
	}
    
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
        int number = scan.nextInt();
        String[] input = new String[50];
        HashSet<String> hs = new HashSet<>();
        for(int i = 0; i < number; i++) {
            input[i] = scan.next();
        }
        hs.add(input[0]);
        for(int i = 1; i < number; i++) {
            isRotation(hs, input[i]); 
        }
		System.out.println(hs.size());
	}
}*/