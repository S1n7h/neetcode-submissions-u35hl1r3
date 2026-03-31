public class Solution
{
    public bool MergeTriplets(int[][] triplets, int[] target)
    {
        int[] res = { 0, 0, 0 };
        foreach (int[] triplet in triplets)
        {
            if (Math.Max(res[0], triplet[0]) <= target[0] && Math.Max(res[1], triplet[1]) <= target[1] && Math.Max(res[2], triplet[2]) <= target[2])
            {
                res[0] = Math.Max(res[0], triplet[0]);
                res[1] = Math.Max(res[1], triplet[1]);
                res[2] = Math.Max(res[2], triplet[2]);
                for (int i = 0; i < res.Length; i++)
                {
                    Console.Write($"{res[i]}");
                }
                Console.WriteLine();
            }
        }
        for (int i = 0; i < res.Length; i++)
        {
            if (res[i] != target[i]) return false;
        }
        return true;
    }
}