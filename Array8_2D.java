 import java.util.Scanner;

public class Array8_2D {
   public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n, m;
        System.out.print("Enter rows and columns: ");
        n = sc.nextInt();
        m = sc.nextInt();

        int[][] arr = new int[n][m];

        System.out.println("Enter elements:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = sc.nextInt();
            }
        }

        System.out.println("Snake pattern:");
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                // left to right
                for (int j = 0; j < m; j++) {
                    System.out.print(arr[i][j] + " ");
                }
            } else {
                // right to left
                for (int j = m - 1; j >= 0; j--) {
                    System.out.print(arr[i][j] + " ");
                }
            }
            System.out.println();
        }

        sc.close();
    }
}

