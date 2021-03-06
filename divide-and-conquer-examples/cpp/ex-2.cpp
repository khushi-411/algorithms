/* Given an array of n elements. Find whether there are three elements in the array such
 * that their sum is equal to given element K or not? in O(n^2) time.
 */


#include <bits/stdc++.h>

using namespace std;

// two pointer approach
int findSum(int arr[], int n, int k)
{
    int low = arr[0];
    int high = arr[n-1];
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum = arr[i];
        while(low <= high)
        {
            if(low + high + sum == k)
                return 1;
            else if(low + high + sum > k)
                high--;
            else
                low++;
        }
    }
    return 0;
}

int main()
{
    int n, k;
    cout << "Enter number of array elements: ";
    cin >> n;
    cout << "Enter element (whose sum to be found): ";
    cin >> k;
    int arr[n];
    cout << "Enter array elements: ";

    for(int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        arr[i] = s;
    }
    sort(arr, arr + n);
    int kk = findSum(arr, n, k);

    if(kk == 1)
        cout << "Positive Result!";
    else
        cout << "Negative Result!";

    return 0;
}

