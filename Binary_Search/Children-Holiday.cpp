#include <bits/stdc++.h>
using namespace std;

struct Assistant
{
    int blowTime;  // Time taken to blow one balloon
    int batchSize; // Total balloons blown before rest
    int restTime;  // Rest time
};

// Function to calculate the number of balloons an assistant can blow in a given time
int balloonsBlown(const Assistant &assistant, int time)
{
    int cycleTime = assistant.blowTime * assistant.batchSize + assistant.restTime;
    int fullCycles = time / cycleTime;
    int remainingTime = time % cycleTime;

    int balloons = fullCycles * assistant.batchSize;
    if (remainingTime >= assistant.blowTime * assistant.batchSize)
    {
        balloons += assistant.batchSize;
    }
    else
    {
        balloons += remainingTime / assistant.blowTime;
    }

    return balloons;
}

// Function to check if all balloons can be blown in the given time
bool canBlowAllBalloons(int m, const vector<Assistant> &assistants, int time)
{
    int totalBalloons = 0;
    for (const auto &assistant : assistants)
    {
        totalBalloons += balloonsBlown(assistant, time);
        if (totalBalloons >= m)
        {
            return true;
        }
    }
    return totalBalloons >= m;
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<Assistant> assistants(n);
    for (auto &assistant : assistants)
    {
        cin >> assistant.blowTime >> assistant.batchSize >> assistant.restTime;
    }

    // Binary search to find the minimum time required
    int left = 0;
    int right = 1e9;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (canBlowAllBalloons(m, assistants, mid))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    // Output the minimum time required
    int minTime = left;
    cout << minTime << endl;

    // Calculate and output the number of balloons each assistant blows in the minimum time
    for (size_t i = 0; i < assistants.size(); ++i)
    {
        if (i > 0)
            cout << " ";
        int blown = balloonsBlown(assistants[i], minTime);
        int balloonsByThisAssistant = min(m, blown);
        cout << balloonsByThisAssistant;
        m -= balloonsByThisAssistant;
    }
    cout << endl;

    return 0;
}
