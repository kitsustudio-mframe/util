/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ******************************************************************************
 * Include
 */
#include "./ArrayQueuePrototype.h"

//-------------------------------------------------------------------------------
#include "mframe.h"

/* ******************************************************************************
 * Macro
 */

/* ******************************************************************************
 * Using
 */
using mframe::util::ArrayQueuePrototype;

//-------------------------------------------------------------------------------
using mframe::lang::Memory;
using mframe::util::ArrayPrototype;

/* ******************************************************************************
 * Variable <Static>
 */

/* ******************************************************************************
 * Construct Method
 */

//-------------------------------------------------------------------------------
ArrayQueuePrototype::ArrayQueuePrototype(const Memory& memory) : Array<void*>(memory) {
  this->clear();
  return;
}

//-------------------------------------------------------------------------------
ArrayQueuePrototype::ArrayQueuePrototype(uint32_t size) : Array<void*>(size) {
  this->clear();
  return;
}

//-------------------------------------------------------------------------------
ArrayQueuePrototype::~ArrayQueuePrototype(void) {
  this->clear();
  return;
}

/* ******************************************************************************
 * Operator Method
 */

/* ******************************************************************************
 * Public Method <Static>
 */

/* ******************************************************************************
 * Public Method <Override> - mframe::lang::Collection<void*>
 */

//-------------------------------------------------------------------------------
void ArrayQueuePrototype::clear(void) {
  this->mHead = 0;
  this->mTail = 0;
  this->mEmpty = true;
  return;
}

//-------------------------------------------------------------------------------
bool ArrayQueuePrototype::isEmpty(void) const {
  return this->mEmpty;
}

//-------------------------------------------------------------------------------
int ArrayQueuePrototype::size(void) const {
  if (this->mEmpty)
    return 0;

  if (this->isFull())
    return this->mElementLength;

  if (this->mTail > this->mHead)
    return this->mTail - this->mHead;

  else
    return (this->mElementLength - this->mHead) + this->mTail;
}

/* ******************************************************************************
 * Public Method <Override> - mframe::lang::Iterable<void*>
 */

//-------------------------------------------------------------------------------
bool ArrayQueuePrototype::peekIndex(int index, void*& result) {
  if (index >= this->size())
    return false;

  if (index < 0)
    return false;

  index += this->mHead;
  if (index >= this->mElementLength)
    index -= this->mElementLength;

  result = (*this)[index];

  return true;
}

/* ******************************************************************************
 * Public Method
 */

/* ******************************************************************************
 * Protected Method <Static>
 */

/* ******************************************************************************
 * Protected Method <Override>
 */

/* ******************************************************************************
 * Protected Method
 */

//-------------------------------------------------------------------------------
bool ArrayQueuePrototype::offerPointer(void* pointer) {
  if (this->isFull())
    return false;

  this->mEmpty = false;

  void** p = static_cast<void**>(this->Pointer::pointer());
  p[this->mHead] = pointer;

  ++this->mHead;
  if (this->mHead >= this->mElementLength)
    this->mHead = 0;

  return true;
}

//-------------------------------------------------------------------------------
void* ArrayQueuePrototype::pollPointer(void) {
  void* result = this->peekPointer();
  if (result == nullptr)
    return nullptr;

  ++this->mTail;
  if (this->mTail >= this->mElementLength)
    this->mTail = 0;

  if (this->mHead == this->mTail)
    this->mEmpty = true;

  return result;
}

//-------------------------------------------------------------------------------
void* ArrayQueuePrototype::peekPointer(void) {
  if (this->isEmpty())
    return nullptr;

  void** p = static_cast<void**>(this->Pointer::pointer());

  return p[this->mTail];
}

/* ******************************************************************************
 * Private Method
 */

/* ******************************************************************************
 * End of file
 */
