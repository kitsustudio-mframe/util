/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */
#include "./CommandHandlerDefaultHelp.h"

//-----------------------------------------------------------------------------------------
#include "mframe_lang.h"
#include "mframe_util.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using util::CommandHandlerDefaultHelp;

/* ****************************************************************************************
 * Variable <Static>
 */
const char* CommandHandlerDefaultHelp::TEXT_COMMAND = "help";
const char* CommandHandlerDefaultHelp::TEXT_DESCRIPTION = "show all command description.";

/* ****************************************************************************************
 * Construct Method
 */

//-----------------------------------------------------------------------------------------
CommandHandlerDefaultHelp::CommandHandlerDefaultHelp(const Iterator<CommandHandler*>& commandIterator) : mCommandIterator(commandIterator) {
  return;
}

//-----------------------------------------------------------------------------------------
CommandHandlerDefaultHelp::~CommandHandlerDefaultHelp(void) {
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override> - util::CommandHandler
 */
//-----------------------------------------------------------------------------------------
const char* CommandHandlerDefaultHelp::getDescription(void) {
  return CommandHandlerDefaultHelp::TEXT_DESCRIPTION;
}

//-----------------------------------------------------------------------------------------
const char* CommandHandlerDefaultHelp::getCommand(void) {
  return CommandHandlerDefaultHelp::TEXT_COMMAND;
}

//-----------------------------------------------------------------------------------------
bool CommandHandlerDefaultHelp::onCommand(CommandExecutor& executor) {
  executor.in().skipNextLine();
  executor.out() << "Help list:\n";
  this->mCommandIterator.reset();

  CommandHandler* c = nullptr;
  while (this->mCommandIterator.next(c)) {
    executor.out() << "  " << c->getCommand() << " - " << c->getDescription() << "\n";
  }

  return true;
}
/* ****************************************************************************************
 * Public Method
 */

/* ****************************************************************************************
 * Protected Method <Static>
 */

/* ****************************************************************************************
 * Protected Method <Override>
 */

/* ****************************************************************************************
 * Protected Method
 */

/* ****************************************************************************************
 * Private Method
 */

/* ****************************************************************************************
 * End of file
 */
