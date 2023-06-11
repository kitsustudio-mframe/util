/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_B378C414_2010_4F0A_BB93_F70AA7B4CD87
#define MFRAME_B378C414_2010_4F0A_BB93_F70AA7B4CD87

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "./../lang/Consumer.h"
#include "./../lang/Iterable.h"

/* ****************************************************************************************
 * Namespace
 */
namespace mframe::util {
  template <class E>
  class Iterator;
}  // namespace mframe::util

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
template <class E>
class mframe::util::Iterator : public mframe::lang::Object,
                               public mframe::lang::Iterable<E> {
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
  Iterable<E>& mIterable;
  int mIndex;

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
   * @brief Construct a new Iterator object
   *
   * @param iterable
   */
  Iterator(Iterable<E>& iterable) : mIterable(iterable) {
    this->mIndex = 0;
    return;
  }

  /**
   * @brief Destroy the Iterator object
   *
   */
  virtual ~Iterator(void) override {
    return;
  }

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mframe::lang::Iterable<E>
   */
 public:
  virtual bool peekIndex(int index, E& result) override {
    return this->mIterable.peekIndex(index, result);
  }

  /* **************************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief 對每個剩餘元素執行給定的操作，直到所有元素都被處理或動作。
   *
   * 如果指定了該順序，則按迭代的順序執行操作。
   *
   * @param action
   */
  virtual void forEachRemaining(Consumer<E&>& action) {
    E e;
    while (this->next(e)) {
      action.accept(e);
    }
    return;
  }

  /**
   * @brief 如果迭代具有更多的元素，則返回true。
   *
   * 換句話說，如果next()返回true，則返回true
   *
   * @return true 如果迭代有更多的元素
   * @return false 迭代中已經沒有新的元素
   */
  virtual bool hasNext(void) {
    E cache;
    return this->mIterable.peekIndex(this->mIndex, cache);
  }

  /**
   * @brief 返回迭代中的下一個元素。
   *
   * @param result 結果
   * @return true 返回成功
   * @return false 返回失敗，已迭代至尾端
   */
  virtual bool next(E& result) {
    bool status = this->mIterable.peekIndex(this->mIndex, result);
    if (status)
      ++this->mIndex;

    return status;
  }

  /**
   * @brief 重設此迭代器，將指針歸零可從同重新訪問
   *
   */
  virtual Iterator<E>& reset(void) {
    this->mIndex = 0;
    return *this;
  }

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

#endif /* MFRAME_B378C414_2010_4F0A_BB93_F70AA7B4CD87 */
