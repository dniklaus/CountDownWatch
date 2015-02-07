/*
 * Watch.cpp
 *
 *  Created on: 03.07.2013
 *      Author: niklausd
 */

#include "Timer.h"
#include "Watch.h"
#include "WatchFsm.h"
#include "WatchFsmState.h"
#include "WatchPart.h"
#include "WatchPartAdapter.h"
#include "WatchFsmAdapter.h"

class SpecWatchFsmAdapter : public WatchFsmAdapter
{
public:
  SpecWatchFsmAdapter(Watch* watch, WatchPart* signPart, WatchPart* hoursPart, WatchPart* minutesPart, WatchPart* secondsPart)
  : m_watch(watch)
  , m_sig(signPart)
  , m_hrs(hoursPart)
  , m_min(minutesPart)
  , m_sec(secondsPart)
  { };

  void enabledTickAction()
  {
    if (m_sig->getVal())
    {
      m_sec->tickDn();
    }
    else
    {
      m_sec->tickUp();
    }
    if (m_watch->isZero())
    {
      m_sig->setCount(0);
    }
  }

  void storePresetAction()
  {
    m_sig->storePreset();
    m_hrs->storePreset();
    m_min->storePreset();
    m_sec->storePreset();
  }

  void loadPresetAction()
  {
    m_sig->loadPreset();
    m_hrs->loadPreset();
    m_min->loadPreset();
    m_sec->loadPreset();
  }

  void setSigSelAction()
  {
    m_sig->setIsSelected(true);
    m_hrs->setIsSelected(false);
    m_min->setIsSelected(false);
    m_sec->setIsSelected(false);
  }

  void setHrsSelAction()
  {
    m_sig->setIsSelected(false);
    m_hrs->setIsSelected(true);
    m_min->setIsSelected(false);
    m_sec->setIsSelected(false);
  }

  void setMinSelAction()
  {
    m_sig->setIsSelected(false);
    m_hrs->setIsSelected(false);
    m_min->setIsSelected(true);
    m_sec->setIsSelected(false);
  }

  void setSecSelAction()
  {
    m_sig->setIsSelected(false);
    m_hrs->setIsSelected(false);
    m_min->setIsSelected(false);
    m_sec->setIsSelected(true);
  }

  void clearSelAction()
  {
    m_sig->setIsSelected(false);
    m_hrs->setIsSelected(false);
    m_min->setIsSelected(false);
    m_sec->setIsSelected(false);
  }

  void decrSetSigAction()
  {
    m_watch->setSig(m_watch->getTime()->sign - 1);
  }

  void incrSetSigAction()
  {
    m_watch->setSig(m_watch->getTime()->sign + 1);
  }

  void decrSetHrsAction()
  {
    m_watch->setHrs(m_watch->getTime()->h - 1);
  }

  void incrSetHrsAction()
  {
    m_watch->setHrs(m_watch->getTime()->h + 1);
  }

  void decrSetMinAction()
  {
    m_watch->setMin(m_watch->getTime()->m - 1);
  }

  void incrSetMinAction()
  {
    m_watch->setMin(m_watch->getTime()->m + 1);
  }

  void decrSetSecAction()
  {
    m_watch->setSec(m_watch->getTime()->s - 1);
  }

  void incrSetSecAction()
  {
    m_watch->setSec(m_watch->getTime()->s + 1);
  }

private:
  Watch* m_watch;
  WatchPart* m_sig;
  WatchPart* m_hrs;
  WatchPart* m_min;
  WatchPart* m_sec;
};

//=============================================================================

class WatchTimerAdapter : public TimerAdapter
{
public:
  WatchTimerAdapter(Watch* watch)
  : m_watch(watch)
  { }

  void timeExpired()
  {
    if (0 != m_watch)
    {
      m_watch->tick();
    }
  }

private:
  Watch* m_watch;
};

const bool ONE_SEC_TIMER_IS_RECURRING = true;
const unsigned int ONE_SEC_TIME_MILLIS = 1000;

//=============================================================================

Watch::Watch()
: m_oneSecTimer(new Timer(new WatchTimerAdapter(this), ONE_SEC_TIMER_IS_RECURRING, ONE_SEC_TIME_MILLIS))
, m_fsm(new WatchFsm())
, m_sig(new WatchPart_Sig())
, m_hrs(new WatchPart_Hrs())
, m_min(new WatchPart_Min())
, m_sec(new WatchPart_Sec())
, m_time(new wTime())
{
  m_sec->attachAdapter(new WatchPartAdapter(m_min));
  m_min->attachAdapter(new WatchPartAdapter(m_hrs));
  m_hrs->attachAdapter(new WatchPartAdapter(0));

  preset();

  m_fsm->attachAdapter(new SpecWatchFsmAdapter(this, m_sig, m_hrs, m_min, m_sec));
}

Watch::~Watch()
{
  delete m_fsm->adapter();
  delete m_fsm; m_fsm = 0;

  delete m_sig->adapter();
  delete m_sig; m_sig = 0;

  delete m_hrs->adapter();
  delete m_hrs; m_hrs = 0;

  delete m_min->adapter();
  delete m_min; m_min = 0;

  delete m_sec->adapter();
  delete m_sec; m_sec = 0;

  delete m_time; m_time = 0;
}

void Watch::preset()
{
  m_time->sign = true;
  setMin(1);
}

//-----------------------------------------------------------------------------
// direct time adjustment access methods
//-----------------------------------------------------------------------------
void Watch::setSig(unsigned int isSignSet)
{
  m_sig->setCount(isSignSet);
}

void Watch::setHrs(unsigned int count)
{
  m_hrs->setCount(count);
}

void Watch::setMin(unsigned int count)
{
  m_min->setCount(count);
}

void Watch::setSec(unsigned int count)
{
  m_sec->setCount(count);
}


//-----------------------------------------------------------------------------
// system tick
//-----------------------------------------------------------------------------
void Watch::tick()
{
  m_fsm->tick();
}


//-----------------------------------------------------------------------------
// event methods
//-----------------------------------------------------------------------------
void Watch::run()
{
  m_fsm->run();
}

void Watch::stop()
{
  m_fsm->stop();
}

void Watch::load()
{
  m_fsm->load();
}

void Watch::store()
{
  m_fsm->store();
}

void Watch::partSelDn()
{
  m_fsm->partSelDn();
}

void Watch::partSelUp()
{
  m_fsm->partSelUp();
}

void Watch::incrSet()
{
  m_fsm->incrSet();
}

void Watch::decrSet()
{
  m_fsm->decrSet();
}

//-----------------------------------------------------------------------------
// get info / status methods
//-----------------------------------------------------------------------------
const char* Watch::currentStateString()
{
  if (0 != m_fsm)
  {
    return m_fsm->state()->toString();
  }
  else
  {
    return "Error: Watch State FSM, current state is unknown!";
  }
}

bool Watch::isSigSelected()
{
  return m_sig->isSelected();
}

bool Watch::isHrsSelected()
{
  return m_hrs->isSelected();
}

bool Watch::isMinSelected()
{
  return m_min->isSelected();
}

bool Watch::isSecSelected()
{
  return m_sec->isSelected();
}

bool Watch::isZero()
{
  return (m_hrs->isZero() && m_min->isZero() && m_sec->isZero());
}

wTime* Watch::getTime()
{
  m_time->sign = m_sig->getVal();
  m_time->h = m_hrs->getVal();
  m_time->m = m_min->getVal();
  m_time->s = m_sec->getVal();
  return m_time;
}
