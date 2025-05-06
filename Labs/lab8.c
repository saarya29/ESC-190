#include "c_img.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
// Q: I saw somewhere that you use size_t and it's more better than using int in thics
// case... is this correct statement... 

// we have a mechanism that opens the files so we're good. 

void change_pixel(struct rgb_img *im, int delta) // you're going to need the image that's in your 
//malloc as *im and you need to have the amount you're going to change it by
{
    int height1 = im->height;
    int width1 = im->width;

    //you're going to go int your malloc and to each of the values and increase them by delta. 
    for (int i = 0; i < height1; i ++)
    {
        for (int j = 0; j < width1; j ++)
        {
            for (int col = 0; col < 3; col ++) // each pixel has an R, G, B and I think you'd want to change all 3 of them, although you can also change only one of them if you wanted. 
            { // getpixel is a function in C. 
                int new_val = get_pixel(im, i, j, col) * delta; // the value you haev plus the amount that you want it to be. 
                if (new_val > 255)
                {
                    new_val = 255; // the value is not going to change. Or theree might be an error of some sort I think?
                }
                if (new_val < 0)
                {
                    new_val = 0;
                }
                im->raster[3* (i * width1 + j) + col] = (uint8_t)new_val;
            }
        }
    }
}
/*
//changing such that only the red pixels change. 
void change_pixel1(struct rgb_img *im, int change) // you're going to need the image that's in your 
//malloc as *im and you need to have the amount you're going to change it by
{
    int height1 = im->height;
    int width1 = im->width;
    //you're going to go int your malloc and to each of the values and increase them by delta. 
    for (int i = 0; i < height1; i ++)
    {
        for (int j = 0; j < width1; j ++)
        { // each pixel has an R, G, B and I think you'd want to change all 3 of them, although you can also change only one of them if you wanted. 
            {
                int new_val = get_pixel(im, i, j, 0) + delta; // the value you haev plus the amount that you want it to be. 
                if (new_val > 255 || new_val < 0)
                {
                    new_val = new_val; // the value is not going to change. Or theree might be an error of some sort I think?
                }
                im->raster[3* (i * width1 + j) + col] = (uint8_t)new_val;
            }
        }
    }
}

void change_pixel2(struct rgb_img *im, int change) // you're going to need the image that's in your 
//malloc as *im and you need to have the amount you're going to change it by
{
    int height1 = im->height;
    int width1 = im->width;
    //you're going to go int your malloc and to each of the values and increase them by delta. 
    for (int i = 0; i < height1; i ++)
    {
        for (int j = 0; j < width1; j ++)
        { // each pixel has an R, G, B and I think you'd want to change all 3 of them, although you can also change only one of them if you wanted. 
            {
                int new_val = get_pixel(im, i, j, 1) + delta; // the value you haev plus the amount that you want it to be. 
                if (new_val > 255 || new_val < 0)
                {
                    new_val = new_val; // the value is not going to change. Or theree might be an error of some sort I think?
                }
                im->raster[3* (i * width1 + j) + col] = (uint8_t)new_val;
            }
        }
    }
}

void change_pixel3(struct rgb_img *im, int change) // you're going to need the image that's in your 
//malloc as *im and you need to have the amount you're going to change it by
{
    int height1 = im->height;
    int width1 = im->width;
    //you're going to go int your malloc and to each of the values and increase them by delta. 
    for (int i = 0; i < height1; i ++)
    {
        for (int j = 0; j < width1; j ++)
        { // each pixel has an R, G, B and I think you'd want to change all 3 of them, although you can also change only one of them if you wanted. 
            {
                int new_val = get_pixel(im, i, j, 2) + delta; // the value you haev plus the amount that you want it to be. 
                if (new_val > 255 || new_val < 0)
                {
                    new_val = new_val; // the value is not going to change. Or theree might be an error of some sort I think?
                }
                im->raster[3* (i * width1 + j) + col] = (uint8_t)new_val;
            }
        }
    }
}*/
void change_one_col(struct rgb_img *im, int delta, int channel)
{
    int height1 = im->height;
    int width1 = im->width;

    for (int i = 0; i < height1; i ++)
    {
        for (int j = 0; j < width1; j ++)
        {
            int pixel_val = im->raster[3*(i *width1 + j) + channel];
            int new_val = pixel_val + delta;

            if (new_val > 255)
            {
                new_val = 255;
            } 
            if (new_val < 0)
            {
                new_val = 0;
            }
            im->raster[3*(i*width1 + j) + channel] = (uint8_t)new_val;
        }
    }
}
/*
void change_two(struct rgb_img *im, int change) // you're going to need the image that's in your 
//malloc as *im and you need to have the amount you're going to change it by
{
    int height1 = im->height;
    int width1 = im->width;

    //you're going to go int your malloc and to each of the values and increase them by delta. 
    for (int i = 0; i < height1; i ++)
    {
        for (int j = 0; j < width1; j ++)
        {
            for (int col = 0; col < 2; col ++) // each pixel has an R, G, B and I think you'd want to change all 3 of them, although you can also change only one of them if you wanted. 
            {
                int new_val = get_pixel(im, i, j, col) + delta; // the value you haev plus the amount that you want it to be. 
                if (new_val > 255 || new_val < 0)
                {
                    new_val = new_val; // the value is not going to change. Or theree might be an error of some sort I think?
                }
                im->raster[3* (i * width1 + j) + col] = (uint8_t)new_val;
            }
        }
    }
}*/

void print_image(struct rgb_img *im) 
{
    int height1 = im->height;
    int width1 = im->width;

    for (int i = 0; i < height1; i++)
    {
        for (int j = 0; j < width1; j++)
        {
            printf("(%d, %d, %d) ", 
                get_pixel(im, i, j, 0),  // Red
                get_pixel(im, i, j, 1),  // Green
                get_pixel(im, i, j, 2)   // Blue
            );
        }
        printf("\n");
    }
}

int main()
{
    struct rgb_img *im;
    
    // Load the image from a file (change "input.jpg" to your actual file)
    read_in_img(&im, "image.bin");

    int delta = 2;
    change_pixel(im, delta); // Modify image

    // Print modified pixel values (optional)

    // Save the modified image to a new file
    write_img(im, "image1.bin");

    // Free allocated memory
    destroy_image(im);

    return 0;
}
