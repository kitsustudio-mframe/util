/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_2564A55F_C25D_43D2_ADD6_BE125D634CFB
#define MFRAME_2564A55F_C25D_43D2_ADD6_BE125D634CFB

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "./../lang/Memory.h"
#include "./../util/Map.h"

/* ****************************************************************************************
 * Namespace
 */
namespace util {
  class ArrayMapPrototype;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
class util::ArrayMapPrototype : public lang::Object,
                                public util::Collection<void*> {
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
  lang::Memory mMemory;
  int mSize;

  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
 protected:
  /**
   * @brief Construct a new Array Map Prototype object
   *
   * @param memory 緩存來源
   */
  ArrayMapPrototype(const lang::Memory& memory);

  /**
   * @brief Destroy the Array Map Prototype object
   *
   * @param size 元素數量
   */
  ArrayMapPrototype(int size);

  /**
   * @brief Destroy the Array Map Prototype object
   *
   */
  virtual ~ArrayMapPrototype(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - lang::Iterable<void*>
   */
 public:
  virtual bool peekIndex(int index, void*& result) override;

  /* **************************************************************************************
   * Public Method <Override> - lang::Collection<void*>
   */
 public:
  virtual void clear(void) override;

  virtual bool isEmpty(void) const override;

  virtual int size(void) const override;

  /* **************************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief 返回此集合的容量
   *
   * @return int
   */
  int length(void) const;
  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override>
   */

  /* **************************************************************************************
   * Protected Method
   */
 protected:
  bool prototypeContainsKey(Interface& key) const;

  bool prototypeContainsValue(void* value) const;

  void* prototypeGet(Interface& key) const;

  void* prototypePut(Interface& key, void* value);

  void* prototypeRemove(Interface& key);

  void* prototypeReplace(Interface& key, void* value);
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

#endif /* MFRAME_2564A55F_C25D_43D2_ADD6_BE125D634CFB */
