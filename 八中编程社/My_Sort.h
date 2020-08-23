void Quick_Sort(int a[],int left,int right)
{
	if(left<right)
	{
		int mid=(left+right)/2;
		swap(a[mid],a[right]);
		int i=left,j=right-1;
		while(i<=j)
		{
			while(a[i]<a[right])
			{
				i++;
			}
			while(a[j]>a[right])
			{
				j--;
			}
			if(i<=j)
			{
				swap(a[i],a[j]);
				i++,j--;
			}
		}
		swap(a[i],a[right]);
		Quick_Sort(a,left,i-1);
		Quick_Sort(a,i+1,right);
	}
}

