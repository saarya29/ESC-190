#if !defined(CIMG)
#define CIMG

#include <stdlib.h>
#include <stdint.h>


struct rgb_img{
    uint8_t *raster;
    size_t height;
    size_t width;
};
// A 1D array that stores the pixel data of the image, and 
// pixel has 3 colour components: R, G, B each stored as an 8 bit value. I am assuming they are all different. 


// you need to look at the dimensions of the image and the 
void create_img(struct rgb_img **im, size_t height, size_t width);
void read_in_img(struct rgb_img **im, char *filename);
void write_img(struct rgb_img *im, char *filename);
uint8_t get_pixel(struct rgb_img *im, int y, int x, int col);
void set_pixel(struct rgb_img *im, int y, int x, int r, int g, int b);
void destroy_image(struct rgb_img *im);
void print_grad(struct rgb_img *grad);

// create image, you're mallocing the image that you have, 
// along with its height and width (I think might potentially also be mallocing the pixels because that could be of suse. )

#endif