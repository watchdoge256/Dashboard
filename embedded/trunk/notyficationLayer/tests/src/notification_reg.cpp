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
#include <string.h>
}
#endif
static void notify(uint8 key, void *newValue, uint16 size);

static void notify(uint8 key, void *newValue, uint16 size)
{

}

static notfyUnit_t notfyUnit;
static notification_t notification;
static notification_t notification2;

static uint64 testVariable = 0x12345678acbde988;
static uint8 testVariableLock;

static uint64 testVariable2[2] = {0x13348acbde988566,0x2233441122665544};
static uint8 testVariableLock2;

namespace
{

  TEST_F(ntfyTest, one_signal)
  {
    EXPECT_EQ(notification_Init(&notfyUnit, notify), TRUE);
    notification.key = 10;
    notification.lock = &testVariableLock;
    notification.pMonitorAddress = &testVariable;
    notification.size = sizeof(testVariable);
    EXPECT_EQ(notificaiton_Register(&notfyUnit, &notification), TRUE);
    EXPECT_EQ(notfyUnit.monTopPtr, 1);
    EXPECT_EQ(notfyUnit.monUnit[0].baseValue, notification.pMonitorAddress);
    EXPECT_EQ(notfyUnit.monUnit[0].size, notification.size);
    EXPECT_EQ(notfyUnit.monUnit[0].backupValue, notfyUnit.bkpArea);
    EXPECT_EQ(notfyUnit.monUnit[0].lock, notification.lock);
    EXPECT_EQ(notfyUnit.monUnit[0].key, notification.key);
    EXPECT_EQ(notfyUnit.monAreaPtr, notification.size);
    EXPECT_EQ(memcmp(notfyUnit.monUnit[0].backupValue,
              notification.pMonitorAddress,
              sizeof(notification.size) ), 0);
  }

  TEST_F(ntfyTest, two_signals)
  {
//    EXPECT_EQ(notification_Init(&notfyUnit, notify), TRUE);
//    notification.key = 10;
//    notification.lock = &testVariableLock;
//    notification.pMonitorAddress = &testVariable;
//    notification.size = sizeof(testVariable);
//    EXPECT_EQ(notificaiton_Register(&notfyUnit, &notification), TRUE);
//    EXPECT_EQ(notfyUnit.monTopPtr, 1);
//    EXPECT_EQ(notfyUnit.monUnit[0].baseValue, notification.pMonitorAddress);
//    EXPECT_EQ(notfyUnit.monUnit[0].size, notification.size);
//    EXPECT_EQ(notfyUnit.monUnit[0].backupValue, notfyUnit.bkpArea);
//    EXPECT_EQ(notfyUnit.monUnit[0].lock, notification.lock);
//    EXPECT_EQ(notfyUnit.monUnit[0].key, notification.key);
//    EXPECT_EQ(notfyUnit.monAreaPtr, notification.size);
//    EXPECT_EQ(memcmp(notfyUnit.monUnit[0].backupValue,
//              notification.pMonitorAddress,
//              sizeof(notification.size) ), 0);

    notification2.key = 11;
    notification2.lock = &testVariableLock2;
    notification2.pMonitorAddress = &testVariable2;
    notification2.size = sizeof(testVariable2);
    EXPECT_EQ(notificaiton_Register(&notfyUnit, &notification2), TRUE);
    EXPECT_EQ(notfyUnit.monTopPtr, 2);
    EXPECT_EQ(notfyUnit.monUnit[1].baseValue, notification2.pMonitorAddress);
    EXPECT_EQ(notfyUnit.monUnit[1].size, notification2.size);
    EXPECT_EQ(notfyUnit.monUnit[1].backupValue, notfyUnit.bkpArea+notification.size);
    EXPECT_EQ(notfyUnit.monUnit[1].lock, notification2.lock);
    EXPECT_EQ(notfyUnit.monUnit[1].key, notification2.key);
    EXPECT_EQ(notfyUnit.monAreaPtr, notification.size + notification2.size);
    EXPECT_EQ(memcmp(notfyUnit.monUnit[1].backupValue,
              notification2.pMonitorAddress,
              sizeof(notification2.size) ), 0);
  }
}

