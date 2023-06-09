/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */
#include "./CommandHandlerEvent.h"

//-----------------------------------------------------------------------------------------
#include "mframe.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */
using mframe::util::CommandHandlerEvent;

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

//-----------------------------------------------------------------------------------------
CommandHandlerEvent::CommandHandlerEvent(bool (*func)(CommandExecutor& executor), const char* command, const char* descirption) {
  if (func == nullptr)
    System::error(this, ErrorCode::NULL_POINTER);

  this->mCommand = command;
  this->mDescription = descirption;
  this->mFunc = func;
}

//-----------------------------------------------------------------------------------------
CommandHandlerEvent::CommandHandlerEvent(bool (*func)(CommandExecutor& executor), const char* command) : CommandHandlerEvent(func, command, "do description.") {
  return;
}

//-----------------------------------------------------------------------------------------
CommandHandlerEvent::~CommandHandlerEvent(void) {
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override>
 */

const char* CommandHandlerEvent::getDescription(void) {
  return this->mDescription;
}

//-----------------------------------------------------------------------------------------
const char* CommandHandlerEvent::getCommand(void) {
  return this->mCommand;
}

//-----------------------------------------------------------------------------------------
bool CommandHandlerEvent::onCommand(CommandExecutor& executor) {
  return this->mFunc(executor);
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
