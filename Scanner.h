/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef UTIL_58A65E9B_2DCB_4DE5_9275_DE26DEE905BF
#define UTIL_58A65E9B_2DCB_4DE5_9275_DE26DEE905BF

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "./../io/ReadBuffer.h"
#include "./../lang/Data.h"
#include "./../lang/Object.h"
#include "./../util/Iterator.h"

/* ****************************************************************************************
 * Namespace
 */
namespace mframe::util {
  class Scanner;
}  // namespace mframe::util

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
class mframe::util::Scanner : public mframe::lang::Object {
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
  mframe::io::ReadBuffer& mReadBuffer;
  mframe::util::Iterator<char> mIterator;

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
   * @brief Construct a new Scanner object
   *
   * @param readBuffer
   */
  Scanner(mframe::io::ReadBuffer& readBuffer);

  /**
   * @brief Destroy the Scanner object
   *
   */
  virtual ~Scanner(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief 取得緩衝區是否擁有字元。
   *
   * @return true 滿足。
   * @return false 不滿足。
   */
  virtual bool hasNext(void);

  /**
   * @brief 取得緩衝區是否擁有指定的字元。
   *
   * @return true 滿足。
   * @return false 不滿足。
   */
  virtual bool hasNextChar(char ch);

  /**
   * @brief 取得緩衝區是否滿足一個布林值。
   *
   * @return true 滿足。
   * @return false 不滿足。
   */
  virtual bool hasNextBoolean(void);

  /**
   * @brief 取得緩衝區是否滿足一個整數。
   *
   * @return true 滿足。
   * @return false 不滿足。
   */
  virtual bool hasNextInteger(void);

  /**
   * @brief 取得緩衝區是否滿足一行。
   *
   * @return true 滿足。
   * @return false 不滿足。
   */
  virtual bool hasNextLine(void);

  /**
   * @brief 取得煥沖區是否滿足一個字幅串。
   *
   * @return true 滿足。
   * @return false 不滿足。
   */
  virtual bool hasNextString(void);

  /**
   * @brief 取得下一個布林值。
   *
   * @param result 布林。
   * @return true 取得成功，從緩衝區推出一個布林值。
   * @return false 取得失敗，可能問題如下：
   */
  virtual bool nextBoolean(bool& result);

  /**
   * @brief 取得下一行。
   *
   * Tips.寫入時將會抹除string內原始資料，如不滿足需求將不會改變result內的內容。
   *
   * @param result 字幅串 。
   * @return true 取得成功，從緩衝區推出一行字幅串。
   * @return false 取得失敗，可能問題如下：
   *
   * - 緩衝區為空。
   * - 資料尚未滿足一行。
   */
  virtual bool nextLine(mframe::lang::Data& result);

  /**
   * @brief 取得下一個整數。
   *
   * @param result 整數。
   * @return true 取得成功，從緩存區推出一個整數。
   * @return false 取得失敗，可能問題如下：
   *
   * - 緩衝區為空。
   * - 資料格式不為整數。
   */
  virtual bool nextInteger(int& result);

  /**
   * @brief 取得下一個字元。
   *
   * @param result 字元。
   * @return true 取得成功，從緩存區推出一個字元。
   * @return false 取得失敗，緩衝區為空。
   */
  virtual bool nextChar(char& result);

  /**
   * @brief 取得下一個字幅串。
   *
   * Tips.寫入時將會抹除string內原始資料，如不滿足需求將不會改變result內的內容。
   *
   * @param result 字符串。
   * @return true 寫入字符串成功。
   * @return false 寫入字符串失敗，可能的原因為以下：
   *
   *  - result 可能為唯獨模式。
   *  - result 內有效空間不足進行寫入。請使用getNextLength()來判斷緩衝區內資料大於result有效空間。
   *  - 緩衝區內不滿足一個字符串的條件，因緩衝區尚未出現NextSymbol<'/r','/n','/t','/0',' '>。
   */
  virtual bool nextString(mframe::lang::Data& result);

  /**
   * @brief 跳躍直到發現指定字元。
   *
   * @param pattern 字元
   * @return int
   *
   *  - -1 : 緩衝區內並未找到pattern。
   *  - 0~ : 跳躍的字元數量。
   */
  virtual int skip(char pattern);

  /**
   * @brief 跳躍當前字幅串。
   *
   * @return int
   *
   *  - -1 : 緩衝區內不滿足一個字符串的條件，因緩衝區尚未出現NextSymbol<'/r','/n','/t','/0',' '>。
   *  - 0~ : 跳躍的字幅串字元數量。
   */
  virtual int skipNext(void);

  /**
   * @brief 跳躍當前行至下一行。
   *
   * @return int
   *
   *  - -1 : 緩衝區內不滿足一個字符串的條件，因緩衝區尚未出現NextLineSymbol<'/r','/n','/0'>。
   *  - 0~ : 跳躍的字幅串字元數量。
   */
  virtual int skipNextLine(void);

  /**
   * @brief 取得至下一個字幅串的字元數量
   *
   * @return int
   *
   *  - -1 : 緩衝區內不滿足一個字符串的條件，因緩衝區尚未出現NextSymbol<'/r','/n','/t','/0',' '>。
   *  - 0~ : 至下一個字幅串的字元數量。
   */
  virtual int getNextLength(void);

  /**
   * @brief 取得至下一行的字幅串數量
   *
   * @return int
   *
   *  - -1 : 緩衝區內不滿足一個字符串的條件，因緩衝區尚未出現NextSymbol<'/r','/n','/0'>。
   *  - 0~ : 至下一個字幅串的字元數量。
   */
  virtual int getNextLineLength(void);

  /**
   * @brief 取得緩衝區來源
   *
   * @return mframe::io::ReadBuffer&
   */
  virtual mframe::io::ReadBuffer& getReadBuffer(void);

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
 private:
  int skipNextLineSymbol(void);
  int skipNextSymbol(void);
};

/* ****************************************************************************************
 * End of file
 */

#endif /* UTIL_58A65E9B_2DCB_4DE5_9275_DE26DEE905BF */
