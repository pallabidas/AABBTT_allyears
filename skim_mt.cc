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
#include "mutau_Tree_mt.h"

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

    TTree* treePtr = (TTree*) fIn->Get("mt/final/Ntuple");
    TH1F *evCounter = (TH1F*) fIn->Get("mt/eventCount");
    TH1F *evCounterW = (TH1F*) fIn->Get("mt/summedWeights");
    HTauTauTree_mt* tree = new HTauTauTree_mt (treePtr);

    TTree *Run_Tree = new TTree("mutau_tree", "mutau_tree");
    Run_Tree->SetDirectory(0);
    Run_Tree->Branch("run", &run, "run/I");
    Run_Tree->Branch("lumi", &lumi, "lumi/I");
    Run_Tree->Branch("evt", &evt, "evt/I");

    Run_Tree->Branch("zptmass_weight_nom", &zptmass_weight_nom, "zptmass_weight_nom/F");
    Run_Tree->Branch("m_trk_ratio", &m_trk_ratio, "m_trk_ratio/F");
    Run_Tree->Branch("m_trg_ic_ratio", &m_trg_ic_ratio, "m_trg_ic_ratio/F");
    Run_Tree->Branch("t_trg_pog_deeptau_medium_mutau_ratio", &t_trg_pog_deeptau_medium_mutau_ratio, "t_trg_pog_deeptau_medium_mutau_ratio/F");
    Run_Tree->Branch("t_trg_pog_deeptau_medium_mutau_ratio_up", &t_trg_pog_deeptau_medium_mutau_ratio_up, "t_trg_pog_deeptau_medium_mutau_ratio_up/F");
    Run_Tree->Branch("t_trg_pog_deeptau_medium_mutau_ratio_down", &t_trg_pog_deeptau_medium_mutau_ratio_down, "t_trg_pog_deeptau_medium_mutau_ratio_down/F");
    Run_Tree->Branch("m_trg_19_ic_ratio", &m_trg_19_ic_ratio, "m_trg_19_ic_ratio/F");
    Run_Tree->Branch("m_trg_20_ic_ratio", &m_trg_20_ic_ratio, "m_trg_20_ic_ratio/F");
    Run_Tree->Branch("m_trg_20_ratio", &m_trg_20_ratio, "m_trg_20_ratio/F");
    Run_Tree->Branch("m_trg_MuTau_Mu20Leg_desy_ratio", &m_trg_MuTau_Mu20Leg_desy_ratio, "m_trg_MuTau_Mu20Leg_desy_ratio/F");
    Run_Tree->Branch("m_sel_trg_ic_ratio", &m_sel_trg_ic_ratio, "m_sel_trg_ic_ratio/F");
    Run_Tree->Branch("m_sel_id_ic_ratio_1", &m_sel_id_ic_ratio_1, "m_sel_id_ic_ratio_1/F");
    Run_Tree->Branch("m_sel_id_ic_ratio_2", &m_sel_id_ic_ratio_2, "m_sel_id_ic_ratio_2/F");
    Run_Tree->Branch("m_idiso_ic_embed_ratio", &m_idiso_ic_embed_ratio, "m_idiso_ic_embed_ratio/F");
    Run_Tree->Branch("m_idiso_ic_ratio", &m_idiso_ic_ratio, "m_idiso_ic_ratio/F");
    Run_Tree->Branch("m_trg_ic_embed_ratio", &m_trg_ic_embed_ratio, "m_trg_ic_embed_ratio/F");
    Run_Tree->Branch("t_trg_mediumDeepTau_mutau_embed_ratio", &t_trg_mediumDeepTau_mutau_embed_ratio, "t_trg_mediumDeepTau_mutau_embed_ratio/F");
    Run_Tree->Branch("t_trg_mediumDeepTau_mutau_embed_ratio_up", &t_trg_mediumDeepTau_mutau_embed_ratio_up, "t_trg_mediumDeepTau_mutau_embed_ratio_up/F");
    Run_Tree->Branch("t_trg_mediumDeepTau_mutau_embed_ratio_down", &t_trg_mediumDeepTau_mutau_embed_ratio_down, "t_trg_mediumDeepTau_mutau_embed_ratio_down/F");
    Run_Tree->Branch("m_trg_19_ic_embed_ratio", &m_trg_19_ic_embed_ratio, "m_trg_19_ic_embed_ratio/F");
    Run_Tree->Branch("m_trg_20_ic_embed_ratio", &m_trg_20_ic_embed_ratio, "m_trg_20_ic_embed_ratio/F");

    Run_Tree->Branch("prefiring_weight", &prefiring_weight, "prefiring_weight/F");
    Run_Tree->Branch("prefiring_weight_up", &prefiring_weight_up, "prefiring_weight_up/F");
    Run_Tree->Branch("prefiring_weight_down", &prefiring_weight_down, "prefiring_weight_down/F");

    Run_Tree->Branch("matchEmbFilter_Mu19Tau20_1", &matchEmbFilter_Mu19Tau20_1, "matchEmbFilter_Mu19Tau20_1/F");
    Run_Tree->Branch("matchEmbFilter_Mu19Tau20_2", &matchEmbFilter_Mu19Tau20_2, "matchEmbFilter_Mu19Tau20_2/F");
    Run_Tree->Branch("matchEmbFilter_Mu20Tau27_1", &matchEmbFilter_Mu20Tau27_1, "matchEmbFilter_Mu20Tau27_1/F");
    Run_Tree->Branch("matchEmbFilter_Mu20Tau27_2017_1", &matchEmbFilter_Mu20Tau27_2017_1, "matchEmbFilter_Mu20Tau27_2017_1/F");
    Run_Tree->Branch("matchEmbFilter_Mu24_1", &matchEmbFilter_Mu24_1, "matchEmbFilter_Mu24_1/F");
    Run_Tree->Branch("matchEmbFilter_Mu27_1", &matchEmbFilter_Mu27_1, "matchEmbFilter_Mu27_1/F");
    Run_Tree->Branch("matchEmbFilter_Mu20Tau27_2", &matchEmbFilter_Mu20Tau27_2, "matchEmbFilter_Mu20Tau27_2/F");
    Run_Tree->Branch("matchEmbFilter_Mu20HPSTau27_2", &matchEmbFilter_Mu20HPSTau27_2, "matchEmbFilter_Mu20HPSTau27_2/F");

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
    Run_Tree->Branch("iso_1", &iso_1, "iso_1/F");

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

    Run_Tree->Branch("passMu22eta2p1", &passMu22eta2p1, "passMu22eta2p1/F");
    Run_Tree->Branch("passTkMu22eta2p1", &passTkMu22eta2p1, "passTkMu22eta2p1/F");
    Run_Tree->Branch("passMu22", &passMu22, "passMu22/F");
    Run_Tree->Branch("passTkMu22", &passTkMu22, "passTkMu22/F");
    Run_Tree->Branch("passMu19Tau20", &passMu19Tau20, "passMu19Tau20/F");
    Run_Tree->Branch("passMu19Tau20SingleL1", &passMu19Tau20SingleL1, "passMu19Tau20SingleL1/F");
    Run_Tree->Branch("matchMu22eta2p1_1", &matchMu22eta2p1_1, "matchMu22eta2p1_1/F");
    Run_Tree->Branch("matchTkMu22eta2p1_1", &matchTkMu22eta2p1_1, "matchTkMu22eta2p1_1/F");
    Run_Tree->Branch("matchMu22_1", &matchMu22_1, "matchMu22_1/F");
    Run_Tree->Branch("matchTkMu22_1", &matchTkMu22_1, "matchTkMu22_1/F");
    Run_Tree->Branch("matchMu19Tau20_1", &matchMu19Tau20_1, "matchMu19Tau20_1/F");
    Run_Tree->Branch("matchMu19Tau20_2", &matchMu19Tau20_2, "matchMu19Tau20_2/F");
    Run_Tree->Branch("matchMu19Tau20SingleL1_1", &matchMu19Tau20SingleL1_1, "matchMu19Tau20SingleL1_1/F");
    Run_Tree->Branch("matchMu19Tau20SingleL1_2", &matchMu19Tau20SingleL1_2, "matchMu19Tau20SingleL1_2/F");
    Run_Tree->Branch("filterMu22eta2p1_1", &filterMu22eta2p1_1, "filterMu22eta2p1_1/F");
    Run_Tree->Branch("filterTkMu22eta2p1_1", &filterTkMu22eta2p1_1, "filterTkMu22eta2p1_1/F");
    Run_Tree->Branch("filterMu22_1", &filterMu22_1, "filterMu22_1/F");
    Run_Tree->Branch("filterTkMu22_1", &filterTkMu22_1, "filterTkMu22_1/F");
    Run_Tree->Branch("filterMu19Tau20_1", &filterMu19Tau20_1, "filterMu19Tau20_1/F");
    Run_Tree->Branch("filterMu19Tau20_2", &filterMu19Tau20_2, "filterMu19Tau20_2/F");
    Run_Tree->Branch("filterMu19Tau20SingleL1_1", &filterMu19Tau20SingleL1_1, "filterMu19Tau20SingleL1_1/F");
    Run_Tree->Branch("filterMu19Tau20SingleL1_2", &filterMu19Tau20SingleL1_2, "filterMu19Tau20SingleL1_2/F");
    Run_Tree->Branch("passMu24", &passMu24, "passMu24/F");
    Run_Tree->Branch("passMu27", &passMu27, "passMu27/F");
    Run_Tree->Branch("passMu20Tau27", &passMu20Tau27, "passMu20Tau27/F");
    Run_Tree->Branch("passMu20HPSTau27", &passMu20HPSTau27, "passMu20HPSTau27/F");
    Run_Tree->Branch("matchMu24_1", &matchMu24_1, "matchMu24_1/F");
    Run_Tree->Branch("matchMu27_1", &matchMu27_1, "matchMu27_1/F");
    Run_Tree->Branch("matchMu20Tau27_1", &matchMu20Tau27_1, "matchMu20Tau27_1/F");
    Run_Tree->Branch("matchMu20Tau27_2", &matchMu20Tau27_2, "matchMu20Tau27_2/F");
    Run_Tree->Branch("matchMu20HPSTau27_1", &matchMu20HPSTau27_1, "matchMu20HPSTau27_1/F");
    Run_Tree->Branch("matchMu20HPSTau27_2", &matchMu20HPSTau27_2, "matchMu20HPSTau27_2/F");
    Run_Tree->Branch("filterMu24_1", &filterMu24_1, "filterMu24_1/F");
    Run_Tree->Branch("filterMu27_1", &filterMu27_1, "filterMu27_1/F");
    Run_Tree->Branch("filterMu20Tau27_1", &filterMu20Tau27_1, "filterMu20Tau27_1/F");
    Run_Tree->Branch("filterMu20Tau27_2", &filterMu20Tau27_2, "filterMu20Tau27_2/F");
    Run_Tree->Branch("filterMu20HPSTau27_1", &filterMu20HPSTau27_1, "filterMu20HPSTau27_1/F");
    Run_Tree->Branch("filterMu20HPSTau27_2", &filterMu20HPSTau27_2, "filterMu20HPSTau27_2/F");

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

    Run_Tree->Branch("bpt_deepflavour_JERDown_1", &bpt_deepflavour_JERDown_1, "bpt_deepflavour_JERDown_1/F");
    Run_Tree->Branch("bpt_deepflavour_JERUp_1", &bpt_deepflavour_JERUp_1, "bpt_deepflavour_JERUp_1/F");
    Run_Tree->Branch("bpt_deepflavour_JetAbsoluteUp_1", &bpt_deepflavour_JetAbsoluteUp_1, "bpt_deepflavour_JetAbsoluteUp_1/F");
    Run_Tree->Branch("bpt_deepflavour_JetAbsoluteDown_1", &bpt_deepflavour_JetAbsoluteDown_1, "bpt_deepflavour_JetAbsoluteDown_1/F");
    Run_Tree->Branch("bpt_deepflavour_JetAbsoluteyearDown_1", &bpt_deepflavour_JetAbsoluteyearDown_1, "bpt_deepflavour_JetAbsoluteyearDown_1/F");
    Run_Tree->Branch("bpt_deepflavour_JetAbsoluteyearUp_1", &bpt_deepflavour_JetAbsoluteyearUp_1, "bpt_deepflavour_JetAbsoluteyearUp_1/F");
    Run_Tree->Branch("bpt_deepflavour_JetBBEC1Down_1", &bpt_deepflavour_JetBBEC1Down_1, "bpt_deepflavour_JetBBEC1Down_1/F");
    Run_Tree->Branch("bpt_deepflavour_JetBBEC1Up_1", &bpt_deepflavour_JetBBEC1Up_1, "bpt_deepflavour_JetBBEC1Up_1/F");
    Run_Tree->Branch("bpt_deepflavour_JetBBEC1yearDown_1", &bpt_deepflavour_JetBBEC1yearDown_1, "bpt_deepflavour_JetBBEC1yearDown_1/F");
    Run_Tree->Branch("bpt_deepflavour_JetBBEC1yearUp_1", &bpt_deepflavour_JetBBEC1yearUp_1, "bpt_deepflavour_JetBBEC1yearUp_1/F");
    Run_Tree->Branch("bpt_deepflavour_JetEC2Down_1", &bpt_deepflavour_JetEC2Down_1, "bpt_deepflavour_JetEC2Down_1/F");
    Run_Tree->Branch("bpt_deepflavour_JetEC2Up_1", &bpt_deepflavour_JetEC2Up_1, "bpt_deepflavour_JetEC2Up_1/F");
    Run_Tree->Branch("bpt_deepflavour_JetEC2yearDown_1", &bpt_deepflavour_JetEC2yearDown_1, "bpt_deepflavour_JetEC2yearDown_1/F");
    Run_Tree->Branch("bpt_deepflavour_JetEC2yearUp_1", &bpt_deepflavour_JetEC2yearUp_1, "bpt_deepflavour_JetEC2yearUp_1/F");
    Run_Tree->Branch("bpt_deepflavour_JetFlavorQCDDown_1", &bpt_deepflavour_JetFlavorQCDDown_1, "bpt_deepflavour_JetFlavorQCDDown_1/F");
    Run_Tree->Branch("bpt_deepflavour_JetFlavorQCDUp_1", &bpt_deepflavour_JetFlavorQCDUp_1, "bpt_deepflavour_JetFlavorQCDUp_1/F");
    Run_Tree->Branch("bpt_deepflavour_JetHFDown_1", &bpt_deepflavour_JetHFDown_1, "bpt_deepflavour_JetHFDown_1/F");
    Run_Tree->Branch("bpt_deepflavour_JetHFUp_1", &bpt_deepflavour_JetHFUp_1, "bpt_deepflavour_JetHFUp_1/F");
    Run_Tree->Branch("bpt_deepflavour_JetHFyearDown_1", &bpt_deepflavour_JetHFyearDown_1, "bpt_deepflavour_JetHFyearDown_1/F");
    Run_Tree->Branch("bpt_deepflavour_JetHFyearUp_1", &bpt_deepflavour_JetHFyearUp_1, "bpt_deepflavour_JetHFyearUp_1/F");
    Run_Tree->Branch("bpt_deepflavour_JetRelativeBalDown_1", &bpt_deepflavour_JetRelativeBalDown_1, "bpt_deepflavour_JetRelativeBalDown_1/F");
    Run_Tree->Branch("bpt_deepflavour_JetRelativeBalUp_1", &bpt_deepflavour_JetRelativeBalUp_1, "bpt_deepflavour_JetRelativeBalUp_1/F");
    Run_Tree->Branch("bpt_deepflavour_JetRelativeSampleDown_1", &bpt_deepflavour_JetRelativeSampleDown_1, "bpt_deepflavour_JetRelativeSampleDown_1/F");
    Run_Tree->Branch("bpt_deepflavour_JetRelativeSampleUp_1", &bpt_deepflavour_JetRelativeSampleUp_1, "bpt_deepflavour_JetRelativeSampleUp_1/F");
    Run_Tree->Branch("bpt_deepflavour_JetTotalUp_1", &bpt_deepflavour_JetTotalUp_1, "bpt_deepflavour_JetTotalUp_1/F");
    Run_Tree->Branch("bpt_deepflavour_JetTotalDown_1", &bpt_deepflavour_JetTotalDown_1, "bpt_deepflavour_JetTotalDown_1/F");

    Run_Tree->Branch("bpt_deepflavour_JERDown_2", &bpt_deepflavour_JERDown_2, "bpt_deepflavour_JERDown_2/F");
    Run_Tree->Branch("bpt_deepflavour_JERUp_2", &bpt_deepflavour_JERUp_2, "bpt_deepflavour_JERUp_2/F");
    Run_Tree->Branch("bpt_deepflavour_JetAbsoluteUp_2", &bpt_deepflavour_JetAbsoluteUp_2, "bpt_deepflavour_JetAbsoluteUp_2/F");
    Run_Tree->Branch("bpt_deepflavour_JetAbsoluteDown_2", &bpt_deepflavour_JetAbsoluteDown_2, "bpt_deepflavour_JetAbsoluteDown_2/F");
    Run_Tree->Branch("bpt_deepflavour_JetAbsoluteyearDown_2", &bpt_deepflavour_JetAbsoluteyearDown_2, "bpt_deepflavour_JetAbsoluteyearDown_2/F");
    Run_Tree->Branch("bpt_deepflavour_JetAbsoluteyearUp_2", &bpt_deepflavour_JetAbsoluteyearUp_2, "bpt_deepflavour_JetAbsoluteyearUp_2/F");
    Run_Tree->Branch("bpt_deepflavour_JetBBEC1Down_2", &bpt_deepflavour_JetBBEC1Down_2, "bpt_deepflavour_JetBBEC1Down_2/F");
    Run_Tree->Branch("bpt_deepflavour_JetBBEC1Up_2", &bpt_deepflavour_JetBBEC1Up_2, "bpt_deepflavour_JetBBEC1Up_2/F");
    Run_Tree->Branch("bpt_deepflavour_JetBBEC1yearDown_2", &bpt_deepflavour_JetBBEC1yearDown_2, "bpt_deepflavour_JetBBEC1yearDown_2/F");
    Run_Tree->Branch("bpt_deepflavour_JetBBEC1yearUp_2", &bpt_deepflavour_JetBBEC1yearUp_2, "bpt_deepflavour_JetBBEC1yearUp_2/F");
    Run_Tree->Branch("bpt_deepflavour_JetEC2Down_2", &bpt_deepflavour_JetEC2Down_2, "bpt_deepflavour_JetEC2Down_2/F");
    Run_Tree->Branch("bpt_deepflavour_JetEC2Up_2", &bpt_deepflavour_JetEC2Up_2, "bpt_deepflavour_JetEC2Up_2/F");
    Run_Tree->Branch("bpt_deepflavour_JetEC2yearDown_2", &bpt_deepflavour_JetEC2yearDown_2, "bpt_deepflavour_JetEC2yearDown_2/F");
    Run_Tree->Branch("bpt_deepflavour_JetEC2yearUp_2", &bpt_deepflavour_JetEC2yearUp_2, "bpt_deepflavour_JetEC2yearUp_2/F");
    Run_Tree->Branch("bpt_deepflavour_JetFlavorQCDDown_2", &bpt_deepflavour_JetFlavorQCDDown_2, "bpt_deepflavour_JetFlavorQCDDown_2/F");
    Run_Tree->Branch("bpt_deepflavour_JetFlavorQCDUp_2", &bpt_deepflavour_JetFlavorQCDUp_2, "bpt_deepflavour_JetFlavorQCDUp_2/F");
    Run_Tree->Branch("bpt_deepflavour_JetHFDown_2", &bpt_deepflavour_JetHFDown_2, "bpt_deepflavour_JetHFDown_2/F");
    Run_Tree->Branch("bpt_deepflavour_JetHFUp_2", &bpt_deepflavour_JetHFUp_2, "bpt_deepflavour_JetHFUp_2/F");
    Run_Tree->Branch("bpt_deepflavour_JetHFyearDown_2", &bpt_deepflavour_JetHFyearDown_2, "bpt_deepflavour_JetHFyearDown_2/F");
    Run_Tree->Branch("bpt_deepflavour_JetHFyearUp_2", &bpt_deepflavour_JetHFyearUp_2, "bpt_deepflavour_JetHFyearUp_2/F");
    Run_Tree->Branch("bpt_deepflavour_JetRelativeBalDown_2", &bpt_deepflavour_JetRelativeBalDown_2, "bpt_deepflavour_JetRelativeBalDown_2/F");
    Run_Tree->Branch("bpt_deepflavour_JetRelativeBalUp_2", &bpt_deepflavour_JetRelativeBalUp_2, "bpt_deepflavour_JetRelativeBalUp_2/F");
    Run_Tree->Branch("bpt_deepflavour_JetRelativeSampleDown_2", &bpt_deepflavour_JetRelativeSampleDown_2, "bpt_deepflavour_JetRelativeSampleDown_2/F");
    Run_Tree->Branch("bpt_deepflavour_JetRelativeSampleUp_2", &bpt_deepflavour_JetRelativeSampleUp_2, "bpt_deepflavour_JetRelativeSampleUp_2/F");
    Run_Tree->Branch("bpt_deepflavour_JetTotalUp_2", &bpt_deepflavour_JetTotalUp_2, "bpt_deepflavour_JetTotalUp_2/F");
    Run_Tree->Branch("bpt_deepflavour_JetTotalDown_2", &bpt_deepflavour_JetTotalDown_2, "bpt_deepflavour_JetTotalDown_2/F");


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

    float tes_dm0_emb=tes_dm0_emb_2018;
    float tes_dm1_emb=tes_dm1_emb_2018;
    float tes_dm10_emb=tes_dm10_emb_2018;
    float tes_dm11_emb=tes_dm11_emb_2018;
    if (year==2017){
       tes_dm0_emb=tes_dm0_emb_2017;
       tes_dm1_emb=tes_dm1_emb_2017;
       tes_dm10_emb=tes_dm10_emb_2017;
       tes_dm11_emb=tes_dm11_emb_2017;
    }
    if (year==2016){
       tes_dm0_emb=tes_dm0_emb_2016;
       tes_dm1_emb=tes_dm1_emb_2016;
       tes_dm10_emb=tes_dm10_emb_2016;
       tes_dm11_emb=tes_dm11_emb_2016;
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
        dau1.SetPtEtaPhiM(tree->mPt,tree->mEta,tree->mPhi,tree->mMass);
        dau2.SetPtEtaPhiM(tree->tPt,tree->tEta,tree->tPhi,tree->tMass);

        float tes_real=1.0;
        int bin = hist_lowpt_2016->GetXaxis()->FindBin(tree->tDecayMode);
        if (year==2016) tes_real = hist_lowpt_2016->GetBinContent(bin);
        if (year==2017) tes_real = hist_lowpt_2017->GetBinContent(bin);
        if (year==2018) tes_real = hist_lowpt_2018->GetBinContent(bin);

        float tes_ele=1.0;
        if (isMC and year==2016){
           if (tree->tDecayMode==0 and fabs(tree->tDecayMode)<1.5) tes_ele=gfes_2016->GetY()[0];
           if (tree->tDecayMode==1 and fabs(tree->tDecayMode)<1.5) tes_ele=gfes_2016->GetY()[1];
           if (tree->tDecayMode==0 and fabs(tree->tDecayMode)>=1.5) tes_ele=gfes_2016->GetY()[2];
           if (tree->tDecayMode==1 and fabs(tree->tDecayMode)>=1.5) tes_ele=gfes_2016->GetY()[3];
        }
        if (isMC and year==2017){
           if (tree->tDecayMode==0 and fabs(tree->tDecayMode)<1.5) tes_ele=gfes_2017->GetY()[0];
           if (tree->tDecayMode==1 and fabs(tree->tDecayMode)<1.5) tes_ele=gfes_2017->GetY()[1];
           if (tree->tDecayMode==0 and fabs(tree->tDecayMode)>=1.5) tes_ele=gfes_2017->GetY()[2];
           if (tree->tDecayMode==1 and fabs(tree->tDecayMode)>=1.5) tes_ele=gfes_2017->GetY()[3];
        }
        if (isMC and year==2018){
           if (tree->tDecayMode==0 and fabs(tree->tDecayMode)<1.5) tes_ele=gfes_2018->GetY()[0];
           if (tree->tDecayMode==1 and fabs(tree->tDecayMode)<1.5) tes_ele=gfes_2018->GetY()[1];
           if (tree->tDecayMode==0 and fabs(tree->tDecayMode)>=1.5) tes_ele=gfes_2018->GetY()[2];
           if (tree->tDecayMode==1 and fabs(tree->tDecayMode)>=1.5) tes_ele=gfes_2018->GetY()[3];
        }

        if (isMC){
           if (tree->tZTTGenMatching==5) dau2=dau2*tes_real;
           else if ((tree->tZTTGenMatching==1 or tree->tZTTGenMatching==3)) dau2=dau2*tes_ele;
        }
        else if (isEmbedded){
           if(tree->tZTTGenMatching==5 && tree->tDecayMode==0) dau2=dau2*tes_dm0_emb;
           else if (tree->tZTTGenMatching==5 && tree->tDecayMode==1) dau2=dau2*tes_dm1_emb;
           else if (tree->tZTTGenMatching==5 && tree->tDecayMode==10) dau2=dau2*tes_dm10_emb;
           else if (tree->tZTTGenMatching==5 && tree->tDecayMode==11) dau2=dau2*tes_dm11_emb;
        }

        if (dau1.DeltaR(dau2)<0.3) continue;
	if (fabs(tree->mPVDXY)>0.045) continue;
        if (fabs(tree->mPVDZ)>0.2) continue;
        if (fabs(tree->tPVDZ)>0.2) continue;
	if (dau1.Pt()<19.5 or dau2.Pt()<19.5) continue;
        if (fabs(dau1.Eta())>2.1 or fabs(dau2.Eta())>2.3) continue;
        if (!tree->tVVVLooseDeepTau2017v2p1VSjet) continue;
        if (!tree->tVLooseDeepTau2017v2p1VSmu) continue;
        if (!tree->tVLooseDeepTau2017v2p1VSe) continue;
        if (tree->tDecayMode==5 or tree->tDecayMode==6) continue;
        if (tree->mRelPFIsoDBDefault>0.5) continue;
	if (!tree->mPFIDMedium) continue;
	if (tree->eVetoZTTp001dxyzR0>0) continue;
	if (tree->muVetoZTTp001dxyzR0>1) continue;
	if (tree->dimuonVeto>0) continue;

        evt_now=tree->evt;
        if (evt_now!=evt_before){
           lt_before=tree->tPt + tree->mPt;
        }
        if (evt_now!=evt_before){
           if (bestEntry>-1)
              fillTree(Run_Tree,tree,bestEntry,recoil,isMC,isEmbedded,year);
           bestEntry=iEntry;
        }
        if (evt_now==evt_before){
           if (tree->tPt + tree->mPt>lt_before+0.0001){
                bestEntry=iEntry;
                lt_before=tree->tPt + tree->mPt;
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


