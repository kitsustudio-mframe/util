/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef UTIL_5D93A9A6_BCB1_43C0_B93F_8EEABFA4B2E7
#define UTIL_5D93A9A6_BCB1_43C0_B93F_8EEABFA4B2E7

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "./../io/PrintBuffer.h"
#include "./../lang/Executor.h"
#include "./../lang/Strings.h"
#include "./../util/ArrayMap.h"
#include "./../util/CommandHandler.h"
#include "./../util/CommandHandlerDefaultHelp.h"
#include "./../util/Scanner.h"

/* ****************************************************************************************
 * Namespace
 */
namespace util {
  class CommandExecutor;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
class util::CommandExecutor : public lang::Object,
                              public lang::Executor {
  /* **************************************************************************************
   * Variable <Public>
   */
 public:
  static const char* TEXT_UNKNOWN_COMMAND;
  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */
 private:
  ArrayMap<lang::Object, CommandHandler> mCommandMap;
  CommandHandlerDefaultHelp mCommandHandlerDefaultHelp;
  lang::Strings mBuffer;
  util::Scanner mInput;
  io::PrintBuffer& mOutput;

  CommandHandler* mCommandHandler;
  void* mAttachment;
  char mSplitCharacter;
  bool mPause;
  bool mResult;

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
   * @brief Construct a new Command Executor object
   *
   * @param mapSize 指令地圖的預設大小
   * @param commandSize 支援最大的指令長度
   * @param output 輸出
   * @param input 輸入
   */
  CommandExecutor(int mapSize, int commandSize, io::PrintBuffer& output, io::ReadBuffer& input);

  /**
   * @brief Destroy the Command Executor object
   *
   */
  virtual ~CommandExecutor(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - lang::Executor
   */
 public:
  virtual void execute(void) override;

  /* **************************************************************************************
   * Public Method <Inline>
   */
 public:
  /**
   * @brief 取得使用者參數
   *
   * @tparam T 類型
   * @param cast 轉換類型，請使用Class<T>::cast()
   * @return T* 返回類型
   */
  template <class T>
  inline T* getAttachment(const T* cast) const {
    return static_cast<T*>(this->mAttachment);
  }

  /**
   * @brief 設定使用者參數
   *
   * @param attachment
   */
  inline void setAttachment(void* attachment) {
    this->mAttachment = attachment;
    return;
  }

  /**
   * @brief 取得分割字元
   *
   * @return char
   */
  inline char getSplitCharacter(void) {
    return this->mSplitCharacter;
  }

  inline void pause(bool enable) {
    this->mPause = enable;
    return;
  }

  inline bool pause(void) {
    return this->mPause;
  }

  inline bool getLastCommandResult(void) {
    return this->mResult;
  }

  /* **************************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief 取得輸出串流
   *
   * @return io::PrintBuffer&
   */
  virtual io::PrintBuffer& out(void);

  /**
   * @brief 取得輸入串流
   *
   * @return io::ReadBuffer&
   */
  virtual util::Scanner& in(void);

  /**
   * @brief 新增指令
   *
   * @param command 指令
   * @param commandHandler 指令執行程序
   * @return true 成功新增指令
   * @return false 新增指令失敗，指令已存在
   */
  virtual bool put(CommandHandler& commandHandler);

  /**
   * @brief 取得指令
   *
   * @param command 指令
   * @return CommandHandler*
   *  - nullptr 指令未找到
   *  - other 指令執行程序
   */
  virtual CommandHandler* get(const char* command);

  /**
   * @brief 移除指令
   *
   * @param command 指令
   * @return true 成功找到指令並移除
   * @return false 尚未找到指令
   */
  virtual bool remove(const char* command);

  /**
   * @brief Get the Buffer object
   *
   * @return Strings&
   */
  virtual Strings& getBuffer(void);

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

#endif /* UTIL_5D93A9A6_BCB1_43C0_B93F_8EEABFA4B2E7 */
