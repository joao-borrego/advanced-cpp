#include <fstream>

#include "Bitmap.h"


namespace fractal {

Bitmap::Bitmap(int width, int height)
    : _width(width), _height(height),
      _pixels(new uint8_t[width * height * 3]{}) {

}

Bitmap::~Bitmap() {

}

void Bitmap::setPixel(int x, int y,
    uint8_t red, uint8_t green, uint8_t blue) {

    uint8_t *pixel = _pixels.get() + (3 * (_width * y + x));
    pixel[0] = blue;
    pixel[1] = green;
    pixel[2] = red;
}

bool Bitmap::write(const std::string &filename) const {

    BitmapFileHeader fileHeader;
    BitmapInfoHeader infoHeader;

    fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader); 
    fileHeader.fileSize = fileHeader.dataOffset + 3 * _width * _height;
    infoHeader.width = _width;
    infoHeader.height = _height;

    std::ofstream file;
    file.open(filename, std::ofstream::out | std::ofstream::binary);
    if (!file) {
        return false;
    }

    file.write(reinterpret_cast<char *>(&fileHeader), sizeof(fileHeader));
    file.write(reinterpret_cast<char *>(&infoHeader), sizeof(infoHeader));
    file.write(reinterpret_cast<char *>(_pixels.get()), 3 * _width * _height);

    file.close();
    if (!file) {
        return false;
    }

    return true;
}

}
