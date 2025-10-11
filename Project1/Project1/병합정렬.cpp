#include <iostream>
#include <vector>
using namespace std;

void MergeSort(vector<int>& _Arr, vector<int>& _Sorted, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int mid = (left + right) / 2;
	MergeSort(_Arr, _Sorted, left, mid);
	MergeSort(_Arr, _Sorted, mid + 1, right);

	if (_Arr[mid] <= _Arr[mid + 1]) return;

	int LeftIdx = left;
	int RightIdx = mid + 1;
	for (int i = left; i <= right; ++i)
	{
		if (LeftIdx > mid)
		{
			_Sorted[i] = _Arr[RightIdx];
			++RightIdx;
		}
		else if (RightIdx > right)
		{
			_Sorted[i] = _Arr[LeftIdx];
			++LeftIdx;
		}
		else if (_Arr[LeftIdx] <= _Arr[RightIdx])
		{
			_Sorted[i] = _Arr[LeftIdx];
			++LeftIdx;
		}
		else
		{
			_Sorted[i] = _Arr[RightIdx];
			++RightIdx;
		}
	}
	for (int i = left; i <= right; ++i)
	{
		_Arr[i] = _Sorted[i];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<int> arr(N);
	vector<int> sorted(N);

	for (int i = 0; i < N; ++i) cin >> arr[i];

	MergeSort(arr, sorted, 0, N - 1);

	for (int x : arr)
		cout << x << '\n';


	return 0;
}