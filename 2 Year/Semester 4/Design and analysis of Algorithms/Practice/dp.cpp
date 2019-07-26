#include<iostream>

using namespace std;

bool checkSubsetSum(int arr[], int n, int sum){
	
	bool dp[n+1][sum+1];

	// for the case when sum equals to 0
	for(int i = 0; i <= n; i++)
		dp[i][0] = true;
		
	//for the case when no element is selected
	for(int i = 1 ; i <= sum ; i++)
		dp[0][i] = false;
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1 ; j <= sum; j++){
			if(j < arr[i-1])
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = dp[i-1][j]||dp[i-1][j- arr[i-1]];
		
		
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

bool sumExistsInSubset(int a[], int n, int sum){
	printf("sum: %d, n: %d\n", sum , n);
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
int main(){
	int n, sum;
	
	cout<<"Enter the size of array: ";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements of array: \n";
	for(int i = 0 ; i < n ; i++)
		cin>>arr[i];
	cout<<"Enter the sum to check in array: ";
	cin>>sum;
	if(checkSubsetSum(arr, n, sum))
		cout<<"There exists a subset with the sum equal to given sum: "<<sum;
	else
		cout<<"There does not exist a subset with the sum equal to given sum: "<<sum;
	
	return 0;
}
