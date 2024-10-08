#include <iostream>
#include <climits>
using namespace std;

void minmaxi(int arr[], int start, int end, int &mini, int &maxi) {
    if (start == end) { //ekch element asla tr
        mini=arr[start];
        maxi=arr[end];
        return;
    }

    if (start + 1 == end) {   //don element asle tr
        if (arr[start] < arr[end]) {
            mini= arr[start];
            maxi= arr[end];
        } else {
            mini= arr[end];
            maxi= arr[start];
        }
        return;
    }

    int mid = (start + end) / 2;
    int lmin, lmax, rmin, rmax;

    minmaxi(arr, start, mid, lmin, lmax);
    minmaxi(arr, mid + 1, end, rmin, rmax);

    mini= min(lmin, rmin);
    maxi= max(lmax, rmax);
}

int main() {
    int n;
    cout<<"enter no of elements"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"enter elements"<<endl;
        cin>>arr[i];
    }
    int mini= INT_MAX;
    int maxi= INT_MIN;

    minmaxi(arr, 0, n - 1, mini, maxi);

    cout << "minimum= " << mini<< endl;
    cout << "maximum= " << maxi<< endl;

    return 0;
}