/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef UTIL_725C70AC_977E_4B0D_B01D_89AD302D24CE
#define UTIL_725C70AC_977E_4B0D_B01D_89AD302D24CE

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "./../util/CommandHandler.h"

/* ****************************************************************************************
 * Namespace
 */
namespace mframe::util {
  template <class C>
  class CommandHandlerMethod;
}  // namespace mframe::util

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
template <class C>
class mframe::util::CommandHandlerMethod : public mframe::lang::FunctionMethod<C, CommandExecutor&, bool>,
                                           public mframe::util::CommandHandler {
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
  CommandHandlerMethod(C& c,
                       bool (C::*method)(CommandExecutor&),
                       const char* command,
                       const char* description) : mframe::lang::FunctionMethod<C, CommandExecutor&, bool>(c, method) {
    this->mDescription = description;
    this->mCommand = command;
    return;
  }

  CommandHandlerMethod(C& c,
                       bool (C::*method)(CommandExecutor&),
                       const char* command) : CommandHandlerMethod(c, method, command, "no description.") {
    return;
  }

  virtual ~CommandHandlerMethod(void) override {
    return;
  }

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override>
   */
 public:
  virtual const char* getDescription(void) override {
    return this->mDescription;
  }

  virtual const char* getCommand(void) override {
    return this->mCommand;
  }

  virtual bool onCommand(CommandExecutor& executor) override {
    return this->apply(executor);
  }
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

#endif /* UTIL_725C70AC_977E_4B0D_B01D_89AD302D24CE */
