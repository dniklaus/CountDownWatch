/*
 * WatchPartAdapter.h
 *
 *  Created on: 02.07.2013
 *      Author: niklausd
 */

#ifndef WATCHPARTADAPTER_H_
#define WATCHPARTADAPTER_H_

class WatchPart;

class WatchPartAdapter
{
public:
  WatchPartAdapter(WatchPart* higherOrderWatchPart);
  virtual ~WatchPartAdapter();

  void carryOutUp();
  void carryOutDn();

private:
  WatchPart* m_higherOrderWatchPart;

private: // forbidden default functions
  WatchPartAdapter& operator = (const WatchPartAdapter& );  // assignment operator
  WatchPartAdapter(const WatchPartAdapter& src);            // copy constructor
};

#endif /* WATCHPARTADAPTER_H_ */
