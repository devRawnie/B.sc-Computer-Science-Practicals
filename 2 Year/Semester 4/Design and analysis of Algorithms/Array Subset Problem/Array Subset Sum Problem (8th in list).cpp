#include<iostream>
using namespace std;
bool sumExistsInSubSet(int a[], int n, int sum){
	
	bool dp[n+1][sum+1];
	for(int i = 0 ; i <= n; i++)
		dp[i][0] = true;
	for(int i = 1; i <=sum ; i++)
		dp[0][i] = false;
		
	for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
//            if(dp[i-1][j]==true)
//                dp[i][j]=true;
// 
//             else
//            {
                if(j<a[i-1])
                    dp[i][j]=dp[i-1][j]; 
                else
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-a[i-1]];
//            }
        }
    }
    for(int i = 0; i <= n; i++)
	{
		for(int j = 0 ; j <= sum; j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
    
    return dp[n][sum];
}
int main()
{
	int n, sum;
	cout<<"\nEnter the number of elements: ";
	cin>>n;
	int arr[n];
	cout<<"\nEnter the elements of the array: \n";
	for(int i = 0 ; i < n; i++)
		cin>>arr[i];
	
	cout<<"\n Enter the sum to find in subset: ";
	cin>>sum;
	if(sumExistsInSubSet(arr, n, sum))
		cout<< "Found a subset with given sum: "<<sum;
	else
		cout<< "Could not find any subset with sum equal to "<<sum;
	
	return 0;
}
