package Anonymous.Sorting;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class quick {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number of elements : ");
		int n = sc.nextInt();
		List<Integer> arr = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			arr.add(sc.nextInt());
		}
		quickSort(arr, 0, arr.size() - 1);
		System.out.println("The sorted array is :");
		for (int i = 0; i < arr.size(); i++) {
			System.out.print(arr.get(i) + " ");
		}
		sc.close();
	}

	private static void quickSort(List<Integer> arr, int left, int right) {
		if (left < right) {
			int pivot = partition(arr, left, right);
			System.out.println("Pivot for left:" + left + " and right:" + right + " is : " + pivot);
			quickSort(arr, left, pivot - 1);
			quickSort(arr, pivot + 1, right);
		}
	}

	private static int partition(List<Integer> arr, int left, int right) {
		int pivot = left;
		int i = left;
		for (int j = left + 1; j <= right; j++) {
			if (arr.get(j) < arr.get(pivot)) {
				swap(arr, j, ++i);
			}
		}
		swap(arr, i, pivot);
		return i + 1;
	}

	private static void swap(List<Integer> arr, int a, int b) {
		int temp = arr.get(a);
		arr.set(a, arr.get(b));
		arr.set(b, temp);
	}
}
