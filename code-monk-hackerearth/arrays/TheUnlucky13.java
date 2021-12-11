package arrays;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class TheUnlucky13 {
    final int MOD = 1000000009;

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int t = Integer.parseInt(bf.readLine());
        int n;

        while(t-- > 0) {
            n = Integer.parseInt(bf.readLine());
            System.out.println(countStrings(n));
        }
    }

    private static int countStrings(int n) {
        /*
            0 -> 0 - 9
            1 -> 0, 2-9
            3 -> 0 - 9

        */
    }
}
