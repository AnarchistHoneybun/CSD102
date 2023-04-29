/*
Question: The professor of a subject wants to leverage the difference
\in everyone's capability within a classroom. She does so, ensuring no
two students with the same marks in the mid-sem exam sit next to each
other. Assuming all students sit in a single row when given all their
marks, arrange them so that no two students with the same marks are adjacent.
If there exists no possible arrangement, output the same sequence as it is.

Hint: Try thinking of how the heap data structure can solve this question


Input:

Number_of_students followed by marks of each student

3 10 10 20

Output:

The final ordering of students depicted by their marks

10 20 10
*/
//todo take an array as input from user
//todo arrange the array so that no two adjacent elements are same

#include <stdio.h>
#include <stdlib.h>


//node to store values and their frequency

struct node
{
    int value;
    int freq;
};

//functions to build a maxheap

void maxHeapify(struct node arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left].freq > arr[largest].freq)
    {
        largest = left;
    }
    if (right < n && arr[right].freq > arr[largest].freq)
    {
        largest = right;
    }
    if (largest != i)
    {
        struct node temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, n, largest);
    }
}

void buildHeap(struct node arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }
}

//function to arrange the array so that no two adjacent elements are same

void diffSort(struct node arr[], int ogarr[], int n, int len){

    int result[n];
    int index = 0;

    struct node prev;
    prev.value = -1;
    prev.freq = -1;

    buildHeap(arr, n);

    while(n>0){

        maxHeapify(arr, n, 0);
        struct node temp = arr[0];
        arr[0] = arr[n-1];
        n--;
        maxHeapify(arr, n, 0);

        result[index++]=temp.value;
        temp.freq--;

        if(prev.freq > 0){
            arr[n++] = prev;
            maxHeapify(arr, n, 0);
        }

        prev = temp;

        // //print statements to check the working of the function
        // printf("\nIteration %d:\n", index);
        // printf("Original array:\n");
        // for(int i = 0; i < n; i++){
        //     printf("Value: %d Frequency: %d", arr[i].value, arr[i].freq);
        //     printf("\n");
        // }
        // printf("Result array:\n");
        // for(int i = 0; i < index; i++){
        //     printf("%d ", result[i]);
        // }
        // printf("\n");


    }

    //printf("index = %d\n", index);
    
    //match length of result array with the length of the original array

    if(index!=len){
        //result[index++] = prev.value;
        //printf("error\n");
        for(int i = 0; i < len; i++){
            printf("%d ", ogarr[i]);
        }
        return;
    }

    //printf("Result array:\n");
    for(int i = 0; i < index; i++){
        printf("%d ", result[i]);
    }


}


int main(){

    int n;
    //printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    //printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    //creating an array of nodes to store the values and their frequencies

    struct node nodes[n];
    int index = 0;
    for(int i = 0; i < n; i++){
        int flag = 0;
        for(int j = 0; j < index; j++){
            if(arr[i] == nodes[j].value){
                nodes[j].freq++;
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            nodes[index].value = arr[i];
            nodes[index].freq = 1;
            index++;
        }
    }

    //printing the array of nodes

    // for(int i = 0; i < index; i++){
    //     printf("Value: %d Frequency: %d", nodes[i].value, nodes[i].freq);
    //     printf("\n");
    // }

    //calling the function to arrange the array so that no two adjacent elements are same

    diffSort(nodes, arr, index, n);

    return 0;
}
