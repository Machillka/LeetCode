namespace Problem20;

public class Solution
{
    public bool IsValid(string s)
    {
        if (s == null)
            return false;
        Stack<char> checkStack = new Stack<char>();
        char tempTop;

        foreach (char c in s)
        {
            if (c == '{' || c == '[' || c == '(')
                checkStack.Push(c);
            else
            {
                if (checkStack.Count <= 0)
                    return false;

                if (c == '}')
                {
                    if (checkStack.TryPeek(out tempTop) && tempTop != '{')
                        return false;
                }

                if (c == ')')
                {
                    if (checkStack.TryPeek(out tempTop) && tempTop != '(')
                        return false;
                }

                if (c == ']')
                {
                    if (checkStack.TryPeek(out tempTop) && tempTop != '[')
                        return false;
                }

                checkStack.Pop();
            }
        }

        return checkStack.Count == 0;
    }
}
