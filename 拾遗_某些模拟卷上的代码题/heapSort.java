public class heapSort {
    public static void heapSort(int[] a){
        int len=a.length;
        for(int i=len/2-1;i>=0;i--){
            adjustHeap(a,i,len);
        }
        for(int i=len-1;i>=0;i--){
            swap(a,0,i);
            adjustHeap(a,0,i);
        }
    }

    private static void swap(int[] a, int i, int i2) {
        var temp=a[i];
        a[i]=a[i2];
        a[i2]=temp;
    }

    private static void adjustHeap(int[] a, int i, int len) {
        int temp=a[i];
        for(int k=2*i+1;k<len;k=2*k+1){
            if(k+1<len&&a[k]<a[k+1]){
                k++;
            }
            if(a[k]>temp){
                a[i]=a[k];
                i=k;
            }else{
                break;
            }
        }
        a[i]=temp;
    }

    public static void main(String[] args) {
        int[] a={1,3,2,5,4,6,7,9,8};
        heapSort(a);
        for(int i:a){
            System.out.println(i);
        }
    }
}
