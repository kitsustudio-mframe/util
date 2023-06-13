/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef MFRAME_BBEA45DB_2443_4AD0_8532_619E2BDE4831
#define MFRAME_BBEA45DB_2443_4AD0_8532_619E2BDE4831

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./../lang/Consumer.h"
#include "./../util/Array.h"
#include "./../util/Collection.h"

/* ******************************************************************************
 * Namespace
 */
namespace mframe::util {
  class ArrayQueuePrototype;
}  // namespace mframe::util

/* ******************************************************************************
 * Class Object
 */
class mframe::util::ArrayQueuePrototype : public mframe::util::Array<void*>,
                                          public mframe::util::Collection<void*> {
  /* ****************************************************************************
   * Subclass
   */

  /* ****************************************************************************
   * Variable <Public>
   */

  /* ****************************************************************************
   * Variable <Protected>
   */
 protected:
  uint16_t mHead;
  uint16_t mTail;
  bool mEmpty;

  /* ****************************************************************************
   * Variable <Private>
   */

  /* ****************************************************************************
   * Abstract method <Public>
   */

  /* ****************************************************************************
   * Abstract method <Protected>
   */

  /* ****************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Array Queue Prototype object
   *
   * @param memory
   */
  ArrayQueuePrototype(const mframe::lang::Memory& memory);

  /**
   * @brief Construct a new Array Queue Prototype object
   *
   * @param size
   */
  ArrayQueuePrototype(int size);

  /**
   * @brief Destroy the Array Queue Prototype object
   *
   */
  virtual ~ArrayQueuePrototype(void) override;

  /* ****************************************************************************
   * Operator Method
   */

  /* ****************************************************************************
   * Public Method <Static>
   */

  /* ****************************************************************************
   * Public Method <Override> - mframe::util::Collection<void*>
   */
 public:
  virtual void clear(void) override;

  virtual bool isEmpty(void) const override;

  virtual int size(void) const override;

  /* ****************************************************************************
   * Public Method <Override> - mframe::lang::Iterable<void*>
   */
 public:
  virtual bool peekIndex(int index, void*& result) override;

  /* ****************************************************************************
   * Public Method
   */

  /* ****************************************************************************
   * Public Method <Inline>
   */
 public:
  /**
   * @brief
   *
   * @return true
   * @return false
   */
  inline bool isFull(void) const {
    return ((this->mHead == this->mTail) && (!this->mEmpty));
  }

  /* ****************************************************************************
   * Protected Method <Static>
   */

  /* ****************************************************************************
   * Protected Method <Override> - mframe::lang::Memroy
   */

  /* ****************************************************************************
   * Protected Method
   */
 protected:
  /**
   * @brief
   *
   * @param pointer
   * @return true
   * @return false
   */
  bool offerPointer(void* pointer);

  /**
   * @brief
   *
   * @return void*
   */
  void* pollPointer(void);

  /**
   * @brief
   *
   * @return void*
   */
  void* peekPointer(void);

  /**
   * @brief
   *
   * @param attachment
   * @param action
   */
  void foreachPrototype(mframe::lang::Consumer<void*>& action) const;

  /* ****************************************************************************
   * Private Method <Static>
   */

  /* ****************************************************************************
   * Private Method <Override>
   */

  /* ****************************************************************************
   * Private Method
   */
};

/* *******************************************************************************
 * End of file
 */

#endif /* MFRAME_BBEA45DB_2443_4AD0_8532_619E2BDE4831 */
