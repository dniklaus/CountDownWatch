/*
 * WatchPartAdapter.cpp
 *
 *  Created on: 02.07.2013
 *      Author: niklausd
 */

#include "WatchPart.h"
#include "WatchPartAdapter.h"

WatchPartAdapter::WatchPartAdapter(WatchPart* higherOrderWatchPart)
: m_higherOrderWatchPart(higherOrderWatchPart)
{ }

WatchPartAdapter::~WatchPartAdapter()
{ }

void WatchPartAdapter::carryOutUp()
{
  if (0 != m_higherOrderWatchPart)
  {
    m_higherOrderWatchPart->tickUp();
  }
}

void WatchPartAdapter::carryOutDn()
{
  if (0 != m_higherOrderWatchPart)
  {
    m_higherOrderWatchPart->tickDn();
  }
}

