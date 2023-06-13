/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */
#include "./CommandExecutor.h"

//-----------------------------------------------------------------------------------------
#include "mframe.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */
using mframe::util::CommandExecutor;

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Variable <Static>
 */
const char* CommandExecutor::TEXT_UNKNOWN_COMMAND = "unknown command please try command help.\n";

/* ****************************************************************************************
 * Construct Method
 */

//-----------------------------------------------------------------------------------------
CommandExecutor::CommandExecutor(int mapSize, int commandSize,
                                 mframe::io::PrintBuffer& output,
                                 mframe::io::ReadBuffer& input) : mCommandMap(mapSize),
                                                                  mCommandHandlerDefaultHelp(Iterator<CommandHandler*>(mCommandMap)),
                                                                  mBuffer(commandSize),
                                                                  mInput(input),
                                                                  mOutput(output) {
  this->mCommandHandler = nullptr;
  this->mPause = false;
  this->mResult = false;
  this->put(this->mCommandHandlerDefaultHelp);
  return;
}

//-----------------------------------------------------------------------------------------
CommandExecutor::~CommandExecutor(void) {
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override> - mframe::lang::Executor
 */

//-----------------------------------------------------------------------------------------
void CommandExecutor::execute(void) {
  bool result = false;

  if (this->mPause) {
    if (this->mCommandHandler)
      result = this->mCommandHandler->onCommand(*this);

    else
      return;

  } else {
    if (!this->mInput.hasNextLine())
      return;

    this->mInput.nextString(this->mBuffer);
    Hashcode h = Hashcode(HashGenerator::getHashcodeLowerCast(this->mBuffer));
    this->mCommandHandler = this->mCommandMap.get(h);
    if (this->mCommandHandler)
      result = this->mCommandHandler->onCommand(*this);

    else {
      result = false;
      this->out() << '\'';
      this->out() << this->mBuffer;
      this->out() << "\' ";
      this->out() << CommandExecutor::TEXT_UNKNOWN_COMMAND;
      this->in().skipNextLine();
    }
  }

  if (!this->mPause) {
    this->mResult = result;
    this->mCommandHandler = nullptr;
    
    if (result)
      this->mOutput << "\n>";
    else
      this->mOutput << "\n>";
  }

  return;
}

/* ****************************************************************************************
 * Public Method <Override> - mframe::util::CommandHandler
 */

/* ****************************************************************************************
 * Public Method
 */

//-----------------------------------------------------------------------------------------
mframe::io::PrintBuffer& CommandExecutor::out(void) {
  return this->mOutput;
}

//-----------------------------------------------------------------------------------------
mframe::util::Scanner& CommandExecutor::in(void) {
  return this->mInput;
}

//-----------------------------------------------------------------------------------------
bool CommandExecutor::put(CommandHandler& commandHandler) {
  Hashcode h = Hashcode(HashGenerator::getHashcodeLowerCast(commandHandler.getCommand()));

  if (this->mCommandMap.containsKey(h)) {
    return false;
  }

  this->mCommandMap.put(h, &commandHandler);
  return true;
}

//-----------------------------------------------------------------------------------------

mframe::util::CommandHandler* CommandExecutor::get(const char* command) {
  Hashcode h = Hashcode(HashGenerator::getHashcodeLowerCast(command));
  return this->mCommandMap.get(h);
}

//-----------------------------------------------------------------------------------------

bool CommandExecutor::remove(const char* command) {
  Strings s = Strings(command);
  if (this->mCommandMap.containsKey(s))
    return false;

  this->mCommandMap.remove(s);
  return true;
}

//-----------------------------------------------------------------------------------------
Strings& CommandExecutor::getBuffer(void) {
  return this->mBuffer;
}

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
