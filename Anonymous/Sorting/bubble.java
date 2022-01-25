package Anonymous.Sorting;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class bubble {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number of elements : ");
		int n = sc.nextInt();
		List<Integer> arr = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			arr.add(sc.nextInt());
		}
		bubbleSort(arr);
		System.out.println("The sorted array is :");
		for (int i = 0; i < arr.size(); i++) {
			System.out.print(arr.get(i) + " ");
		}
		sc.close();
	}

	private static void bubbleSort(List<Integer> arr) {
		for (int i = 0; i < arr.size() - 1; i++) {
			for (int j = 0; j < arr.size() - i - 1; j++) {
				if (arr.get(j) > arr.get(j + 1))
					swap(arr, j, j + 1);
			}
		}
	}

	private static void swap(List<Integer> arr, int j, int i) {
		int temp = arr.get(i);
		arr.set(i, arr.get(j));
		arr.set(j, temp);
	}
}
