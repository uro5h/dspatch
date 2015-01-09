/************************************************************************
DSPatch - Cross-Platform, Object-Oriented, Flow-Based Programming Library
Copyright (c) 2012-2013 Marcus Tomlinson

This file is part of DSPatch.

GNU Lesser General Public License Usage
This file may be used under the terms of the GNU Lesser General Public
License version 3.0 as published by the Free Software Foundation and
appearing in the file LGPLv3.txt included in the packaging of this
file. Please review the following information to ensure the GNU Lesser
General Public License version 3.0 requirements will be met:
http://www.gnu.org/copyleft/lgpl.html.

Other Usage
Alternatively, this file may be used in accordance with the terms and
conditions contained in a signed written agreement between you and
Marcus Tomlinson.

DSPatch is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
************************************************************************/

#include "../include/DSPatch.h"

//=================================================================================================

DspCircuit* DSPatch::_globalCircuit = new DspCircuit();

//=================================================================================================

bool DSPatch::IsThisGlobalCircuit( DspComponent* thisComponent )
{
  if( _globalCircuit != NULL )
  {
    return _globalCircuit == thisComponent;
  }

  return false;
}

//-------------------------------------------------------------------------------------------------

bool DSPatch::AddGlobalComponent( DspComponent* component, std::string componentName )
{
  if( _globalCircuit != NULL )
  {
    return _globalCircuit->AddComponent( component, componentName );
  }

  return false;
}

//-------------------------------------------------------------------------------------------------

void DSPatch::RemoveGlobalComponent( DspComponent* component )
{
  if( _globalCircuit != NULL )
  {
    return _globalCircuit->RemoveComponent( component );
  }
}

//-------------------------------------------------------------------------------------------------

unsigned short DSPatch::GetGlobalComponentCount()
{
  if( _globalCircuit != NULL )
  {
    return _globalCircuit->GetComponentCount();
  }

  return 0;
}

//-------------------------------------------------------------------------------------------------

void DSPatch::StartGlobalAutoTick()
{
  if( _globalCircuit != NULL )
  {
    _globalCircuit->StartAutoTick();
  }
}

//-------------------------------------------------------------------------------------------------

void DSPatch::StopGlobalAutoTick()
{
  if( _globalCircuit != NULL )
  {
    _globalCircuit->StopAutoTick();
  }
}

//-------------------------------------------------------------------------------------------------

void DSPatch::SetGlobalThreadCount( unsigned short threadCount )
{
  if( _globalCircuit != NULL )
  {
    _globalCircuit->SetThreadCount( threadCount );
  }
}

//-------------------------------------------------------------------------------------------------

void DSPatch::Finalize()
{
  delete _globalCircuit;
  _globalCircuit = NULL;
}

//=================================================================================================
