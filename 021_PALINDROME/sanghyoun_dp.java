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
			// �迭 ũ�� �Է��� ����
			br.readLine();
			// ���ڵ��� �迭 ����
			nums = br.readLine().split(" ");
			// ���ڵ��� ���Ҿ� ��� ��� �迭 ����
			answ = pal.solution(nums);
			// ���� ���� �Է�
			queSize = Integer.parseInt(br.readLine());
			// ���� ���� ��ŭ �ݺ�
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
		// ���̸�ŭ ����
		boolean[][] cache = new boolean[input.length][input.length];
		// ���ۺ��� ������ ��� ���, end�� �׻� start���� ũ�ٰ� ����
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
