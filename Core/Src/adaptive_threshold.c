#include "main.h"
#include "adaptive_threshold.h"


// 自适应阈值法，这里是对img_data[x][y]进行二值化
uint8_t adaptiveThreshold(uint8_t* img_data, int x, int y, int width, int height) {

  // block必须为奇数

  // 取中间像素点
  int half_block = block / 2;
  // 计算局部阈值
  int thres = 0;
  for(int dy = -half_block; dy <= half_block; dy++)
  {
    for(int dx = -half_block; dx <= half_block; dx++)
    {
      thres += img_data[(x + dx) + (y + dy) * width];
    }
  }
  thres = thres / (block * block) - clip_value;
  // 进行二值化，x+y*width也就是img_data[x][y]的索引
  return (img_data[x + y * width] > thres ? 255 : 0);


}


// 在迷宫法的巡线过程中使用自适应二值化
void mazeLineTracing(uint8_t* img_data, uint8_t* output_data, int width, int height) {

    // 初始化起始点，这里假设从图片的最下方中间开始
    int start_x = width / 2;  // 图像的水平中心
    int start_y = height - 1;  // 图像的最下方

    // 巡线的方向：右手法则，初始方向为右
    int direction = 0;  // 0表示上，1表示右，2表示下，3表示左，每次加1表示顺时针旋转90°
    int dx[] = {0, 1, 0, -1};  // x方向的步长
    int dy[] = {1, 0, -1, 0};  // y方向的步长

    int x;
    int y = start_y;

    // 向左找到左边界线
    x = start_x;
    while (x >= 0) {

      uint8_t binarized_value1 = adaptiveThreshold(img_data, x - 1, y, width, height);
      uint8_t binarized_value2 = adaptiveThreshold(img_data, x - 2, y, width, height);
      //在这个位置如果需要可以加上对output.data的赋值


      // 保险起见，如果左侧两个位置的像素都是黑色，则认为找到了边线（后续应该考虑增加到三个）
      if (binarized_value1 == 255 && binarized_value2 == 255) {
        break;
      }
      else {
        x--;
      }
    }


    // 边界条件是左上方
    while (x >= 0 && y >= 0 ) {
        // 对当前像素点进行自适应二值化
        uint8_t binarized_value = adaptiveThreshold(img_data, x, y, width, height);

        // 将二值化后的结果存入输出数据
        output_data[x + y * width] = binarized_value;



        //如果所朝方向是边界，则顺时针旋转90°
        uint8_t binarized_up = adaptiveThreshold(img_data, x + dx[direction], y + dy[direction], width, height);
        if (binarized_up == 255) {
          direction = (direction + 1) % 4;  // 顺时针旋转90°
        }
        //如果所朝方向不是边界，则沿着所朝方向前进，且只走一次
        else {
          x = x + dx[direction];
          y = y + dy[direction];
        }






        int next_direction = (direction + 3) % 4;  // 右转
        int nx = x + dx[next_direction];
        int ny = y + dy[next_direction];

        // 判断右侧的像素是否为边界
        uint8_t next_pixel = adaptiveThreshold(img_data, nx, ny, width, height);

        if (next_pixel == 255) {
            // 如果右侧为边界，转向右
            direction = next_direction;
        } else {
            // 否则沿当前方向继续前进
            direction = (direction + 1) % 4;  // 左转
        }

        // 更新当前坐标
        x = x + dx[direction];
        y = y + dy[direction];
    }
}

