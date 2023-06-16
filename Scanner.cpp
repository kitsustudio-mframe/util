/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */
#include "./Scanner.h"

//-----------------------------------------------------------------------------------------
#include "mframe.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */
using mframe::util::Scanner;

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

//-----------------------------------------------------------------------------------------
Scanner::Scanner(mframe::io::ReadBuffer& readBuffer) : mReadBuffer(readBuffer),
                                                       mIterator(readBuffer) {
  return;
}

//-----------------------------------------------------------------------------------------
Scanner::~Scanner(void) {
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override>
 */

/* ****************************************************************************************
 * Public Method
 */

//-----------------------------------------------------------------------------------------
bool Scanner::hasNext(void) {
  return (this->getNextLength() >= 0);
}

//-----------------------------------------------------------------------------------------
bool Scanner::hasNextChar(char ch) {
  this->mIterator.rewind();
  char c;
  while (this->mIterator.next(c)) {
    if (c == ch)
      return true;
  }

  return false;
}

//-----------------------------------------------------------------------------------------
bool Scanner::hasNextBoolean(void) {
  return Booleans::isBoolean(this->mIterator.rewind());
}

//-----------------------------------------------------------------------------------------
bool Scanner::hasNextInteger(void) {
  return Integers::isInteger(this->mIterator.rewind());
}

//-----------------------------------------------------------------------------------------
bool Scanner::hasNextLine(void) {
  return (this->getNextLineLength() >= 0);
}

//-----------------------------------------------------------------------------------------
bool Scanner::hasNextString(void) {
  return (this->getNextLength() >= 0);
}

//-----------------------------------------------------------------------------------------
bool Scanner::nextBoolean(bool& result) {
  bool status = Booleans::parseBoolean(result, this->mIterator.rewind());

  if (status)
    this->skipNext();

  return status;
}

//-----------------------------------------------------------------------------------------
bool Scanner::nextLine(Data& result) {
  int length = this->getNextLineLength();
  if (length < 0)
    return false;

  if (result.isReadOnly())
    return false;

  if (length >= result.length())
    return false;

  int status = this->mReadBuffer.poll(result, length, false);

  // write 0x00 to end;
  *result.pointer(status, Class<char>::cast()) = 0x00;

  this->skipNextLineSymbol();
  return true;
}

//-----------------------------------------------------------------------------------------
bool Scanner::nextInteger(int& result) {
  this->mIterator.rewind();

  if (!Integers::parseInteger(result, this->mIterator))
    return false;

  this->skipNext();
  return true;
}

//-----------------------------------------------------------------------------------------
bool Scanner::nextChar(char& result) {
  return this->mReadBuffer.pollByte(result, false);
}

//-----------------------------------------------------------------------------------------
bool Scanner::nextString(Data& result) {
  int length = this->getNextLength();
  if (length < 0)
    return false;

  if (result.isReadOnly())
    return false;

  if (length >= result.length())
    return false;

  int status = this->mReadBuffer.poll(result, length, false);

  // write 0x00 to end;
  *result.pointer(status, Class<char>::cast()) = 0x00;

  this->skipNextSymbol();
  return true;
}

//-----------------------------------------------------------------------------------------
int Scanner::skip(char pattern) {
  int result = 0;
  this->mIterator.rewind();
  char c;

  while (this->mIterator.next(c)) {
    if (c == pattern)
      return this->mReadBuffer.skip(result);

    ++result;
  }

  return -1;
}

//-----------------------------------------------------------------------------------------
int Scanner::skipNext(void) {
  int result = this->getNextLength();
  if (result < 0)
    return 0;

  this->mReadBuffer.skip(result);
  this->skipNextSymbol();
  return result;
}

//-----------------------------------------------------------------------------------------
int Scanner::skipNextLine(void) {
  int result = this->getNextLineLength();
  if (result < 0)
    return 0;

  this->mReadBuffer.skip(result);
  this->skipNextLineSymbol();
  return result;
}

//-----------------------------------------------------------------------------------------
int Scanner::getNextLength(void) {
  int result = 0;
  this->mIterator.rewind();
  char c;

  while (this->mIterator.next(c)) {
    if (Character::isNextSymbol(c))
      return result;

    ++result;
  }

  return -1;
}

//-----------------------------------------------------------------------------------------
int Scanner::getNextLineLength(void) {
  int result = 0;
  this->mIterator.rewind();
  char c;

  while (this->mIterator.next(c)) {
    if (Character::isNextLineSymbol(c))
      return result;

    ++result;
  }

  return -1;
}

//-----------------------------------------------------------------------------------------
mframe::io::ReadBuffer& Scanner::getReadBuffer(void) {
  return this->mReadBuffer;
}
/* ****************************************************************************************
 * Protected Method <Static>
 */

/* ****************************************************************************************
 * Protected Method <Override>
 */

/* ****************************************************************************************
 * Protected Method
 */

/* ****************************************************************************************
 * Private Method
 */
//-----------------------------------------------------------------------------------------
int Scanner::skipNextSymbol(void) {
  this->mIterator.rewind();
  int result = 0;
  char c;
  while (this->mIterator.next(c)) {
    if (!Character::isNextSymbol(c))
      break;

    ++result;
  }

  if (result)
    return this->mReadBuffer.skip(result);

  return result;
}

//-----------------------------------------------------------------------------------------
int Scanner::skipNextLineSymbol(void) {
  this->mIterator.rewind();
  int i = 0;
  char c;
  while (this->mIterator.next(c)) {
    if (!Character::isNextLineSymbol(c))
      break;

    ++i;
  }

  if (i)
    this->mReadBuffer.skip(i);

  return i;
}

/* ****************************************************************************************
 * End of file
 */
