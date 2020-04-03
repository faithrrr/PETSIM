#ifndef PETRunAction_h
#define PETRunAction_h 1

#include "G4UserRunAction.hh"
#include "G4RunManager.hh"
#include "G4Run.hh"
#include "globals.hh"

#include "TTree.h"
#include "TBranch.h"

class G4Run;

class PETRunAction : public G4UserRunAction {
public:
  PETRunAction();

  virtual ~PETRunAction();

  virtual void BeginOfRunAction(const G4Run*);
  virtual void EndOfRunAction(const G4Run*);

  void  SetRndmFreq(G4int val) { fSaveRndm = val; }
  G4int GetRndmFreq()          { return fSaveRndm; }

  virtual void FillEventHitTree(G4int NumberOfHitInAnEvent, G4double EnergyOfPhoton,G4double wavelengthOfPhotonHit, G4double Pos_x, G4double Pos_y, G4double Pos_z, G4double Time);
  virtual void FillSecondaryTree(G4double Sec_x, G4double Sec_y, G4double Sec_z, G4double Sec_energy);
  virtual void FillGammaTree(G4int gammaCounter);
  virtual void FillCerenTree(G4double Time1);

  inline void SetAutoSeed (const G4bool val) { fAutoSeed = val; }

private:
  G4int fSaveRndm;
  G4bool fAutoSeed;

  TFile* outputFilename;
  TTree* eventTree;
  TTree* gammaTree;
  TTree* secTree;
  TTree* CerenTree;
  G4int eventHit;
  G4double energy;
  G4double wavelengthHit;
  G4double posx;
  G4double posy;
  G4double posz;
  G4double time1;
  G4int GammaCount;
  G4String name;
  G4double compt_energy;
  G4double phot_energy;
  G4double sec_x;
  G4double sec_y;
  G4double sec_z;
  G4double both_energy;
  G4double CerenTime;


};

#endif
