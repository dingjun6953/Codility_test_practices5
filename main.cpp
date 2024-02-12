/*
For a given array A of N integers and a sequence S of N integers from the set {−1, 1}, we define val(A, S) as follows:

val(A, S) = |sum{ A[i]*S[i] for i = 0..N−1 }|

(Assume that the sum of zero elements equals zero.)

For a given array A, we are looking for such a sequence S that minimizes val(A,S).

Write a function:

class Solution { public int solution(int[] A); }

that, given an array A of N integers, computes the minimum value of val(A,S) from all possible values of val(A,S) for all possible sequences S of N integers from the set {−1, 1}.

For example, given array:

  A[0] =  1
  A[1] =  5
  A[2] =  2
  A[3] = -2
your function should return 0, since for S = [−1, 1, −1, 1], val(A, S) = 0, which is the minimum possible value.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..20,000];
each element of array A is an integer within the range [−100..100].
Copyright 2009–2024 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <ctime>
#include <climits>

using namespace std;

int solution(vector<int> &A) {
    // Implement your solution here
    auto size = A.size();
    int S_size=pow(2,size);
    srand(time(0));

    int *sum= new int [S_size];
    int **S = new int*[S_size];
    for(int i=0; i<S_size; i++)
    {
        S[i] = new int [size];
    }
    int min=INT_MAX;
    int final_min=INT_MAX;
    for (int k=0; k<5; k++){

    for(int i=0; i<S_size; i++)
    {
        sum[i]=0;
        for(int j=0; j<size;j++)
        {
            if(rand()%10<5)
            {
                S[i][j]=1;
            }
            else
            {
                S[i][j]=-1;
            }
            sum[i] += A[j]*S[i][j];
       }

       if (abs(sum[i])<min) min=abs(sum[i]);
    }
    if(final_min>min) final_min=min;


    }

return final_min;
}




int main()
{
    vector<int> A = {1, 5, 2, -2, 10,7,9,-4,-11,-12,-30,-1,40,19,22,30,-3,-2,-9,18,2};

    int min=solution(A);

    cout<<"min="<<min;

    return 0;
}
