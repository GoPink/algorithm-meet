import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Palindrome {
	public static void main(String[] args) {
		int numSize = 0, queSize = 0;
		String numList[] = null, queNums[][] = null;
		try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))){
			// 배열 크기 입력
			numSize = Integer.parseInt(br.readLine());
			// 크기만큼 생성
			numList = new String[numSize];
			// 입력에서 파싱해서 배열에 입력
			numList = br.readLine().split(" ");
			// 질문 크기 입력
			queSize = Integer.parseInt(br.readLine());
			// 크기만큼 생성
			queNums = new String[queSize][2];
			// 입력에서 파싱해서 2차원 배열에 입력
			for (int cnt = 0; cnt < queSize; cnt++) {
				queNums[cnt] = br.readLine().split(" ");
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		// 질문 수 만큼 반복
		for (int index = 0; index < queSize; index++) {
			int ret = 0;
			// 시작과 끝 인덱스 설정 (배열이므로 -1함)
			int startIdx = Integer.parseInt(queNums[index][0])-1;
			int endIdx = Integer.parseInt(queNums[index][1])-1;
			int cnt = endIdx-startIdx;
			// 시작~끝 까지 일치여부 검사
			for (int idx = 0; idx <= cnt/2; idx++) {
				if (!numList[startIdx + idx].equals(numList[endIdx - idx])) {
					// 하나라도 같지 않으면 ret = 0
					ret = 0;
					break;
				} else {
					// 계속 같으면 ret = 1
					ret = 1;
				}
			}
			System.out.println(ret);
		}
	}
}
