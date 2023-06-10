/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ******************************************************************************
 * Include
 */
#include "./ArrayPrototype.h"

//-------------------------------------------------------------------------------
#include "mframe.h"

/* ******************************************************************************
 * Using
 */
using lang::Memory;
using lang::Pointers;
using util::ArrayPrototype;

/* ******************************************************************************
 * Variable <Static>
 */

/* ******************************************************************************
 * Construct Method
 */

/* ******************************************************************************
 * Operator Method
 */

//-------------------------------------------------------------------------------
ArrayPrototype::ArrayPrototype(const Memory& memory, size_t elementSize) : Memory(memory) {
  this->mElementSize = static_cast<int>(elementSize);
  this->mElementLength = (this->length() / this->mElementSize);
  return;
}

//-------------------------------------------------------------------------------
ArrayPrototype::ArrayPrototype(size_t length, size_t elementSize) : Memory(length * elementSize) {
  this->mElementSize = static_cast<int>(elementSize);
  this->mElementLength = this->length() / static_cast<int>(elementSize);
}

//-------------------------------------------------------------------------------
ArrayPrototype::~ArrayPrototype(void) {
  return;
}

/* ******************************************************************************
 * Public Method <Static>
 */

/* ******************************************************************************
 * Public Method <Override>
 */

/* ******************************************************************************
 * Public Method
 */

//-------------------------------------------------------------------------------
int ArrayPrototype::getElementLength(void) const {
  return this->mElementLength;
}

//-------------------------------------------------------------------------------
int ArrayPrototype::getElementSize(void) const {
  return this->mElementSize;
}

//-------------------------------------------------------------------------------
int ArrayPrototype::indexOf(const void* element) const {
  int result = -1;

  for (int i = 0; i < this->mElementLength; i++) {
    const void* dst = &static_cast<uint8_t*>(this->pointer())[i * this->mElementSize];

    if (Pointers::compare(dst, element, this->mElementSize) != 0)
      continue;

    result = static_cast<int>(i);
    break;
  }

  return result;
}

/* ******************************************************************************
 * Protected Method <Static>
 */

/* ******************************************************************************
 * Protected Method <Override>
 */

/* ******************************************************************************
 * Protected Method
 */

/* ******************************************************************************
 * Private Method
 */

/* ******************************************************************************
 * End of file
 */
