namespace Problem215
{
	public class Solution
	{
		public int FindKthLargest(int[] nums, int k)
		{
			var heap = new PriorityQueue<int, int>(Comparer<int>.Create((x, y) => y.CompareTo(x)));
			for (int i = 0; i < nums.Length; i++)
			{
				heap.Enqueue(nums[i], nums[i]);
			}

			while (k > 1)
			{
				heap.Dequeue();
				k -= 1;
			}

			return heap.Peek();
		}
	}
}
