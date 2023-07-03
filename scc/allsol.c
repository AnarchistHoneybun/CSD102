1:
    int i, j, temp;
    for(i=0;i<d;i++)
    {
        temp = arr[0];
        for(j=0;j<arr_count-1;j++)
        {
            arr[j] = arr[j+1];
        }
        arr[arr_count-1] = temp;
    }
    *result_count = arr_count;
    return arr;

2:
    SinglyLinkedListNode *temp = malloc(sizeof(SinglyLinkedListNode));
    temp->data = data;
    temp->next = NULL;
    if(position == 0)
    {
        temp->next = llist;
        llist = temp;
        return llist;
    }
    SinglyLinkedListNode *temp1 = llist;
    for(int i=0;i<position-1;i++)
    {
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
    return llist;

3:
    SinglyLinkedListNode *temp = llist;
    int count = 0;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    temp = llist;
    for(int i=0;i<count-positionFromTail-1;i++)
    {
        temp = temp->next;
    }
    return temp->data;

4:
    int i, pos = 0, neg = 0, zero = 0;
    for(i=0;i<arr_count;i++)
    {
        if(arr[i] > 0)
        {
            pos++;
        }
        else if(arr[i] < 0)
        {
            neg++;
        }
        else
        {
            zero++;
        }
    }
    
    //6 decimal places in the ratio
    printf("%f\n", (float)pos/arr_count);
    printf("%f\n", (float)neg/arr_count);
    printf("%f\n", (float)zero/arr_count);

5:
    int i, j, sum1 = 0, sum2 = 0;
    for(i=0;i<arr_rows;i++)
    {
        for(j=0;j<arr_columns;j++)
        {
            if(i == j)
            {
                sum1 += arr[i][j];
            }
            if(i+j == arr_rows-1)
            {
                sum2 += arr[i][j];
            }
        }
    }
    return abs(sum1-sum2);