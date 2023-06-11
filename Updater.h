/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_CF8A21F0_A644_4EE4_A29D_B76F28A9FD43
#define MFRAME_CF8A21F0_A644_4EE4_A29D_B76F28A9FD43

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./../lang/Interface.h"

/* ******************************************************************************
 * Namespace
 */
namespace mframe::lang {
  struct Updater;
}  // namespace mframe::lang

/* ******************************************************************************
 * Class/Interface/Struct/Enum
 */
struct mframe::lang::Updater : public virtual mframe::lang::Interface {
  /* ****************************************************************************
   * Method
   */

  /**
   * @brief 更新資源
   *
   * @return true 開始嘗試更新成功
   * @return false 開始嘗試更新失敗
   */
  virtual bool update(void) abstract;

  /**
   * @brief 是否正在更新
   *
   * @return true 正在更新中
   * @return false 等待更新
   */
  virtual bool isUpdating(void) abstract;
};

/* ******************************************************************************
 * End of file
 */

#endif /* MFRAME_CF8A21F0_A644_4EE4_A29D_B76F28A9FD43 */
