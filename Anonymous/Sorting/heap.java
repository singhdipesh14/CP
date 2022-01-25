package Anonymous.Sorting;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class heap {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number of elements : ");
		int n = sc.nextInt();
		List<Integer> arr = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			arr.add(sc.nextInt());
		}
		heapSort(arr);
		System.out.println("The sorted array is :");
		for (int i = 0; i < arr.size(); i++) {
			System.out.print(arr.get(i) + " ");
		}
		sc.close();
	}

	private static void heapSort(List<Integer> arr) {
		for (int i = arr.size() / 2 - 1; i >= 0; i--) {
			heapify(arr, arr.size(), i);
		}
		for (int i = arr.size() - 1; i > 0; i--) {
			swap(arr, 0, i);
			heapify(arr, i, 0);
		}
	}

	private static void heapify(List<Integer> arr, int size, int i) {
		int largest = i;
		int r = 2 * i + 1;
		int l = 2 * i + 2;
		if (l < size && arr.get(l) > arr.get(largest)) {
			largest = l;
		}
		if (r < size && arr.get(r) > arr.get(largest)) {
			largest = r;
		}
		if (largest != i) {
			swap(arr, i, largest);
		}
		heapify(arr, size, largest);
	}

	private static void swap(List<Integer> arr, int j, int i) {
		int temp = arr.get(i);
		arr.set(i, arr.get(j));
		arr.set(j, temp);
	}
}
