#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Task
{
    int id;
    int arrivalTime;
    int burstTime;
};

bool compareBurstTimes(const Task &a, const Task &b)
{
    return a.burstTime < b.burstTime;
}

void SJF(const vector<Task> &tasks)
{
    vector<Task> sortedTasks = tasks;
    sort(sortedTasks.begin(), sortedTasks.end(), compareBurstTimes);

    int currentTime = 0;
    cout << "Scheduled tasks using Shortest Job First (SJF):" << endl;
    for (const auto &task : sortedTasks)
    {
        cout << "Task " << task.id << " scheduled at time " << currentTime << endl;
        currentTime += task.burstTime;
    }
}

void FCFS(const vector<Task> &tasks)
{
    int currentTime = 0;
    cout << "Scheduled tasks using First Come, First Served (FCFS):" << endl;
    for (const auto &task : tasks)
    {
        if (task.arrivalTime > currentTime)
        {
            currentTime = task.arrivalTime;
        }
        cout << "Task " << task.id << " scheduled at time " << currentTime << endl;
        currentTime += task.burstTime;
    }
}

int main()
{
    vector<Task> tasks = {
        {1, 0, 4},
        {2, 1, 3},
        {3, 2, 5},
        {4, 3, 6}};

    FCFS(tasks);

    return 0;
}
