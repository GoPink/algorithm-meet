import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int number = sc.nextInt();// �Է� �����̸���
		String s[] = new String[number];
		boolean check = false;

		String output = "";// ��� ��

		for (int i = 0; i < number; i++)
			s[i] = sc.next();// ���ڿ��� ��Ʈ�� �迭�� �޾Ƶ��δ�.
		
		for(int i=0; i<s[0].length();i++) {//���� ���̴� �����ϱ� �� ���ڿ��� ���̸�ŭ
			for(int j=0; j<number-1; j++) {//��ü ���� ���� ��ŭ
				if(s[j].charAt(i)!=s[j+1].charAt(i)) {//�ϳ��� �ٸ��� ?�ϱ� �ٸ���
					check=true;
					break;
				}
			}
			if(check) {//�ٸ���� ?���̱�
				output +="?";
				check=false;
			}else {//������� false�� �ϰ� 
				output +=s[0].charAt(i);//��¥�� �� ���� ���̱� ������ 0���� �ص� �ȴ�.
			}
		}
		
		System.out.println(output);
	}
}