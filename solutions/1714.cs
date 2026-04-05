namespace Problem1714
{
	public class Solution
	{
		// public int[] SmallestK(int[] arr, int k)
		// {
		// 	if (arr.Length == k)
		// 		return arr;

		// 	int pivotIndex = arr.Length / 2;
		// 	int pivotVal = arr[pivotIndex];

		// 	// int lowPoint = 0;
		// 	// int highPoint = arr.Length - 1;
		// 	// while (lowPoint < highPoint)
		// 	// {
		// 	// 	// 双指针, 查找到不符合升降序列的元素 进行交换, 满足 左侧一定小于pivot, 右侧一定大于pivot
		// 	// 	while (arr[lowPoint] <= arr[pivot]) lowPoint++;
		// 	// 	while (arr[highPoint] >= arr[pivot]) highPoint--;

		// 	// 	(arr[highPoint], arr[lowPoint]) = (arr[lowPoint], arr[highPoint]);
		// 	// }

		// 	var highList = new List<int>();
		// 	var lowList = new List<int>();

		// 	foreach (var val in arr)
		// 	{
		// 		if (val <= pivotVal)
		// 			lowList.Add(val);
		// 		if (val > pivotVal)
		// 			highList.Add(val);
		// 	}

		// 	// low 正好是前k个小的数字
		// 	if (k == lowList.Count)
		// 	{
		// 		return [.. lowList];
		// 	}
		// 	else if (k < )
		// }
	}
}
