#include <bits/stdc++.h>
using namespace std;
// namespace std;
int longestConsecutive(vector<int> &nums)
{
  int longLength = 0;
  int counter = 0;
  sort(nums.begin(), nums.end());

  for (auto x : nums)
  {
    if (x == (x + 1) - 1)
    {
      counter++;
    }
    else
    {
      counter = 0;
    }
    if (counter > longLength)
    {
      longLength = counter;
    }
  }
  return longLength;
}

int main()
{
  vector<int> v{1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
  int a = longestConsecutive(v);
  cout << a << " " << endl;
  cout << "Sorted \n";
  for (auto x : v)
    cout << x << " ";
  return 0;
};

// #include <iostream>
// using namespace std;

// int main()
// {

// int myNumbers[5] = {10, 20, 30, 40, 50};
// for (int i = 0; i < 5; i++) {
//   cout << myNumbers[i] << "\n";
// }
//     // try
//     // {
//     //     int age = 15;
//     //     if (age >= 18)
//     //     {
//     //         cout << "Access granted - you are old enough.";
//     //     }
//     //     else
//     //     {
//     //         throw(age);
//     //     }
//     // }
//     // catch (int myNum)
//     // {
//     //     cout << "Access denied - You must be at least 18 years old.\n";
//     //     cout << "Age is: " << myNum;
//     // }
//     return 0;
// }