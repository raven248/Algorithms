package arrays;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class MonkAndNiceStrings {
    static class Node {
        Node[] children = new Node[26];
        int leafs = 0;
        int[] count = new int[26];

        public int countLowerStrings(final String str) {
            Node ptr = this;
            int res = 0;

            for(int i=0;i<str.length();i++) {
                int index = str.charAt(i)-'a';

                res += ptr.leafs;
                for(int j=0;j<index;j++)
                    res += ptr.count[j];
                if(ptr.children[index] == null)
                    return res;
                ptr = ptr.children[index];
            }

            return res;
        }

        public void insert(String str) {
            Node ptr = this;

            for(int i=0;i<str.length();i++) {
                int index = str.charAt(i)-'a';
                if(ptr.children[index] == null)
                    ptr.children[index] = new Node();
                ptr.count[index]++;
                ptr = ptr.children[index];
            }
            ptr.leafs++;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Node root = new Node();

        for(int i=0;i<n;i++) {
            String str = br.readLine();
            root.insert(str);
            System.out.println(root.countLowerStrings(str));
        }
    }
}
