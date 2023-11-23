public class QuickSort {
    
    private static int Partition(int a[],int low,int high){
        int pivot=a[low];
        while(low<high){
            while(low<high&&a[high]>=pivot){
                high--;
            }
            a[low]=a[high];
            while(low<high&&a[low]<=pivot){
                low++;
            }
            a[high]=a[low];
        }
        a[low]=pivot;
        return low;
    }

    public static void QuickSort(int a[],int low,int high){
        if(low<high){
            int pivotpos=Partition(a,low,high);
            QuickSort(a,low,pivotpos-1);
            QuickSort(a,pivotpos+1,high);
        }
    }

    static void test(){
        int [] a={3,5,1};
        QuickSort(a,0,a.length-1);
        for(int i=0;i<a.length;i++){
            System.out.print(a[i]);
            System.out.print(" ");
        }
    }

    public static void main(String[] args){
        test();
    }
}
