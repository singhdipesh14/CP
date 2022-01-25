package Anonymous.Sorting;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class merge {

	public static void mergeFunc(List<Integer> arr, int left, int right) {
		int mid = left + (right - left) / 2;
		List<Integer> elle = new ArrayList<>(), aar = new ArrayList<>();
		for (int i = left; i <= mid; i++) {
			elle.add(arr.get(i));
		}
		for (int i = mid + 1; i <= right; i++) {
			aar.add(arr.get(i));
		}
		int i = 0, j = 0, k = left;
		while (i < elle.size() && j < aar.size()) {
			if (elle.get(i) > aar.get(j)) {
				arr.set(k++, aar.get(j++));
			} else {
				arr.set(k++, elle.get(i++));
			}
		}
		while (i < elle.size()) {
			arr.set(k++, elle.get(i++));
		}
		while (j < aar.size()) {
			arr.set(k++, aar.get(j++));
		}
	}

	public static void mergeSort(List<Integer> arr, int left, int right) {
		if (left < right == true) {
			int mid = left + (right - left) / 2;
			mergeSort(arr, left, mid);
			mergeSort(arr, mid + 1, right);
			mergeFunc(arr, left, right);
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number of elements : ");
		int n = sc.nextInt();
		List<Integer> arr = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			arr.add(sc.nextInt());
		}
		System.out.println("The sorted array is :");
		mergeSort(arr, 0, arr.size() - 1);
		for (int i = 0; i < arr.size(); i++) {
			System.out.print(arr.get(i) + " ");
		}
		sc.close();
	}
}