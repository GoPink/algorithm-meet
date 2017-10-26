package command_prompt_041;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int num = 0;
        String[] input = new String[50];
        boolean check = false;
        String output = "";

        num = scan.nextInt();

        for (int i = 0; i < num; i++) {
            input[i] = scan.next();
        }
        for (int i = 0; i < input[0].length(); i++) {
            for (int j = 0; j < num - 1; j++) {
                if (input[j].charAt(i) != input[j + 1].charAt(j)) {
                    check = true;
                    break;
                }
            }
            if (check) {
                output += "?";
                check = false;
            } else {
                output += Character.toString(input[0].charAt(i));
            }
        }

        System.out.println(output);

    }

}