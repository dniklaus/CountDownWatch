/**
 * Watch.h
 *
 *  Created on: 03.07.2013
 *      Author: niklausd
 */

#ifndef WATCH_H_
#define WATCH_H_

#include "basictypes.h"

class Timer;
class WatchPart;
class WatchFsm;

typedef struct
{
  bool sign;
  unsigned int h;
  unsigned int m;
  unsigned int s;
} wTime;

class Watch
{
public:
  Watch();
  virtual ~Watch();

  // system tick
  void tick();                          /// Watch clock stimulus, call this on a regular base, i.e. every 10 ms

  // direct time adjustment access methods
  void setSig(unsigned int isSignSet);  /// Set watch part "sign"
  void setHrs(unsigned int count);      /// Set watch part "hours"
  void setMin(unsigned int count);      /// Set watch part "minutes"
  void setSec(unsigned int count);      /// Set watch part "seconds"


  // control events
  void run();                           /// Start/continue the counting down/up
  void stop();                          /// Stop the counting
  void load();                          /// Load preset value (effective in stopped mode only)
  void store();                         /// Store current value as the preset value (effective in stopped mode only)
  void partSelUp();                     ///
  void partSelDn();
  void incrSet();
  void decrSet();


  // get info / status methods
  bool isSigSelected();
  bool isHrsSelected();
  bool isMinSelected();
  bool isSecSelected();
  const char* currentStateString();
  bool isRunning();
  bool isZero();
  wTime* getTime();

private:
  void preset();

private:
  Timer* m_oneSecTimer;

  WatchFsm* m_fsm;

  WatchPart* m_sig;
  WatchPart* m_hrs;
  WatchPart* m_min;
  WatchPart* m_sec;

  wTime* m_time;

private: // forbidden default functions
  Watch& operator = (const Watch& );  // assignment operator
  Watch(const Watch& src);            // copy constructor
};

#endif /* WATCH_H_ */
