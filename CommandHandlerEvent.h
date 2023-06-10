/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef UTIL_91741AE6_8AB5_4802_A30F_52D738500D9B
#define UTIL_91741AE6_8AB5_4802_A30F_52D738500D9B

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "./../lang/Object.h"
#include "./../util/CommandHandler.h"

/* ****************************************************************************************
 * Namespace
 */
namespace util {
  class CommandHandlerEvent;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
class util::CommandHandlerEvent : public lang::Object,
                                  public util::CommandHandler {
  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */
 private:
  bool (*mFunc)(CommandExecutor& executor);
  const char* mCommand;
  const char* mDescription;

  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Command Handler Event object
   *
   * @param func
   * @param command 指令
   * @param descirption 指令描述
   */
  CommandHandlerEvent(bool (*func)(CommandExecutor& executor), const char* command, const char* descirption);

  /**
   * @brief Construct a new Command Handler Event object
   *
   * @param func
   * @param command 指令
   */
  CommandHandlerEvent(bool (*func)(CommandExecutor& executor), const char* command);

  /**
   * @brief Destroy the Command Handler Event object
   *
   */
  virtual ~CommandHandlerEvent(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - util::CommandHandler
   */
 public:
  virtual const char* getDescription(void) override;

  virtual const char* getCommand(void) override;

  virtual bool onCommand(CommandExecutor& executor) override;
  /* **************************************************************************************
   * Public Method
   */

  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override>
   */

  /* **************************************************************************************
   * Protected Method
   */

  /* **************************************************************************************
   * Private Method <Static>
   */

  /* **************************************************************************************
   * Private Method <Override>
   */

  /* **************************************************************************************
   * Private Method
   */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* UTIL_91741AE6_8AB5_4802_A30F_52D738500D9B */
