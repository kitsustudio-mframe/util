/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef MFRAME_BFC82B3D_EF2A_4C50_AC22_04B947DCE669
#define MFRAME_BFC82B3D_EF2A_4C50_AC22_04B947DCE669

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./../util/Collection.h"

/* ******************************************************************************
 * Namespace
 */
namespace lang {
  template <typename E>
  struct Queue;
}

/* ******************************************************************************
 * Class/Interface/Struct
 */
template <typename E>
struct lang::Queue : public util::Collection<E*> {
  /* ****************************************************************************
   * Method
   */

  /**
   * @brief
   * 如果在不違反容量限制的情況下立即執行，則將指定的元素插入到此隊列中。
   * 當使用容量限制隊列時，此方法通常優於 add(E) ，這可能無法僅通過拋出異常來插入元素。
   *
   * @param e - 要添加的元素
   * @return true如果元素被添加到這個隊列，否則 false
   */
  virtual bool offer(E* e) abstract;

  /**
   * @brief
   * 檢索並刪除此隊列的頭，如果此隊列為空，則返回null。
   *
   * @return E* - 這個隊列的頭部或者null，如果這個隊列是空的
   */
  virtual E* poll(void) abstract;

  /**
   * @brief
   * 檢索但不刪除此隊列的頭部，如果此隊列為空，則返回 null 。
   *
   * @return E* - 這個隊列的頭部或者null，如果這個隊列是空的
   */
  virtual E* peek(void) abstract;
};

/* *******************************************************************************
 * End of file
 */

#endif /* MFRAME_BFC82B3D_EF2A_4C50_AC22_04B947DCE669 */
