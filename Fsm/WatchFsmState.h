/*
 * WatchFsmState.h
 *
 *  Created on: 07.08.2013
 *      Author: niklausd
 */

#ifndef WATCHFSMSTATE_H_
#define WATCHFSMSTATE_H_

class WatchFsm;

class WatchFsmState
{
public:
  WatchFsmState() { }
  virtual ~WatchFsmState() { }

  virtual void runEvt(WatchFsm* fsm) { }
  virtual void stopEvt(WatchFsm* fsm) { }
  virtual void tickEvt(WatchFsm* fsm) { }
  virtual void partSelUpEvt(WatchFsm* fsm) { }
  virtual void partSelDnEvt(WatchFsm* fsm) { }
  virtual void storePresetEvt(WatchFsm* fsm) { }
  virtual void loadPresetEvt(WatchFsm* fsm) { }
  virtual void incrSetEvt(WatchFsm* fsm) { }
  virtual void decrSetEvt(WatchFsm* fsm) { }

  virtual void entry(WatchFsm* fsm) { }

  virtual const char* toString() = 0;

private: // forbidden default functions
  WatchFsmState& operator = (const WatchFsmState& );  // assignment operator
  WatchFsmState(const WatchFsmState& src);            // copy constructor
};

//-----------------------------------------------------------------------------

class WatchFsmStateStopped: public WatchFsmState
{
public:
  static WatchFsmState* Instance();
  virtual ~WatchFsmStateStopped() { }

  void runEvt(WatchFsm* fsm);
  void storePresetEvt(WatchFsm* fsm);
  void loadPresetEvt(WatchFsm* fsm);
  void partSelUpEvt(WatchFsm* fsm);
  void partSelDnEvt(WatchFsm* fsm);

  const char* toString();

private:
  WatchFsmStateStopped() { }

private:
  static WatchFsmState* s_instance;

private: // forbidden default functions
  WatchFsmStateStopped& operator = (const WatchFsmStateStopped& );  // assignment operator
  WatchFsmStateStopped(const WatchFsmStateStopped& src);            // copy constructor
};

//-----------------------------------------------------------------------------

class WatchFsmStateSetSig: public WatchFsmState
{
public:
  static WatchFsmState* Instance();
  virtual ~WatchFsmStateSetSig() { }

  void runEvt(WatchFsm* fsm);
  void stopEvt(WatchFsm* fsm);
  void partSelDnEvt(WatchFsm* fsm);
  void incrSetEvt(WatchFsm* fsm);
  void decrSetEvt(WatchFsm* fsm);

  void entry(WatchFsm* fsm);

  const char* toString();

private:
  WatchFsmStateSetSig() { }

private:
  static WatchFsmState* s_instance;

private: // forbidden default functions
  WatchFsmStateSetSig& operator = (const WatchFsmStateSetSig& );  // assignment operator
  WatchFsmStateSetSig(const WatchFsmStateSetSig& src);            // copy constructor
};

//-----------------------------------------------------------------------------

class WatchFsmStateSetHrs: public WatchFsmState
{
public:
  static WatchFsmState* Instance();
  virtual ~WatchFsmStateSetHrs() { }

  void runEvt(WatchFsm* fsm);
  void stopEvt(WatchFsm* fsm);
  void partSelUpEvt(WatchFsm* fsm);
  void partSelDnEvt(WatchFsm* fsm);
  void incrSetEvt(WatchFsm* fsm);
  void decrSetEvt(WatchFsm* fsm);

  void entry(WatchFsm* fsm);

  const char* toString();

private:
  WatchFsmStateSetHrs() { }

private:
  static WatchFsmState* s_instance;

private: // forbidden default functions
  WatchFsmStateSetHrs& operator = (const WatchFsmStateSetHrs& );  // assignment operator
  WatchFsmStateSetHrs(const WatchFsmStateSetHrs& src);            // copy constructor
};

//-----------------------------------------------------------------------------

class WatchFsmStateSetMin: public WatchFsmState
{
public:
  static WatchFsmState* Instance();
  virtual ~WatchFsmStateSetMin() { }

  void runEvt(WatchFsm* fsm);
  void stopEvt(WatchFsm* fsm);
  void partSelUpEvt(WatchFsm* fsm);
  void partSelDnEvt(WatchFsm* fsm);
  void incrSetEvt(WatchFsm* fsm);
  void decrSetEvt(WatchFsm* fsm);

  void entry(WatchFsm* fsm);

  const char* toString();

private:
  WatchFsmStateSetMin() { }

private:
  static WatchFsmState* s_instance;

private: // forbidden default functions
  WatchFsmStateSetMin& operator = (const WatchFsmStateSetMin& );  // assignment operator
  WatchFsmStateSetMin(const WatchFsmStateSetMin& src);            // copy constructor
};

//-----------------------------------------------------------------------------

class WatchFsmStateSetSec: public WatchFsmState
{
public:
  static WatchFsmState* Instance();
  virtual ~WatchFsmStateSetSec() { }

  void runEvt(WatchFsm* fsm);
  void stopEvt(WatchFsm* fsm);
  void partSelUpEvt(WatchFsm* fsm);
  void incrSetEvt(WatchFsm* fsm);
  void decrSetEvt(WatchFsm* fsm);

  void entry(WatchFsm* fsm);

  const char* toString();

private:
  WatchFsmStateSetSec() { }

private:
  static WatchFsmState* s_instance;

private: // forbidden default functions
  WatchFsmStateSetSec& operator = (const WatchFsmStateSetSec& );  // assignment operator
  WatchFsmStateSetSec(const WatchFsmStateSetSec& src);            // copy constructor
};

//-----------------------------------------------------------------------------

class WatchFsmStateRunning: public WatchFsmState
{
public:
  static WatchFsmState* Instance();
  virtual ~WatchFsmStateRunning() { }

  void stopEvt(WatchFsm* fsm);
  void tickEvt(WatchFsm* fsm);

  void entry(WatchFsm* fsm);

  const char* toString();

private:
  WatchFsmStateRunning() { }

private:
  static WatchFsmState* s_instance;

private: // forbidden default functions
  WatchFsmStateRunning& operator = (const WatchFsmStateRunning& );  // assignment operator
  WatchFsmStateRunning(const WatchFsmStateRunning& src);            // copy constructor
};

//-----------------------------------------------------------------------------

#endif /* WATCHFSMSTATE_H_ */
