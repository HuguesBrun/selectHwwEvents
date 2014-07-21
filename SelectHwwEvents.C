#define SelectHwwEvents_cxx
// The class definition in SelectHwwEvents.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("SelectHwwEvents.C")
// root> T->Process("SelectHwwEvents.C","some options")
// root> T->Process("SelectHwwEvents.C+")
//

#include "SelectHwwEvents.h"
#include <TH2.h>
#include <TStyle.h>


void SelectHwwEvents::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void SelectHwwEvents::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t SelectHwwEvents::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either SelectHwwEvents::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the data. When processing
   // keyed objects with PROOF, the object is already loaded and is available
   // via the fObject pointer.
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.
    fChain->GetEntry(entry);
    if (entry%1000==0) cout << "i=" << entry << endl;
    vector<genLepton> theGenParticles;
    int nbGenPart = T_Gen_Eta->size();
    for (int i = 0 ; i < nbGenPart ; i++){
        genLepton theGen;
        theGen.pt = T_Gen_Pt->at(i);
        theGen.phi = T_Gen_Phi->at(i);
        theGen.eta = T_Gen_Eta->at(i);
        theGen.pdgID = T_Gen_pdgID->at(i);
        if ((fabs(theGen.pdgID)!=13)&&(fabs(theGen.pdgID)!=11)) continue;
        if (T_Gen_FromW->at(i)!=1) continue;
        theGenParticles.push_back(theGen);
    }
    nbGenPart = theGenParticles.size();
    cout << "nb of gen parts=" << nbGenPart << endl;
    if (nbGenPart<2) return kTRUE;
    std::sort(theGenParticles.begin(), theGenParticles.end());
    
    
    genLepton leadLepton = theGenParticles.at(0);
    genLepton trailLepton = theGenParticles.at(1);
    
    leadPt = leadLepton.pt;
    trailPt = trailLepton.pt;
    
    leadEta = leadLepton.eta;
    trailEta = trailLepton.eta;
    
    
    typeEvent = 0;
    if ((fabs(leadLepton.pdgID)==13)&&(fabs(trailLepton.pdgID)==11)) typeEvent=1;
    if ((fabs(leadLepton.pdgID)==11)&&(fabs(trailLepton.pdgID)==13)) typeEvent=2;
    
    
    passPathMuE_Loose = T_Event_pathsFired->at(0);
    passPathMuE_Medium= T_Event_pathsFired->at(3);
    passPathMuE_Tight= T_Event_pathsFired->at(5);
    passPathMuE_Simon= T_Event_pathsFired->at(7);
    
    passPathEMu_Loose = T_Event_pathsFired->at(1);
    passPathEMu_Medium= T_Event_pathsFired->at(2);
    passPathEMu_Tight= T_Event_pathsFired->at(4);
    passPathEMu_Simon= T_Event_pathsFired->at(6);
    
    leadMuEFilter_Loose = TheHightLegMathed(leadLepton,0, 10);
    leadEMuFilter_Loose = TheHightLegMathed(leadLepton,11, 21);
    
    leadMuEFilter_Medium = TheHightLegMathed(leadLepton,22, 32);
    leadEMuFilter_Medium = TheHightLegMathed(leadLepton,33, 43);

    leadMuEFilter_Tight = TheHightLegMathed(leadLepton,44, 54);
    leadEMuFilter_Tight = TheHightLegMathed(leadLepton,55, 65);
    
    leadMuEFilter_Simon = TheHightLegMathed(leadLepton,66, 76);
    leadEMuFilter_Simon = TheHightLegMathed(leadLepton,77, 87);
    
    trailMuEFilter_Loose = TheHightLegMathed(trailLepton,0, 10);
    trailEMuFilter_Loose = TheHightLegMathed(trailLepton,11, 21);
    
    trailMuEFilter_Medium = TheHightLegMathed(trailLepton,22, 32);
    trailEMuFilter_Medium = TheHightLegMathed(trailLepton,33, 43);
    
    trailMuEFilter_Tight = TheHightLegMathed(trailLepton,44, 54);
    trailEMuFilter_Tight = TheHightLegMathed(trailLepton,55, 65);
    
    trailMuEFilter_Simon = TheHightLegMathed(trailLepton,66, 76);
    trailEMuFilter_Simon = TheHightLegMathed(trailLepton,77, 87);
    
    myTree->Fill();
    
  //  if (entry>100) Abort("the end !!!");


   return kTRUE;
}


int SelectHwwEvents::TheHightLegMathed(genLepton theGen, int lowLeg, int maxLeg){
    int nbTriggerLeg = T_Trig_Pt->size();
    int theHigherLeg = 0;
    for (int i = 0 ; i < nbTriggerLeg ; i++){
        if (T_Trig_Leg->at(i) <lowLeg) continue;
        if (T_Trig_Leg->at(i) > maxLeg) continue;
        float deltaR = sqrt(pow(theGen.eta-T_Trig_Eta->at(i),2)+ pow(acos(cos((theGen.phi-T_Trig_Phi->at(i)))),2));
        if (deltaR<0.1) {theHigherLeg= T_Trig_Leg->at(i); }
        
    }
    return theHigherLeg;
}

void SelectHwwEvents::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void SelectHwwEvents::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
    myFile->Write();
    myFile->Close();
}
