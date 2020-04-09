/*
 * notyfication_tests.cpp
 *
 *  Created on: 14 kwi 2019
 *      Author: amiar
 */

#ifdef __cplusplus
#include "../inc/notification_reg.h"
extern "C" {
#include <string.h>
#include <stdlib.h>
#include <time.h>
}
#endif


static notfyUnit_t notfyUnit;
static notification_t notificationArr[NOTIFICATION_MONITOR_SIGNALS];
static uint64 testVariable[2*NOTIFICATION_MONITOR_SIGNALS];
static uint8 testVariableLock[NOTIFICATION_MONITOR_SIGNALS];

static void notify(uint8 key, void *newValue, uint16 size);
static void initTestVars(void);

static void notify(uint8 key, void *newValue, uint16 size)
{

}

/* --------------------------------
 * @brief: This function shall initialize monitors for each signal
 *          If passed null pointers then it shall use local variables
 * @param: notificationArray - pointer to Array containing information about notifications
 * @param: testVariableLockArray - pointer to array containin information about localization of notification's locks
 * @param: monitorAddressArray - array containing addresses to be monitored
 * @param: sizeArray - array containing size of corresponding monitored space
 *
 * */
void reg_initNotifications(notification_t *notificationArray, uint8 *testVariableLockArray, uint8 *monitorAddressArray, uint32 *sizeArray)
{
  uint32 i;
  uint32 privateSizeArray[NOTIFICATION_MONITOR_SIGNALS];
  uint8 *monAddrArrBuff; // this pointer is for calculating next address of parameter
  // if null pointer then self initialization
  // ----------------------------------------
  for(i=0; i<NOTIFICATION_MONITOR_SIGNALS; i++)
  {
    privateSizeArray[i] = 2*sizeof(uint64); //testVariables have 2*64 byte
  }
  initTestVars();

  if (!notificationArray)
  {
    notificationArray = notificationArr;
    testVariableLockArray = testVariableLock;
    monitorAddressArray = (uint8*)testVariable;
    sizeArray = privateSizeArray;
  }

  monAddrArrBuff = monitorAddressArray;
  for (i=0; i<NOTIFICATION_MONITOR_SIGNALS; i++)
  {
    notificationArr[i].key = i+1;
    notificationArr[i].lock = &testVariableLockArray[i];
    notificationArr[i].pMonitorAddress = &monAddrArrBuff + sizeArray[i];
    monAddrArrBuff += sizeArray[i];
    notificationArr[i].size = sizeArray[i];
  }
}

static void initTestVars(void)
{
  uint32 seed,i;
  seed = time(NULL);
  srand(seed);


  for (i=0;i<NOTIFICATION_MONITOR_SIGNALS*2;i++)
  {
    testVariable[i] = (uint64)((((uint64)rand())<<32) + (uint64)rand());
  }

}
namespace
{

  TEST_F(ntfyTest, one_signal)
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
  }

  TEST_F(ntfyTest, two_signals)
  {
//
//    notification2.key = 11;
//    notification2.lock = &testVariableLock2;
//    notification2.pMonitorAddress = &testVariable2;
//    notification2.size = sizeof(testVariable2);
//    EXPECT_EQ(notificaiton_Register(&notfyUnit, &notification2), TRUE);
//    EXPECT_EQ(notfyUnit.monTopPtr, 2);
//    EXPECT_EQ(notfyUnit.monUnit[1].baseValue, notification2.pMonitorAddress);
//    EXPECT_EQ(notfyUnit.monUnit[1].size, notification2.size);
//    EXPECT_EQ(notfyUnit.monUnit[1].backupValue, notfyUnit.bkpArea+notification.size);
//    EXPECT_EQ(notfyUnit.monUnit[1].lock, notification2.lock);
//    EXPECT_EQ(notfyUnit.monUnit[1].key, notification2.key);
//    EXPECT_EQ(notfyUnit.monAreaPtr, notification.size + notification2.size);
//    EXPECT_EQ(memcmp(notfyUnit.monUnit[1].backupValue,
//              notification2.pMonitorAddress,
//              sizeof(notification2.size) ), 0);
  }
}

