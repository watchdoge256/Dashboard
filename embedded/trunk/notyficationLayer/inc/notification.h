/*
 * notifications.h
 *
 *  Created on: 12 kwi 2019
 *      Author: amiar
 */

#ifndef INC_NOTIFICATION_H_
#define INC_NOTIFICATION_H_

#include "types.h"

// Maximum area for parameters
// ---------------------------
#define NOTIFICATION_MONITOR_AREA_SIZE  2048

// Maximum number of signals
// -------------------------
#define NOTIFICATION_MONITOR_SIGNALS    10

typedef void (*notificationCallback)(uint8 key, void *newValue, uint16 size);

// This structure stores information about single notification
// -----------------------------------------------------------
typedef struct notification_Tag {
  uint8 key;
  void *pMonitorAddress;
  uint8 *lock;
  uint32 size;
 }notification_t;

 // This structure is used by monitor to emit publication value
 // -----------------------------------------------------------
 typedef struct monitorUnit_Tag {
   void *baseValue;
   void *backupValue;
   uint16 size;
   uint8 *lock;
   uint8 key;
 }monitorUnit_t;

// This structure contains notification unit memory organization
// -------------------------------------------------------------
 typedef struct notificationUnit_Tag {
   uint8 bkpArea[NOTIFICATION_MONITOR_AREA_SIZE];
   uint8 monTopPtr;
   uint16 monAreaPtr;
   notificationCallback internalCallback;
   monitorUnit_t monUnit[NOTIFICATION_MONITOR_SIGNALS];
 }notfyUnit_t;

 extern uint8 notification_Init(notfyUnit_t *pNotyUnit, notificationCallback callback);
 extern uint8 notificaiton_Register(notfyUnit_t *pNotyUnit, notification_t *notification);
 extern void notification_Monitor(notfyUnit_t *pNotyUnit);

#endif /* INC_notification_H_ */
