package arrays;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class MinimumAndXorOr {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bf.readLine());
        int n;
        StringTokenizer st;

        while(t > 0) {
            n = Integer.parseInt(bf.readLine());
            st = new StringTokenizer(bf.readLine());

            int[] arr = new int[n];
            for(int i=0;i<n;i++)
                arr[i] = Integer.parseInt(st.nextToken());

            
            System.out.println(getMinXor(arr));

            t--;
        }
    }

    private static int getMinXor(final int[] arr) {
        Arrays.sort(arr);
        int res = arr[1]^arr[0];

        for(int i=2;i<arr.length;i++)
            res = Math.min(res, arr[i]^arr[i-1]);

        return res;
    }
}
