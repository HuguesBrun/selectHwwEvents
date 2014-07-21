//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Jul  9 15:34:06 2014 by ROOT version 6.00/00
// from TTree eventsTree/
// found on file: Hww2012_testWPs.root
//////////////////////////////////////////////////////////

#ifndef SelectHwwEvents_h
#define SelectHwwEvents_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"


struct genLepton{
    float pt;
    float eta;
    float phi;
    float pdgID;
    float motherID;
    bool operator<(const genLepton& a) const
    {
        return pt > a.pt;
    }
};

class SelectHwwEvents : public TSelector {
public :
    
    
    TFile *myFile;
    TTree *myTree;
    
    float leadPt;
    float leadEta;
    float trailPt;
    float trailEta;
    
    int typeEvent;

    int passPathMuE_Loose;
    int passPathMuE_Medium;
    int passPathMuE_Tight;
    int passPathMuE_Simon;
    
    int passPathEMu_Loose;
    int passPathEMu_Medium;
    int passPathEMu_Tight;
    int passPathEMu_Simon;
    
    int leadMuEFilter_Loose;
    int leadMuEFilter_Medium;
    int leadMuEFilter_Tight;
    int leadMuEFilter_Simon;
    
    int leadEMuFilter_Loose;
    int leadEMuFilter_Medium;
    int leadEMuFilter_Tight;
    int leadEMuFilter_Simon;
    
    int trailEMuFilter_Loose;
    int trailEMuFilter_Medium;
    int trailEMuFilter_Tight;
    int trailEMuFilter_Simon;
    
    int trailMuEFilter_Loose;
    int trailMuEFilter_Medium;
    int trailMuEFilter_Tight;
    int trailMuEFilter_Simon;
    
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           T_Event_RunNumber;
   Int_t           T_Event_EventNumber;
   Int_t           T_Event_LuminosityBlock;
   Int_t           T_Event_nPU;
   Float_t         T_Event_nTruePU;
   Int_t           T_Event_nPUm;
   Int_t           T_Event_nPUp;
   Float_t         T_Event_AveNTruePU;
   vector<int>     *T_Event_pathsFired;
   vector<float>   *T_Trig_Eta;
   vector<float>   *T_Trig_Pt;
   vector<float>   *T_Trig_Phi;
   vector<int>     *T_Trig_Leg;
   vector<float>   *T_Trig_Value;
   vector<float>   *T_Trig_Value2;
   vector<float>   *T_Gen_Eta;
   vector<float>   *T_Gen_Phi;
   vector<float>   *T_Gen_Pt;
   vector<int>     *T_Gen_pdgID;
   vector<int>     *T_Gen_MotherID;
   vector<int>     *T_Gen_FromW;
   vector<int>     *T_Gen_FromTau;

   // List of branches
   TBranch        *b_T_Event_RunNumber;   //!
   TBranch        *b_T_Event_EventNumber;   //!
   TBranch        *b_T_Event_LuminosityBlock;   //!
   TBranch        *b_T_Event_nPU;   //!
   TBranch        *b_T_Event_nTruePU;   //!
   TBranch        *b_T_Event_nPUm;   //!
   TBranch        *b_T_Event_nPUp;   //!
   TBranch        *b_T_Event_AveNTruePU;   //!
   TBranch        *b_T_Event_pathsFired;   //!
   TBranch        *b_T_Trig_Eta;   //!
   TBranch        *b_T_Trig_Pt;   //!
   TBranch        *b_T_Trig_Phi;   //!
   TBranch        *b_T_Trig_Leg;   //!
   TBranch        *b_T_Trig_Value;   //!
   TBranch        *b_T_Trig_Value2;   //!
   TBranch        *b_T_Gen_Eta;   //!
   TBranch        *b_T_Gen_Phi;   //!
   TBranch        *b_T_Gen_Pt;   //!
   TBranch        *b_T_Gen_pdgID;   //!
   TBranch        *b_T_Gen_MotherID;   //!
   TBranch        *b_T_Gen_FromW;   //!
   TBranch        *b_T_Gen_FromTau;   //!

   SelectHwwEvents(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~SelectHwwEvents() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
    virtual int TheHightLegMathed(genLepton , int , int );
   virtual void    Terminate();

   ClassDef(SelectHwwEvents,0);
};

#endif

#ifdef SelectHwwEvents_cxx
void SelectHwwEvents::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

    
    myFile = new TFile("theOutFile.root","RECREATE");
    myTree = new TTree("myTree","");
    myTree->Branch("T_Event_nPU",&T_Event_nPU,"T_Event_nPU/I");
    myTree->Branch("leadPt",&leadPt,"leadPt/F");
    myTree->Branch("leadEta",&leadEta,"leadEta/F");
    myTree->Branch("trailPt",&trailPt,"trailPt/F");
    myTree->Branch("trailEta",&trailEta,"trailEta/F");
    myTree->Branch("typeEvent",&typeEvent,"typeEvent/I");
    
    myTree->Branch("passPathMuE_Loose",&passPathMuE_Loose,"passPathMuE_Loose/I");
    myTree->Branch("passPathMuE_Medium",&passPathMuE_Medium,"passPathMuE_Medium/I");
    myTree->Branch("passPathMuE_Tight",&passPathMuE_Tight,"passPathMuE_Tight/I");
    myTree->Branch("passPathMuE_Simon",&passPathMuE_Simon,"passPathMuE_Simon/I");
 
    myTree->Branch("passPathEMu_Loose",&passPathEMu_Loose,"passPathEMu_Loose/I");
    myTree->Branch("passPathEMu_Medium",&passPathEMu_Medium,"passPathEMu_Medium/I");
    myTree->Branch("passPathEMu_Tight",&passPathEMu_Tight,"passPathEMu_Tight/I");
    myTree->Branch("passPathEMu_Simon",&passPathEMu_Simon,"passPathEMu_Simon/I");

    myTree->Branch("leadMuEFilter_Loose",&leadMuEFilter_Loose,"leadMuEFilter_Loose/I");
    myTree->Branch("leadMuEFilter_Medium",&leadMuEFilter_Medium,"leadMuEFilter_Medium/I");
    myTree->Branch("leadMuEFilter_Tight",&leadMuEFilter_Tight,"leadMuEFilter_Tight/I");
    myTree->Branch("leadMuEFilter_Simon",&leadMuEFilter_Simon,"leadMuEFilter_Simon/I");
 
    myTree->Branch("leadEMuFilter_Loose",&leadEMuFilter_Loose,"leadEMuFilter_Loose/I");
    myTree->Branch("leadEMuFilter_Medium",&leadEMuFilter_Medium,"leadEMuFilter_Medium/I");
    myTree->Branch("leadEMuFilter_Tight",&leadEMuFilter_Tight,"leadEMuFilter_Tight/I");
    myTree->Branch("leadEMuFilter_Simon",&leadEMuFilter_Simon,"leadEMuFilter_Simon/I");
    
    myTree->Branch("trailMuEFilter_Loose",&trailMuEFilter_Loose,"trailMuEFilter_Loose/I");
    myTree->Branch("trailMuEFilter_Medium",&trailMuEFilter_Medium,"trailMuEFilter_Medium/I");
    myTree->Branch("trailMuEFilter_Tight",&trailMuEFilter_Tight,"trailMuEFilter_Tight/I");
    myTree->Branch("trailMuEFilter_Simon",&trailMuEFilter_Simon,"trailMuEFilter_Simon/I");
    
    myTree->Branch("trailEMuFilter_Loose",&trailEMuFilter_Loose,"trailEMuFilter_Loose/I");
    myTree->Branch("trailEMuFilter_Medium",&trailEMuFilter_Medium,"trailEMuFilter_Medium/I");
    myTree->Branch("trailEMuFilter_Tight",&trailEMuFilter_Tight,"trailEMuFilter_Tight/I");
    myTree->Branch("trailEMuFilter_Simon",&trailEMuFilter_Simon,"trailEMuFilter_Simon/I");
 
  
  // Set object pointer
   T_Event_pathsFired = 0;
   T_Trig_Eta = 0;
   T_Trig_Pt = 0;
   T_Trig_Phi = 0;
   T_Trig_Leg = 0;
   T_Trig_Value = 0;
   T_Trig_Value2 = 0;
   T_Gen_Eta = 0;
   T_Gen_Phi = 0;
   T_Gen_Pt = 0;
   T_Gen_pdgID = 0;
   T_Gen_MotherID = 0;
   T_Gen_FromW = 0;
   T_Gen_FromTau = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("T_Event_RunNumber", &T_Event_RunNumber, &b_T_Event_RunNumber);
   fChain->SetBranchAddress("T_Event_EventNumber", &T_Event_EventNumber, &b_T_Event_EventNumber);
   fChain->SetBranchAddress("T_Event_LuminosityBlock", &T_Event_LuminosityBlock, &b_T_Event_LuminosityBlock);
   fChain->SetBranchAddress("T_Event_nPU", &T_Event_nPU, &b_T_Event_nPU);
   fChain->SetBranchAddress("T_Event_nTruePU", &T_Event_nTruePU, &b_T_Event_nTruePU);
   fChain->SetBranchAddress("T_Event_nPUm", &T_Event_nPUm, &b_T_Event_nPUm);
   fChain->SetBranchAddress("T_Event_nPUp", &T_Event_nPUp, &b_T_Event_nPUp);
   fChain->SetBranchAddress("T_Event_AveNTruePU", &T_Event_AveNTruePU, &b_T_Event_AveNTruePU);
   fChain->SetBranchAddress("T_Event_pathsFired", &T_Event_pathsFired, &b_T_Event_pathsFired);
   fChain->SetBranchAddress("T_Trig_Eta", &T_Trig_Eta, &b_T_Trig_Eta);
   fChain->SetBranchAddress("T_Trig_Pt", &T_Trig_Pt, &b_T_Trig_Pt);
   fChain->SetBranchAddress("T_Trig_Phi", &T_Trig_Phi, &b_T_Trig_Phi);
   fChain->SetBranchAddress("T_Trig_Leg", &T_Trig_Leg, &b_T_Trig_Leg);
   fChain->SetBranchAddress("T_Trig_Value", &T_Trig_Value, &b_T_Trig_Value);
   fChain->SetBranchAddress("T_Trig_Value2", &T_Trig_Value2, &b_T_Trig_Value2);
   fChain->SetBranchAddress("T_Gen_Eta", &T_Gen_Eta, &b_T_Gen_Eta);
   fChain->SetBranchAddress("T_Gen_Phi", &T_Gen_Phi, &b_T_Gen_Phi);
   fChain->SetBranchAddress("T_Gen_Pt", &T_Gen_Pt, &b_T_Gen_Pt);
   fChain->SetBranchAddress("T_Gen_pdgID", &T_Gen_pdgID, &b_T_Gen_pdgID);
   fChain->SetBranchAddress("T_Gen_MotherID", &T_Gen_MotherID, &b_T_Gen_MotherID);
   fChain->SetBranchAddress("T_Gen_FromW", &T_Gen_FromW, &b_T_Gen_FromW);
   fChain->SetBranchAddress("T_Gen_FromTau", &T_Gen_FromTau, &b_T_Gen_FromTau);
}

Bool_t SelectHwwEvents::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef SelectHwwEvents_cxx
