public class mergeSort {
    public static void mergeSort(int[] a){
        int len=a.length;
        int[] temp=new int[len];
        mergeSort(a,0,len-1,temp);
    }

    private static void mergeSort(int[] a, int left, int right, int[] temp) {
        if(left<right){
            int mid=(left+right)/2;
            mergeSort(a,left,mid,temp);
            mergeSort(a,mid+1,right,temp);
            merge(a,left,mid,right,temp);
        }
    }

    private static void merge(int[] a, int left, int mid, int right, int[] temp) {
        int i=left;
        int j=mid+1;
        int t=0;
        while(i<=mid&&j<=right){
            if(a[i]<=a[j]){
                temp[t++]=a[i++];
            }else{
                temp[t++]=a[j++];
            }
        }
        while(i<=mid){
            temp[t++]=a[i++];
        }
        while(j<=right){
            temp[t++]=a[j++];
        }
        t=0;
        while(left<=right){
            a[left++]=temp[t++];
        }
    }

    public static void main(String[] args) {
        int[] a={1,3,2,5,4,6,7,9,8};
        mergeSort(a);
        for(int i:a){
            System.out.println(i);
        }
    }
}
