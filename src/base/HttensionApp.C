#include "HttensionApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
HttensionApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

HttensionApp::HttensionApp(InputParameters parameters) : MooseApp(parameters)
{
  HttensionApp::registerAll(_factory, _action_factory, _syntax);
}

HttensionApp::~HttensionApp() {}

void
HttensionApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"HttensionApp"});
  Registry::registerActionsTo(af, {"HttensionApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
HttensionApp::registerApps()
{
  registerApp(HttensionApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
HttensionApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  HttensionApp::registerAll(f, af, s);
}
extern "C" void
HttensionApp__registerApps()
{
  HttensionApp::registerApps();
}
