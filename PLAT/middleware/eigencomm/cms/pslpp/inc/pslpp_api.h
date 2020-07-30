#ifndef __PS_LPP_API_H__
#define __PS_LPP_API_H__
/******************************************************************************
 ******************************************************************************
 Copyright:      - 2017- Copyrights of EigenComm Ltd.
 File name:      - pslpp_api.h
 Description:    - LPP functions
 History:        - 03/28/2019, Originated by xpliu
 ******************************************************************************
******************************************************************************/
#include "cms_api.h"

/******************************************************************************
 *****************************************************************************
 * MARCO
 *****************************************************************************
******************************************************************************/


/******************************************************************************
 *****************************************************************************
 * ENUM
 *****************************************************************************
******************************************************************************/



/******************************************************************************
 *****************************************************************************
 * STRUCT
 *****************************************************************************
******************************************************************************/


/******************************************************************************
 *****************************************************************************
 * Functions
 *****************************************************************************
******************************************************************************/
extern CmsRetId psLppProcCmiInd(const SignalBuf *indSignalPtr);
extern CmsRetId psLppProcCmiCnf(const SignalBuf *cnfSignalPtr);
extern CmsRetId psLppProcTimerExpiry(OsaTimerExpiry *pTimerExpiry);
extern void PslppInitialise(void);

#endif
