package arrays;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class MonkBeingMonitor {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        while(t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            Map<Integer, Integer> count = new HashMap<>();
            StringTokenizer st = new StringTokenizer(br.readLine());

            for(int i=0;i<n;i++) {
                int key = Integer.parseInt(st.nextToken());
                int value = count.getOrDefault(key, 0)+1;

                count.put(key, value);
            }

            int[][] arr = new int[count.size()][2];

            int index = 0;
            for(Map.Entry<Integer, Integer> entry: count.entrySet()) {
                int key = entry.getKey();
                int value = entry.getValue();

                arr[index][0] = key;
                arr[index][1] = value;
                index++;
            }

            Arrays.sort(arr, Comparator.comparingInt((int[] a) -> a[0]));


//            for(int i=0;i<arr.length;i++) {
//                System.out.print(arr[i][0] +"::"+arr[i][1]+" ");
//            }
//            System.out.println();

            int maxDiff = -1;
            int minCount = arr[0][1];

            for(int i=1;i<arr.length;i++) {
                int diff = arr[i][1]-minCount;
                if(diff > 0 && diff > maxDiff) {
                    maxDiff = diff;
                }
                if(minCount > arr[i][1]) {
                    minCount = arr[i][1];
                }
            }

            System.out.println(maxDiff);
        }
    }
}
