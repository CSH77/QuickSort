#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& vec, int left, int right)
{
    int pivot = vec[left];
    int low = left + 1;
    int high = right;

    while(low <= high)
    {
        //find number that bigger than pivot
        while(pivot > vec[low] && low <= right)
            low++;

        //find number that smaller than pivot
        while(pivot < vec[high] && high > left)
            high--;

        //if low and high is not cross over, swap both of them.
        if(low <= high)
            swap(vec[low], vec[high]);
    }

    //swap pivot and high,
    swap(vec[left], vec[high]);
    return high;
}

void quickSort(vector<int>& vec, int left, int right)
{
    if(left <= right)
    {
        int pivot = partition(vec, left, right);
        quickSort(vec, left, pivot - 1);
        quickSort(vec, pivot + 1, right);
    }
}


int main()
{
    vector<int> vec = {5,9,6,7,3,2,8,1,4};

    quickSort(vec, 0, vec.size() - 1);

    for(auto iter = vec.begin(); iter != vec.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
    return 0;
}



