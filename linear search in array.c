#include<stdio.h>

main()
{
    int a[10],n,i,s,found=0;
    int mid=n/2;

    printf("enter the number of elements\n");
    scanf("%d",&n);

    printf("enter the elements\n");

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("the elements are\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

    printf("\nsearch element:\n");
    scanf("%d",&s);

    for(i=0;i<n;i++)
    {
        if(a[i]==s)
            found=1;

    }

    if(found==1)
        printf("element %d found",s);
    else
        printf("element not found");
}
