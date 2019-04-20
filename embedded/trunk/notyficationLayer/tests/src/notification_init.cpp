/*
 * notyfication_tests.cpp
 *
 *  Created on: 14 kwi 2019
 *      Author: amiar
 */

#ifdef __cplusplus
#include "../inc/notification_init.h"
extern "C" {
#include "../../inc/notification.h"
}
#endif
static void notify(uint8 key, void *newValue, uint16 size);

static void notify(uint8 key, void *newValue, uint16 size)
{

}

static notfyUnit_t notfyUnit;

namespace
{
  TEST_F(ntfyTest, initTest_NULL)
  {
    EXPECT_EQ(notification_Init(&notfyUnit, NULL), FALSE);
  }
  TEST_F(ntfyTest, initTest_callback)
  {
    EXPECT_EQ(notification_Init(&notfyUnit, notify), TRUE);
    EXPECT_EQ((void*)notfyUnit.internalCallback, (void*)notify);
  }
}

