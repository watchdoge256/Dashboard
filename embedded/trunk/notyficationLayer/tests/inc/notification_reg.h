/*
 * notyfication_tests.h
 *
 *  Created on: 14 kwi 2019
 *      Author: amiar
 */
#ifndef NOTYFICATION_REG_H_
#define NOTYFICATION_REG_H_
#include "gtest_config.h"
#include "gtest.h"
#ifdef __cplusplus
extern "C" {
#include "../../inc/notification.h"
}
#endif

/*
 * Those tests checks if parameters are being registered in correct way
 *  */

extern void reg_initNotifications(notification_t *notificationArray, uint8 *testVariableLockArray, uint64 *monitorAddressArray, uint32 *sizeArray);

class ntfyTest : public ::testing::Test
{
protected:
   virtual void SetUp()
   {
     reg_initNotifications(NULL, NULL, NULL, NULL);
   }

   virtual void TearDown()
   {
   }
};


#endif /* NOTYFICATION_INIT_H_ */
