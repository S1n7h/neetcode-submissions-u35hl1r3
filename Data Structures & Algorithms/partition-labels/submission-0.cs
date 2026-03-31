public class Solution
{
    public List<int> PartitionLabels(string s)
    {
        List<int> ret = new List<int>();
        string temp = "";

        foreach(char character in s)
        {
            temp += character;

            //check for current character's count
            if (s.Count(x=> x == character) == temp.Count(x=> x == character))  
            {
                //iterate through all the character in temp
                for (int i = 0; i < temp.Length; i++)
                {   
                    //compare current temp idx count 
                    if (s.Count(x => x == temp[i]) != temp.Count(x => x == temp[i]))
                    {
                        break;
                    }

                    else
                    {
                        //all character of temp have equal count to character count in s
                        if (i == temp.Length - 1)
                        {
                            ret.Add(temp.Length);
                            temp = "";
                        }
                        else continue;
                    }
                }
            }
        }
        
        return ret;
    }
}