#include <stdio.h>
#include "seamcarving.h"
#include "c_img.h"
#include <math.h>
#include <stdlib.h>

int main() {
    struct rgb_img *im;
    struct rgb_img *cur_im;
    struct rgb_img *grad;
    double *best;
    int *path;

    read_in_img(&im, "HJoceanSmall.bin");

    for(int i = 0; i < 5; i++){
        printf("i = %d\n", i);
        calc_energy(im,  &grad);
        printf("here1");
        dynamic_seam(grad, &best);
        printf("here2");
        recover_path(best, grad->height, grad->width, &path);
        printf("here3");
        remove_seam(im, &cur_im, path);
        printf("here4");

        char filename[200];
        sprintf(filename, "img%d.bin", i);
        write_img(cur_im, filename);


        destroy_image(im);
        destroy_image(grad);
        free(best);
        free(path);
        im = cur_im;
    }
    destroy_image(im);
}
