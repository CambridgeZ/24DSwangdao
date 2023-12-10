public class bubbleSort {
    public static void bubbleSort(int a[], int n) {
        for (int i = n - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (a[j] > a[j + 1]) {
                    swap(a, j, j + 1);
                }
            }

            for (int k = 0; k < a.length; k++) {
                System.out.print(a[k]);
                System.out.print(" ");
            }
            System.out.println();
        }

        
    }
    
    public static void swap(int a[], int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    public static void main(String[] args) {
        int[] a={1,3,2,5,4,6,7,9,8};
        bubbleSort(a,a.length);
        for(int i:a){
            System.out.println(i);
        }
    }
}
