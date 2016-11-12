import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Palindrome {
	public static void main(String[] args) {
		Palindrome pal = new Palindrome();
		int queSize = 0;
		String[] nums = null;
		boolean[][] answ = null;
		try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
				BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))){
			// 배열 크기 입력을 무시
			br.readLine();
			// 숫자들의 배열 정의
			nums = br.readLine().split(" ");
			// 숫자들의 바텀업 방식 결과 배열 생성
			answ = pal.solution(nums);
			// 질문 개수 입력
			queSize = Integer.parseInt(br.readLine());
			// 질문 개수 만큼 반복
			while(queSize-->0){
				String[] que = br.readLine().split(" ");
				int start = Integer.parseInt(que[0])-1;
				int end = Integer.parseInt(que[1])-1;
				bw.write((answ[start][end]?"1\n":"0\n"));
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

	}
	public boolean[][] solution(String[] input){
		// 길이만큼 선언
		boolean[][] cache = new boolean[input.length][input.length];
		// 시작부터 끝까지 모두 계산, end는 항상 start보다 크다고 가정
		for(int end = 0; end < input.length; end++){
			for(int start = 0; start <= end; start++){
				cache[start][end] = input[start].equals(input[end]);
				if(end-start>2){
					cache[start][end] = cache[start][end] && cache[start+1][end-1];
				}
			}
		}

		return cache;
	}
}
