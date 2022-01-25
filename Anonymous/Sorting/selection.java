package Anonymous.Sorting;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class selection {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number of elements : ");
		int n = sc.nextInt();
		List<Integer> arr = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			arr.add(sc.nextInt());
		}
		selectionSort(arr);
		System.out.println("The sorted array is :");
		for (int i = 0; i < arr.size(); i++) {
			System.out.print(arr.get(i) + " ");
		}
		sc.close();
	}

	private static void selectionSort(List<Integer> arr) {
		for (int i = 0; i < arr.size() - 1; i++) {
			int min = i;
			for (int j = i + 1; j < arr.size(); j++) {
				if (arr.get(j) < arr.get(min)) {
					min = j;
				}
			}
			swap(arr, min, i);
		}
	}

	private static void swap(List<Integer> arr, int j, int i) {
		int temp = arr.get(i);
		arr.set(i, arr.get(j));
		arr.set(j, temp);
	}
}
