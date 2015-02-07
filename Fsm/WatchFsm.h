/*
 * Fsm.h
 *
 *  Created on: 07.08.2013
 *      Author: niklausd
 */

#ifndef FSM_H_
#define FSM_H_

class WatchFsmState;
class WatchFsmAdapter;

class WatchFsm
{
public:
  WatchFsm();
  virtual ~WatchFsm();

  void changeState(WatchFsmState* state);

  WatchFsmState* state();
  WatchFsmAdapter* adapter();
  void attachAdapter(WatchFsmAdapter* adapter);
  /**
   * FSM Events
   */
  void run();
  void stop();
  void store();
  void load();
  void tick();
  void partSelUp();
  void partSelDn();
  void incrSet();
  void decrSet();

private:
  WatchFsmAdapter* m_adapter;
  WatchFsmState* m_state;

private: // forbidden default functions
  WatchFsm& operator = (const WatchFsm& );  // assignment operator
  WatchFsm(const WatchFsm& src);            // copy constructor
};

#endif /* FSM_H_ */
