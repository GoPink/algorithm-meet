import java.util.Scanner;

public class Main {
	
	public static boolean pell(char[] a) {
		
		for(int i=0; i<a.length/2;i++) {
				if(a[i]==a[a.length-1-i]) {
					
				}
				else 
					return false;
			}
		return true;
	}

	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
		String s=sc.next();
		
		char[] c=s.toCharArray();
		
		if(pell(c))
			System.out.println("1");
		else 
			System.out.println("0");
	}

}