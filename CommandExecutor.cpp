/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "./CommandExecutor.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using util::CommandExecutor;

/* ****************************************************************************************
 * Variable <Static>
 */
const char* CommandExecutor::TEXT_UNKNOWN_COMMAND = "unknown command please try command help.\n";

/* ****************************************************************************************
 * Construct Method
 */

//-----------------------------------------------------------------------------------------
CommandExecutor::CommandExecutor(int mapSize, int commandSize,
                                 lang::PrintBuffer& output,
                                 lang::ReadBuffer& input) : mCommandMap(mapSize),
                                                            mCommandHandlerDefaultHelp(Iterator<CommandHandler*>(mCommandMap)),
                                                            mBuffer(static_cast<size_t>(commandSize)),
                                                            mInput(input),
                                                            mOutput(output) {
  this->mCommandHandler = nullptr;
  this->mEchoEnable = false;
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
 * Public Method <Override> - lang::Executor
 */

//-----------------------------------------------------------------------------------------
void CommandExecutor::execute(void) {
  if(!this->mInput.hasNextLine())
    return;

  this->mInput.nextString(this->mBuffer);
  Hashcode h = Hashcode(HashGen::getHashcodeLowerCast(this->mBuffer));
  
  CommandHandler* commandHandler = this->mCommandMap.get(h);
  if(commandHandler)
    commandHandler->onCommand(*this);

  else{
    this->out() <<'\'' << this->mBuffer << "\' " << CommandExecutor::TEXT_UNKNOWN_COMMAND;
    this->in().skipNextLine();
  }
  
  return;
}

/* ****************************************************************************************
 * Public Method <Override> - util::CommandHandler
 */

/* ****************************************************************************************
 * Public Method
 */

//-----------------------------------------------------------------------------------------
lang::PrintBuffer& CommandExecutor::out(void) {
  return this->mOutput;
}

//-----------------------------------------------------------------------------------------
util::Scanner& CommandExecutor::in(void) {
  return this->mInput;
}

//-----------------------------------------------------------------------------------------
bool CommandExecutor::put(CommandHandler& commandHandler) {
  Hashcode h = Hashcode(HashGen::getHashcodeLowerCast(commandHandler.getCommand()));
  
  if (this->mCommandMap.containsKey(h)) {
    return false;
  }

  this->mCommandMap.put(h, &commandHandler);
  return true;
}

//-----------------------------------------------------------------------------------------

util::CommandHandler* CommandExecutor::get(const char* command) {
  Hashcode h = Hashcode(HashGen::getHashcodeLowerCast(command));
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

//-----------------------------------------------------------------------------------------
void CommandExecutor::echoEnable(bool enable) {
  this->mEchoEnable = enable;
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
