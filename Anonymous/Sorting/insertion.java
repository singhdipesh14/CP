package Anonymous.Sorting;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class insertion {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number of elements : ");
		int n = sc.nextInt();
		List<Integer> arr = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			arr.add(sc.nextInt());
		}
		insertionSort(arr);
		System.out.println("The sorted array is :");
		for (int i = 0; i < arr.size(); i++) {
			System.out.print(arr.get(i) + " ");
		}
		sc.close();
	}

	private static void insertionSort(List<Integer> arr) {
		for (int i = 1; i < arr.size(); i++) {
			int j = i - 1;
			while (j >= 0 && arr.get(j) > arr.get(i)) {
				j--;
			}
			int temp = arr.get(i);
			for (int k = i; k > j + 1; k--) {
				arr.set(k, arr.get(k - 1));
			}
			arr.set(j + 1, temp);
		}
	}
}
