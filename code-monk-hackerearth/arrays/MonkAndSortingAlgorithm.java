package arrays;

import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class MonkAndSortingAlgorithm {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        long[][] arr = new long[n][2];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++) {
            arr[i][0] = Long.parseLong(st.nextToken());
            arr[i][1] = arr[i][0];
        }

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        while(true) {
            Arrays.sort(arr, Comparator.comparingLong((long[] a) -> a[1]%100000));

            boolean notDone = false;
            for(int i=0;i<arr.length;i++) {
                bw.write(arr[i][0]+" ");
                arr[i][1] /= 100000;
                if(arr[i][1] != 0)
                    notDone = true;
            }
            bw.write('\n');

            if(!notDone)
                break;
        }

        bw.flush();
    }
}
