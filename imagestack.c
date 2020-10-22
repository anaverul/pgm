#include<stdio.h>
#include<stdlib.h>
int ind(int r, int c, int i, int n_cols, int n_mat)
{
    return r * n_cols * n_mat + c * n_mat + i;
}
int main(int argc, char** argv[])
{
    char magic[2];
    int max_gray;
    int n_mat = argc - 2;
    int n_cols;
    int n_rows;
    FILE* file1 = fopen(argv[1], "r");
    fscanf(file1, "%s%d%d%d", magic, n_cols, n_rows, max_gray)
        //FILE* output_image_pointer = fopen(argv[argc - 2], "w");
        FILE* image_pointer[argc - 1];
    for (int i = 0; i < argc - 1; i++)
    {
        image_pointer[i] = fopen(argv[i], "r");
    }
    int* arr = (int*)malloc(n_rows * n_cols * n_mat * sizeof(int));
    if (arr == NULL)
    {
        printf("out of memory\n")
            exit(0);
    }
    for (int i = 0; i < n_mat; i++)
    {
        for (int r = 0; r < n_rows; r++)
        {
            for (int c = 0; c < n_cols; c++)
            {
                fscanf(image_pointer[i], "%d", &arr[ind(r, c, i, n_cols, n_mat)]);
            }
        }
        fclose(image_pointer[i])
    }
}
float median(int arr[])
{
    int length = sizeof(arr)
        float median = 0;
    if (length % 2 == 0)
        median = (array[(length - 1) / 2] + array[length / 2]) / 2.0;
    else
        median = array[length / 2];

    return median;
}
void sort(int arr[], int left, int right)
{
    int middle;
    if (left < right)
    {
        middle = (left + right) / 2;
        sort(arr, left, middle);
        sort(arr, middle + 1, right);
        merge(arr, left, middle, middle + 1, right)
    }
}
void merge(arr[], int left1, int right1, int left2, int right2)
{
    int temporary_arr[60];
    int ls = left1;
    int rs = left2;
    int c = 0;
    while (ls <= right1 && rs <= right2)
    {
        if (arr[ls] < arr[rs]
            temporary_arr[c++] = arr[ls++];
        else
            temporary_arr[c++] = arr[rs++];
    }
    while (ls <= right1)
    {
        temporary_arr[c++] = arr[ls++];
    }
    while (rs <= right2)
    {
        temporary_arr[c++] = arr[rs++];
    }
    for (ls, rs = 0; rs < right2; ls++, rs++)
    {
        arr[ls] = temporary_arr[rs];
    }


//fscanf(image_pointer[0], "%d", &arr[ind(r, c, i, n_cols, n_mat );
//fscanf(image_pointer[0], "%d%d", &n_rows, &n_cols);

