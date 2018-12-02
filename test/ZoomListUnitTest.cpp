#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "ZoomList.h"

class ZoomListUnitTest : public testing::Test {
    protected:
        virtual void SetUp() {}
        virtual void TearDown() {}
};



TEST_F(ZoomListUnitTest, test_doZoom_ZeroZoomLevel_CenterCoordinatesValid) {
    int width = 400;
    int height = 200;
    ZoomList zoomList(width, height);

    auto zoom = zoomList.doZoom((width / 2), (height / 2));

    EXPECT_EQ(0, zoom.first);
    EXPECT_EQ(0, zoom.second);
}



TEST_F(ZoomListUnitTest, test_doZoom_ZeroZoomLevel_RightBottomCoordinatesValid) {
    int width = 400;
    int height = 200;
    ZoomList zoomList(width, height);

    auto zoom = zoomList.doZoom(width, height);

    EXPECT_EQ((width / 2), zoom.first);
    EXPECT_EQ((height / 2), zoom.second);
}


