/*Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.

Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7 
*/

#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int p_back(int a[],  int l , int h)
{
	int pivot = a[h];
	int i = l - 1;
	for (int j = l ; j < h ; j++)
	{
		if (a[j] < pivot)
		{
			i++;
			swap(&a[j], &a[i]);
		}
	}
	swap(&a[h], &a[i + 1]);
	return i + 1;
}
void QuickSort(int a[], int s, int e)
{
	if (s >= e)
		return;
	int p = p_back(a, s, e);
	QuickSort(a, s, p - 1);
	QuickSort(a, p + 1, e);
}

void quickSort(int input[], int size) {
  int start = 0;
	int end = size - 1;

	QuickSort(input, start, end);

}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}