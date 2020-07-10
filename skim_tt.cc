#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <map>
#include <string>
#include "TH1F.h"
#include "TH2F.h"
#include "TH3F.h"
#include "TTree.h"
#include "TChain.h"
#include "TFile.h"
#include "TMath.h"
#include "TSystem.h"
#include "TRandom.h"
#include "TLorentzVector.h"
#include "TRandom3.h"
#include "makeHisto.h"
#include "tautau_Tree_tt.h"

int main(int argc, char** argv) {

    using namespace std;
    myMap1 = new map<string, TH1F*>();
    myMap2 = new map<string, TH2F*>();
    string status_sample = *(argv + 1);
    bool isMC = false;
    bool isEmbedded = false;
    bool isData = false;
    if (status_sample.compare("mc") == 0) isMC = true;
    if (status_sample.compare("embedded") == 0) isEmbedded = true;
    if (status_sample.compare("data") == 0) isData = true;
    string out = *(argv + 2);
    string outname= out;
    TFile *fout = TFile::Open(outname.c_str(), "RECREATE");

    string in = *(argv + 3);
    string inname= in;
    TFile *fIn = TFile::Open(inname.c_str());

    int recoil=0;
    string recoilType = *(argv + 4);
    if (recoilType.compare("W") == 0)  recoil=1;
    if (recoilType.compare("Z") == 0)  recoil=2;

    string year_sample = *(argv + 5);
    int year=2018;
    if (year_sample.compare("2016") == 0) year=2016;
    if (year_sample.compare("2017") == 0) year=2017;

    TTree* treePtr = (TTree*) fIn->Get("tt/final/Ntuple");
    TH1F *evCounter = (TH1F*) fIn->Get("tt/eventCount");
    TH1F *evCounterW = (TH1F*) fIn->Get("tt/summedWeights");
    HTauTauTree_tt* tree = new HTauTauTree_tt (treePtr);

    TTree *Run_Tree = new TTree("tautau_tree", "tautau_tree");
    Run_Tree->SetDirectory(0);
    Run_Tree->Branch("run", &run, "run/I");
    Run_Tree->Branch("lumi", &lumi, "lumi/I");
    Run_Tree->Branch("evt", &evt, "evt/I");

    Run_Tree->Branch("matchEmbFilter_1", &matchEmbFilter_1, "matchEmbFilter_1/F");
    Run_Tree->Branch("matchEmbFilter_2", &matchEmbFilter_2, "matchEmbFilter_2/F");

    Run_Tree->Branch("genpX", &genpX, "genpX/F");
    Run_Tree->Branch("genpY", &genpY, "genpY/F");
    Run_Tree->Branch("genM", &genM, "genM/F");
    Run_Tree->Branch("genpT", &genpT, "genpT/F");
    Run_Tree->Branch("vispX", &vispX, "vispX/F");
    Run_Tree->Branch("vispY", &vispY, "vispY/F");

    Run_Tree->Branch("Rivet_higgsPt", &Rivet_higgsPt, "Rivet_higgsPt/F");
    Run_Tree->Branch("Rivet_nJets30", &Rivet_nJets30, "Rivet_nJets30/F");
    Run_Tree->Branch("Rivet_stage0_cat", &Rivet_stage0_cat, "Rivet_stage0_cat/F");
    Run_Tree->Branch("Rivet_stage1_1_fine_cat_pTjet30GeV", &Rivet_stage1_1_fine_cat_pTjet30GeV, "Rivet_stage1_1_fine_cat_pTjet30GeV/F");
    Run_Tree->Branch("Rivet_stage1_1_cat_pTjet30GeV", &Rivet_stage1_1_cat_pTjet30GeV, "Rivet_stage1_1_cat_pTjet30GeV/F");
    Run_Tree->Branch("Rivet_stage1_cat_pTjet30GeV", &Rivet_stage1_cat_pTjet30GeV, "Rivet_stage1_cat_pTjet30GeV/F");
    Run_Tree->Branch("gentau1_eta", &gentau1_eta, "gentau1_eta/F");
    Run_Tree->Branch("gentau2_eta", &gentau2_eta, "gentau2_eta/F");
    Run_Tree->Branch("gentau1_pt", &gentau1_pt, "gentau1_pt/F");
    Run_Tree->Branch("gentau2_pt", &gentau2_pt, "gentau2_pt/F");

    Run_Tree->Branch("npv", &npv, "npv/F");
    Run_Tree->Branch("npu", &npu, "npu/F");

    Run_Tree->Branch("pt_1", &pt_1, "pt_1/F");
    Run_Tree->Branch("phi_1", &phi_1, "phi_1/F");
    Run_Tree->Branch("eta_1", &eta_1, "eta_1/F");
    Run_Tree->Branch("m_1", &m_1, "m_1/F");
    Run_Tree->Branch("e_1", &e_1, "e_1/F");
    Run_Tree->Branch("q_1", &q_1, "q_1/F");
    Run_Tree->Branch("l1_decayMode", &l1_decayMode, "l1_decayMode/F");
    Run_Tree->Branch("decayModeFinding_1", &decayModeFinding_1, "decayModeFinding_1/F");
    Run_Tree->Branch("byVVVLooseDeepVSjet_1", &byVVVLooseDeepVSjet_1, "byVVVLooseDeepVSjet_1/F");
    Run_Tree->Branch("byVVLooseDeepVSjet_1", &byVVLooseDeepVSjet_1, "byVVLooseDeepVSjet_1/F");
    Run_Tree->Branch("byVLooseDeepVSjet_1", &byVLooseDeepVSjet_1, "byVLooseDeepVSjet_1/F");
    Run_Tree->Branch("byLooseDeepVSjet_1", &byLooseDeepVSjet_1, "byLooseDeepVSjet_1/F");
    Run_Tree->Branch("byMediumDeepVSjet_1", &byMediumDeepVSjet_1, "byMediumDeepVSjet_1/F");
    Run_Tree->Branch("byTightDeepVSjet_1", &byTightDeepVSjet_1, "byTightDeepVSjet_1/F");
    Run_Tree->Branch("byVTightDeepVSjet_1", &byVTightDeepVSjet_1, "byVTightDeepVSjet_1/F");
    Run_Tree->Branch("byVVTightDeepVSjet_1", &byVVTightDeepVSjet_1, "byVVTightDeepVSjet_1/F");
    Run_Tree->Branch("byVLooseDeepVSmu_1", &byVLooseDeepVSmu_1, "byVLooseDeepVSmu_1/F");
    Run_Tree->Branch("byLooseDeepVSmu_1", &byLooseDeepVSmu_1, "byLooseDeepVSmu_1/F");
    Run_Tree->Branch("byMediumDeepVSmu_1", &byMediumDeepVSmu_1, "byMediumDeepVSmu_1/F");
    Run_Tree->Branch("byTightDeepVSmu_1", &byTightDeepVSmu_1, "byTightDeepVSmu_1/F");
    Run_Tree->Branch("byVTightDeepVSmu_1", &byVTightDeepVSmu_1, "byVTightDeepVSmu_1/F");
    Run_Tree->Branch("byVVTightDeepVSmu_1", &byVVTightDeepVSmu_1, "byVVTightDeepVSmu_1/F");
    Run_Tree->Branch("byVVVLooseDeepVSe_1", &byVVVLooseDeepVSe_1, "byVVVLooseDeepVSe_1/F");
    Run_Tree->Branch("byVVLooseDeepVSe_1", &byVVLooseDeepVSe_1, "byVVLooseDeepVSe_1/F");
    Run_Tree->Branch("byVLooseDeepVSe_1", &byVLooseDeepVSe_1, "byVLooseDeepVSe_1/F");
    Run_Tree->Branch("byLooseDeepVSe_1", &byLooseDeepVSe_1, "byLooseDeepVSe_1/F");
    Run_Tree->Branch("byMediumDeepVSe_1", &byMediumDeepVSe_1, "byMediumDeepVSe_1/F");
    Run_Tree->Branch("byTightDeepVSe_1", &byTightDeepVSe_1, "byTightDeepVSe_1/F");
    Run_Tree->Branch("byVTightDeepVSe_1", &byVTightDeepVSe_1, "byVTightDeepVSe_1/F");
    Run_Tree->Branch("byVVTightDeepVSe_1", &byVVTightDeepVSe_1, "byVVTightDeepVSe_1/F");

    Run_Tree->Branch("pt_2", &pt_2, "pt_2/F");
    Run_Tree->Branch("phi_2", &phi_2, "phi_2/F");
    Run_Tree->Branch("eta_2", &eta_2, "eta_2/F");
    Run_Tree->Branch("m_2", &m_2, "m_2/F");
    Run_Tree->Branch("e_2", &e_2, "e_2/F");
    Run_Tree->Branch("q_2", &q_2, "q_2/F");
    Run_Tree->Branch("l2_decayMode", &l2_decayMode, "l2_decayMode/F");
    Run_Tree->Branch("decayModeFinding_2", &decayModeFinding_2, "decayModeFinding_2/F");
    Run_Tree->Branch("byVVVLooseDeepVSjet_2", &byVVVLooseDeepVSjet_2, "byVVVLooseDeepVSjet_2/F");
    Run_Tree->Branch("byVVLooseDeepVSjet_2", &byVVLooseDeepVSjet_2, "byVVLooseDeepVSjet_2/F");
    Run_Tree->Branch("byVLooseDeepVSjet_2", &byVLooseDeepVSjet_2, "byVLooseDeepVSjet_2/F");
    Run_Tree->Branch("byLooseDeepVSjet_2", &byLooseDeepVSjet_2, "byLooseDeepVSjet_2/F");
    Run_Tree->Branch("byMediumDeepVSjet_2", &byMediumDeepVSjet_2, "byMediumDeepVSjet_2/F");
    Run_Tree->Branch("byTightDeepVSjet_2", &byTightDeepVSjet_2, "byTightDeepVSjet_2/F");
    Run_Tree->Branch("byVTightDeepVSjet_2", &byVTightDeepVSjet_2, "byVTightDeepVSjet_2/F");
    Run_Tree->Branch("byVVTightDeepVSjet_2", &byVVTightDeepVSjet_2, "byVVTightDeepVSjet_2/F");
    Run_Tree->Branch("byVLooseDeepVSmu_2", &byVLooseDeepVSmu_2, "byVLooseDeepVSmu_2/F");
    Run_Tree->Branch("byLooseDeepVSmu_2", &byLooseDeepVSmu_2, "byLooseDeepVSmu_2/F");
    Run_Tree->Branch("byMediumDeepVSmu_2", &byMediumDeepVSmu_2, "byMediumDeepVSmu_2/F");
    Run_Tree->Branch("byTightDeepVSmu_2", &byTightDeepVSmu_2, "byTightDeepVSmu_2/F");
    Run_Tree->Branch("byVTightDeepVSmu_2", &byVTightDeepVSmu_2, "byVTightDeepVSmu_2/F");
    Run_Tree->Branch("byVVTightDeepVSmu_2", &byVVTightDeepVSmu_2, "byVVTightDeepVSmu_2/F");
    Run_Tree->Branch("byVVVLooseDeepVSe_2", &byVVVLooseDeepVSe_2, "byVVVLooseDeepVSe_2/F");
    Run_Tree->Branch("byVVLooseDeepVSe_2", &byVVLooseDeepVSe_2, "byVVLooseDeepVSe_2/F");
    Run_Tree->Branch("byVLooseDeepVSe_2", &byVLooseDeepVSe_2, "byVLooseDeepVSe_2/F");
    Run_Tree->Branch("byLooseDeepVSe_2", &byLooseDeepVSe_2, "byLooseDeepVSe_2/F");
    Run_Tree->Branch("byMediumDeepVSe_2", &byMediumDeepVSe_2, "byMediumDeepVSe_2/F");
    Run_Tree->Branch("byTightDeepVSe_2", &byTightDeepVSe_2, "byTightDeepVSe_2/F");
    Run_Tree->Branch("byVTightDeepVSe_2", &byVTightDeepVSe_2, "byVTightDeepVSe_2/F");
    Run_Tree->Branch("byVVTightDeepVSe_2", &byVVTightDeepVSe_2, "byVVTightDeepVSe_2/F");

    Run_Tree->Branch("numGenJets", &numGenJets, "numGenJets/F");
    Run_Tree->Branch("jetPt_2", &jetPt_2, "jetPt_2/F");

    Run_Tree->Branch("Flag_ecalBadCalibReducedMINIAODFilter", &Flag_ecalBadCalibReducedMINIAODFilter, "Flag_ecalBadCalibReducedMINIAODFilter/F");
    Run_Tree->Branch("Flag_goodVertices", &Flag_goodVertices, "Flag_goodVertices/F");
    Run_Tree->Branch("Flag_globalSuperTightHalo2016Filter", &Flag_globalSuperTightHalo2016Filter, "Flag_globalSuperTightHalo2016Filter/F");
    Run_Tree->Branch("Flag_eeBadScFilter", &Flag_eeBadScFilter, "Flag_eeBadScFilter/F");
    Run_Tree->Branch("Flag_ecalBadCalibFilter", &Flag_ecalBadCalibFilter, "Flag_ecalBadCalibFilter/F");
    Run_Tree->Branch("Flag_badMuons", &Flag_badMuons, "Flag_badMuons/F");
    Run_Tree->Branch("Flag_duplicateMuons", &Flag_duplicateMuons, "Flag_duplicateMuons/F");
    Run_Tree->Branch("Flag_HBHENoiseIsoFilter", &Flag_HBHENoiseIsoFilter, "Flag_HBHENoiseIsoFilter/F");
    Run_Tree->Branch("Flag_HBHENoiseFilter", &Flag_HBHENoiseFilter, "Flag_HBHENoiseFilter/F");
    Run_Tree->Branch("Flag_EcalDeadCellTriggerPrimitiveFilter", &Flag_EcalDeadCellTriggerPrimitiveFilter, "Flag_EcalDeadCellTriggerPrimitiveFilter/F");
    Run_Tree->Branch("Flag_BadPFMuonFilter", &Flag_BadPFMuonFilter, "Flag_BadPFMuonFilter/F");
    Run_Tree->Branch("Flag_BadChargedCandidateFilter", &Flag_BadChargedCandidateFilter, "Flag_BadChargedCandidateFilter/F");

    Run_Tree->Branch("met", &met, "met/F");
    Run_Tree->Branch("metSig", &metSig, "metSig/F");
    Run_Tree->Branch("metcov00", &metcov00, "metcov00/F");
    Run_Tree->Branch("metcov10", &metcov10, "metcov10/F");
    Run_Tree->Branch("metcov11", &metcov11, "metcov11/F");
    Run_Tree->Branch("metcov01", &metcov01, "metcov01/F");
    Run_Tree->Branch("metphi", &metphi, "metphi/F");
    Run_Tree->Branch("met_py", &met_py, "met_py/F");
    Run_Tree->Branch("met_px", &met_px, "met_px/F");
    Run_Tree->Branch("met_UESUp", &met_UESUp, "met_UESUp/F");
    Run_Tree->Branch("metphi_UESUp", &metphi_UESUp, "metphi_UESUp/F");
    Run_Tree->Branch("met_UESDown", &met_UESDown, "met_UESDown/F");
    Run_Tree->Branch("metphi_UESDown", &metphi_UESDown, "metphi_UESDown/F");

    Run_Tree->Branch("met_JetAbsoluteUp", &met_JetAbsoluteUp, "met_JetAbsoluteUp/F");
    Run_Tree->Branch("metphi_JetAbsoluteUp", &metphi_JetAbsoluteUp, "metphi_JetAbsoluteUp/F");
    Run_Tree->Branch("met_JetAbsoluteDown", &met_JetAbsoluteDown, "met_JetAbsoluteDown/F");
    Run_Tree->Branch("metphi_JetAbsoluteDown", &metphi_JetAbsoluteDown, "metphi_JetAbsoluteDown/F");
    Run_Tree->Branch("met_JetAbsoluteyearUp", &met_JetAbsoluteyearUp, "met_JetAbsoluteyearUp/F");
    Run_Tree->Branch("metphi_JetAbsoluteyearUp", &metphi_JetAbsoluteyearUp, "metphi_JetAbsoluteyearUp/F");
    Run_Tree->Branch("met_JetAbsoluteyearDown", &met_JetAbsoluteyearDown, "met_JetAbsoluteyearDown/F");
    Run_Tree->Branch("metphi_JetAbsoluteyearDown", &metphi_JetAbsoluteyearDown, "metphi_JetAbsoluteyearDown/F");
    Run_Tree->Branch("met_JetBBEC1Up", &met_JetBBEC1Up, "met_JetBBEC1Up/F");
    Run_Tree->Branch("metphi_JetBBEC1Up", &metphi_JetBBEC1Up, "metphi_JetBBEC1Up/F");
    Run_Tree->Branch("met_JetBBEC1Down", &met_JetBBEC1Down, "met_JetBBEC1Down/F");
    Run_Tree->Branch("metphi_JetBBEC1Down", &metphi_JetBBEC1Down, "metphi_JetBBEC1Down/F");
    Run_Tree->Branch("met_JetBBEC1yearUp", &met_JetBBEC1yearUp, "met_JetBBEC1yearUp/F");
    Run_Tree->Branch("metphi_JetBBEC1yearUp", &metphi_JetBBEC1yearUp, "metphi_JetBBEC1yearUp/F");
    Run_Tree->Branch("met_JetBBEC1yearDown", &met_JetBBEC1yearDown, "met_JetBBEC1yearDown/F");
    Run_Tree->Branch("metphi_JetBBEC1yearDown", &metphi_JetBBEC1yearDown, "metphi_JetBBEC1yearDown/F");
    Run_Tree->Branch("met_JetEC2Up", &met_JetEC2Up, "met_JetEC2Up/F");
    Run_Tree->Branch("metphi_JetEC2Up", &metphi_JetEC2Up, "metphi_JetEC2Up/F");
    Run_Tree->Branch("met_JetEC2Down", &met_JetEC2Down, "met_JetEC2Down/F");
    Run_Tree->Branch("metphi_JetEC2Down", &metphi_JetEC2Down, "metphi_JetEC2Down/F");
    Run_Tree->Branch("met_JetEC2yearUp", &met_JetEC2yearUp, "met_JetEC2yearUp/F");
    Run_Tree->Branch("metphi_JetEC2yearUp", &metphi_JetEC2yearUp, "metphi_JetEC2yearUp/F");
    Run_Tree->Branch("met_JetEC2yearDown", &met_JetEC2yearDown, "met_JetEC2yearDown/F");
    Run_Tree->Branch("metphi_JetEC2yearDown", &metphi_JetEC2yearDown, "metphi_JetEC2yearDown/F");
    Run_Tree->Branch("met_JetFlavorQCDUp", &met_JetFlavorQCDUp, "met_JetFlavorQCDUp/F");
    Run_Tree->Branch("metphi_JetFlavorQCDUp", &metphi_JetFlavorQCDUp, "metphi_JetFlavorQCDUp/F");
    Run_Tree->Branch("met_JetFlavorQCDDown", &met_JetFlavorQCDDown, "met_JetFlavorQCDDown/F");
    Run_Tree->Branch("metphi_JetFlavorQCDDown", &metphi_JetFlavorQCDDown, "metphi_JetFlavorQCDDown/F");
    Run_Tree->Branch("met_JetHFUp", &met_JetHFUp, "met_JetHFUp/F");
    Run_Tree->Branch("metphi_JetHFUp", &metphi_JetHFUp, "metphi_JetHFUp/F");
    Run_Tree->Branch("met_JetHFDown", &met_JetHFDown, "met_JetHFDown/F");
    Run_Tree->Branch("metphi_JetHFDown", &metphi_JetHFDown, "metphi_JetHFDown/F");
    Run_Tree->Branch("met_JetHFyearUp", &met_JetHFyearUp, "met_JetHFyearUp/F");
    Run_Tree->Branch("metphi_JetHFyearUp", &metphi_JetHFyearUp, "metphi_JetHFyearUp/F");
    Run_Tree->Branch("met_JetHFyearDown", &met_JetHFyearDown, "met_JetHFyearDown/F");
    Run_Tree->Branch("metphi_JetHFyearDown", &metphi_JetHFyearDown, "metphi_JetHFyearDown/F");
    Run_Tree->Branch("met_JetRelativeBalUp", &met_JetRelativeBalUp, "met_JetRelativeBalUp/F");
    Run_Tree->Branch("metphi_JetRelativeBalUp", &metphi_JetRelativeBalUp, "metphi_JetRelativeBalUp/F");
    Run_Tree->Branch("met_JetRelativeBalDown", &met_JetRelativeBalDown, "met_JetRelativeBalDown/F");
    Run_Tree->Branch("metphi_JetRelativeBalDown", &metphi_JetRelativeBalDown, "metphi_JetRelativeBalDown/F");
    Run_Tree->Branch("met_JetRelativeSampleUp", &met_JetRelativeSampleUp, "met_JetRelativeSampleUp/F");
    Run_Tree->Branch("metphi_JetRelativeSampleUp", &metphi_JetRelativeSampleUp, "metphi_JetRelativeSampleUp/F");
    Run_Tree->Branch("met_JetRelativeSampleDown", &met_JetRelativeSampleDown, "met_JetRelativeSampleDown/F");
    Run_Tree->Branch("metphi_JetRelativeSampleDown", &metphi_JetRelativeSampleDown, "metphi_JetRelativeSampleDown/F");
    Run_Tree->Branch("met_JERUp", &met_JERUp, "met_JERUp/F");
    Run_Tree->Branch("metphi_JERUp", &metphi_JERUp, "metphi_JERUp/F");
    Run_Tree->Branch("met_JERDown", &met_JERDown, "met_JERDown/F");
    Run_Tree->Branch("metphi_JERDown", &metphi_JERDown, "metphi_JERDown/F");

    Run_Tree->Branch("met_responseUp", &met_responseUp, "met_responseUp/F");
    Run_Tree->Branch("met_responseDown", &met_responseDown, "met_responseDown/F");
    Run_Tree->Branch("met_resolutionUp", &met_resolutionUp, "met_resolutionUp/F");
    Run_Tree->Branch("met_resolutionDown", &met_resolutionDown, "met_resolutionDown/F");
    Run_Tree->Branch("metphi_responseUp", &metphi_responseUp, "metphi_responseUp/F");
    Run_Tree->Branch("metphi_responseDown", &metphi_responseDown, "metphi_responseDown/F");
    Run_Tree->Branch("metphi_resolutionUp", &metphi_resolutionUp, "metphi_resolutionUp/F");
    Run_Tree->Branch("metphi_resolutionDown", &metphi_resolutionDown, "metphi_resolutionDown/F");

    Run_Tree->Branch("passDoubleTau35", &passDoubleTau35, "passDoubleTau35/F");
    Run_Tree->Branch("passDoubleTauCmb35", &passDoubleTauCmb35, "passDoubleTauCmb35/F");
    Run_Tree->Branch("matchDoubleTau35_1", &matchDoubleTau35_1, "matchDoubleTau35_1/F");
    Run_Tree->Branch("matchDoubleTauCmb35_1", &matchDoubleTauCmb35_1, "matchDoubleTauCmb35_1/F");
    Run_Tree->Branch("matchDoubleTau35_2", &matchDoubleTau35_2, "matchDoubleTau35_2/F");
    Run_Tree->Branch("matchDoubleTauCmb35_2", &matchDoubleTauCmb35_2, "matchDoubleTauCmb35_2/F");
    Run_Tree->Branch("filterDoubleTau35_1", &filterDoubleTau35_1, "filterDoubleTau35_1/F");
    Run_Tree->Branch("filterDoubleTauCmb35_1", &filterDoubleTauCmb35_1, "filterDoubleTauCmb35_1/F");
    Run_Tree->Branch("filterDoubleTau35_2", &filterDoubleTau35_2, "filterDoubleTau35_2/F");
    Run_Tree->Branch("filterDoubleTauCmb35_2", &filterDoubleTauCmb35_2, "filterDoubleTauCmb35_2/F");

    Run_Tree->Branch("passDoubleTightTau35TightID", &passDoubleTightTau35TightID, "passDoubleTightTau35TightID/F");
    Run_Tree->Branch("passDoubleMediumTau40TightID", &passDoubleMediumTau40TightID, "passDoubleMediumTau40TightID/F");
    Run_Tree->Branch("passDoubleTightTau40ID", &passDoubleTightTau40ID, "passDoubleTightTau40ID/F");
    Run_Tree->Branch("matchDoubleTightTau35TightID_1", &matchDoubleTightTau35TightID_1, "matchDoubleTightTau35TightID_1/F");
    Run_Tree->Branch("matchDoubleMediumTau40TightID_1", &matchDoubleMediumTau40TightID_1, "matchDoubleMediumTau40TightID_1/F");
    Run_Tree->Branch("matchDoubleTightTau40ID_1", &matchDoubleTightTau40ID_1, "matchDoubleTightTau40ID_1/F");
    Run_Tree->Branch("filterDoubleTightTau35TightID_1", &filterDoubleTightTau35TightID_1, "filterDoubleTightTau35TightID_1/F");
    Run_Tree->Branch("filterDoubleMediumTau40TightID_1", &filterDoubleMediumTau40TightID_1, "filterDoubleMediumTau40TightID_1/F");
    Run_Tree->Branch("filterDoubleTightTau40ID_1", &filterDoubleTightTau40ID_1, "filterDoubleTightTau40ID_1/F");
    Run_Tree->Branch("matchDoubleTightTau35TightID_2", &matchDoubleTightTau35TightID_2, "matchDoubleTightTau35TightID_2/F");
    Run_Tree->Branch("matchDoubleMediumTau40TightID_2", &matchDoubleMediumTau40TightID_2, "matchDoubleMediumTau40TightID_2/F");
    Run_Tree->Branch("matchDoubleTightTau40ID_2", &matchDoubleTightTau40ID_2, "matchDoubleTightTau40ID_2/F");
    Run_Tree->Branch("filterDoubleTightTau35TightID_2", &filterDoubleTightTau35TightID_2, "filterDoubleTightTau35TightID_2/F");
    Run_Tree->Branch("filterDoubleMediumTau40TightID_2", &filterDoubleMediumTau40TightID_2, "filterDoubleMediumTau40TightID_2/F");
    Run_Tree->Branch("filterDoubleTightTau40ID_2", &filterDoubleTightTau40ID_2, "filterDoubleTightTau40ID_2/F");

    Run_Tree->Branch("passDoubleMediumHPSTau35", &passDoubleMediumHPSTau35, "passDoubleMediumHPSTau35/F");
    Run_Tree->Branch("matchDoubleMediumHPSTau35_1", &matchDoubleMediumHPSTau35_1, "matchDoubleMediumHPSTau35_1/F");
    Run_Tree->Branch("filterDoubleMediumHPSTau35_1", &filterDoubleMediumHPSTau35_1, "filterDoubleMediumHPSTau35_1/F");
    Run_Tree->Branch("matchDoubleMediumHPSTau35_2", &matchDoubleMediumHPSTau35_2, "matchDoubleMediumHPSTau35_2/F");
    Run_Tree->Branch("filterDoubleMediumHPSTau35_2", &filterDoubleMediumHPSTau35_2, "filterDoubleMediumHPSTau35_2/F");

    Run_Tree->Branch("mjj", &mjj, "mjj/F");
    Run_Tree->Branch("mjj_JetAbsoluteUp", &mjj_JetAbsoluteUp, "mjj_JetAbsoluteUp/F");
    Run_Tree->Branch("mjj_JetAbsoluteDown", &mjj_JetAbsoluteDown, "mjj_JetAbsoluteDown/F");
    Run_Tree->Branch("mjj_JetAbsoluteyearUp", &mjj_JetAbsoluteyearUp, "mjj_JetAbsoluteyearUp/F");
    Run_Tree->Branch("mjj_JetAbsoluteyearDown", &mjj_JetAbsoluteyearDown, "mjj_JetAbsoluteyearDown/F");
    Run_Tree->Branch("mjj_JetBBEC1Up", &mjj_JetBBEC1Up, "mjj_JetBBEC1Up/F");
    Run_Tree->Branch("mjj_JetBBEC1Down", &mjj_JetBBEC1Down, "mjj_JetBBEC1Down/F");
    Run_Tree->Branch("mjj_JetBBEC1yearUp", &mjj_JetBBEC1yearUp, "mjj_JetBBEC1yearUp/F");
    Run_Tree->Branch("mjj_JetBBEC1yearDown", &mjj_JetBBEC1yearDown, "mjj_JetBBEC1yearDown/F");
    Run_Tree->Branch("mjj_JetEC2Up", &mjj_JetEC2Up, "mjj_JetEC2Up/F");
    Run_Tree->Branch("mjj_JetEC2Down", &mjj_JetEC2Down, "mjj_JetEC2Down/F");
    Run_Tree->Branch("mjj_JetEC2yearUp", &mjj_JetEC2yearUp, "mjj_JetEC2yearUp/F");
    Run_Tree->Branch("mjj_JetEC2yearDown", &mjj_JetEC2yearDown, "mjj_JetEC2yearDown/F");
    Run_Tree->Branch("mjj_JetFlavorQCDUp", &mjj_JetFlavorQCDUp, "mjj_JetFlavorQCDUp/F");
    Run_Tree->Branch("mjj_JetFlavorQCDDown", &mjj_JetFlavorQCDDown, "mjj_JetFlavorQCDDown/F");
    Run_Tree->Branch("mjj_JetHFUp", &mjj_JetHFUp, "mjj_JetHFUp/F");
    Run_Tree->Branch("mjj_JetHFDown", &mjj_JetHFDown, "mjj_JetHFDown/F");
    Run_Tree->Branch("mjj_JetHFyearUp", &mjj_JetHFyearUp, "mjj_JetHFyearUp/F");
    Run_Tree->Branch("mjj_JetHFyearDown", &mjj_JetHFyearDown, "mjj_JetHFyearDown/F");
    Run_Tree->Branch("mjj_JetRelativeBalUp", &mjj_JetRelativeBalUp, "mjj_JetRelativeBalUp/F");
    Run_Tree->Branch("mjj_JetRelativeBalDown", &mjj_JetRelativeBalDown, "mjj_JetRelativeBalDown/F");
    Run_Tree->Branch("mjj_JetRelativeSampleUp", &mjj_JetRelativeSampleUp, "mjj_JetRelativeSampleUp/F");
    Run_Tree->Branch("mjj_JetRelativeSampleDown", &mjj_JetRelativeSampleDown, "mjj_JetRelativeSampleDown/F");
    Run_Tree->Branch("mjj_JERUp", &mjj_JERUp, "mjj_JERUp/F");
    Run_Tree->Branch("mjj_JERDown", &mjj_JERDown, "mjj_JERDown/F");

    Run_Tree->Branch("gen_match_1", &gen_match_1, "gen_match_1/I");
    Run_Tree->Branch("gen_match_2", &gen_match_2, "gen_match_2/I");

    Run_Tree->Branch("njets", &njets, "njets/I");
    Run_Tree->Branch("njets_JetAbsoluteUp", &njets_JetAbsoluteUp, "njets_JetAbsoluteUp/I");
    Run_Tree->Branch("njets_JetAbsoluteDown", &njets_JetAbsoluteDown, "njets_JetAbsoluteDown/I");
    Run_Tree->Branch("njets_JetAbsoluteyearUp", &njets_JetAbsoluteyearUp, "njets_JetAbsoluteyearUp/I");
    Run_Tree->Branch("njets_JetAbsoluteyearDown", &njets_JetAbsoluteyearDown, "njets_JetAbsoluteyearDown/I");
    Run_Tree->Branch("njets_JetBBEC1Up", &njets_JetBBEC1Up, "njets_JetBBEC1Up/I");
    Run_Tree->Branch("njets_JetBBEC1Down", &njets_JetBBEC1Down, "njets_JetBBEC1Down/I");
    Run_Tree->Branch("njets_JetBBEC1yearUp", &njets_JetBBEC1yearUp, "njets_JetBBEC1yearUp/I");
    Run_Tree->Branch("njets_JetBBEC1yearDown", &njets_JetBBEC1yearDown, "njets_JetBBEC1yearDown/I");
    Run_Tree->Branch("njets_JetEC2Up", &njets_JetEC2Up, "njets_JetEC2Up/I");
    Run_Tree->Branch("njets_JetEC2Down", &njets_JetEC2Down, "njets_JetEC2Down/I");
    Run_Tree->Branch("njets_JetEC2yearUp", &njets_JetEC2yearUp, "njets_JetEC2yearUp/I");
    Run_Tree->Branch("njets_JetEC2yearDown", &njets_JetEC2yearDown, "njets_JetEC2yearDown/I");
    Run_Tree->Branch("njets_JetFlavorQCDUp", &njets_JetFlavorQCDUp, "njets_JetFlavorQCDUp/I");
    Run_Tree->Branch("njets_JetFlavorQCDDown", &njets_JetFlavorQCDDown, "njets_JetFlavorQCDDown/I");
    Run_Tree->Branch("njets_JetHFUp", &njets_JetHFUp, "njets_JetHFUp/I");
    Run_Tree->Branch("njets_JetHFDown", &njets_JetHFDown, "njets_JetHFDown/I");
    Run_Tree->Branch("njets_JetHFyearUp", &njets_JetHFyearUp, "njets_JetHFyearUp/I");
    Run_Tree->Branch("njets_JetHFyearDown", &njets_JetHFyearDown, "njets_JetHFyearDown/I");
    Run_Tree->Branch("njets_JetRelativeBalUp", &njets_JetRelativeBalUp, "njets_JetRelativeBalUp/I");
    Run_Tree->Branch("njets_JetRelativeBalDown", &njets_JetRelativeBalDown, "njets_JetRelativeBalDown/I");
    Run_Tree->Branch("njets_JetRelativeSampleUp", &njets_JetRelativeSampleUp, "njets_JetRelativeSampleUp/I");
    Run_Tree->Branch("njets_JetRelativeSampleDown", &njets_JetRelativeSampleDown, "njets_JetRelativeSampleDown/I");
    Run_Tree->Branch("njets_JERUp", &njets_JERUp, "njets_JERUp/I");
    Run_Tree->Branch("njets_JERDown", &njets_JERDown, "njets_JERDown/I");

    Run_Tree->Branch("jpt_1", &jpt_1, "jpt_1/F");
    Run_Tree->Branch("jpt_1_JetAbsoluteUp", &jpt_1_JetAbsoluteUp, "jpt_1_JetAbsoluteUp/F");
    Run_Tree->Branch("jpt_1_JetAbsoluteDown", &jpt_1_JetAbsoluteDown, "jpt_1_JetAbsoluteDown/F");
    Run_Tree->Branch("jpt_1_JetAbsoluteyearUp", &jpt_1_JetAbsoluteyearUp, "jpt_1_JetAbsoluteyearUp/F");
    Run_Tree->Branch("jpt_1_JetAbsoluteyearDown", &jpt_1_JetAbsoluteyearDown, "jpt_1_JetAbsoluteyearDown/F");
    Run_Tree->Branch("jpt_1_JetBBEC1Up", &jpt_1_JetBBEC1Up, "jpt_1_JetBBEC1Up/F");
    Run_Tree->Branch("jpt_1_JetBBEC1Down", &jpt_1_JetBBEC1Down, "jpt_1_JetBBEC1Down/F");
    Run_Tree->Branch("jpt_1_JetBBEC1yearUp", &jpt_1_JetBBEC1yearUp, "jpt_1_JetBBEC1yearUp/F");
    Run_Tree->Branch("jpt_1_JetBBEC1yearDown", &jpt_1_JetBBEC1yearDown, "jpt_1_JetBBEC1yearDown/F");
    Run_Tree->Branch("jpt_1_JetEC2Up", &jpt_1_JetEC2Up, "jpt_1_JetEC2Up/F");
    Run_Tree->Branch("jpt_1_JetEC2Down", &jpt_1_JetEC2Down, "jpt_1_JetEC2Down/F");
    Run_Tree->Branch("jpt_1_JetEC2yearUp", &jpt_1_JetEC2yearUp, "jpt_1_JetEC2yearUp/F");
    Run_Tree->Branch("jpt_1_JetEC2yearDown", &jpt_1_JetEC2yearDown, "jpt_1_JetEC2yearDown/F");
    Run_Tree->Branch("jpt_1_JetFlavorQCDUp", &jpt_1_JetFlavorQCDUp, "jpt_1_JetFlavorQCDUp/F");
    Run_Tree->Branch("jpt_1_JetFlavorQCDDown", &jpt_1_JetFlavorQCDDown, "jpt_1_JetFlavorQCDDown/F");
    Run_Tree->Branch("jpt_1_JetHFUp", &jpt_1_JetHFUp, "jpt_1_JetHFUp/F");
    Run_Tree->Branch("jpt_1_JetHFDown", &jpt_1_JetHFDown, "jpt_1_JetHFDown/F");
    Run_Tree->Branch("jpt_1_JetHFyearUp", &jpt_1_JetHFyearUp, "jpt_1_JetHFyearUp/F");
    Run_Tree->Branch("jpt_1_JetHFyearDown", &jpt_1_JetHFyearDown, "jpt_1_JetHFyearDown/F");
    Run_Tree->Branch("jpt_1_JetRelativeBalUp", &jpt_1_JetRelativeBalUp, "jpt_1_JetRelativeBalUp/F");
    Run_Tree->Branch("jpt_1_JetRelativeBalDown", &jpt_1_JetRelativeBalDown, "jpt_1_JetRelativeBalDown/F");
    Run_Tree->Branch("jpt_1_JetRelativeSampleUp", &jpt_1_JetRelativeSampleUp, "jpt_1_JetRelativeSampleUp/F");
    Run_Tree->Branch("jpt_1_JetRelativeSampleDown", &jpt_1_JetRelativeSampleDown, "jpt_1_JetRelativeSampleDown/F");
    Run_Tree->Branch("jpt_1_JERUp", &jpt_1_JERUp, "jpt_1_JERUp/F");
    Run_Tree->Branch("jpt_1_JERDown", &jpt_1_JERDown, "jpt_1_JERDown/F");

    Run_Tree->Branch("jeta_1", &jeta_1, "jeta_1/F");
    Run_Tree->Branch("jphi_1", &jphi_1, "jphi_1/F");

    Run_Tree->Branch("jpt_2", &jpt_2, "jpt_2/F");
    Run_Tree->Branch("jeta_2", &jeta_2, "jeta_2/F");
    Run_Tree->Branch("jphi_2", &jphi_2, "jphi_2/F");
    Run_Tree->Branch("jcsv_1", &jcsv_1, "jcsv_1/F");
    Run_Tree->Branch("jcsv_2", &jcsv_2, "jcsv_2/F");

    Run_Tree->Branch("bweight", &bweight, "bweight/F");

    Run_Tree->Branch("bpt_deepcsv_1", &bpt_deepcsv_1, "bpt_deepcsv_1/F");
    Run_Tree->Branch("bflavour_deepcsv_1", &bflavour_deepcsv_1, "bflavour_deepcsv_1/F");
    Run_Tree->Branch("beta_deepcsv_1", &beta_deepcsv_1, "beta_deepcsv_1/F");
    Run_Tree->Branch("bphi_deepcsv_1", &bphi_deepcsv_1, "bphi_deepcsv_1/F");
    Run_Tree->Branch("bm_deepcsv_1", &bm_deepcsv_1, "bm_deepcsv_1/F");
    Run_Tree->Branch("bscore_deepcsv_1", &bscore_deepcsv_1, "bscore_deepcsv_1/F");
    Run_Tree->Branch("bpt_deepcsv_2", &bpt_deepcsv_2, "bpt_deepcsv_2/F");
    Run_Tree->Branch("bflavour_deepcsv_2", &bflavour_deepcsv_2, "bflavour_deepcsv_2/F");
    Run_Tree->Branch("beta_deepcsv_2", &beta_deepcsv_2, "beta_deepcsv_2/F");
    Run_Tree->Branch("bphi_deepcsv_2", &bphi_deepcsv_2, "bphi_deepcsv_2/F");
    Run_Tree->Branch("bm_deepcsv_2", &bm_deepcsv_2, "bm_deepcsv_2/F");
    Run_Tree->Branch("bscore_deepcsv_2", &bscore_deepcsv_2, "bscore_deepcsv_2/F");

    Run_Tree->Branch("bpt_deepflavour_1", &bpt_deepflavour_1, "bpt_deepflavour_1/F");
    Run_Tree->Branch("bflavour_deepflavour_1", &bflavour_deepflavour_1, "bflavour_deepflavour_1/F");
    Run_Tree->Branch("beta_deepflavour_1", &beta_deepflavour_1, "beta_deepflavour_1/F");
    Run_Tree->Branch("bphi_deepflavour_1", &bphi_deepflavour_1, "bphi_deepflavour_1/F");
    Run_Tree->Branch("bm_deepflavour_1", &bm_deepflavour_1, "bm_deepflavour_1/F");
    Run_Tree->Branch("bscore_deepflavour_1", &bscore_deepflavour_1, "bscore_deepflavour_1/F");
    Run_Tree->Branch("bpt_deepflavour_2", &bpt_deepflavour_2, "bpt_deepflavour_2/F");
    Run_Tree->Branch("bflavour_deepflavour_2", &bflavour_deepflavour_2, "bflavour_deepflavour_2/F");
    Run_Tree->Branch("beta_deepflavour_2", &beta_deepflavour_2, "beta_deepflavour_2/F");
    Run_Tree->Branch("bphi_deepflavour_2", &bphi_deepflavour_2, "bphi_deepflavour_2/F");
    Run_Tree->Branch("bm_deepflavour_2", &bm_deepflavour_2, "bm_deepflavour_2/F");
    Run_Tree->Branch("bscore_deepflavour_2", &bscore_deepflavour_2, "bscore_deepflavour_2/F");

    Run_Tree->Branch("pt_top1", &pt_top1, "pt_top1/F");
    Run_Tree->Branch("pt_top2", &pt_top2, "pt_top2/F");
    Run_Tree->Branch("genweight", &genweight, "genweight/F");

    Run_Tree->Branch("gen_Higgs_pt", &gen_Higgs_pt, "gen_Higgs_pt/F");
    Run_Tree->Branch("gen_Higgs_mass", &gen_Higgs_mass, "gen_Higgs_mass/F");

    Run_Tree->Branch("genpt_1", &genpt_1, "genpt_1/F");
    Run_Tree->Branch("geneta_1", &geneta_1, "geneta_1/F");
    Run_Tree->Branch("genpt_2", &genpt_2, "genpt_2/F");
    Run_Tree->Branch("geneta_2", &geneta_2, "geneta_2/F");

    int threshold_deepflavour_L=0.0614;
    int threshold_deepflavour_M=0.3093;
    int threshold_deepcsv_L=0.2217;
    int threshold_deepcsv_M=0.6321;
    if (year==2017){
       threshold_deepflavour_L=0.0521;
       threshold_deepflavour_M=0.3033;
       threshold_deepcsv_L=0.1522;
       threshold_deepcsv_M=0.4941;
    }
    if (year==2018){
       threshold_deepflavour_L=0.0494;
       threshold_deepflavour_M=0.2770;
       threshold_deepcsv_L=0.1241;
       threshold_deepcsv_M=0.4184;
    }

    float tes_dm0=tes_dm0_2018;
    float tes_dm1=tes_dm1_2018;
    float tes_dm10=tes_dm10_2018;
    float tes_dm11=tes_dm11_2018;
    float tes_dm0_emb=tes_dm0_emb_2018;
    float tes_dm1_emb=tes_dm1_emb_2018;
    float tes_dm10_emb=tes_dm10_emb_2018;
    float tes_dm11_emb=tes_dm11_emb_2018;
    float tes_dm0_fakeele=tes_dm0_fakeele_2018;
    float tes_dm1_fakeele=tes_dm1_fakeele_2018;
    float tes_B_fakeele_emb=tes_B_fakeele_emb_2018;
    float tes_E_fakeele_emb=tes_E_fakeele_emb_2018;
    float tes_dm0_fakemu=tes_dm0_fakemu_2018;
    float tes_dm1_fakemu=tes_dm1_fakemu_2018;

    if (year==2017){
       tes_dm0=tes_dm0_2017;
       tes_dm1=tes_dm1_2017;
       tes_dm10=tes_dm10_2017;
       tes_dm11=tes_dm11_2017;
       tes_dm0_emb=tes_dm0_emb_2017;
       tes_dm1_emb=tes_dm1_emb_2017;
       tes_dm10_emb=tes_dm10_emb_2017;
       tes_dm11_emb=tes_dm11_emb_2017;
       tes_dm0_fakeele=tes_dm0_fakeele_2017;
       tes_dm1_fakeele=tes_dm1_fakeele_2017;
       tes_B_fakeele_emb=tes_B_fakeele_emb_2017;
       tes_E_fakeele_emb=tes_E_fakeele_emb_2017;
       tes_dm0_fakemu=tes_dm0_fakemu_2017;
       tes_dm1_fakemu=tes_dm1_fakemu_2017;
    }
    if (year==2016){
       tes_dm0=tes_dm0_2016;
       tes_dm1=tes_dm1_2016;
       tes_dm10=tes_dm10_2016;
       tes_dm11=tes_dm11_2016;
       tes_dm0_emb=tes_dm0_emb_2016;
       tes_dm1_emb=tes_dm1_emb_2016;
       tes_dm10_emb=tes_dm10_emb_2016;
       tes_dm11_emb=tes_dm11_emb_2016;
       tes_dm0_fakeele=tes_dm0_fakeele_2016;
       tes_dm1_fakeele=tes_dm1_fakeele_2016;
       tes_B_fakeele_emb=tes_B_fakeele_emb_2016;
       tes_E_fakeele_emb=tes_E_fakeele_emb_2016;
       tes_dm0_fakemu=tes_dm0_fakemu_2016;
       tes_dm1_fakemu=tes_dm1_fakemu_2016;
    }


    int bestEntry=-1;
    ULong64_t evt_now=0;
    ULong64_t evt_before=-1;
    float lt_before=0;
    plotFill("nevents",0,9,0,9,evCounter->GetBinContent(1));
    plotFill("nevents",1,9,0,9,evCounterW->GetBinContent(1));
    for (int iEntry = 0; iEntry < tree->GetEntries() ; iEntry++)
    {
        float pu=1.0;
        tree->GetEntry(iEntry);
        bool print=false;
        if (iEntry % 1000 == 0) fprintf(stdout, "\r  Processed events: %8d ", iEntry);
        fflush(stdout);
        plotFill("pileup_mc",tree->nTruePU,80,0,80);
        TLorentzVector dau1;
        TLorentzVector dau2;
        dau1.SetPtEtaPhiM(tree->t1Pt,tree->t1Eta,tree->t1Phi,tree->t1Mass);
        dau2.SetPtEtaPhiM(tree->t2Pt,tree->t2Eta,tree->t2Phi,tree->t2Mass);

        if (isMC){
           if (tree->t1ZTTGenMatching==5 && tree->t1DecayMode==0) dau1=dau1*tes_dm0;
           else if (tree->t1ZTTGenMatching==5 && tree->t1DecayMode==1) dau1=dau1*tes_dm1;
           else if (tree->t1ZTTGenMatching==5 && tree->t1DecayMode==10) dau1=dau1*tes_dm10;
           else if (tree->t1ZTTGenMatching==5 && tree->t1DecayMode==11) dau1=dau1*tes_dm11;
           else if ((tree->t1ZTTGenMatching==1 or tree->t1ZTTGenMatching==3) && tree->t1DecayMode==0) dau1=dau1*tes_dm0_fakeele;
           else if ((tree->t1ZTTGenMatching==1 or tree->t1ZTTGenMatching==3) && tree->t1DecayMode==1) dau1=dau1*tes_dm1_fakeele;
           else if ((tree->t1ZTTGenMatching==2 or tree->t1ZTTGenMatching==4) && tree->t1DecayMode==0) dau1=dau1*tes_dm0_fakemu;
           else if ((tree->t1ZTTGenMatching==2 or tree->t1ZTTGenMatching==4) && tree->t1DecayMode==1) dau1=dau1*tes_dm1_fakemu;

           if (tree->t2ZTTGenMatching==5 && tree->t2DecayMode==0) dau2=dau2*tes_dm0;
           else if (tree->t2ZTTGenMatching==5 && tree->t2DecayMode==1) dau2=dau2*tes_dm1;
           else if (tree->t2ZTTGenMatching==5 && tree->t2DecayMode==10) dau2=dau2*tes_dm10;
           else if (tree->t2ZTTGenMatching==5 && tree->t2DecayMode==11) dau2=dau2*tes_dm11;
           else if ((tree->t2ZTTGenMatching==1 or tree->t2ZTTGenMatching==3) && tree->t2DecayMode==0) dau2=dau2*tes_dm0_fakeele;
           else if ((tree->t2ZTTGenMatching==1 or tree->t2ZTTGenMatching==3) && tree->t2DecayMode==1) dau2=dau2*tes_dm1_fakeele;
           else if ((tree->t2ZTTGenMatching==2 or tree->t2ZTTGenMatching==4) && tree->t2DecayMode==0) dau2=dau2*tes_dm0_fakemu;
           else if ((tree->t2ZTTGenMatching==2 or tree->t2ZTTGenMatching==4) && tree->t2DecayMode==1) dau2=dau2*tes_dm1_fakemu;
        }
        else if (isEmbedded){
           if(tree->t1ZTTGenMatching==5 && tree->t1DecayMode==0) dau1=dau1*tes_dm0_emb;
           else if (tree->t1ZTTGenMatching==5 && tree->t1DecayMode==1) dau1=dau1*tes_dm1_emb;
           else if (tree->t1ZTTGenMatching==5 && tree->t1DecayMode==10) dau1=dau1*tes_dm10_emb;
           else if (tree->t1ZTTGenMatching==5 && tree->t1DecayMode==11) dau1=dau1*tes_dm11_emb;
           else if ((tree->t1ZTTGenMatching==1 or tree->t1ZTTGenMatching==3) && fabs(tree->t1Eta)>1.5) dau1=dau1*tes_E_fakeele_emb;
           else if ((tree->t1ZTTGenMatching==1 or tree->t1ZTTGenMatching==3) && fabs(tree->t1Eta)<1.5) dau1=dau1*tes_B_fakeele_emb;

           if(tree->t2ZTTGenMatching==5 && tree->t2DecayMode==0) dau2=dau2*tes_dm0_emb;
           else if (tree->t2ZTTGenMatching==5 && tree->t2DecayMode==1) dau2=dau2*tes_dm1_emb;
           else if (tree->t2ZTTGenMatching==5 && tree->t2DecayMode==10) dau2=dau2*tes_dm10_emb;
           else if (tree->t2ZTTGenMatching==5 && tree->t2DecayMode==11) dau2=dau2*tes_dm11_emb;
           else if ((tree->t2ZTTGenMatching==1 or tree->t2ZTTGenMatching==3) && fabs(tree->t2Eta)>1.5) dau2=dau2*tes_E_fakeele_emb;
           else if ((tree->t2ZTTGenMatching==1 or tree->t2ZTTGenMatching==3) && fabs(tree->t2Eta)<1.5) dau2=dau2*tes_B_fakeele_emb;
        }

        if (dau1.DeltaR(dau2)<0.4) continue;
        if (fabs(tree->t1PVDZ)>0.2) continue;
        if (fabs(tree->t2PVDZ)>0.2) continue;
	if (dau1.Pt()<39.0 or dau2.Pt()<39.0) continue;
        if (fabs(dau1.Eta())>2.1 or fabs(dau2.Eta())>2.1) continue;
        if (!tree->t1VVVLooseDeepTau2017v2p1VSjet) continue;
        if (!tree->t1VLooseDeepTau2017v2p1VSmu) continue;
        if (!tree->t1VLooseDeepTau2017v2p1VSe) continue;
        if (tree->t1DecayMode==5 or tree->t1DecayMode==6) continue;
        if (!tree->t2VVVLooseDeepTau2017v2p1VSjet) continue;
        if (!tree->t2VLooseDeepTau2017v2p1VSmu) continue;
        if (!tree->t2VLooseDeepTau2017v2p1VSe) continue;
        if (tree->t2DecayMode==5 or tree->t2DecayMode==6) continue;
	if (tree->eVetoZTTp001dxyzR0>0) continue;
	if (tree->muVetoZTTp001dxyzR0>0) continue;

	int n_deepcsv_L=0;
        int n_deepcsv_M=0;
        int n_deepflavour_L=0;
        int n_deepflavour_M=0;
	if (tree->deepcsvb1_btagscore>=threshold_deepcsv_L) n_deepcsv_L=n_deepcsv_L+1;
        if (tree->deepcsvb2_btagscore>=threshold_deepcsv_L) n_deepcsv_L=n_deepcsv_L+1;
        if (tree->deepcsvb1_btagscore>=threshold_deepcsv_M) n_deepcsv_M=n_deepcsv_M+1;
        if (tree->deepcsvb2_btagscore>=threshold_deepcsv_M) n_deepcsv_M=n_deepcsv_M+1;
        if (tree->deepflavourb1_btagscore>=threshold_deepflavour_L) n_deepflavour_L=n_deepflavour_L+1;
        if (tree->deepflavourb2_btagscore>=threshold_deepflavour_L) n_deepflavour_L=n_deepflavour_L+1; 
        if (tree->deepflavourb1_btagscore>=threshold_deepflavour_M) n_deepflavour_M=n_deepflavour_M+1;
        if (tree->deepflavourb2_btagscore>=threshold_deepflavour_M) n_deepflavour_M=n_deepflavour_M+1;
	if (n_deepcsv_L<2 and n_deepcsv_M<1 and n_deepflavour_L<2 and n_deepflavour_M<1) continue; //at least 2 L btags or 1 M btag

        evt_now=tree->evt;
        if (evt_now!=evt_before){
           lt_before=tree->t1Pt + tree->t2Pt;
        }
        if (evt_now!=evt_before){
           if (bestEntry>-1)
              fillTree(Run_Tree,tree,bestEntry,recoil,isMC,isEmbedded,year);
           bestEntry=iEntry;
        }
        if (evt_now==evt_before){
           if (tree->t1Pt + tree->t2Pt>lt_before+0.0001){
                bestEntry=iEntry;
                lt_before=tree->t1Pt + tree->t2Pt;
           }
        }
        evt_before=evt_now;

    }
    if (bestEntry>-1)
       fillTree(Run_Tree,tree,bestEntry,recoil,isMC,isEmbedded,year);
    fout->cd();
    Run_Tree->Write();
    map<string, TH1F*>::const_iterator iMap1 = myMap1->begin();
    map<string, TH1F*>::const_iterator jMap1 = myMap1->end();
    for (; iMap1 != jMap1; ++iMap1)
        nplot1(iMap1->first)->Write();
    map<string, TH2F*>::const_iterator iMap2 = myMap2->begin();
    map<string, TH2F*>::const_iterator jMap2 = myMap2->end();
    for (; iMap2 != jMap2; ++iMap2)
        nplot2(iMap2->first)->Write();

    fout->Close();
    return 0;
}

