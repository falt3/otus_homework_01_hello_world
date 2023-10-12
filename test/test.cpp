#include <gtest/gtest.h>

#include "lib.h"

TEST(LibVersion, Version) {
    int vers = version();
    ASSERT_TRUE(vers > 0);
}