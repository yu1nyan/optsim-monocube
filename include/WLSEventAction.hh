//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: WLSEventAction.hh 69561 2013-05-08 12:25:56Z gcosmo $
//
/// \file optical/wls/include/WLSEventAction.hh
/// \brief Definition of the WLSEventAction class
//

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#ifndef WLSEventAction_h
#define WLSEventAction_h 1

#include "globals.hh"
#include "G4UserEventAction.hh"
#include "G4ThreeVector.hh"
#include "WLSPrimaryGeneratorAction.hh"
#include "WLSStackingAction.hh"

class WLSRunAction;
class WLSEventActionMessenger;
class WLSPrimaryGeneratorAction;
class WLSStackingAction;

class WLSEventAction : public G4UserEventAction
{
  public:

    //WLSEventAction(WLSRunAction*,);
    //WLSEventAction(WLSRunAction*,WLSPrimaryGeneratorAction*);
    WLSEventAction(WLSRunAction*,WLSPrimaryGeneratorAction*,WLSStackingAction*);
    virtual ~WLSEventAction();

  public:

    virtual void   BeginOfEventAction(const G4Event*);
    virtual void     EndOfEventAction(const G4Event*);

    G4int GetEventNo();
    void SetEventVerbose(G4int);

    void SetDrawFlag(G4String val)  { fDrawFlag = val; };
    void SetPrintModulo(G4int val)  { fPrintModulo = val; };

    void SetForceDrawPhotons(G4bool b){fForceDrawPhotons=b;}
    void SetForceDrawNoPhotons(G4bool b){fForceNoPhotons=b;}

    void SetBeamPrimaryX(G4int a) { fPrimaryX = a; } // add
    void SetBeamPrimaryY(G4int a) { fPrimaryY = a; } // add
    void SetBeamPrimaryZ(G4int a) { fPrimaryZ = a; } // add

    void AddPhotCountX(G4int a) { fPhotCountX += a; } // add
    void AddPhotCountY(G4int a) { fPhotCountY += a; } // add
    void AddPhotCountZ(G4int a) { fPhotCountZ += a; } // add
    void AddPhottime(G4double a)       { 
                if( fPhottime == 0 || fPhottime > a)  fPhottime = a; } //add
    void AddPhotlasttime(G4double a ) { 
                if(fPhotlasttime < a) fPhotlasttime = a;}//add

	void GiveParticleInitialPosi(G4ThreeVector a);
  private:

    WLSRunAction* fRunAction;
    WLSEventActionMessenger* fEventMessenger;
	 WLSPrimaryGeneratorAction *fPrimarysource;
	 WLSStackingAction* fStacking;

    G4int fVerboseLevel;
    G4int fPrintModulo;
 
    G4int fMPPCCollID;
 
    G4String fDrawFlag;

    G4bool fForceDrawPhotons;
    G4bool fForceNoPhotons;

	int fPrimaryX; // add
	int fPrimaryY; // add
	int fPrimaryZ; // add
	int fPhotCountX; // add
	int fPhotCountY; // add
	int fPhotCountZ; // add
  double fPhottime; //add
  double fPhotlasttime; //add
};

#endif
