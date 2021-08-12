//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "HttensionTestApp.h"
#include "HttensionApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
HttensionTestApp::validParams()
{
  InputParameters params = HttensionApp::validParams();
  return params;
}

HttensionTestApp::HttensionTestApp(InputParameters parameters) : MooseApp(parameters)
{
  HttensionTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

HttensionTestApp::~HttensionTestApp() {}

void
HttensionTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  HttensionApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"HttensionTestApp"});
    Registry::registerActionsTo(af, {"HttensionTestApp"});
  }
}

void
HttensionTestApp::registerApps()
{
  registerApp(HttensionApp);
  registerApp(HttensionTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
HttensionTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  HttensionTestApp::registerAll(f, af, s);
}
extern "C" void
HttensionTestApp__registerApps()
{
  HttensionTestApp::registerApps();
}
