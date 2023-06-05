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

/* ****************************************************************************************
 * Construct Method
 */

//-----------------------------------------------------------------------------------------
CommandExecutor::CommandExecutor(int mapSize, int commandSize,
                                 lang::PrintBuffer& output,
                                 lang::ReadBuffer& input) : mCommandMap(mapSize),
                                                            mBuffer(static_cast<size_t>(commandSize)),
                                                            mOutput(output),
                                                            mInput(input) {
  this->mCommandHandler = nullptr;
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
  if (this->mCommandHandler) {
    if (this->mCommandHandler->onCommand(*this)){
      this->mCommandHandler = nullptr;
      this->mBuffer.clear();
    }

    else
      return;
  }

  while (this->mInput.avariable()) {
    if(this->mCommandHandler)
      break;
    
    this->mInput.getByte(this->mSplitCharacter);
    switch (this->mSplitCharacter) {
      case '\0':
      case '\r':
      case '\n':
        this->mSplitCharacter = '\n';
      
      case ' ':
      case ';':
        if(this->mBuffer.isEmpty())
          break;
      
        this->mCommandHandler = static_cast<CommandHandler*>(this->mCommandMap.getHash(this->mBuffer.hashcodeLowerCast()));
      
        if (this->mCommandHandler == nullptr)
          this->mCommandHandler = this;
        
        break;

      default:
        this->mBuffer += (this->mSplitCharacter);
        break;
    }
  }

  return;
}

/* ****************************************************************************************
 * Public Method <Override> - util::COmmandHandler
 */
bool CommandExecutor::onCommand(CommandExecutor& executor) {
  if (this->getSplitCharacter() == '\n') {
    executor.out() << "unknown command.\n";
    return true;
  }

  while (executor.in().avariable()) {
    char c;
    executor.in().getByte(c);
    switch (c) {
      case '\0':
      case '\r':
      case '\n':
        executor.out() << "unknown command.\n";
        return true;

      default:
        break;
    }
  }
  return false;
}

/* ****************************************************************************************
 * Public Method
 */

//-----------------------------------------------------------------------------------------
lang::PrintBuffer& CommandExecutor::out(void) {
  return this->mOutput;
}

//-----------------------------------------------------------------------------------------
lang::ReadBuffer& CommandExecutor::in(void) {
  return this->mInput;
}

//-----------------------------------------------------------------------------------------
bool CommandExecutor::putCommand(const char* command, CommandHandler& commandHandler) {
  int hashcode = HashGen::getHashcodeLowerCast(command);
  this->out() << "add command: " << command << "  hashcode: " << hashcode << "\n";
  
  if (this->mCommandMap.containsKeyHash(hashcode)){
    this->out() << "command is exist\n";
    return false;
  }
    

  this->mCommandMap.putHash(hashcode, &commandHandler);
  return true;
}

//-----------------------------------------------------------------------------------------

util::CommandHandler* CommandExecutor::getCommand(const char* command) {
  Strings s = Strings(command);
  return this->mCommandMap.get(s);
}

//-----------------------------------------------------------------------------------------

bool CommandExecutor::removeCommand(const char* command) {
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
