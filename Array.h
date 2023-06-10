/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef MFRAME_FCCC3E6F_E524_4464_BA6F_FF9492970DA8
#define MFRAME_FCCC3E6F_E524_4464_BA6F_FF9492970DA8

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./../lang/Memory.h"
#include "./../util/ArrayPrototype.h"

/* ******************************************************************************
 * Namespace
 */
namespace util {
  template <typename E>
  class Array;
}

/* ******************************************************************************
 * Class/Interface/Struct
 */
template <typename E>
class util::Array : public util::ArrayPrototype {
  /* ****************************************************************************
   * Variable <Public>
   */

  /* ****************************************************************************
   * Variable <Protected>
   */

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
   * @brief Construct a new Array object
   *
   * @param memory
   */
  Array(const lang::Memory& memory) : util::ArrayPrototype(memory, sizeof(E)) {
    return;
  }

  /**
   * @brief Construct a new Array object
   *
   * @param e
   * @param length
   */
  Array(E* e, size_t length) : util::ArrayPrototype(lang::Memory(e, sizeof(E) * length), sizeof(E)) {
    return;
  }

  /**
   * @brief Construct a new Array object
   *
   * @param e
   * @param length
   */
  Array(const E* e, size_t length) : util::ArrayPrototype(lang::Memory(e, sizeof(E) * length), sizeof(E)) {
    return;
  }

  /**
   * @brief Construct a new Array object
   *
   * @param length
   */
  Array(size_t length) : util::ArrayPrototype(length, sizeof(E)) {
    return;
  }

  /**
   * @brief Destroy the Array object
   *
   */
  virtual ~Array(void) override {
    return;
  }

  /* ****************************************************************************
   * Operator Method
   */
 public:
  /**
   * @brief
   *
   * @param index
   * @return E
   */
  E operator[](int index) const {
    return static_cast<E*>(this->pointer())[index];
  }

  /**
   * @brief
   *
   * @param index
   * @return E&
   */
  E& operator[](int index) {
    return static_cast<E*>(this->pointer())[index];
  }

  /* ****************************************************************************
   * Public Method <Static>
   */

  /* ****************************************************************************
   * Public Method <Override>
   */

  /* ****************************************************************************
   * Public Method
   */

  /* ****************************************************************************
   * Public Method <Inline>
   */
 public:
  /**
   * @brief
   * 返回此陣列的長度。
   *
   * @return uint32_t 由該對象表示的陣列的長度。
   */
  inline int length(void) const {
    return this->mElementLength;
  }

  /**
   * @brief
   * 返回此列表中指定元素的第一次出現的索引，如果此列表不包含元素，則返回-1。
   *
   * @param e - 要搜索的元素
   * @return int 此列表中指定元素的首次出現的索引，如果此列表不包含元素，則為-1
   */
  inline int indexOf(const E& e) const {
    return this->ArrayPrototype::indexOf(&e);
  }

  /**
   * @brief
   * 如果此列表包含指定的元素，則返回true。
   *
   * @param e - 要在此列表中存在的元素要測試的元素
   * @return true 如果此列表包含指定的元素
   */
  inline bool contains(const E& e) const {
    return (this->ArrayPrototype::indexOf(&e) != -1);
  }

  /* ****************************************************************************
   * Protected Method <Static>
   */

  /* ****************************************************************************
   * Protected Method <Override>
   */

  /* ****************************************************************************
   * Protected Method
   */

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

/* ******************************************************************************
 * End of file
 */

#endif /* MFRAME_FCCC3E6F_E524_4464_BA6F_FF9492970DA8 */
