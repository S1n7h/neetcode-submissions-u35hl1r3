public class Solution
{
    public bool IsNStraightHand(int[] hand, int groupSize)
    {
        if (hand.Length % groupSize != 0) return false;
        SortedDictionary<int, int> hash = new SortedDictionary<int, int>();

        int min = hand.Min();

        foreach(int num in hand)
        {
            if (hash.ContainsKey(num) == false)
            {
                hash.Add(num , 1);
            }
            else hash[num]++;
        }

        for (int times = 0; times < hand.Length / groupSize; times++)
        {
            foreach (var item in hash)
            {
                Console.WriteLine($"Key: {item.Key}  Value: {item.Value}");
            }

            Console.WriteLine();
            KeyValuePair<int, int> FirstPair = hash.First();
            for (int idx = FirstPair.Key; idx < FirstPair.Key + groupSize; idx++)
            {
                
                if (--hash[idx] == 0) hash.Remove(idx);
                if (idx + 1 <  FirstPair.Key + groupSize &&
                    hash.ContainsKey(idx + 1) == false) return false;
            }
        }return true;
    }
}