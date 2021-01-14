 
     // C Program to Merge two sorted array into third array
     
 
    #include <stdio.h>
    void main()
    {
 
        int array1[50], array2[50], array3[100], m, n, i, j, k = 0;  //array declaration
        printf("\n Enter size of  Array 1: ");
        scanf("%d", &m);
 
        printf("\n Enter sorted elements of array 1: \n");  //print first array
        for (i = 0; i < m; i++) 
        {
            scanf("%d", &array1[i]);
        }
 
        printf("\n Enter size of array 2: ");    //print 2nd array
        scanf("%d", &n);
 
        printf("\n Enter sorted elements of array 2: \n");
        for (i = 0; i < n; i++) 
        {
            scanf("%d", &array2[i]);
        }
 
        i = 0;
        j = 0;
 
       //fuction two merge two arrays


        while (i < m && j < n) 
        {
            if (array1[i] < array2[j])    // comparing values of array1 and array2
            {
                array3[k] = array1[i];    //store an item from array1 and array2
                i++;
            }
 
            else 
            {
                array3[k] = array2[j];
                j++;
            }
            k++;
        }
 
       
            while (j < n)     //copying if any element left in array1
            {
                array3[k] = array2[j];
                j++;
                k++;
            }
       
 
            while (i < m)   //copying if any element left in array2
            {
                array3[k] = array1[i];
                i++;
                k++;
            }
        
 
        printf("\n After merging: \n");
        for (i = 0; i < m + n; i++) 
        {
            printf("\n%d", array3[i]);
        }
 
    }