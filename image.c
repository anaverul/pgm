#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
    int rows, cols;
    char magic[3];
    int max_gray;
    FILE* pgm_image_pointer;
    FILE* negative_image_pointer;
    FILE* rotated_image_pointer;
    pgm_image_pointer = fopen(argv[1], "r");
    negative_image_pointer = fopen(argv[2], "w");
    rotated_image_pointer = fopen(argv[3], "w");
    if (pgm_image_pointer == NULL)
    {
        printf("Could not locate the image\n");
        exit(1);
    }
    fscanf(pgm_image_pointer, "%s%d%d%d", magic, &cols, &rows, &max_gray);
    int arr[rows][cols];   //create empty 2D array
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            fscanf(pgm_image_pointer, "%d", &arr[r][c]);  //populare 2D array
        }
    }
    fclose(pgm_image_pointer);
    fprintf(rotated_image_pointer, "%s\n", magic);  //write inside the rotated_image_pointer file?
    fprintf(rotated_image_pointer, "%d %d\n%d\n", rows, cols, max_gray); //too many arguments. Can I add all these ints in one line?
    //int arr_r[cols][rows]
    for (int r = 0; r < cols; r++)
    {
        for (int c = 0; c < rows; c++)
        {
            fprintf(rotated_image_pointer, "%d ", arr[rows - c - 1][r]);
        }

    }
    fclose(rotated_image_pointer);
    fprintf(negative_image_pointer, "%s\n", magic);  //write inside the rotated_image_pointer file?
    fprintf(negative_image_pointer, "%d %d\n%d\n", cols, rows, max_gray);
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            fprintf(negative_image_pointer, "%d ", 255 - arr[r][c]);
        }

    }
    fclose(negative_image_pointer);
    return 0;
}
