// public class Solution
// {
//     static public int NumberOfSteps(int num)
//     {
//         int step = 0;
//         while (num != 0)
//         {
//             step += 1;
//             if (num % 2 == 1)
//             {
//                 num -= 1;
//             }
//             else
//             {
//                 num >>= 1;
//             }
//         }

//         return step;
//     }

//     static public void Main()
//     {
//         Console.WriteLine(NumberOfSteps(8));
//     }
// }