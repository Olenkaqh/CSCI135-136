/*

  Description:
    The program reads a PGM image from the file "inImage.pgm",
    and outputs a modified image to "outImage.pgm" and and creates a white frame around
    an area where the white box was.
*/


#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

using namespace std;

const int MAX_H = 512;
const int MAX_W = 512;

// Reads a PGM file.
// Notice that: height and width are passed by reference!
void readImage(int image[MAX_H][MAX_W], int &height, int &width) {
	char c;
	int x;
	ifstream instr;
	instr.open("inImage.pgm");

	// read the header P2
	instr >> c;
	assert(c == 'P');
	instr >> c;
	assert(c == '2');

	// skip the comments (if any)
	while ((instr>>ws).peek() == '#') {
		instr.ignore(4096, '\n');
	}

	instr >> width;
	instr >> height;

	assert(width <= MAX_W);
	assert(height <= MAX_H);
	int max;
	instr >> max;
	assert(max == 255);

	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
			instr >> image[row][col];
	instr.close();
	return;
}


// Writes a PGM file
// Need to provide the array data and the image dimensions
void writeImage(int image[MAX_H][MAX_W], int height, int width) {
	ofstream ostr;
	ostr.open("outImage.pgm");
	if (ostr.fail()) {
		cout << "Unable to write file\n";
		exit(1);
	};

	// print the header
	ostr << "P2" << endl;
	// width, height
	ostr << width << ' ';
	ostr << height << endl;
	ostr << 255 << endl;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			assert(image[row][col] < 256);
			assert(image[row][col] >= 0);
			ostr << image[row][col] << ' ';
			ostr << endl;
		}
	}
	ostr.close();
	return;
}

int main() {

	int img[MAX_H][MAX_W];
	int h, w; // h is rows and w is columns

	readImage(img, h, w); // read it from the file "inImage.pgm"
	// h and w were passed by reference and
	// now contain the dimensions of the picture
	// and the 2-dimesional array img contains the image data

	// Now we can manipulate the image the way we like
	// for example we copy its contents into a new array
	int out[MAX_H][MAX_W]; // copy image created to be modified

	for(int row = 0; row < h; row++) {
		for(int col = 0; col < w ; col++) {
			if( row == h/4 || row == 3*h/4) // checks if the row is part of the desired perimeter
			{
				if (col >= w/4 && col <= 3*w/4) //checks if col is within the desired perimeter at that row
				{
					out[row][col] = 255; //changes pixel to white
				}
				else
				{
					out[row][col] = img[row][col]; //keeps the pixels
				}

			}

			else if( col == w/4 || col == 3*w /4) //checks if the col is within the desired perimeter
			{
				if (row >= h/4 && row <= 3*h/4) // checks if the row is within the desired perimiter at that col
				{
					out[row][col] = 255; //changes pixel to white
				}
				else
				{
					out[row][col] = img[row][col]; //keeps the pixels
				}
			}
			else
			{
				out[row][col] = img[row][col]; //if none of the conditions is met, the pixels stay with the same intensity

			}
			
		}
	}

	// and save this new image to file "outImage.pgm"
	writeImage(out, h, w);

}
