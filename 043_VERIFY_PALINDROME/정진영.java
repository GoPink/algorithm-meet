import java.util.Scanner;
public class Main {
    public static int isPalindrome(char[] str, int begin, int end) {
		for(int i = begin; i < end - (i - begin); i++) {
			if(str[i] != str[end-(i-begin)])
				return 0;
		}
		return 1;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		String input = scan.next();
		final int NUMBER = 100;
		char[] change = new char[NUMBER];
        
        for(int i = 0; i < input.length(); i++) {
			change[i] = input.charAt(i);
		} //입력한 문자열을 배열을 만들어주어 넣어준다
	
		System.out.println(isPalindrome(change, 0, input.length()- 1));
	}
}
