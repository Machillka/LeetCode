#include <queue>
#include <vector>

using std::vector;

class Solution
{
  public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for (const auto& pre : prerequisites)
        {
            const int course = pre[0];
            const int preCourse = pre[1];

            // precourse -> course
            graph[preCourse].push_back(course);
            indegree[course]++;
        }

        std::queue<int> availableCourses;

        for (int course = 0; course < numCourses; course++)
        {
            if (indegree[course] == 0)
                availableCourses.push(course);
        }

        int complete = 0;

        while (!availableCourses.empty())
        {
            const int currentCourse = availableCourses.front();
            availableCourses.pop();

            complete++;

            for (const int nextCourse : graph[currentCourse])
            {
                indegree[nextCourse]--;

                if (indegree[nextCourse] == 0)
                {
                    availableCourses.push(nextCourse);
                }
            }
        }

        return complete == numCourses;
    }
};