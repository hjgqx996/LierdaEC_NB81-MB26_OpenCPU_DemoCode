#ifndef __NPI_CONFIG_H__
#define __NPI_CONFIG_H__
/****************************************************************************
 *
 * Copy right:   2017-, Copyrigths of EigenComm Ltd.
 * File name:    npi_config.h
 * Description:  NPI configuration header file
 * History:      Rev1.0   2020-04-02
 *
 ****************************************************************************/
#include "osasys.h"
#include "cms_def.h"


/******************************************************************************
 *****************************************************************************
 * MARCO/MARCO
 *****************************************************************************
******************************************************************************/

#define NPI_NVM_FILE_VERSION   0
#define NPI_NVM_FILE_NAME      "npiconfig.nvm"

typedef enum NPIProcessStatusItem_Tag
{
    NPI_PROCESS_STATUS_ITEM_RFCALI,      // RFCALI done?
    NPI_PROCESS_STATUS_ITEM_RFNST,       // RFNST done?
    NPI_PROCESS_STATUS_ITEM_MAX
} NPIProcessStatusItem;

/******************************************************************************
 *****************************************************************************
 * STRUCT
 *****************************************************************************
******************************************************************************/

typedef struct NPINvmHeader_Tag
{
    UINT16 fileBodySize; //file body size, not include size of header;
    UINT8  version;
    UINT8  checkSum;
} NPINvmHeader;

/*
 * used for NPI status
*/
typedef struct NPIProcessStatus_Tag
{
    UINT32  rfCaliDone       : 1;       // RFCALI process done
    UINT32  rfNSTDone        : 1;       // RFNST process done
    UINT32  rsvd0            : 30;
} NPIProcessStatus;

typedef struct NPIProdModeStatus_Tag
{
    UINT32 prodModeEnable;
} NPIProdModeStatus;

/*
 * NPI NVM file structure
*/
typedef struct NPINvmConfig_Tag
{
    /*
     * NPI process status
    */
    NPIProcessStatus npiStatus;
    NPIProdModeStatus prodModeStatus;
} NPINvmConfig;



/******************************************************************************
 *****************************************************************************
 * API
 *****************************************************************************
******************************************************************************/

/*
 * load/read "npiconfig.nvm" NVM file
*/
void npiLoadNvmConfig(void);

/*
 * save "npiconfig.nvm" NVM file
*/
void npiSaveNvmConfig(void);


/*
 * get one NPI process status item value
*/
UINT32 npiGetProcessStatusItemValue(NPIProcessStatusItem cfgEnum);

/*
 * set and save one NPI process status item value
*/
void npiSetAndSaveProcessStatusItemValue(NPIProcessStatusItem cfgEnum, UINT32 value);

/*
 * set one NPI process status item value, but not write to flash, need call API: npiSaveNvmConfig()
 * used in case: if need to write several config values, in order to reduce times of write flash
*/
void npiSetProcessStatusItemValue(NPIProcessStatusItem cfgEnum, UINT32 value, BOOL *bChanged);

/**
  \fn           bool npiGetProdModeEnableStatus(void)
  \brief        Get/return prodModeEnable status value
  \returns      status value
*/
bool npiGetProdModeEnableStatus(void);

/**
  \fn           void npiSetProdModeEnableStatus(bool enable)
  \brief        Set prodModeEnable status value
  \param[in]    enable   whether enable prodMode or not
  \returns      void
*/
void npiSetProdModeEnableStatus(bool enable);

#endif
