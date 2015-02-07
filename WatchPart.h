/*
 * WatchPart.h
 *
 *  Created on: 01.07.2013
 *      Author: niklausd
 */

#ifndef WATCHPART_H_
#define WATCHPART_H_

#include "basictypes.h"

class WatchPartAdapter;

class WatchPart
{
public:
  WatchPart(unsigned int maxCount);
  virtual ~WatchPart();

public:
  void tickUp();
  void tickDn();

  unsigned int getVal() const { return m_count; }
  unsigned int getMaxVal() const { return cMaxCount; }
  bool isZero() const { return (0 == m_count); }

  void setCount(unsigned int val);
  void reset();
  void loadPreset();
  void storePreset();

  void attachAdapter(WatchPartAdapter* adapter);
  WatchPartAdapter* adapter();

  void setIsSelected(BTBool isSelected) { m_isSelected = isSelected; }
  BTBool isSelected() { return m_isSelected; }

private:
  const unsigned int cMaxCount;
  unsigned int m_count;
  unsigned int m_presetVal;
  BTBool m_isSelected;
  WatchPartAdapter* m_adapter;

private: // forbidden default functions
  WatchPart& operator = (const WatchPart& );  // assignment operator
  WatchPart(const WatchPart& src);            // copy constructor
};


class WatchPart_Sec : public WatchPart
{
public:
  WatchPart_Sec()
  : WatchPart(59)
  {  };

private: // forbidden default functions
  WatchPart_Sec& operator = (const WatchPart_Sec& );  // assignment operator
  WatchPart_Sec(const WatchPart_Sec& src);            // copy constructor
};

class WatchPart_Min : public WatchPart
{
public:
  WatchPart_Min()
  : WatchPart(59)
  {  };

private: // forbidden default functions
  WatchPart_Min& operator = (const WatchPart_Min& );  // assignment operator
  WatchPart_Min(const WatchPart_Min& src);            // copy constructor
};

class WatchPart_Hrs : public WatchPart
{
public:
  WatchPart_Hrs()
  : WatchPart(23)
  {  };

private: // forbidden default functions
  WatchPart_Hrs& operator = (const WatchPart_Hrs& );  // assignment operator
  WatchPart_Hrs(const WatchPart_Hrs& src);            // copy constructor
};

class WatchPart_Sig : public WatchPart
{
public:
  WatchPart_Sig()
  : WatchPart(1)
  {  };

private: // forbidden default functions
  WatchPart_Sig& operator = (const WatchPart_Sig& );  // assignment operator
  WatchPart_Sig(const WatchPart_Sig& src);            // copy constructor
};

#endif /* WATCHPART_H_ */
