#include "block.h"

/**
 * Returns the width of the block.
 */
int Block::width() const{/*your code here*/
return data.size();
}

/**
 * Returns the height of the block.
 */
int Block::height() const{/*your code here*/
if (data.size() == 0) {
  return 0;
} else return data[0].size();
//consider for the case if data is empty
//it doesn't contain any element
}

/**
 * Default Block constructor.
 */
Block::Block() {/* nothing */}

/**
 * Useful Block constructor.
 * Makes a block from the rectangle of width by height pixels in im
 //drag the pixels of the image into the block
 //the color of the image is paste on to the block
 * whose upper-left corner is at position (x,y).
 */
Block::Block(PNG & im, int x, int y, int width, int height) {
  for (int col=0; col < width; col++){
    vector<HSLAPixel> pixels;
    for (int row=0; row < height; row++) {
      HSLAPixel origPixel = *im.getPixel(x+col, y+row);
      pixels.push_back(origPixel);
    }
    data.push_back(pixels);
  }
}
// // data[width];
// // for (int i=0; i< data.size(); i++) {
// //   data[i].resize(height);
// // }
// //
// // int *initalY = y;
// // int *initalX = x;
// //
// // for (int; x< width; x++){
// //
// //     for (int y=0; y <height ; y++) {
// //   data[x][y] = (im.getPixel(initalX, initaly)));
// //   initaly = initalY + 1;
// //   }
//
//


// for (int initalW = 0; initalW < width ; initalW ++){
//   int initalY = y;
//   for(int initalH= 0; initalH < height; initalH ++){
//     data[initalW][initalH] = *im.getPixel(x,initalY);
//     initalY = initalY -1;
//   }
//   x = x+1;
// }
//}

//
// vector<HSLAPixel> imheight(height);
// vector<vector<HSLAPixel>> imwidth(width);
// for(int i = 0; i < width; i++) {
//   for(int j = 0; j < height; j++) {
//     imheight[j] = *im.getPixel(x, y);
//     y++;
//   }
//   imwidth[i] = imheight;
//   x++;
// }
// data = imwidth;
// }



//returns a pointer to a pixel




/**
 * Draws the block at position (x,y) in the image im
 */
// void Block::render(PNG & im, int x, int y) const {/*your code here*/
//
//
//
// }

void Block::render(PNG & im, int x, int y) const {
	for(unsigned i = 0; i < data.size(); i++) {
		for (unsigned j = 0; j < data[0].size(); j++) {
			*im.getPixel(x+i, y+j) = data[i][j];
		}
	}
}

/**
 * Changes the saturation of every pixel in the block to 0,
 * which removes the color, leaving grey.
 */
// void Block::greyscale() {/*your code here*/
// for (unsigned int i=0; i<data.size(); i++) {
//   for (unsigned int y=0; y<data[0].size(); y++) {
//     data[i][y].s = 0;
//   }
// }


/**
 * Changes the saturation of every pixel in the block to 0,
 * which removes the color, leaving grey.
 */
 //
void Block::greyscale() {/*your code here*/
	for(unsigned i = 0; i < data.size(); i++) {
		for(unsigned j = 0; j < data[0].size(); j++) {
			data[i][j].s = 0;
		}
	}
}
