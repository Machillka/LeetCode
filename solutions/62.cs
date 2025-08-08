namespace Problem62;

class Solution
{
    int [,] roadCounts = new int[105, 105];

    public int FindPathDFS(int x, int y, int endPosX, int endPosY)
    {
        if (x > endPosX || y > endPosY)
            return 0;

        if (roadCounts[x, y] != 0)
            return roadCounts[x, y];

        int currentCounts = FindPathDFS(x + 1, y, endPosX, endPosY) + FindPathDFS(x, y + 1, endPosX, endPosY);

        roadCounts[x, y] = currentCounts;

        return roadCounts[x, y];
    }

    public int UniquePaths(int m, int n)
    {
        // 终点标记 1
        roadCounts[m, n] = 1;

        // 起点作为 1, 1 下标从 1 开始
        FindPathDFS(1, 1, m, n);

        Console.WriteLine(roadCounts);

        return roadCounts[1, 1];
    }
}