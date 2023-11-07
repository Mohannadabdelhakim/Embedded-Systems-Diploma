int main()
{
    int r=0,c=0,i=0,j=0;
    printf("please enter the rows and columns of your matrix \n");
    scanf("%d %d",&r,&c);
    int a[r][c],t[c][r];

    //for transposing the matrix values

    for(i=0;i<r;i++)
	{
        for(j=0;j<c;j++)
        {
        printf("enter the matrix values of %d %d : ",i+1,j+1);
        scanf(" %d",&a[i][j]);
        }
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			t[j][i]=a[i][j];
		}
	}

	//for printing the array matrix
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d \t",a[i][j]);
		}
		printf(" \n");
	}

	//for printing the transposed matrix
	for(i=0;i<c;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("%d \t",t[i][j]);
		}
		printf(" \n");
	}

}
