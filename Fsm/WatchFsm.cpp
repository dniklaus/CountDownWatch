/*
 * Fsm.cpp
 *
 *  Created on: 07.08.2013
 *      Author: niklausd
 */

#include "WatchFsm.h"
#include "WatchFsmState.h"

WatchFsm::WatchFsm()
: m_adapter(0)
, m_state(WatchFsmStateStopped::Instance())
{ }

WatchFsm::~WatchFsm()
{ }

void WatchFsm::changeState(WatchFsmState* state)
{
  if (state != m_state)
  {
    state->entry(this);
  }
  m_state = state;
}

void WatchFsm::attachAdapter(WatchFsmAdapter* adapter)
{
  m_adapter = adapter;
}

WatchFsmAdapter* WatchFsm::adapter()
{
  return m_adapter;
}

WatchFsmState* WatchFsm::state()
{
  return m_state;
}

void WatchFsm::run()
{
  if (0 != m_state)
  {
    m_state->runEvt(this);
  }
}

void WatchFsm::stop()
{
  if (0 != m_state)
  {
    m_state->stopEvt(this);
  }
}

void WatchFsm::store()
{
  if (0 != m_state)
  {
    m_state->storePresetEvt(this);
  }

}

void WatchFsm::load()
{
  if (0 != m_state)
  {
    m_state->loadPresetEvt(this);
  }
}


void WatchFsm::tick()
{
  if (0 != m_state)
  {
    m_state->tickEvt(this);
  }
}

void WatchFsm::partSelUp()
{
  if (0 != m_state)
  {
    m_state->partSelUpEvt(this);
  }
}

void WatchFsm::partSelDn()
{
  if (0 != m_state)
  {
    m_state->partSelDnEvt(this);
  }
}

void WatchFsm::incrSet()
{
  if (0 != m_state)
  {
    m_state->incrSetEvt(this);
  }
}

void WatchFsm::decrSet()
{
  if (0 != m_state)
  {
    m_state->decrSetEvt(this);
  }
}
