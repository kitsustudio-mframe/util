/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef MFRAME_B4F9BAD4_2126_4397_B252_0E3E47A7DA8F
#define MFRAME_B4F9BAD4_2126_4397_B252_0E3E47A7DA8F

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./../lang/Consumer.h"
#include "./../lang/Memory.h"
#include "./../util/Array.h"
#include "./../util/Collection.h"

/* ******************************************************************************
 * Namespace
 */
namespace mframe::util {
  struct Pool;
}  // namespace mframe::util

/* ******************************************************************************
 * Class/Interface/Struct
 */
struct mframe::util::Pool : public mframe::util::Collection<mframe::lang::Memory> {
  /* ****************************************************************************
   * Method
   */

  /**
   * @brief Returns this pool element size of byte
   *
   * @return uint32_t element size of byte.
   */
  virtual uint32_t elementSize(void) const abstract;

  /**
   * @brief Returns this pool's capacity.
   *
   * @return uint32_t The capacity of this pool.
   */
  virtual uint32_t capacity(void) const abstract;

  /**
   * @brief Alloc memory from pool.
   *
   * @return void* element pointer if pool not full, otherwise null pointer.
   */
  virtual void* alloc(void) abstract;

  /**
   * @brief
   *
   * @return mframe::lang::Memory
   */
  virtual mframe::lang::Memory allocMemory(void) abstract;

  /**
   * @brief Alloc memory from pool and copy element.
   *
   * @param elenemt Element pointer.
   * @return void* element pointer if pool not full, otherwise null pointer.
   */
  virtual void* add(const void* elenemt) abstract;

  /**
   * @brief Free this element memory.
   *
   * @param element Element pointer.
   * @return true this poll found element and remove.
   * @return false element not found in this pool.
   */
  virtual bool remove(void* element) abstract;
};

/* *******************************************************************************
 * End of file
 */

#endif /* MFRAME_B4F9BAD4_2126_4397_B252_0E3E47A7DA8F */
