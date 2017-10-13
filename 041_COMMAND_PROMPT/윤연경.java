import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int number = sc.nextInt();// 입력 파일이름수
		String s[] = new String[number];
		boolean check = false;

		String output = "";// 결과 값

		for (int i = 0; i < number; i++)
			s[i] = sc.next();// 문자열을 스트링 배열로 받아들인다.
		
		for(int i=0; i<s[0].length();i++) {//문자 길이는 같으니까 한 문자열의 길이만큼
			for(int j=0; j<number-1; j++) {//전체 문자 갯수 만큼
				if(s[j].charAt(i)!=s[j+1].charAt(i)) {//하나라도 다르면 ?니까 다르면
					check=true;
					break;
				}
			}
			if(check) {//다를경우 ?붙이기
				output +="?";
				check=false;
			}else {//같을경우 false로 하고 
				output +=s[0].charAt(i);//어짜피 다 같은 것이기 때문에 0으로 해도 된다.
			}
		}
		
		System.out.println(output);
	}
}