#ifndef ADAPTIVE_THRESHOLD_H
#define ADAPTIVE_THRESHOLD_H

#include "main.h"
#include "stdio.h"


#define block 5
#define clip_value 6



uint8_t adaptiveThreshold(uint8_t* img_data, int x, int y, int width, int height);
void mazeLineTracing(uint8_t* img_data, uint8_t* output_data, int width, int height);




#endif