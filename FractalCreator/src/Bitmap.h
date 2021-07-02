#ifndef BITMAP_H_
#define BITMAP_H_

#include <string>
#include <cstdint>
#include <memory>

#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

namespace fractal {

class Bitmap {
private:
    int _width {0};
    int _height {0};
    std::unique_ptr<uint8_t[]> _pixels {nullptr};

public:
    /// Contructor
    /// \param width Width in pixels
    /// \param height Height in pixels
    Bitmap(int width, int height);
    virtual ~Bitmap();
    void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
    bool write(const std::string &filename) const;
};

}

#endif
