/*
 * WatchFsmState.cpp
 *
 *  Created on: 07.08.2013
 *      Author: niklausd
 */

#include "WatchFsm.h"
#include "WatchFsmState.h"
#include "WatchFsmAdapter.h"


//-----------------------------------------------------------------------------

WatchFsmState* WatchFsmStateStopped::s_instance = 0;

WatchFsmState* WatchFsmStateStopped::Instance()
{
  if (0 == s_instance)
  {
    s_instance = new WatchFsmStateStopped();
  }
  return s_instance;
}

const char* WatchFsmStateStopped::toString()
{
  return "WatchFsmStateStopped";
}

void WatchFsmStateStopped::runEvt(WatchFsm* fsm)
{
  fsm->changeState(WatchFsmStateRunning::Instance());
}

void WatchFsmStateStopped::storePresetEvt(WatchFsm* fsm)
{
  WatchFsmAdapter* adapter = fsm->adapter();
  if (0 != adapter)
  {
    adapter->storePresetAction();
  }
}

void WatchFsmStateStopped::loadPresetEvt(WatchFsm* fsm)
{
  WatchFsmAdapter* adapter = fsm->adapter();
  if (0 != adapter)
  {
    adapter->loadPresetAction();
  }
}

void WatchFsmStateStopped::partSelUpEvt(WatchFsm* fsm)
{
  fsm->changeState(WatchFsmStateSetHrs::Instance());
}

void WatchFsmStateStopped::partSelDnEvt(WatchFsm* fsm)
{
  fsm->changeState(WatchFsmStateSetHrs::Instance());
}

//-----------------------------------------------------------------------------

WatchFsmState* WatchFsmStateSetSig::s_instance = 0;

WatchFsmState* WatchFsmStateSetSig::Instance()
{
  if (0 == s_instance)
  {
    s_instance = new WatchFsmStateSetSig();
  }
  return s_instance;
}

const char* WatchFsmStateSetSig::toString()
{
  return "WatchFsmStateSetSig";
}

void WatchFsmStateSetSig::entry(WatchFsm* fsm)
{
  WatchFsmAdapter* adapter = fsm->adapter();
  if (0 != adapter)
  {
    adapter->setSigSelAction();
  }
}

void WatchFsmStateSetSig::runEvt(WatchFsm* fsm)
{
  WatchFsmStateStopped::Instance()->runEvt(fsm);
}

void WatchFsmStateSetSig::stopEvt(WatchFsm* fsm)
{
  WatchFsmAdapter* adapter = fsm->adapter();
  if (0 != adapter)
  {
    adapter->clearSelAction();
  }
  fsm->changeState(WatchFsmStateStopped::Instance());
}

void WatchFsmStateSetSig::partSelDnEvt(WatchFsm* fsm)
{
  fsm->changeState(WatchFsmStateSetHrs::Instance());
}

void WatchFsmStateSetSig::decrSetEvt(WatchFsm* fsm)
{
  WatchFsmAdapter* adapter = fsm->adapter();
  if (0 != adapter)
  {
    adapter->decrSetSigAction();
  }
}

void WatchFsmStateSetSig::incrSetEvt(WatchFsm* fsm)
{
  WatchFsmAdapter* adapter = fsm->adapter();
  if (0 != adapter)
  {
    adapter->incrSetSigAction();
  }
}

//-----------------------------------------------------------------------------

WatchFsmState* WatchFsmStateSetHrs::s_instance = 0;

WatchFsmState* WatchFsmStateSetHrs::Instance()
{
  if (0 == s_instance)
  {
    s_instance = new WatchFsmStateSetHrs();
  }
  return s_instance;
}

const char* WatchFsmStateSetHrs::toString()
{
  return "WatchFsmStateSetHrs";
}

void WatchFsmStateSetHrs::entry(WatchFsm* fsm)
{
  WatchFsmAdapter* adapter = fsm->adapter();
  if (0 != adapter)
  {
    adapter->setHrsSelAction();
  }
}

void WatchFsmStateSetHrs::runEvt(WatchFsm* fsm)
{
  WatchFsmStateStopped::Instance()->runEvt(fsm);
}

void WatchFsmStateSetHrs::stopEvt(WatchFsm* fsm)
{
  WatchFsmAdapter* adapter = fsm->adapter();
  if (0 != adapter)
  {
    adapter->clearSelAction();
  }
  fsm->changeState(WatchFsmStateStopped::Instance());
}

void WatchFsmStateSetHrs::partSelUpEvt(WatchFsm* fsm)
{
  fsm->changeState(WatchFsmStateSetSig::Instance());
}

void WatchFsmStateSetHrs::partSelDnEvt(WatchFsm* fsm)
{
  fsm->changeState(WatchFsmStateSetMin::Instance());
}

void WatchFsmStateSetHrs::decrSetEvt(WatchFsm* fsm)
{
  WatchFsmAdapter* adapter = fsm->adapter();
  if (0 != adapter)
  {
    adapter->decrSetHrsAction();
  }
}

void WatchFsmStateSetHrs::incrSetEvt(WatchFsm* fsm)
{
  WatchFsmAdapter* adapter = fsm->adapter();
  if (0 != adapter)
  {
    adapter->incrSetHrsAction();
  }
}

//-----------------------------------------------------------------------------

WatchFsmState* WatchFsmStateSetMin::s_instance = 0;

WatchFsmState* WatchFsmStateSetMin::Instance()
{
  if (0 == s_instance)
  {
    s_instance = new WatchFsmStateSetMin();
  }
  return s_instance;
}

const char* WatchFsmStateSetMin::toString()
{
  return "WatchFsmStateSetMin";
}

void WatchFsmStateSetMin::entry(WatchFsm* fsm)
{
  WatchFsmAdapter* adapter = fsm->adapter();
  if (0 != adapter)
  {
    adapter->setMinSelAction();
  }
}

void WatchFsmStateSetMin::runEvt(WatchFsm* fsm)
{
  WatchFsmStateStopped::Instance()->runEvt(fsm);
}

void WatchFsmStateSetMin::stopEvt(WatchFsm* fsm)
{
  WatchFsmAdapter* adapter = fsm->adapter();
  if (0 != adapter)
  {
    adapter->clearSelAction();
  }
  fsm->changeState(WatchFsmStateStopped::Instance());
}

void WatchFsmStateSetMin::partSelUpEvt(WatchFsm* fsm)
{
  fsm->changeState(WatchFsmStateSetHrs::Instance());
}

void WatchFsmStateSetMin::partSelDnEvt(WatchFsm* fsm)
{
  fsm->changeState(WatchFsmStateSetSec::Instance());
}

void WatchFsmStateSetMin::decrSetEvt(WatchFsm* fsm)
{
  WatchFsmAdapter* adapter = fsm->adapter();
  if (0 != adapter)
  {
    adapter->decrSetMinAction();
  }
}

void WatchFsmStateSetMin::incrSetEvt(WatchFsm* fsm)
{
  WatchFsmAdapter* adapter = fsm->adapter();
  if (0 != adapter)
  {
    adapter->incrSetMinAction();
  }
}

//-----------------------------------------------------------------------------

WatchFsmState* WatchFsmStateSetSec::s_instance = 0;

WatchFsmState* WatchFsmStateSetSec::Instance()
{
  if (0 == s_instance)
  {
    s_instance = new WatchFsmStateSetSec();
  }
  return s_instance;
}

const char* WatchFsmStateSetSec::toString()
{
  return "WatchFsmStateSetSec";
}

void WatchFsmStateSetSec::entry(WatchFsm* fsm)
{
  WatchFsmAdapter* adapter = fsm->adapter();
  if (0 != adapter)
  {
    adapter->setSecSelAction();
  }
}

void WatchFsmStateSetSec::runEvt(WatchFsm* fsm)
{
  WatchFsmStateStopped::Instance()->runEvt(fsm);
}

void WatchFsmStateSetSec::stopEvt(WatchFsm* fsm)
{
  WatchFsmAdapter* adapter = fsm->adapter();
  if (0 != adapter)
  {
    adapter->clearSelAction();
  }
  fsm->changeState(WatchFsmStateStopped::Instance());
}

void WatchFsmStateSetSec::partSelUpEvt(WatchFsm* fsm)
{
  fsm->changeState(WatchFsmStateSetMin::Instance());
}

void WatchFsmStateSetSec::decrSetEvt(WatchFsm* fsm)
{
  WatchFsmAdapter* adapter = fsm->adapter();
  if (0 != adapter)
  {
    adapter->decrSetSecAction();
  }
}

void WatchFsmStateSetSec::incrSetEvt(WatchFsm* fsm)
{
  WatchFsmAdapter* adapter = fsm->adapter();
  if (0 != adapter)
  {
    adapter->incrSetSecAction();
  }
}

//-----------------------------------------------------------------------------

WatchFsmState* WatchFsmStateRunning::s_instance = 0;

WatchFsmState* WatchFsmStateRunning::Instance()
{
  if (0 == s_instance)
  {
    s_instance = new WatchFsmStateRunning();
  }
  return s_instance;
}

void WatchFsmStateRunning::entry(WatchFsm* fsm)
{
  WatchFsmAdapter* adapter = fsm->adapter();
  if (0 != adapter)
  {
    adapter->clearSelAction();
  }
}

const char* WatchFsmStateRunning::toString()
{
  return "WatchFsmStateRunning";
}

void WatchFsmStateRunning::stopEvt(WatchFsm* fsm)
{
  fsm->changeState(WatchFsmStateStopped::Instance());
}

void WatchFsmStateRunning::tickEvt(WatchFsm* fsm)
{
  WatchFsmAdapter* adapter = fsm->adapter();
  if (0 != adapter)
  {
    adapter->enabledTickAction();
  }
}
