/*
 * notification.c
 *
 *  Created on: 12 kwi 2019
 *      Author: amiar
 */
#include "notification.h"
#include "string.h"

void notification_Init(notfyUnit_t *pNotyUnit, notificationCallback callback)
{
  pNotyUnit->internalCallback = callback;
}

bool notyficaiton_Register(notfyUnit_t *pNtfyUnit, notification_t *notification)
{
  bool ret = FALSE;
  if (pNtfyUnit->monTopPtr < NOTIFICATION_MONITOR_SIGNALS)
  {
    pNtfyUnit->monUnit[pNtfyUnit->monTopPtr].baseValue = notification->pMonitorAddress;
    pNtfyUnit->monUnit[pNtfyUnit->monTopPtr].size = notification->size;
    pNtfyUnit->monUnit[pNtfyUnit->monTopPtr].backupValue = pNtfyUnit->bkpArea + pNtfyUnit->monAreaPtr;
    pNtfyUnit->monUnit[pNtfyUnit->monTopPtr].lock = notification->lock;
    pNtfyUnit->monUnit[pNtfyUnit->monTopPtr].key = notification->key;

    memcpy(pNtfyUnit->monUnit[pNtfyUnit->monTopPtr].backupValue,
        pNtfyUnit->monUnit[pNtfyUnit->monTopPtr].baseValue,
        pNtfyUnit->monUnit[pNtfyUnit->monTopPtr].size);

    pNtfyUnit->monAreaPtr+= notification->size;
    pNtfyUnit->monTopPtr++;
    ret = TRUE;
  }
  return ret;
}

void notification_Monitor(notfyUnit_t *pNotyUnit)
{
  uint8 i;
  for (i=0; i<pNotyUnit->monTopPtr; i++)
  {
    if(pNotyUnit->monUnit[i].lock == FALSE)
    {
      pNotyUnit->monUnit[i].lock = TRUE;
      if (memcmp(pNotyUnit->monUnit[i].backupValue,
          pNotyUnit->monUnit[i].baseValue,
          pNotyUnit->monUnit[i].size))
      {
        memcpy(pNotyUnit->monUnit[i].backupValue,
            pNotyUnit->monUnit[i].baseValue,
            pNotyUnit->monUnit[i].size);
        if(pNotyUnit->internalCallback)
        {
          pNotyUnit->internalCallback(pNotyUnit->monUnit[i].key, pNotyUnit->monUnit[i].backupValue, pNotyUnit->monUnit[i].size);
        }
      }
      pNotyUnit->monUnit[i].lock = FALSE;
    }
  }

}
