package arrays;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class MonkAndSuffixSort {
    static class QuickSelect {
        final String str;
        int[] arr;
        int target;

        QuickSelect(String str) {
            this.str = str;
            this.arr = new int[str.length()];

            for(int i=0;i<arr.length;i++) {
                arr[i] = i;
            }
        }

        int compare(int indexA, int indexB) {
            while(indexA < arr.length && indexB < arr.length) {
                if(str.charAt(indexA) < str.charAt(indexB))
                    return -1;
                else if(str.charAt(indexA) > str.charAt(indexB))
                    return 1;
                indexA++;
                indexB++;
            }

            return (indexA < arr.length)? 1: (indexB < arr.length)? -1: 0;
        }

        private void solve(int l, int r) {
            if(l < r) {
                int i = l;
                int j = i+1;

                while(j <= r) {
                    int compRes = compare(arr[l], arr[j]);

                    if(compRes >= 0) {
                        i++;
                        if(i < j) {
                            arr[i] = arr[i]^arr[j];
                            arr[j] = arr[i]^arr[j];
                            arr[i] = arr[i]^arr[j];
                        }
                    }
                    j++;
                }

                if(i > l) {
                    arr[l] = arr[l]^arr[i];
                    arr[i] = arr[l]^arr[i];
                    arr[l] = arr[l]^arr[i];
                }

                if(i > target)
                    solve(l, i-1);
                else if(i < target)
                    solve(i+1, r);
            }
        }

        String getKthSmallestIndex(int k) {
            target = k-1;
            solve(0, arr.length-1);
            return str.substring(arr[target]);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        String str = st.nextToken();
        int k = Integer.parseInt(st.nextToken());

        System.out.println(new QuickSelect(str).getKthSmallestIndex(k));
    }
}
