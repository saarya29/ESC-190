#include <stdio.h>
#include <string.h>
#include "seamcarving.h"
#include "c_img.h"
#include <math.h>
#include <stdlib.h>
#include <limits.h>

void calc_energy(struct rgb_img *im, struct rgb_img **grad){
    int height1 = im->height;
    int width1 = im->width;
    create_img(grad, height1, width1);

    for (int y = 0; y < height1; y++){
        for (int x = 0; x < width1; x++){
            int delta_x_square = 0;
            int delta_y_square = 0;
            for (int col = 0; col < 3; col++){
                int left_x = get_pixel(im, y, (x - 1 + width1)%width1, col); 
                int right_x = get_pixel(im, y, (x + 1) % width1, col); 
                int up_y = get_pixel(im, (y - 1 + height1) % height1, x, col);
                int down_y = get_pixel(im, (y + 1) % height1, x, col);

                int delta_x = right_x - left_x;
                int delta_y = down_y - up_y;
                delta_x_square += delta_x * delta_x;
                delta_y_square += delta_y * delta_y;     
            }
            int energy = ((int)sqrt(delta_x_square + delta_y_square))/10;
            if (energy  > 255){
                energy = 255;
            }
            set_pixel(*grad, y, x,(uint8_t)energy, (uint8_t)energy, (uint8_t)energy);
        }
    }
}

double minimum_pixel(double a, double b, double c)
{
    double min = a;
    if (b < min)
    {
        min = b;
    }
    if (c < min)
    {
        min = c;
    }
    return min;
}

void dynamic_seam(struct rgb_img *grad, double **best_arr)
{
   int height1 = grad->height;
   int width1 = grad->width; 
   *best_arr = (double *)malloc(height1*width1*sizeof(double)); 
   if (*best_arr == NULL) 
   {
        printf("Memory allocation failed!\n");
        exit(1);
   }
   for (int i = 0; i < width1; i++) 
   {
    (*best_arr)[i] = get_pixel(grad, 0, i, 0); 
   }

    for (int j = 1; j< height1; j++)
    {

        for (int k = 0; k<width1; k++)
        {
            double up = (*best_arr)[(j-1)*width1 + k];
            double up_right =up;
            double up_left = up;
            if (k > 0)
            {
                up_left = (*best_arr)[(j - 1)*width1 + (k-1)];
            }
            if (k < width1 - 1)
            {
                up_right = (*best_arr)[(j-1)*width1 + (k + 1)];
            }
            double nxt_pix = minimum_pixel(up, up_left, up_right);
            (*best_arr)[j *width1 + k] = get_pixel(grad, j, k, 0) + nxt_pix;
        }
    }
}

void recover_path(double *best, int height, int width, int **path)
{
    *path = (int *)malloc(height* sizeof(int));
    if (*path == NULL)
    {
        exit(1);
    }
    double abs_min = INFINITY;
    int best_index = 0;
    for(int i= 0; i < width; i++)
    {
        if ((best)[(height - 1)*width + i] < abs_min){
            abs_min= (best)[(height - 1)*width + i];
            best_index = i;  
        }
    }
    (*path)[height - 1] = best_index;
    for (int j = height-1; j > 0; j--)
    {
        int current_index = (*path)[j];
        double up = (best)[(j-1)*width + best_index];
        double up_left = up;
        double up_right = up;
        if (current_index > 0)
        {
            up_left = (best)[(j - 1)*width + (best_index-1)];
        }
        if (current_index < (width - 1))
        {
            up_right = (best)[(j-1)*width + (best_index + 1)]; 
        }

        double nxt_pix = minimum_pixel(up, up_left, up_right); 
        if (nxt_pix == up)
        {
            best_index = current_index;
        }
        else if (nxt_pix == up_right)
        {
            best_index = current_index + 1; 
        }
        else if (nxt_pix == up_left)
        {
            best_index = current_index - 1;
        }
        (*path)[j-1] = best_index;
   } 
}

void remove_seam(struct rgb_img *src, struct rgb_img **dest, int *path)
{
   size_t height = src-> height;
   size_t width = src -> width;

   create_img(dest, height, width-1); //new image veetoed one collumn. 

   for (size_t y = 0; y< height; y++){
    int seam_x = path[y];

    for(size_t x = 0; x < seam_x; x++){
        uint8_t r = get_pixel(src, x, y, 0);
        uint8_t g = get_pixel(src, x, y, 1);
        uint8_t b = get_pixel(src, x, y, 2);
        set_pixel(*dest,y,x,r,g,b);
    }// copys everything before the seam 
    for(size_t x = seam_x +1; x < width; x++)
        {
            uint8_t r = get_pixel(src, x, y, 0);
            uint8_t g = get_pixel(src, x, y, 1);
            uint8_t b = get_pixel(src, x, y, 2);
            set_pixel(*dest,y,x-1,r,g,b);// shift ecerything to left to accomidate the gap now there
        }
    }
}

void print_d(double *best_arr, struct rgb_img *grad){
    for(int i =0;i<grad->height;i++){
        for(int j=0;j<grad->width;j++){
            printf("%f ", best_arr[i*grad->width +j]);
        }
        printf("\n");
    }
}


void print_i(int *best_arr, struct rgb_img *grad)
{
    for (int i = 0; grad->height; i++)
    {
        printf("%d", best_arr[i]);
    }
    printf("\n");
}

// int main()
// {
//     struct rgb_img *im;
//     struct rgb_img *grad;
//     double *best_arr; 
    
    // Load the image from a file (change "input.jpg" to your actual file)
    // read_in_img(&im, "6x5.bin");
    // calc_energy(im, &grad);
    // printf("Energy Gradient\n");
    // print_grad(grad);
    // dynamic_seam(grad, &best_arr);
    // printf("Best Energy Array\n");
    // print_d(best_arr, grad);

    // int height2 = im->height;
    // int width2 = im->width;
    // int *path; 
    // recover_path(best_arr, height2, width2, &path);
    // //might move into an actual function later. 
    // printf("Seam path:\n");
    // print_i(path, grad);
    // free(best_arr);
    // free(path);
    // destroy_image(im);
    // // return 0;
// }
