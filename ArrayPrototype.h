/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef MFRAME_EC5AD114_2891_41FA_8DE3_9D5FAD422A07
#define MFRAME_EC5AD114_2891_41FA_8DE3_9D5FAD422A07

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./../lang/Memory.h"

/* ******************************************************************************
 * Namespace
 */
namespace mframe::util {
  class ArrayPrototype;
}  // namespace mframe::util

/* ******************************************************************************
 * Class/Interface/Struct
 */
class mframe::util::ArrayPrototype : public mframe::lang::Memory {
  /* ****************************************************************************
   * Variable <Public>
   */

  /* ****************************************************************************
   * Variable <Protected>
   */
 protected:
  int mElementSize;
  int mElementLength;

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
   * @brief Construct a new Array Prototype object
   *
   * @param memory
   * @param elementSize
   */
  ArrayPrototype(const mframe::lang::Memory& memory, int elementSize);

  /**
   * @brief Construct a new Array Prototype object
   *
   * @param length
   * @param elementSize
   */
  ArrayPrototype(int length, int elementSize);

  /**
   * @brief Destroy the Array Prototype object
   *
   */
  virtual ~ArrayPrototype(void) override;

  /* ****************************************************************************
   * Operator Method
   */

  /* ****************************************************************************
   * Public Method <Static>
   */

  /* ****************************************************************************
   * Public Method <Override>
   */

  /* ****************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief
   * 返回此陣列的長度。
   *
   * @return uint32_t 由該對象表示的陣列的長度。
   */
  int getElementLength(void) const;

  /**
   * @brief
   * 返回陣列元素的尺寸大小。
   *
   * @return int 元素的尺寸大小。
   */
  int getElementSize(void) const;

  /* ****************************************************************************
   * Protected Method <Static>
   */

  /* ****************************************************************************
   * Protected Method <Override>
   */

  /* ****************************************************************************
   * Protected Method
   */
 protected:
  using Memory::indexOf;

  /**
   * @brief
   * 返回此列表中指定元素的第一次出現的索引，如果此列表不包含元素，則返回-1。
   *
   * @param e - 要搜索的元素
   * @return int 此列表中指定元素的首次出現的索引，如果此列表不包含元素，則為-1
   */
  int indexOf(const void* element) const;

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

#endif /* MFRAME_EC5AD114_2891_41FA_8DE3_9D5FAD422A07 */
