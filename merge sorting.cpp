#include <iostream>
using namespace std;
	void input() {
		int size = 5;
		int arr[5];
		int index;
		for (int i = 0; i < size; i++) {
			cout << "Enter the number " << i + 1<<" ";
			cin >> index;
			arr[i] = index;
		}
	}
	void merge(int arr[], int l, int mid, int r) {
		
		//int mid = (l + r) / 2;
		int n1 = mid - l + 1;
		int n2 = r - mid;
		int *a=new int[n1];
		int *b=new int[n2];
		for (int i = 0;i < n1;i++)
		{
			a[i] = arr[l + i];
		}
		for (int i = 0;i < n2;i++) {
			b[i] = arr[mid+l + i];
		}

		int i = 0;
		int j = 0;
		int k = l;
		while (i < n1 && j < n2) {
			if (a[i] <= b[j]) {
				arr[k] = a[i];
				k++;
				i++;
			}
			else {
				arr[k] = b[j];
				k++;
				j++;
			}
		}
		while (i < n1) {
			arr[k] = a[i];
			k++;
			i++;
		}

		while (j < n2) {
			arr[k] = arr[j];
			k++;
			j++;
		}
	}
	void mergsort(int arr[], int l, int r) {
		if (l < r) {
			int mid = (l + r) / 2;
			mergsort(arr, l, mid);
			mergsort(arr, mid + 1, r);
			merge(arr, l, mid, r);	
		}
	}
	void display(int arr[]) {
		cout << " the array is ";
		for (int i = 0;i < 5;i++) {
			cout << arr[i] << " ";
		}
	}
int main() {
	int arr[5];
	input();
	mergsort(arr, 0, 4);
	display(arr);
}