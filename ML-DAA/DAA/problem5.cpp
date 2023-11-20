#include <bits/stdc++.h>
using namespace std;

void sumofsubset(vector<int> arr, vector<int> temp, int i, int sum, int target)
{
    if (sum == target)
    {
        cout << "To get target " << target << " elements needed are: ";
        for (auto ele : temp)
        {
            cout << ele << " ";
        }
        cout << endl;
        return;
    }
    if (i >= arr.size())
        return;

    temp.push_back(arr[i]);
    sumofsubset(arr, temp, i + 1, sum + arr[i], target);
    temp.pop_back();
    sumofsubset(arr, temp, i + 1, sum, target);
}

int main()
{
    //     Write a program to find sum of subset using backtracking approach.

    // M = 35 and
    // i) w = {5, 7, 10, 12, 15, 18, 20}
    // ii) w = {20, 18, 15, 12, 10, 7, 5}
    // iii) w = {15, 7, 20, 5, 18, 10, 12}

    int target = 35;
    vector<int> arr1 = {5,
                        7,
                        10,
                        12,
                        15,
                        18,
                        20};
    vector<int> arr2 = {20, 18, 15, 12, 10, 7, 5};
    vector<int> arr3 = {15, 7, 20, 5, 18, 10, 12};

    sumofsubset(arr1, {}, 0, 0, target);
    cout << "\n\n";

    sumofsubset(arr2, {}, 0, 0, target);
    cout << "\n\n";

    sumofsubset(arr3, {}, 0, 0, target);
    cout << "\n\n";
    return 0;
}