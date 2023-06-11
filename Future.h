/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_858D7963_BBA9_4496_8D4B_B2D77E1330CC
#define MFRAME_858D7963_BBA9_4496_8D4B_B2D77E1330CC

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./../io/CompletionHandler.h"
#include "./../lang/Object.h"
#include "./../lang/Thread.h"

/* ******************************************************************************
 * Namespace
 */
namespace mframe::util {
  class Future;
}  // namespace mframe::util

/* ******************************************************************************
 * Class/struct/Struct/Enum
 */
class mframe::util::Future : public mframe::lang::Object,
                             public mframe::io::CompletionHandler<int, void*> {
  /* ****************************************************************************
   * Enum
   */
 public:
  enum struct Status : uint32_t {
    IDLE,
    WAIT,
    DONE_COMPLETED,
    DONE_FAILED
  };

  /* ****************************************************************************
   * Variable <Public>
   */

  /* ****************************************************************************
   * Variable <Protected>
   */

  /* ****************************************************************************
   * Variable <Private>
   */
 private:
  Status mStatus;
  mframe::lang::Thread* mThread;
  int mResult;

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
   * @brief Construct a new Future object
   *
   */
  Future(void);

  /**
   * @brief Destroy the Future object
   *
   */
  virtual ~Future(void) override;

  /* ****************************************************************************
   * Operator Method
   */

  /* ****************************************************************************
   * Public Method <Static>
   */

  /* ****************************************************************************
   * Public Method <Override> - mframe::lang::CompletionHandler<int ,void*>
   */
 public:
  /**
   * @brief
   *
   * @param result
   * @param attachment
   */
  virtual void completed(int result, void* attachment) override;

  /**
   * @brief
   *
   * @param exc
   * @param attachment
   */
  virtual void failed(void* exc, void* attachment) override;

  /* ****************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief
   *
   * @return true
   * @return false
   */
  bool setWait(void);

  /**
   * @brief
   *
   */
  void waitDone(void);

  /**
   * @brief
   *
   * @param timeout
   */
  void waitDone(int timeout);

  /**
   * @brief
   *
   * @return int
   */
  bool get(int& result);

  /**
   * @brief
   *
   * @param timeout
   * @return int
   */
  bool get(int& result, int timeout);

  /**
   * @brief
   *
   */
  void clear(void);

  /**
   * @brief
   *
   * @return true
   * @return false
   */
  bool isDone(void);

  /**
   * @brief
   *
   * @return true
   * @return false
   */
  bool isCompleted(void);

  /**
   * @brief
   *
   * @return true
   * @return false
   */
  bool isFailed(void);

  /**
   * @brief
   *
   * @return true
   * @return false
   */
  bool isIdle(void);

  /**
   * @brief
   *
   * @return true
   * @return false
   */
  bool isBusy(void);

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

#endif /* MFRAME_858D7963_BBA9_4496_8D4B_B2D77E1330CC */
