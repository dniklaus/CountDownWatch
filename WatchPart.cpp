/*
 * WatchPart.cpp
 *
 *  Created on: 01.07.2013
 *      Author: niklausd
 */

#include "WatchPartAdapter.h"
#include "WatchPart.h"

WatchPart::WatchPart(unsigned int maxCount)
: cMaxCount(maxCount)
, m_count(0)
, m_presetVal(0)
, m_isSelected(BTFALSE)
, m_adapter(0)
{ }

WatchPart::~WatchPart()
{ }

void WatchPart::attachAdapter(WatchPartAdapter* adapter)
{
  m_adapter = adapter;
}

WatchPartAdapter* WatchPart::adapter()
{
  return m_adapter;
}

void WatchPart::reset()
{
  m_count = 0;
}

void WatchPart::loadPreset()
{
  setCount(m_presetVal);
}

void WatchPart::storePreset()
{
  m_presetVal = m_count;
}

void WatchPart::setCount(unsigned int val)
{
  if (cMaxCount < val)
  {
    val = m_count;
  }
  m_count = val;
}

void WatchPart::tickUp()
{
  if (cMaxCount > m_count)
  {
    m_count++;
  }
  else
  {
    m_count = 0;
    if (0 != m_adapter)
    {
      m_adapter->carryOutUp();
    }
  }
}

void WatchPart::tickDn()
{
  if (0 < m_count)
  {
    m_count--;
  }
  else
  {
    m_count = cMaxCount;
    if (0 != m_adapter)
    {
      m_adapter->carryOutDn();
    }
  }
}
