import java.util.*;

class selectSort {
	public static void selectSort(int []a){
		int n=a.length;
		
		for(int i=0;i<n;i++){
			int min_index=i;
			for(int j=i+1;j<n;j++){
				if(a[j]<a[min_index]){
					min_index=j;
				}
			}
			int t=a[i];
			a[i]=a[min_index];
			a[min_index]=t;
		}
	}
	
	public static void main(String[] args) {
		int [] a={3,5,1};
		selectSort(a);
		
		for(int i=0;i<a.length;i++){
			System.out.print(a[i]);
			System.out.print(" ");
		}
		
	}
}