#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void main()
{
            srand (time(NULL));
			//printf("%d\n",rand()%52);
			//printf("%d\n",rand() / (RAND_MAX / 52 + 1));
			int a[5];
			for(int i=0;i<6;i++)
			{
				a[i]=rand()/(RAND_MAX / 6 + 1);
				for(int j=0;j<i;j++)
				{
					while(a[j]==a[i])
					{
						a[i]=rand()/(RAND_MAX / 6 + 1);
					}
				}
			}
			
}