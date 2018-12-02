#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "BitmapFileHeader.h"

class BitmapFileHeaderUnitTest : public testing::Test {
    protected:
        virtual void SetUp() {}
        virtual void TearDown() {}
};



TEST_F(BitmapFileHeaderUnitTest, test_Bitmap_Size_Is_Correct) {
    int width = 400;
    int height = 200;
    int numColors = 3;
    BitmapFileHeader bitmapFileHeader(width, height, numColors);

    int expectedBitmapSize = (width * height * numColors);
    EXPECT_EQ(expectedBitmapSize, (bitmapFileHeader.getFileSize() - bitmapFileHeader.getDataOffset()));
}



TEST_F(BitmapFileHeaderUnitTest, test_Bitmap_Size_Is_Correct_Without_Colors) {
    int width = 400;
    int height = 200;
    int numColors = 0;
    BitmapFileHeader bitmapFileHeader(width, height, numColors);

    int expectedBitmapSize = (width * height * numColors);
    EXPECT_EQ(expectedBitmapSize, (bitmapFileHeader.getFileSize() - bitmapFileHeader.getDataOffset()));
}
