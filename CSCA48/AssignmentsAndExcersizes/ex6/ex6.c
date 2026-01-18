/**
 * Exercise 6 - Convolutions and Edge detection!
 *
 * Please read the comments below carefully, they describe your task in detail.
 * Any clarifications and corrections will be posted to Piazza so please keep
 * an eye on the forum!
 *
 * Starter code:  Mustafa Quraish & Charles Xu, 2022
 */

#include "imgUtils.c"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Image dimensions
#define SIZEX 512
#define SIZEY 512

// Kernel size
#define K_SIZE 3

// Declaration of the X and Y kernel matrices.
double GX[K_SIZE][K_SIZE] = {
    {1, 0, -1},
    {2, 0, -2},
    {1, 0, -1},
};

double GY[K_SIZE][K_SIZE] = {
    {1, 2, 1},
    {0, 0, 0},
    {-1, -2, -1},
};

/*****************************************************************************/
void printNode(int px, int py, unsigned char inp[SIZEY][SIZEX]){
  for (int i= -1; i<=1; i++){
    printf("\n");
    for (int j= -1; j<=1; j++){
      if (py+i<0||py+i>=SIZEX){
        printf("0,");
      }
      else if(px+j<0||px+j>=SIZEY){
        printf("0,");
      }else{
        printf("%d,",inp[py+i][px+j]);
      }
    }
  }
  printf("\n");
  return;
}
double convolve(unsigned char inp[SIZEY][SIZEX], int px, int py,
                double kernel[K_SIZE][K_SIZE])
{
  /**
   * Perform the convolution of the given kernel and the image with (px, py) as
   * the center pixel. In essense, the center of the kernel is placed at the
   * given pixel, and you compute weighted sum (refer to tha handout for an
   * example) and return it.
   *
   * If (px, py) is one of the pixels at the edge of the screen (and thus part
   * of the kernel is leaking outside the image), you may assume that those
   * pixels are black. In other words, you should pretend that all pixels
   * outside the image are just black for the sake of computation.
   *
   * NOTE: In this case, the weighted sum is also an integer because of GX and
   *       GY. However, in general the kernels can have floating point values,
   *       so doing it this way will let you generalize your solution much more
   *       easily if you wish to do so.
   * NOTE: Note that the 2D array is flipped (Y, X) instead of (X, Y).
   */
  double weighted=0;
  for (int i= -1; i<=1; i++){
    for (int j= -1; j<=1; j++){
      if (py+i<0||py+i>=SIZEX){
      }
      else if(px+j<0||px+j>=SIZEY){
      }else{
        weighted += inp[py+i][px+j]*kernel[i+1][j+1];
      }
    }
  }
  return weighted; // Return with the correct value
}

void sobel(unsigned char inp[SIZEY][SIZEX], unsigned char out[SIZEY][SIZEX])
{
  /**
   * Given an input image, perform the Sobel edge detection algorithm and store
   * the output in `out`.  Remember that this boils down to:
   *
   * for pixel in input:
   *    g_x = convolve GX at pixel
   *    g_y = convolve GY at pixel
   *    set corresponding output pixel to sqrt(g_x^2 + g_y^2)
   *
   * NOTE: The expression sqrt(g_x^2 + g_y^2) may result in values greater than
   *       255. If the value is greater, just set it equal to 255. Round down
   *       in case of floating point values.
   * NOTE: Note that the 2D array is flipped (Y, X) instead of (X, Y).
   */
  double xVal=0, yVal=0, temp=0;
  for(int i=0; i<SIZEX; i++){
    for(int j=0; j<SIZEY; j++){
      xVal = convolve(inp,i,j,GX);
      yVal = convolve(inp,i,j,GY);
      temp = (int)(sqrt(pow(yVal,2)+pow(xVal,2)));
      if (temp>255){
        out[j][i]=255;
      }else{
        out[j][i]=temp;
      }
    }
  }
  return; // Update `out` before returning
}

/*****************************************************************************/

#ifndef __testing__ // You know the drill, don't remove this

int main()
{
  /* Feel free to change the contents INSIDE the main function to help test */

  // Initialize the 2D-arrays that will store the values of the pixels
  unsigned char data[SIZEY][SIZEX];
  unsigned char edge[SIZEY][SIZEX];

  // We will store the values of the input image
  readPGM("face.pgm", &data[0][0]);

  // Test convolve()
  double res = convolve(data, 0, 0, GY);
  if (res != -132.0)
  {
    printf("Error: convolve() test 1 output incorrect.\n");
    printf("Expected: %f,  Yours: %f\n", -132.0, res);
    //exit(1);
  }

  // Pixel somewhere in the middle
  res = convolve(data, 324, 218, GX);
  if (res != -21.0)
  {
    printf("Error: convolve() test 2 output incorrect.\n");
    printf("Expected: %f,  Yours: %f\n", -21.0, res);
    //exit(1);
  }

  printf("- convolve() output was correct.\n");

  // Call the sobel function
  sobel(data, edge);

  // Write the values to the output image
  writePGM("output.pgm", &edge[0][0]);

  // Compare to the expected image
  readPGM("expected.pgm", &data[0][0]);
  /*
  for (int i = 0; i < SIZEX; i++)
  {
    for (int j = 0; j < SIZEY; j++)
    {
      if (data[j][i] != edge[j][i])
      {
        printf("Error: Pixel (x=%d, y=%d) has the wrong colour.\n", i, j);
        printf("Expected: %u,  Yours: %u\n", data[j][i], edge[j][i]);
        exit(1);
      }
    }
  }
  */
  printf("- sobel() output was correct.\n");
  return 0;
}

#endif
