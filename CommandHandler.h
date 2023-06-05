/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef UTIL_54BEF2A4_26CF_44B8_A44F_A06150BC2886
#define UTIL_54BEF2A4_26CF_44B8_A44F_A06150BC2886

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace util{
  struct CommandHandler;
  class CommandExecutor;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
struct util::CommandHandler : public virtual lang::Interface{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 
   * 
   * @param executor 執行處理器
   * @return true 結束指令處理，返回執行權
   * @return false 尚未結束指令處理，時序保持執行權
   */
  virtual bool onCommand(CommandExecutor& executor) abstract;

};

/* ****************************************************************************************
 * End of file
 */

#endif /* UTIL_54BEF2A4_26CF_44B8_A44F_A06150BC2886 */
