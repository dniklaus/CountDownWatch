/*
 * WatchFsmAdapter.h
 *
 *  Created on: 10.08.2013
 *      Author: niklausd
 */

#ifndef WATCHFSMADAPTER_H_
#define WATCHFSMADAPTER_H_

/*
 *
 */
class WatchFsmAdapter
{
public:
  WatchFsmAdapter();
  virtual ~WatchFsmAdapter();

  /**
   * FSM Actions
   */
  virtual void enabledTickAction() { }
  virtual void storePresetAction() { }
  virtual void loadPresetAction()  { }

  virtual void setSigSelAction()   { }

  virtual void setHrsSelAction()   { }
  virtual void setMinSelAction()   { }
  virtual void setSecSelAction()   { }
  virtual void clearSelAction()    { }

  virtual void decrSetSigAction()  { }
  virtual void incrSetSigAction()  { }

  virtual void decrSetHrsAction()  { }
  virtual void incrSetHrsAction()  { }

  virtual void decrSetMinAction()  { }
  virtual void incrSetMinAction()  { }

  virtual void decrSetSecAction()  { }
  virtual void incrSetSecAction()  { }

  virtual void startTimerAction(int timeMillis) { }

private: // forbidden default functions
  WatchFsmAdapter& operator = (const WatchFsmAdapter& );  // assignment operator
  WatchFsmAdapter(const WatchFsmAdapter& src);            // copy constructor
};

#endif /* WATCHFSMADAPTER_H_ */
