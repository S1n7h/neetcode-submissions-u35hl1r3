public class Solution
{
    public int Jump(int[] nums)
    {
        if (nums.Length == 1) return 0;
        Queue<int> q = new Queue<int>();
        int ret = 1;
        q.Enqueue(0);

        while (q.Count != 0)
        {
            int Size = q.Count;
            for (int i = 0; i < Size; i++)
            {
                int idx = q.Dequeue();
                for (int j = idx + 1; j <= idx + nums[idx]; j++)
                {
                    if (j >= nums.Length - 1) return ret;
                    q.Enqueue(j);
                }
            }
            ret++;
        }
        return ret;
    }
}