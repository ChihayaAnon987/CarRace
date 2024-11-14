#ifndef ADAPTIVE_THRESHOLD_H
#define ADAPTIVE_THRESHOLD_H

#include "stdio.h"

#define block 5
#define clip_value 6



uint8_t adaptiveThreshold(uint8_t* img_data, int x, int y, int width, int height, int block, uint8_t clip_value);
void mazeLineTracing(uint8_t* img_data, uint8_t* output_data, int width, int height, int block, uint8_t clip_value);




#endif