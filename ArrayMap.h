/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_7EB43082_1596_43AB_9C6E_93D8D36DE60D
#define MFRAME_7EB43082_1596_43AB_9C6E_93D8D36DE60D

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "./../util/ArrayMapPrototype.h"

/* ****************************************************************************************
 * Namespace
 */
namespace util {
  template <class K, class V>
  class ArrayMap;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
template <class K = lang::Interface, class V = lang::Interface>
class util::ArrayMap : public util::ArrayMapPrototype, public util::Map<K, V> {
  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */

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
   * @brief Construct a new Array Map object
   *
   * @param memory
   */
  ArrayMap(const lang::Memory& memory) : ArrayMapPrototype(memory) {
    return;
  }

  /**
   * @brief Construct a new Array Map object
   *
   * @param size
   */
  ArrayMap(int size) : ArrayMapPrototype(size) {
    return;
  }

  /**
   * @brief Destroy the Array Map object
   *
   */
  virtual ~ArrayMap(void) override {
    return;
  }

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - lang::Iterable<E>
   */
 public:
  virtual bool peekIndex(int index, V*& result) override {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wundefined-reinterpret-cast"

    return ArrayMapPrototype::peekIndex(index, reinterpret_cast<void*&>(result));

#pragma clang diagnostic pop
  }

  /* **************************************************************************************
   * Public Method <Override> - lang::Collection<E>
   */
 public:
  virtual void clear(void) override {
    ArrayMapPrototype::clear();
  }

  virtual bool isEmpty(void) const override {
    return ArrayMapPrototype::isEmpty();
  }

  virtual int size(void) const override {
    return ArrayMapPrototype::size();
  }

  /* **************************************************************************************
   * Public Method <Override> - util::Map<V>
   */
 public:
  virtual bool containsKey(K& key) const override {
    return ArrayMapPrototype::prototypeContainsKey(key);
  }

  virtual bool containsValue(V* value) const override {
    return ArrayMapPrototype::prototypeContainsValue(value);
  }

  virtual V* get(K& key) const override {
    return reinterpret_cast<V*>(ArrayMapPrototype::prototypeGet(key));
  }

  virtual V* put(K& key, V* value) override {
    return reinterpret_cast<V*>(ArrayMapPrototype::prototypePut(key, value));
  }

  virtual V* remove(K& key) override {
    return reinterpret_cast<V*>(ArrayMapPrototype::prototypeRemove(key));
  }

  virtual V* replace(K& key, V* value) override {
    return reinterpret_cast<V*>(ArrayMapPrototype::prototypeReplace(key, value));
  }

  /* **************************************************************************************
   * Public Method
   */

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
 private:
  using util::ArrayMapPrototype::peekIndex;
};

/* ****************************************************************************************
 * End of file
 */

#endif /* MFRAME_7EB43082_1596_43AB_9C6E_93D8D36DE60D */
