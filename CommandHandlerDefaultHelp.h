/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef UTIL_80396FB1_BC61_4C99_A388_F1ECB0AC5171
#define UTIL_80396FB1_BC61_4C99_A388_F1ECB0AC5171

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------
#include "./CommandHandler.h"

/* ****************************************************************************************
 * Namespace
 */
namespace util {
  class CommandHandlerDefaultHelp;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
class util::CommandHandlerDefaultHelp : public lang::Object,
                                        public util::CommandHandler {
  /* **************************************************************************************
   * Variable <Public>
   */
  public:
    static const char* TEXT_COMMAND;
    static const char* TEXT_DESCRIPTION;

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */
  private:
    Iterator<CommandHandler*> mCommandIterator;

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
   * @brief Construct a new Command Handler Default Help object
   * 
   * @param commandIterator 
   */
  CommandHandlerDefaultHelp(const Iterator<CommandHandler*>& commandIterator);

  /**
   * @brief Destroy the Command Handler Default Help object
   * 
   */
  virtual ~CommandHandlerDefaultHelp(void) override;

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

#endif /* UTIL_80396FB1_BC61_4C99_A388_F1ECB0AC5171 */
