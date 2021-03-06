/******************************************************************************

*(C) Copyright 2018 EIGENCOMM International Ltd.

* All Rights Reserved

******************************************************************************
*  Filename: at_lwm2m_task.h
*
*  Description: Process LWM2M client related AT commands
*
*  History:
*
*  Notes:
*
******************************************************************************/
#ifndef _AT_CTLWM2M_TASK_H
#define _AT_CTLWM2M_TASK_H

#include "cms_api.h"

#define CTLWM2M_TASK_STACK_SIZE   2048
#define CTLWM2M_MSG_TIMEOUT 500

enum CTLWM2M_RC
{
    CTLWM2M_OK = 0,
    CTLWM2M_TASK_ERR
};

enum CTLWM2M_MSG_CMD
{
    MSG_CTLWM2M_DEREG_CLIENT, 
    MSG_CTLWM2M_SEND, 
    MSG_CTLWM2M_UPDATE, 
};

enum CTLWM2M_TASK_STATUS
{
    CTLWM2M_TASK_STAT_NONE, 
    CTLWM2M_TASK_STAT_CREATE
};

typedef struct
{
	UINT8 mode;
    UINT8 seqNum;
    CHAR *data;
}CTLWM2M_SEND_DATA_STRUCT;

typedef struct
{
    BOOL  update;
	UINT8 bindingMode;
    UINT8* objInsList;
}CTLWM2M_UPDATE_STRUCT;

typedef struct
{
    uint8_t cmd_type;
    UINT16 reqhandle;
    CTLWM2M_SEND_DATA_STRUCT send_data;
    CTLWM2M_UPDATE_STRUCT update;
}CTLWM2M_ATCMD_Q_MSG;

typedef struct
{
	int ret;
	int atHandle;
}ctlwm2m_cnf_msg;

CmsRetId ctlwm2m_client_update(UINT32 reqHandle, BOOL update, UINT8 bindingMode, UINT8* objInsList);
CmsRetId ctlwm2m_client_send(UINT32 reqHandle, char* data, UINT8 mode, UINT8 seqNum);
CmsRetId ctlwm2m_client_dereg(UINT32 reqHandle);

int ctlwm2m_client_create(void);

#endif
