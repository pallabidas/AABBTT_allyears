#ifndef THTH_TREE_H
#define	THTH_TREE_H

#include "RooWorkspace.h"
#include "RooRealVar.h"
#include "RooFunctor.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <utility>
#include <map>
#include <string>
#include "TTree.h"
#include "TFile.h"
#include "TSystem.h"
#include "HTauTauTree_em.h"
#include "RecoilCorrector.h"
#include "MEtSys.h"
#include "correction.h"

using namespace std;
float zptmass_weight_nom,e_trk_ratio,e_idiso_ic_ratio,m_idiso_ic_ratio,m_trk_ratio,e_trk_embed_ratio,e_idiso_ic_embed_ratio,m_idiso_ic_embed_ratio,m_trg_8_ic_data,e_trg_23_ic_data,m_trg_23_ic_data,e_trg_12_ic_data,e_trg_12_ic_mc,m_trg_23_ic_mc,e_trg_23_ic_mc,m_trg_8_ic_mc,e_trg_12_ic_embed,m_trg_23_ic_embed,e_trg_23_ic_embed,m_trg_8_ic_embed,m_sel_trg_ic_ratio,m_sel_id_ic_ratio_1,m_sel_id_ic_ratio_2;
float bpt_deepflavour_JERDown_1,bpt_deepflavour_JERUp_1,bpt_deepflavour_JetAbsoluteDown_1,bpt_deepflavour_JetAbsoluteUp_1,bpt_deepflavour_JetAbsoluteyearDown_1,bpt_deepflavour_JetAbsoluteyearUp_1,bpt_deepflavour_JetBBEC1Down_1,bpt_deepflavour_JetBBEC1Up_1,bpt_deepflavour_JetBBEC1yearDown_1,bpt_deepflavour_JetBBEC1yearUp_1,bpt_deepflavour_JetEC2Down_1,bpt_deepflavour_JetEC2Up_1,bpt_deepflavour_JetEC2yearDown_1,bpt_deepflavour_JetEC2yearUp_1,bpt_deepflavour_JetFlavorQCDDown_1,bpt_deepflavour_JetFlavorQCDUp_1,bpt_deepflavour_JetHFDown_1,bpt_deepflavour_JetHFUp_1,bpt_deepflavour_JetHFyearDown_1,bpt_deepflavour_JetHFyearUp_1,bpt_deepflavour_JetRelativeBalDown_1,bpt_deepflavour_JetRelativeBalUp_1,bpt_deepflavour_JetRelativeSampleDown_1,bpt_deepflavour_JetRelativeSampleUp_1,bpt_deepflavour_JetTotalDown_1,bpt_deepflavour_JetTotalUp_1;
float bpt_deepflavour_JERDown_2,bpt_deepflavour_JERUp_2,bpt_deepflavour_JetAbsoluteDown_2,bpt_deepflavour_JetAbsoluteUp_2,bpt_deepflavour_JetAbsoluteyearDown_2,bpt_deepflavour_JetAbsoluteyearUp_2,bpt_deepflavour_JetBBEC1Down_2,bpt_deepflavour_JetBBEC1Up_2,bpt_deepflavour_JetBBEC1yearDown_2,bpt_deepflavour_JetBBEC1yearUp_2,bpt_deepflavour_JetEC2Down_2,bpt_deepflavour_JetEC2Up_2,bpt_deepflavour_JetEC2yearDown_2,bpt_deepflavour_JetEC2yearUp_2,bpt_deepflavour_JetFlavorQCDDown_2,bpt_deepflavour_JetFlavorQCDUp_2,bpt_deepflavour_JetHFDown_2,bpt_deepflavour_JetHFUp_2,bpt_deepflavour_JetHFyearDown_2,bpt_deepflavour_JetHFyearUp_2,bpt_deepflavour_JetRelativeBalDown_2,bpt_deepflavour_JetRelativeBalUp_2,bpt_deepflavour_JetRelativeSampleDown_2,bpt_deepflavour_JetRelativeSampleUp_2,bpt_deepflavour_JetTotalDown_2,bpt_deepflavour_JetTotalUp_2;

float prefiring_weight,prefiring_weight_up, prefiring_weight_down;
float lheweight_muR0p5_muF0p5,lheweight_muR0p5_muF1,lheweight_muR0p5_muF2,lheweight_muR1_muF0p5,lheweight_muR1_muF2,lheweight_muR2_muF0p5,lheweight_muR2_muF1,lheweight_muR2_muF2,PythiaWeight_fsr_muR0p25,PythiaWeight_fsr_muR0p5,PythiaWeight_fsr_muR2,PythiaWeight_fsr_muR4,PythiaWeight_isr_muR0p25,PythiaWeight_isr_muR0p5,PythiaWeight_isr_muR2,PythiaWeight_isr_muR4;
float gentau1_eta, gentau1_pt, gentau2_eta, gentau2_pt;
float gen_met_pt, gen_met_phi, gen_tauh_pt, gen_tauh_eta, gen_tauh_phi, gen_mu_pt, gen_mu_eta, gen_mu_phi, HTTgenfinalstate;
float L1iso, L1pt, bweight;
float met_responseUp, met_responseDown, met_resolutionUp, met_resolutionDown;
float metphi_responseUp, metphi_responseDown, metphi_resolutionUp, metphi_resolutionDown;
float met_JetAbsoluteUp, met_JetAbsoluteDown, metphi_JetAbsoluteUp, metphi_JetAbsoluteDown;
float met_JetAbsoluteyearUp, met_JetAbsoluteyearDown, metphi_JetAbsoluteyearUp, metphi_JetAbsoluteyearDown;
float met_JetBBEC1Up, met_JetBBEC1Down, metphi_JetBBEC1Up, metphi_JetBBEC1Down;
float met_JetBBEC1yearUp, met_JetBBEC1yearDown, metphi_JetBBEC1yearUp, metphi_JetBBEC1yearDown;
float met_JetEC2Up, met_JetEC2Down, metphi_JetEC2Up, metphi_JetEC2Down;
float met_JetEC2yearUp, met_JetEC2yearDown, metphi_JetEC2yearUp, metphi_JetEC2yearDown;
float met_JetFlavorQCDUp, met_JetFlavorQCDDown, metphi_JetFlavorQCDUp, metphi_JetFlavorQCDDown;
float met_JetHFUp, met_JetHFDown, metphi_JetHFUp, metphi_JetHFDown;
float met_JetHFyearUp, met_JetHFyearDown, metphi_JetHFyearUp, metphi_JetHFyearDown;
float met_JetRelativeBalUp, met_JetRelativeBalDown, metphi_JetRelativeBalUp, metphi_JetRelativeBalDown;
float met_JetRelativeSampleUp, met_JetRelativeSampleDown, metphi_JetRelativeSampleUp, metphi_JetRelativeSampleDown;
float met_JERUp, met_JERDown, metphi_JERUp, metphi_JERDown;
float jcsv_1, jcsv_2;
float mjj_JetAbsoluteUp, mjj_JetAbsoluteyearUp, mjj_JetBBEC1Up, mjj_JetBBEC1yearUp, mjj_JetEC2Up, mjj_JetEC2yearUp, mjj_JetFlavorQCDUp, mjj_JetHFUp, mjj_JetHFyearUp, mjj_JetRelativeBalUp, mjj_JetRelativeSampleUp, mjj_JERUp;
float mjj_JetAbsoluteDown, mjj_JetAbsoluteyearDown, mjj_JetBBEC1Down, mjj_JetBBEC1yearDown, mjj_JetEC2Down, mjj_JetEC2yearDown, mjj_JetFlavorQCDDown, mjj_JetHFDown, mjj_JetHFyearDown, mjj_JetRelativeBalDown, mjj_JetRelativeSampleDown, mjj_JERDown;
float jpt_1_JetAbsoluteUp, jpt_1_JetAbsoluteyearUp, jpt_1_JetBBEC1Up, jpt_1_JetBBEC1yearUp, jpt_1_JetEC2Up, jpt_1_JetEC2yearUp, jpt_1_JetFlavorQCDUp, jpt_1_JetHFUp, jpt_1_JetHFyearUp, jpt_1_JetRelativeBalUp, jpt_1_JetRelativeSampleUp, jpt_1_JERUp;
float jpt_1_JetAbsoluteDown, jpt_1_JetAbsoluteyearDown, jpt_1_JetBBEC1Down, jpt_1_JetBBEC1yearDown, jpt_1_JetEC2Down, jpt_1_JetEC2yearDown, jpt_1_JetFlavorQCDDown, jpt_1_JetHFDown, jpt_1_JetHFyearDown, jpt_1_JetRelativeBalDown, jpt_1_JetRelativeSampleDown, jpt_1_JERDown;
int njets_JetAbsoluteUp, njets_JetAbsoluteyearUp, njets_JetBBEC1Up, njets_JetBBEC1yearUp, njets_JetEC2Up, njets_JetEC2yearUp, njets_JetFlavorQCDUp, njets_JetHFUp, njets_JetHFyearUp, njets_JetRelativeBalUp, njets_JetRelativeSampleUp, njets_JERUp;
int njets_JetAbsoluteDown, njets_JetAbsoluteyearDown, njets_JetBBEC1Down, njets_JetBBEC1yearDown, njets_JetEC2Down, njets_JetEC2yearDown, njets_JetFlavorQCDDown, njets_JetHFDown, njets_JetHFyearDown, njets_JetRelativeBalDown, njets_JetRelativeSampleDown, njets_JERDown;

float passMu8E23, passMu23E12;
float matchMu8E23_1, matchMu23E12_1, filterMu8E23_1, filterMu23E12_1;
float matchMu8E23_2, matchMu23E12_2, filterMu8E23_2, filterMu23E12_2;
float passMu8E23DZ, passMu23E12DZ;
float matchMu8E23DZ_1, matchMu23E12DZ_1, filterMu8E23DZ_1, filterMu23E12DZ_1;
float matchMu8E23DZ_2, matchMu23E12DZ_2, filterMu8E23DZ_2, filterMu23E12DZ_2;

int njets, nbtag, nbtagL;
float mjj;
float Rivet_VEta,Rivet_VPt,Rivet_errorCode,Rivet_higgsEta,Rivet_higgsPt,Rivet_nJets25,Rivet_nJets30,Rivet_p4decay_VEta,Rivet_p4decay_VPt,Rivet_prodMode,Rivet_stage0_cat,Rivet_stage1_1_cat_pTjet30GeV,Rivet_stage1_1_fine_cat_pTjet30GeV, Rivet_stage1_cat_pTjet30GeV,Rivet_higgsRapidity,Rivet_j1pt,Rivet_j1eta,Rivet_j1phi,Rivet_j1m,Rivet_j2pt,Rivet_j2eta,Rivet_j2phi,Rivet_j2m;
unsigned int run, lumi, evt, NUP = -10;
int gen_match_1, gen_match_2=0;
float npu, rho, npv=-1, puweight, weight, numGenJets,jetPt_2;
float e_1, px_1, py_1, pz_1, pt_1, phi_1, eta_1, m_1, q_1, d0_1, dZ_1, mt_1, iso_1, l1_decayMode, isoDB_1;
float e_2, px_2, py_2, pz_2, pt_2, phi_2, eta_2, m_2, q_2, d0_2, dZ_2, mt_2, iso_2, l2_decayMode;
float je_1, jmass_1, jpt_1, jpx_1, jpy_1, jpz_1, jeta_1, jphi_1, jrawf_1, jmva_1, jpfid_1, jpuid_1;
float je_2, jmass_2, jpx_2, jpy_2, jpz_2, jpt_2, jeta_2, jphi_2, jrawf_2, jmva_2, jpfid_2, jpuid_2;
float bpt_1, beta_1, bphi_1, brawf_1, bmva_1, bpfid_1, bpuid_1, bflavor_1, bm_1, bscore_1;
float bpt_2, beta_2, bphi_2, brawf_2, bmva_2, bpfid_2, bpuid_2, bflavor_2, bm_2, bscore_2;
float bpt_deepflavour_1, beta_deepflavour_1, bphi_deepflavour_1, bflavour_deepflavour_1, bm_deepflavour_1, bscore_deepflavour_1;
float bpt_deepflavour_2, beta_deepflavour_2, bphi_deepflavour_2, bflavour_deepflavour_2, bm_deepflavour_2, bscore_deepflavour_2;
float bpt_deepcsv_1, beta_deepcsv_1, bphi_deepcsv_1, bflavour_deepcsv_1, bm_deepcsv_1, bscore_deepcsv_1;
float bpt_deepcsv_2, beta_deepcsv_2, bphi_deepcsv_2, bflavour_deepcsv_2, bm_deepcsv_2, bscore_deepcsv_2;
float met, metphi, metcov00,metcov01,metcov10,metcov11;
float met_UESDown, met_UESUp, metphi_UESDown, metphi_UESUp;
float top_reweighting, gen_Higgs_pt, gen_Higgs_mass=1.0;
float extraelec_veto, extramuon_veto, dilepton_veto=false;
float met_px, met_py,genpX,genpY,vispX,vispY,metSig,genpT,genM;
float pt_top1, pt_top2, genweight;
float decayModeFinding_2, againstElectronTightMVA6_2, againstElectronVTightMVA6_2, againstElectronVLooseMVA6_2, againstElectronMediumMVA6_2, againstElectronLooseMVA6_2, againstMuonLoose3_2, againstMuonTight3_2;
float Flag_BadChargedCandidateFilter, Flag_BadPFMuonFilter, Flag_EcalDeadCellTriggerPrimitiveFilter, Flag_HBHENoiseFilter, Flag_HBHENoiseIsoFilter, Flag_badCloneMuon, Flag_badGlobalMuon, Flag_eeBadScFilter, Flag_globalTightHalo2016Filter, Flag_goodVertices, Flag_globalSuperTightHalo2016Filter, Flag_badMuons, Flag_duplicateMuons, Flag_ecalBadCalibFilter, Flag_ecalBadCalibReducedMINIAODFilter;
float genpt_1, genpt_2, geneta_1, geneta_2, pt_1_ScaleUp, pt_1_ScaleDown;
bool preVFP = true;

//https://github.com/CMS-HTT/RecoilCorrections
RecoilCorrector recoilPFMetCorrector2018("HTT-utilities/RecoilCorrections/data/TypeI-PFMet_Run2018.root");
MEtSys metSys2018("HTT-utilities/RecoilCorrections/data/PFMEtSys_2018.root");

RecoilCorrector recoilPFMetCorrector2017("HTT-utilities/RecoilCorrections/data/TypeI-PFMET_2017.root");
MEtSys metSys2017("HTT-utilities/RecoilCorrections/data/PFMEtSys_2017.root");

RecoilCorrector recoilPFMetCorrector2016("HTT-utilities/RecoilCorrections/data/TypeI-PFMet_Run2016_legacy.root");
MEtSys metSys2016("HTT-utilities/RecoilCorrections/data/PFMEtSys_2016.root");


TFile fwmc2016("htt_scalefactors_legacy_2016.root");
RooWorkspace *wmc2016 = (RooWorkspace*)fwmc2016.Get("w");

TFile fwmc2017("htt_scalefactors_legacy_2017.root");
RooWorkspace *wmc2017 = (RooWorkspace*)fwmc2017.Get("w");

TFile fwmc2018("htt_scalefactors_legacy_2018.root");
RooWorkspace *wmc2018 = (RooWorkspace*)fwmc2018.Get("w");

void fillTree(TTree *Run_Tree, HTauTauTree_em *tree, int entry_tree, int recoil, bool ismc, bool isembedded, int year){
  tree->GetEntry(entry_tree);

  prefiring_weight=tree->prefiring_weight;
  prefiring_weight_up=tree->prefiring_weight_up;
  prefiring_weight_down=tree->prefiring_weight_down;

  HTTgenfinalstate=tree->HTTgenfinalstate;
  gen_met_pt=tree->genMetPt;
  gen_met_phi=tree->genMetPhi;

  run = tree->run;
  lumi = tree->lumi;
  evt =tree->evt;
  genweight = tree->GenWeight;

  passMu8E23=tree->mu8e23Pass;
  passMu23E12=tree->mu23e12Pass;
  matchMu8E23_1=tree->eMatchesMu8e23Path;
  matchMu23E12_1=tree->eMatchesMu23e12Path;
  filterMu8E23_1=tree->eMatchesMu8e23Filter;
  filterMu23E12_1=tree->eMatchesMu23e12Filter;
  matchMu8E23_2=tree->mMatchesMu8e23Path;
  matchMu23E12_2=tree->mMatchesMu23e12Path;
  filterMu8E23_2=tree->mMatchesMu8e23Filter;
  filterMu23E12_2=tree->mMatchesMu23e12Filter;

  passMu8E23DZ=tree->mu8e23DZPass;
  passMu23E12DZ=tree->mu23e12DZPass;
  matchMu8E23DZ_1=tree->eMatchesMu8e23DZPath;
  matchMu23E12DZ_1=tree->eMatchesMu23e12DZPath;
  filterMu8E23DZ_1=tree->eMatchesMu8e23DZFilter;
  filterMu23E12DZ_1=tree->eMatchesMu23e12DZFilter;
  matchMu8E23DZ_2=tree->mMatchesMu8e23DZPath;
  matchMu23E12DZ_2=tree->mMatchesMu23e12DZPath;
  filterMu8E23DZ_2=tree->mMatchesMu8e23DZFilter;
  filterMu23E12DZ_2=tree->mMatchesMu23e12DZFilter;
  
  geneta_1=tree->eGenEta;
  geneta_2=tree->mGenEta;
  genpt_1=tree->eGenPt;
  genpt_2=tree->mGenPt;

  /*lheweight_muR0p5_muF0p5=tree->lheweight_muR0p5_muF0p5;
  lheweight_muR0p5_muF1=tree->lheweight_muR0p5_muF1;
  lheweight_muR0p5_muF2=tree->lheweight_muR0p5_muF2;
  lheweight_muR1_muF0p5=tree->lheweight_muR1_muF0p5;
  lheweight_muR1_muF2=tree->lheweight_muR1_muF2;
  lheweight_muR2_muF0p5=tree->lheweight_muR2_muF0p5;
  lheweight_muR2_muF1=tree->lheweight_muR2_muF1;
  lheweight_muR2_muF2=tree->lheweight_muR2_muF2;
  PythiaWeight_fsr_muR0p25=tree->PythiaWeight_fsr_muR0p25;
  PythiaWeight_fsr_muR0p5=tree->PythiaWeight_fsr_muR0p5;
  PythiaWeight_fsr_muR2=tree->PythiaWeight_fsr_muR2;
  PythiaWeight_fsr_muR4=tree->PythiaWeight_fsr_muR4;
  PythiaWeight_isr_muR0p25=tree->PythiaWeight_isr_muR0p25;
  PythiaWeight_isr_muR0p5=tree->PythiaWeight_isr_muR0p5;
  PythiaWeight_isr_muR2=tree->PythiaWeight_isr_muR2;
  PythiaWeight_isr_muR4=tree->PythiaWeight_isr_muR4;*/

  Rivet_VEta=tree->Rivet_VEta;
  Rivet_VPt=tree->Rivet_VPt;
  Rivet_errorCode=tree->Rivet_errorCode;
  Rivet_higgsEta=tree->Rivet_higgsEta;
  Rivet_higgsPt=tree->Rivet_higgsPt;
  Rivet_nJets25=tree->Rivet_nJets25;
  Rivet_nJets30=tree->Rivet_nJets30;
  Rivet_p4decay_VEta=tree->Rivet_p4decay_VEta;
  Rivet_p4decay_VPt=tree->Rivet_p4decay_VPt;
  Rivet_prodMode=tree->Rivet_prodMode;
  Rivet_stage0_cat=tree->Rivet_stage0_cat;
  Rivet_stage1_1_fine_cat_pTjet30GeV=tree->Rivet_stage1_1_fine_cat_pTjet30GeV;
  Rivet_stage1_1_cat_pTjet30GeV=tree->Rivet_stage1_1_cat_pTjet30GeV;
  Rivet_stage1_cat_pTjet30GeV=tree->Rivet_stage1_cat_pTjet30GeV;
  Rivet_j1pt=tree->Rivet_j1pt;
  Rivet_j2pt=tree->Rivet_j2pt;
  Rivet_j1eta=tree->Rivet_j1eta;
  Rivet_j2eta=tree->Rivet_j2eta;
  Rivet_j1phi=tree->Rivet_j1phi;
  Rivet_j2phi=tree->Rivet_j2phi;
  Rivet_j1m=tree->Rivet_j1m;
  Rivet_j2m=tree->Rivet_j2m;
  Rivet_higgsRapidity=tree->Rivet_higgsRapidity;
  gentau2_pt=tree->gentau2_pt;
  gentau1_pt=tree->gentau1_pt;
  gentau2_eta=tree->gentau2_eta;
  gentau1_eta=tree->gentau1_eta;

  genpX=tree->genpX;
  genpY=tree->genpY;
  vispX=tree->vispX;
  vispY=tree->vispY;
  genpT=tree->genpT;
  genM=tree->genM;

  Flag_ecalBadCalibReducedMINIAODFilter = tree->Flag_ecalBadCalibReducedMINIAODFilter;
  Flag_BadChargedCandidateFilter = tree->Flag_BadChargedCandidateFilter;
  Flag_BadPFMuonFilter = tree->Flag_BadPFMuonFilter;
  Flag_EcalDeadCellTriggerPrimitiveFilter = tree->Flag_EcalDeadCellTriggerPrimitiveFilter;
  Flag_HBHENoiseFilter = tree->Flag_HBHENoiseFilter;
  Flag_HBHENoiseIsoFilter = tree->Flag_HBHENoiseIsoFilter;
  Flag_badMuons = tree->Flag_badMuons;
  Flag_duplicateMuons = tree->Flag_duplicateMuons;
  Flag_ecalBadCalibFilter = tree->Flag_ecalBadCalibFilter;
  Flag_eeBadScFilter = tree->Flag_eeBadScFilter;
  Flag_globalSuperTightHalo2016Filter = tree->Flag_globalSuperTightHalo2016Filter;
  Flag_globalTightHalo2016Filter = tree->Flag_globalTightHalo2016Filter;
  Flag_goodVertices = tree->Flag_goodVertices;

  metcov00=tree->metcov00;
  metcov01=tree->metcov01;
  metcov10=tree->metcov10;
  metcov11=tree->metcov11;

  numGenJets=tree->numGenJets;

  gen_Higgs_pt=tree->genpT;
  gen_Higgs_mass=tree->genM;

  pt_top1=tree->topQuarkPt1;
  pt_top2=tree->topQuarkPt2;

  weight=tree->GenWeight;

  njets = tree->jetVeto30;
  nbtag = tree->bjetDeepCSVVeto20Medium_2018_DR0p5;
  nbtagL = tree->bjetDeepCSVVeto20Loose_2018_DR0p5;
  njets_JetAbsoluteUp = tree->jetVeto30_JetAbsoluteUp;
  njets_JetAbsoluteDown = tree->jetVeto30_JetAbsoluteDown;
  njets_JetAbsoluteyearUp = tree->jetVeto30_JetAbsoluteyearUp;
  njets_JetAbsoluteyearDown = tree->jetVeto30_JetAbsoluteyearDown;
  njets_JetBBEC1Up = tree->jetVeto30_JetBBEC1Up;
  njets_JetBBEC1Down = tree->jetVeto30_JetBBEC1Down;
  njets_JetBBEC1yearUp = tree->jetVeto30_JetBBEC1yearUp;
  njets_JetBBEC1yearDown = tree->jetVeto30_JetBBEC1yearDown;
  njets_JetEC2Up = tree->jetVeto30_JetEC2Up;
  njets_JetEC2Down = tree->jetVeto30_JetEC2Down;
  njets_JetEC2yearUp = tree->jetVeto30_JetEC2yearUp;
  njets_JetEC2yearDown = tree->jetVeto30_JetEC2yearDown;
  njets_JetFlavorQCDUp = tree->jetVeto30_JetFlavorQCDUp;
  njets_JetFlavorQCDDown = tree->jetVeto30_JetFlavorQCDDown;
  njets_JetHFUp = tree->jetVeto30_JetHFUp;
  njets_JetHFDown = tree->jetVeto30_JetHFDown;
  njets_JetHFyearUp = tree->jetVeto30_JetHFyearUp;
  njets_JetHFyearDown = tree->jetVeto30_JetHFyearDown;
  njets_JetRelativeBalUp = tree->jetVeto30_JetRelativeBalUp;
  njets_JetRelativeBalDown = tree->jetVeto30_JetRelativeBalDown;
  njets_JetRelativeSampleUp = tree->jetVeto30_JetRelativeSampleUp;
  njets_JetRelativeSampleDown = tree->jetVeto30_JetRelativeSampleDown;
  njets_JERUp = tree->jetVeto30_JERUp;
  njets_JERDown = tree->jetVeto30_JERDown;

  gen_match_1=tree->eZTTGenMatching;
  gen_match_2=tree->mZTTGenMatching;

  TLorentzVector tau1;
  TLorentzVector tau2;
  tau1.SetPtEtaPhiM(tree->ePt,tree->eEta,tree->ePhi,tree->eMass);
  tau2.SetPtEtaPhiM(tree->mPt,tree->mEta,tree->mPhi,tree->mMass);

  TLorentzVector mymetvector[27];
  mymetvector[0].SetPtEtaPhiM(tree->type1_pfMetEt,0,tree->type1_pfMetPhi,0);
  mymetvector[1].SetPtEtaPhiM(tree->type1_pfMet_shiftedPt_JetAbsoluteUp,0,tree->type1_pfMet_shiftedPhi_JetAbsoluteUp,0);
  mymetvector[2].SetPtEtaPhiM(tree->type1_pfMet_shiftedPt_JetAbsoluteDown,0,tree->type1_pfMet_shiftedPhi_JetAbsoluteDown,0);
  mymetvector[3].SetPtEtaPhiM(tree->type1_pfMet_shiftedPt_JetAbsoluteyearUp,0,tree->type1_pfMet_shiftedPhi_JetAbsoluteyearUp,0);
  mymetvector[4].SetPtEtaPhiM(tree->type1_pfMet_shiftedPt_JetAbsoluteyearDown,0,tree->type1_pfMet_shiftedPhi_JetAbsoluteyearDown,0);
  mymetvector[5].SetPtEtaPhiM(tree->type1_pfMet_shiftedPt_JetBBEC1Up,0,tree->type1_pfMet_shiftedPhi_JetBBEC1Up,0);
  mymetvector[6].SetPtEtaPhiM(tree->type1_pfMet_shiftedPt_JetBBEC1Down,0,tree->type1_pfMet_shiftedPhi_JetBBEC1Down,0);
  mymetvector[7].SetPtEtaPhiM(tree->type1_pfMet_shiftedPt_JetBBEC1yearUp,0,tree->type1_pfMet_shiftedPhi_JetBBEC1yearUp,0);
  mymetvector[8].SetPtEtaPhiM(tree->type1_pfMet_shiftedPt_JetBBEC1yearDown,0,tree->type1_pfMet_shiftedPhi_JetBBEC1yearDown,0);
  mymetvector[9].SetPtEtaPhiM(tree->type1_pfMet_shiftedPt_JetEC2Up,0,tree->type1_pfMet_shiftedPhi_JetEC2Up,0);
  mymetvector[10].SetPtEtaPhiM(tree->type1_pfMet_shiftedPt_JetEC2Down,0,tree->type1_pfMet_shiftedPhi_JetEC2Down,0);
  mymetvector[11].SetPtEtaPhiM(tree->type1_pfMet_shiftedPt_JetEC2yearUp,0,tree->type1_pfMet_shiftedPhi_JetEC2yearUp,0);
  mymetvector[12].SetPtEtaPhiM(tree->type1_pfMet_shiftedPt_JetEC2yearDown,0,tree->type1_pfMet_shiftedPhi_JetEC2yearDown,0);
  mymetvector[13].SetPtEtaPhiM(tree->type1_pfMet_shiftedPt_JetFlavorQCDUp,0,tree->type1_pfMet_shiftedPhi_JetFlavorQCDUp,0);
  mymetvector[14].SetPtEtaPhiM(tree->type1_pfMet_shiftedPt_JetFlavorQCDDown,0,tree->type1_pfMet_shiftedPhi_JetFlavorQCDDown,0);
  mymetvector[15].SetPtEtaPhiM(tree->type1_pfMet_shiftedPt_JetHFUp,0,tree->type1_pfMet_shiftedPhi_JetHFUp,0);
  mymetvector[16].SetPtEtaPhiM(tree->type1_pfMet_shiftedPt_JetHFDown,0,tree->type1_pfMet_shiftedPhi_JetHFDown,0);
  mymetvector[17].SetPtEtaPhiM(tree->type1_pfMet_shiftedPt_JetHFyearUp,0,tree->type1_pfMet_shiftedPhi_JetHFyearUp,0);
  mymetvector[18].SetPtEtaPhiM(tree->type1_pfMet_shiftedPt_JetHFyearDown,0,tree->type1_pfMet_shiftedPhi_JetHFyearDown,0);
  mymetvector[19].SetPtEtaPhiM(tree->type1_pfMet_shiftedPt_JetRelativeBalUp,0,tree->type1_pfMet_shiftedPhi_JetRelativeBalUp,0);
  mymetvector[20].SetPtEtaPhiM(tree->type1_pfMet_shiftedPt_JetRelativeBalDown,0,tree->type1_pfMet_shiftedPhi_JetRelativeBalDown,0);
  mymetvector[21].SetPtEtaPhiM(tree->type1_pfMet_shiftedPt_JetRelativeSampleUp,0,tree->type1_pfMet_shiftedPhi_JetRelativeSampleUp,0);
  mymetvector[22].SetPtEtaPhiM(tree->type1_pfMet_shiftedPt_JetRelativeSampleDown,0,tree->type1_pfMet_shiftedPhi_JetRelativeSampleDown,0);
  mymetvector[23].SetPtEtaPhiM(tree->type1_pfMet_shiftedPt_JERUp,0,tree->type1_pfMet_shiftedPhi_JERUp,0);
  mymetvector[24].SetPtEtaPhiM(tree->type1_pfMet_shiftedPt_JERDown,0,tree->type1_pfMet_shiftedPhi_JERDown,0);
  mymetvector[25].SetPtEtaPhiM(tree->type1_pfMet_shiftedPt_UnclusteredEnUp,0,tree->type1_pfMet_shiftedPhi_UnclusteredEnUp,0);
  mymetvector[26].SetPtEtaPhiM(tree->type1_pfMet_shiftedPt_UnclusteredEnDown,0,tree->type1_pfMet_shiftedPhi_UnclusteredEnDown,0);

  float pfmetcorr_exvector[27];
  float pfmetcorr_eyvector[27];
  for (int j=0; j<27; ++j){
     pfmetcorr_exvector[j]=mymetvector[j].Px();
     pfmetcorr_eyvector[j]=mymetvector[j].Py();
  }

  TLorentzVector mymet_resolutionUp, mymet_resolutionDown, mymet_responseUp, mymet_responseDown;
  float pfmetcorr_ex_responseUp,pfmetcorr_ey_responseUp,pfmetcorr_ex_responseDown,pfmetcorr_ey_responseDown,pfmetcorr_ex_resolutionUp,pfmetcorr_ey_resolutionUp,pfmetcorr_ex_resolutionDown,pfmetcorr_ey_resolutionDown;

  int recoiljets=tree->jetVeto30+1;
  if (recoil==2) recoiljets=tree->jetVeto30;

  for (int j=0; j<27; ++j){
    if (recoil>=1){
      if (year == 2018) {
        recoilPFMetCorrector2018.CorrectByMeanResolution(
          mymetvector[j].Px(), // uncorrected type I pf met px (float)
          mymetvector[j].Py(), // uncorrected type I pf met py (float)
          tree->genpX, // generator Z/W/Higgs px (float)
          tree->genpY, // generator Z/W/Higgs py (float)
          tree->vispX, // generator visible Z/W/Higgs px (float)
          tree->vispY, // generator visible Z/W/Higgs py (float)
          recoiljets,  // number of jets (hadronic jet multiplicity) (int)
          pfmetcorr_exvector[j], // corrected type I pf met px (float)
          pfmetcorr_eyvector[j]  // corrected type I pf met py (float)
        );
      }
      if (year == 2017) {
        recoilPFMetCorrector2017.CorrectByMeanResolution(
          mymetvector[j].Px(), // uncorrected type I pf met px (float)
          mymetvector[j].Py(), // uncorrected type I pf met py (float)
          tree->genpX, // generator Z/W/Higgs px (float)
          tree->genpY, // generator Z/W/Higgs py (float)
          tree->vispX, // generator visible Z/W/Higgs px (float)
          tree->vispY, // generator visible Z/W/Higgs py (float)
          recoiljets,  // number of jets (hadronic jet multiplicity) (int)
          pfmetcorr_exvector[j], // corrected type I pf met px (float)
          pfmetcorr_eyvector[j]  // corrected type I pf met py (float)
        );
      }
      if (year == 2016) {
        recoilPFMetCorrector2016.CorrectByMeanResolution(
          mymetvector[j].Px(), // uncorrected type I pf met px (float)
          mymetvector[j].Py(), // uncorrected type I pf met py (float)
          tree->genpX, // generator Z/W/Higgs px (float)
          tree->genpY, // generator Z/W/Higgs py (float)
          tree->vispX, // generator visible Z/W/Higgs px (float)
          tree->vispY, // generator visible Z/W/Higgs py (float)
          recoiljets,  // number of jets (hadronic jet multiplicity) (int)
          pfmetcorr_exvector[j], // corrected type I pf met px (float)
          pfmetcorr_eyvector[j]  // corrected type I pf met py (float)
        );
      }
    }
  }

  mymetvector[0].SetPxPyPzE(pfmetcorr_exvector[0],pfmetcorr_eyvector[0],0,sqrt(pfmetcorr_exvector[0]*pfmetcorr_exvector[0]+pfmetcorr_eyvector[0]*pfmetcorr_eyvector[0]));
  int Process= MEtSys::ProcessType::BOSON;
  if (recoil>=1){
    if (year == 2018) {
      metSys2018.ApplyMEtSys(mymetvector[0].Px(),mymetvector[0].Py(),
                       genpX,genpY,
                       vispX,vispY,
                       recoiljets,
                       Process,
                       MEtSys::SysType::Response,
                       MEtSys::SysShift::Up,
                       pfmetcorr_ex_responseUp,pfmetcorr_ey_responseUp
                       );

      metSys2018.ApplyMEtSys(mymetvector[0].Px(),mymetvector[0].Py(),
                       genpX,genpY,
                       vispX,vispY,
                       recoiljets,
                       Process,
                       MEtSys::SysType::Response,
                       MEtSys::SysShift::Down,
                       pfmetcorr_ex_responseDown,pfmetcorr_ey_responseDown
                       );

      metSys2018.ApplyMEtSys(mymetvector[0].Px(),mymetvector[0].Py(),
                       genpX,genpY,
                       vispX,vispY,
                       recoiljets,
                       Process,
                       MEtSys::SysType::Resolution,
                       MEtSys::SysShift::Up,
                       pfmetcorr_ex_resolutionUp,pfmetcorr_ey_resolutionUp
                       );
      metSys2018.ApplyMEtSys(mymetvector[0].Px(),mymetvector[0].Py(),
                       genpX,genpY,
                       vispX,vispY,
                       recoiljets,
                       Process,
                       MEtSys::SysType::Resolution,
                       MEtSys::SysShift::Down,
                       pfmetcorr_ex_resolutionDown,pfmetcorr_ey_resolutionDown
                       );
    }
    if (year == 2017) {
      metSys2017.ApplyMEtSys(mymetvector[0].Px(),mymetvector[0].Py(),
                       genpX,genpY,
                       vispX,vispY,
                       recoiljets,
                       Process,
                       MEtSys::SysType::Response,
                       MEtSys::SysShift::Up,
                       pfmetcorr_ex_responseUp,pfmetcorr_ey_responseUp
                       );

      metSys2017.ApplyMEtSys(mymetvector[0].Px(),mymetvector[0].Py(),
                       genpX,genpY,
                       vispX,vispY,
                       recoiljets,
                       Process,
                       MEtSys::SysType::Response,
                       MEtSys::SysShift::Down,
                       pfmetcorr_ex_responseDown,pfmetcorr_ey_responseDown
                       );

      metSys2017.ApplyMEtSys(mymetvector[0].Px(),mymetvector[0].Py(),
                       genpX,genpY,
                       vispX,vispY,
                       recoiljets,
                       Process,
                       MEtSys::SysType::Resolution,
                       MEtSys::SysShift::Up,
                       pfmetcorr_ex_resolutionUp,pfmetcorr_ey_resolutionUp
                       );
      metSys2017.ApplyMEtSys(mymetvector[0].Px(),mymetvector[0].Py(),
                       genpX,genpY,
                       vispX,vispY,
                       recoiljets,
                       Process,
                       MEtSys::SysType::Resolution,
                       MEtSys::SysShift::Down,
                       pfmetcorr_ex_resolutionDown,pfmetcorr_ey_resolutionDown
                       );
    }
    if (year == 2016) {
      metSys2016.ApplyMEtSys(mymetvector[0].Px(),mymetvector[0].Py(),
                       genpX,genpY,
                       vispX,vispY,
                       recoiljets,
                       Process,
                       MEtSys::SysType::Response,
                       MEtSys::SysShift::Up,
                       pfmetcorr_ex_responseUp,pfmetcorr_ey_responseUp
                       );

      metSys2016.ApplyMEtSys(mymetvector[0].Px(),mymetvector[0].Py(),
                       genpX,genpY,
                       vispX,vispY,
                       recoiljets,
                       Process,
                       MEtSys::SysType::Response,
                       MEtSys::SysShift::Down,
                       pfmetcorr_ex_responseDown,pfmetcorr_ey_responseDown
                       );

      metSys2016.ApplyMEtSys(mymetvector[0].Px(),mymetvector[0].Py(),
                       genpX,genpY,
                       vispX,vispY,
                       recoiljets,
                       Process,
                       MEtSys::SysType::Resolution,
                       MEtSys::SysShift::Up,
                       pfmetcorr_ex_resolutionUp,pfmetcorr_ey_resolutionUp
                       );
      metSys2016.ApplyMEtSys(mymetvector[0].Px(),mymetvector[0].Py(),
                       genpX,genpY,
                       vispX,vispY,
                       recoiljets,
                       Process,
                       MEtSys::SysType::Resolution,
                       MEtSys::SysShift::Down,
                       pfmetcorr_ex_resolutionDown,pfmetcorr_ey_resolutionDown
                       );
    }
  }

  for (int j=0; j<27; ++j){
     mymetvector[j].SetPxPyPzE(pfmetcorr_exvector[j],pfmetcorr_eyvector[j],0,sqrt(pfmetcorr_exvector[j]*pfmetcorr_exvector[j]+pfmetcorr_eyvector[j]*pfmetcorr_eyvector[j]));
  }

  mymet_responseUp.SetPxPyPzE(pfmetcorr_ex_responseUp,pfmetcorr_ey_responseUp,0,sqrt(pfmetcorr_ex_responseUp*pfmetcorr_ex_responseUp+pfmetcorr_ey_responseUp*pfmetcorr_ey_responseUp));
  mymet_responseDown.SetPxPyPzE(pfmetcorr_ex_responseDown,pfmetcorr_ey_responseDown,0,sqrt(pfmetcorr_ex_responseDown*pfmetcorr_ex_responseDown+pfmetcorr_ey_responseDown*pfmetcorr_ey_responseDown));
  mymet_resolutionUp.SetPxPyPzE(pfmetcorr_ex_resolutionUp,pfmetcorr_ey_resolutionUp,0,sqrt(pfmetcorr_ex_resolutionUp*pfmetcorr_ex_resolutionUp+pfmetcorr_ey_resolutionUp*pfmetcorr_ey_resolutionUp));
  mymet_resolutionDown.SetPxPyPzE(pfmetcorr_ex_resolutionDown,pfmetcorr_ey_resolutionDown,0,sqrt(pfmetcorr_ex_resolutionDown*pfmetcorr_ex_resolutionDown+pfmetcorr_ey_resolutionDown*pfmetcorr_ey_resolutionDown));

  met=mymetvector[0].Pt();
  metphi=mymetvector[0].Phi();
  met_px=mymetvector[0].Px();
  met_py=mymetvector[0].Py();

  met_JetAbsoluteUp=mymetvector[1].Pt();
  metphi_JetAbsoluteUp=mymetvector[1].Phi();
  met_JetAbsoluteDown=mymetvector[2].Pt();
  metphi_JetAbsoluteDown=mymetvector[2].Phi();
  met_JetAbsoluteyearUp=mymetvector[3].Pt();
  metphi_JetAbsoluteyearUp=mymetvector[3].Phi();
  met_JetAbsoluteyearDown=mymetvector[4].Pt();
  metphi_JetAbsoluteyearDown=mymetvector[4].Phi();
  met_JetBBEC1Up=mymetvector[5].Pt();
  metphi_JetBBEC1Up=mymetvector[5].Phi();
  met_JetBBEC1Down=mymetvector[6].Pt();
  metphi_JetBBEC1Down=mymetvector[6].Phi();
  met_JetBBEC1yearUp=mymetvector[7].Pt();
  metphi_JetBBEC1yearUp=mymetvector[7].Phi();
  met_JetBBEC1yearDown=mymetvector[8].Pt();
  metphi_JetBBEC1yearDown=mymetvector[8].Phi();
  met_JetEC2Up=mymetvector[9].Pt();
  metphi_JetEC2Up=mymetvector[9].Phi();
  met_JetEC2Down=mymetvector[10].Pt();
  metphi_JetEC2Down=mymetvector[10].Phi();
  met_JetEC2yearUp=mymetvector[11].Pt();
  metphi_JetEC2yearUp=mymetvector[11].Phi();
  met_JetEC2yearDown=mymetvector[12].Pt();
  metphi_JetEC2yearDown=mymetvector[12].Phi();
  met_JetFlavorQCDUp=mymetvector[13].Pt();
  metphi_JetFlavorQCDUp=mymetvector[13].Phi();
  met_JetFlavorQCDDown=mymetvector[14].Pt();
  metphi_JetFlavorQCDDown=mymetvector[14].Phi();
  met_JetHFUp=mymetvector[15].Pt();
  metphi_JetHFUp=mymetvector[15].Phi();
  met_JetHFDown=mymetvector[16].Pt();
  metphi_JetHFDown=mymetvector[16].Phi();
  met_JetHFyearUp=mymetvector[17].Pt();
  metphi_JetHFyearUp=mymetvector[17].Phi();
  met_JetHFyearDown=mymetvector[18].Pt();
  metphi_JetHFyearDown=mymetvector[18].Phi();
  met_JetRelativeBalUp=mymetvector[19].Pt();
  metphi_JetRelativeBalUp=mymetvector[19].Phi();
  met_JetRelativeBalDown=mymetvector[20].Pt();
  metphi_JetRelativeBalDown=mymetvector[20].Phi();
  met_JetRelativeSampleUp=mymetvector[21].Pt();
  metphi_JetRelativeSampleUp=mymetvector[21].Phi();
  met_JetRelativeSampleDown=mymetvector[22].Pt();
  metphi_JetRelativeSampleDown=mymetvector[22].Phi();
  met_JERUp=mymetvector[23].Pt();
  metphi_JERUp=mymetvector[23].Phi();
  met_JERDown=mymetvector[24].Pt();
  metphi_JERDown=mymetvector[24].Phi();
  met_UESUp=mymetvector[25].Pt();
  metphi_UESUp=mymetvector[25].Phi();
  met_UESDown=mymetvector[26].Pt();
  metphi_UESDown=mymetvector[26].Phi();

  met_responseUp=mymet_responseUp.Pt();
  met_resolutionUp=mymet_resolutionUp.Pt();
  metphi_responseUp=mymet_responseUp.Phi();
  metphi_resolutionUp=mymet_resolutionUp.Phi();
  met_responseDown=mymet_responseDown.Pt();
  met_resolutionDown=mymet_resolutionDown.Pt();
  metphi_responseDown=mymet_responseDown.Phi();
  metphi_resolutionDown=mymet_resolutionDown.Phi();

  float uncorrectedE=tau1.E();
  TLorentzVector myeleScaleUp=tau1*(tree->eEnergyScaleUp/uncorrectedE);
  TLorentzVector myeleScaleDown=tau1*(tree->eEnergyScaleDown/uncorrectedE);
  if (ismc) tau1=tau1*(tree->eCorrectedEt/uncorrectedE);

  auto embeddingeleESset = correction::CorrectionSet::from_file("eleES_2018UL.json");
  if (year==2017) embeddingeleESset = correction::CorrectionSet::from_file("eleES_2017UL.json");
  if (year==2016 && preVFP) embeddingeleESset = correction::CorrectionSet::from_file("eleES_2016preVFPUL.json");
  if (year==2016 && !preVFP) embeddingeleESset = correction::CorrectionSet::from_file("eleES_2016postVFPUL.json");
  if (isembedded){
    if (fabs(tau1.Eta())<1.479) tau1=tau1*embeddingeleESset->at("eleES")->evaluate({"barrel", "nom"});
    if (fabs(tau1.Eta())>1.479) tau1=tau1*embeddingeleESset->at("eleES")->evaluate({"endcap", "nom"});
  }
  m_1 = tree->eMass;
  e_1 = tau1.E();
  pt_1 = tau1.Pt();
  pt_1_ScaleUp = myeleScaleUp.Pt();
  pt_1_ScaleDown = myeleScaleDown.Pt();
  phi_1 = tau1.Phi();
  eta_1 = tau1.Eta();
  dZ_1 = tree->ePVDZ;
  d0_1 = tree->ePVDXY;
  iso_1 = tree->eRelPFIsoRho;
  if (tau1.DeltaR(tau2)<0.4 and iso_1*pt_1>=tau2.Pt()) iso_1=(tree->eRelPFIsoRho*pt_1-tau2.Pt())/pt_1; // remove muon from isolation cone
  q_1 = tree->eCharge;

  m_2 = tau2.M();
  e_2 = tau2.E();
  pt_2 = tau2.Pt();
  phi_2 = tau2.Phi();
  eta_2 = tau2.Eta();
  dZ_2 = tree->mPVDZ;
  d0_2=tree->mPVDXY;
  iso_2=tree->mRelPFIsoDBDefault;
  q_2 = tree->mCharge;
  if (tau1.DeltaR(tau2)<0.4 and iso_2*pt_2>=tau1.Pt()) iso_2=(tree->mRelPFIsoDBDefault*pt_2-tau1.Pt())/pt_2; // remove electron from isolation cone

  jpt_1=tree->j1pt;
  jpt_1_JERUp=tree->j1pt_JERUp;
  jpt_1_JERDown=tree->j1pt_JERDown;
  jpt_1_JetAbsoluteUp=tree->j1pt_JetAbsoluteUp;
  jpt_1_JetAbsoluteDown=tree->j1pt_JetAbsoluteDown;
  jpt_1_JetAbsoluteyearUp=tree->j1pt_JetAbsoluteyearUp;
  jpt_1_JetAbsoluteyearDown=tree->j1pt_JetAbsoluteyearDown;
  jpt_1_JetBBEC1Up=tree->j1pt_JetBBEC1Up;
  jpt_1_JetBBEC1Down=tree->j1pt_JetBBEC1Down;
  jpt_1_JetBBEC1yearUp=tree->j1pt_JetBBEC1yearUp;
  jpt_1_JetBBEC1yearDown=tree->j1pt_JetBBEC1yearDown;
  jpt_1_JetEC2Up=tree->j1pt_JetEC2Up;
  jpt_1_JetEC2Down=tree->j1pt_JetEC2Down;
  jpt_1_JetEC2yearUp=tree->j1pt_JetEC2yearUp;
  jpt_1_JetEC2yearDown=tree->j1pt_JetEC2yearDown;
  jpt_1_JetFlavorQCDUp=tree->j1pt_JetFlavorQCDUp;
  jpt_1_JetFlavorQCDDown=tree->j1pt_JetFlavorQCDDown;
  jpt_1_JetHFUp=tree->j1pt_JetHFUp;
  jpt_1_JetHFDown=tree->j1pt_JetHFDown;
  jpt_1_JetHFyearUp=tree->j1pt_JetHFyearUp;
  jpt_1_JetHFyearDown=tree->j1pt_JetHFyearDown;
  jpt_1_JetRelativeBalUp=tree->j1pt_JetRelativeBalUp;
  jpt_1_JetRelativeBalDown=tree->j1pt_JetRelativeBalDown;
  jpt_1_JetRelativeSampleUp=tree->j1pt_JetRelativeSampleUp;
  jpt_1_JetRelativeSampleDown=tree->j1pt_JetRelativeSampleDown;

  jpt_2=tree->j2pt;
  jeta_1=tree->j1eta;
  jeta_2=tree->j2eta;
  jphi_1=tree->j1phi;
  jphi_2=tree->j2phi;

  bpt_deepcsv_1=tree->deepcsvb1_pt;
  beta_deepcsv_1=tree->deepcsvb1_eta;
  bphi_deepcsv_1=tree->deepcsvb1_phi;
  bm_deepcsv_1=tree->deepcsvb1_m;
  bflavour_deepcsv_1=tree->deepcsvb1_hadronflavour;
  bscore_deepcsv_1=tree->deepcsvb1_btagscore;
  bpt_deepcsv_2=tree->deepcsvb2_pt;
  beta_deepcsv_2=tree->deepcsvb2_eta;
  bphi_deepcsv_2=tree->deepcsvb2_phi;
  bm_deepcsv_2=tree->deepcsvb2_m;
  bflavour_deepcsv_2=tree->deepcsvb2_hadronflavour;
  bscore_deepcsv_2=tree->deepcsvb2_btagscore;

  bpt_deepflavour_1=tree->deepflavourb1_pt;
  beta_deepflavour_1=tree->deepflavourb1_eta;
  bphi_deepflavour_1=tree->deepflavourb1_phi;
  bm_deepflavour_1=tree->deepflavourb1_m;
  bflavour_deepflavour_1=tree->deepflavourb1_hadronflavour;
  bscore_deepflavour_1=tree->deepflavourb1_btagscore;
  bpt_deepflavour_2=tree->deepflavourb2_pt;
  beta_deepflavour_2=tree->deepflavourb2_eta;
  bphi_deepflavour_2=tree->deepflavourb2_phi;
  bm_deepflavour_2=tree->deepflavourb2_m;
  bflavour_deepflavour_2=tree->deepflavourb2_hadronflavour;
  bscore_deepflavour_2=tree->deepflavourb2_btagscore;

  bpt_deepflavour_JERDown_1=tree->deepflavourb1_pt_JERDown;
  bpt_deepflavour_JERUp_1=tree->deepflavourb1_pt_JERUp;
  bpt_deepflavour_JetAbsoluteDown_1=tree->deepflavourb1_pt_JetAbsoluteDown;
  bpt_deepflavour_JetAbsoluteUp_1=tree->deepflavourb1_pt_JetAbsoluteUp;
  bpt_deepflavour_JetAbsoluteyearDown_1=tree->deepflavourb1_pt_JetAbsoluteyearDown;
  bpt_deepflavour_JetAbsoluteyearUp_1=tree->deepflavourb1_pt_JetAbsoluteyearUp;
  bpt_deepflavour_JetBBEC1Down_1=tree->deepflavourb1_pt_JetBBEC1Down;
  bpt_deepflavour_JetBBEC1Up_1=tree->deepflavourb1_pt_JetBBEC1Up;
  bpt_deepflavour_JetBBEC1yearDown_1=tree->deepflavourb1_pt_JetBBEC1yearDown;
  bpt_deepflavour_JetBBEC1yearUp_1=tree->deepflavourb1_pt_JetBBEC1yearUp;
  bpt_deepflavour_JetEC2Down_1=tree->deepflavourb1_pt_JetEC2Down;
  bpt_deepflavour_JetEC2Up_1=tree->deepflavourb1_pt_JetEC2Up;
  bpt_deepflavour_JetEC2yearDown_1=tree->deepflavourb1_pt_JetEC2yearDown;
  bpt_deepflavour_JetEC2yearUp_1=tree->deepflavourb1_pt_JetEC2yearUp;
  bpt_deepflavour_JetFlavorQCDDown_1=tree->deepflavourb1_pt_JetFlavorQCDDown;
  bpt_deepflavour_JetFlavorQCDUp_1=tree->deepflavourb1_pt_JetFlavorQCDUp;
  bpt_deepflavour_JetHFDown_1=tree->deepflavourb1_pt_JetHFDown;
  bpt_deepflavour_JetHFUp_1=tree->deepflavourb1_pt_JetHFUp;
  bpt_deepflavour_JetHFyearDown_1=tree->deepflavourb1_pt_JetHFyearDown;
  bpt_deepflavour_JetHFyearUp_1=tree->deepflavourb1_pt_JetHFyearUp;
  bpt_deepflavour_JetRelativeBalDown_1=tree->deepflavourb1_pt_JetRelativeBalDown;
  bpt_deepflavour_JetRelativeBalUp_1=tree->deepflavourb1_pt_JetRelativeBalUp;
  bpt_deepflavour_JetRelativeSampleDown_1=tree->deepflavourb1_pt_JetRelativeSampleDown;
  bpt_deepflavour_JetRelativeSampleUp_1=tree->deepflavourb1_pt_JetRelativeSampleUp;
  bpt_deepflavour_JetTotalDown_1=tree->deepflavourb1_pt_JetTotalDown;
  bpt_deepflavour_JetTotalUp_1=tree->deepflavourb1_pt_JetTotalUp;

  bpt_deepflavour_JERDown_2=tree->deepflavourb2_pt_JERDown;
  bpt_deepflavour_JERUp_2=tree->deepflavourb2_pt_JERUp;
  bpt_deepflavour_JetAbsoluteDown_2=tree->deepflavourb2_pt_JetAbsoluteDown;
  bpt_deepflavour_JetAbsoluteUp_2=tree->deepflavourb2_pt_JetAbsoluteUp;
  bpt_deepflavour_JetAbsoluteyearDown_2=tree->deepflavourb2_pt_JetAbsoluteyearDown;
  bpt_deepflavour_JetAbsoluteyearUp_2=tree->deepflavourb2_pt_JetAbsoluteyearUp;
  bpt_deepflavour_JetBBEC1Down_2=tree->deepflavourb2_pt_JetBBEC1Down;
  bpt_deepflavour_JetBBEC1Up_2=tree->deepflavourb2_pt_JetBBEC1Up;
  bpt_deepflavour_JetBBEC1yearDown_2=tree->deepflavourb2_pt_JetBBEC1yearDown;
  bpt_deepflavour_JetBBEC1yearUp_2=tree->deepflavourb2_pt_JetBBEC1yearUp;
  bpt_deepflavour_JetEC2Down_2=tree->deepflavourb2_pt_JetEC2Down;
  bpt_deepflavour_JetEC2Up_2=tree->deepflavourb2_pt_JetEC2Up;
  bpt_deepflavour_JetEC2yearDown_2=tree->deepflavourb2_pt_JetEC2yearDown;
  bpt_deepflavour_JetEC2yearUp_2=tree->deepflavourb2_pt_JetEC2yearUp;
  bpt_deepflavour_JetFlavorQCDDown_2=tree->deepflavourb2_pt_JetFlavorQCDDown;
  bpt_deepflavour_JetFlavorQCDUp_2=tree->deepflavourb2_pt_JetFlavorQCDUp;
  bpt_deepflavour_JetHFDown_2=tree->deepflavourb2_pt_JetHFDown;
  bpt_deepflavour_JetHFUp_2=tree->deepflavourb2_pt_JetHFUp;
  bpt_deepflavour_JetHFyearDown_2=tree->deepflavourb2_pt_JetHFyearDown;
  bpt_deepflavour_JetHFyearUp_2=tree->deepflavourb2_pt_JetHFyearUp;
  bpt_deepflavour_JetRelativeBalDown_2=tree->deepflavourb2_pt_JetRelativeBalDown;
  bpt_deepflavour_JetRelativeBalUp_2=tree->deepflavourb2_pt_JetRelativeBalUp;
  bpt_deepflavour_JetRelativeSampleDown_2=tree->deepflavourb2_pt_JetRelativeSampleDown;
  bpt_deepflavour_JetRelativeSampleUp_2=tree->deepflavourb2_pt_JetRelativeSampleUp;
  bpt_deepflavour_JetTotalDown_2=tree->deepflavourb2_pt_JetTotalDown;
  bpt_deepflavour_JetTotalUp_2=tree->deepflavourb2_pt_JetTotalUp;

  mjj=tree->vbfMass;
  mjj_JERUp=tree->vbfMass_JERUp;
  mjj_JERDown=tree->vbfMass_JERDown;
  mjj_JetAbsoluteUp=tree->vbfMass_JetAbsoluteUp;
  mjj_JetAbsoluteDown=tree->vbfMass_JetAbsoluteDown;
  mjj_JetAbsoluteyearUp=tree->vbfMass_JetAbsoluteyearUp;
  mjj_JetAbsoluteyearDown=tree->vbfMass_JetAbsoluteyearDown;
  mjj_JetBBEC1Up=tree->vbfMass_JetBBEC1Up;
  mjj_JetBBEC1Down=tree->vbfMass_JetBBEC1Down;
  mjj_JetBBEC1yearUp=tree->vbfMass_JetBBEC1yearUp;
  mjj_JetBBEC1yearDown=tree->vbfMass_JetBBEC1yearDown;
  mjj_JetEC2Up=tree->vbfMass_JetEC2Up;
  mjj_JetEC2Down=tree->vbfMass_JetEC2Down;
  mjj_JetEC2yearUp=tree->vbfMass_JetEC2yearUp;
  mjj_JetEC2yearDown=tree->vbfMass_JetEC2yearDown;
  mjj_JetFlavorQCDUp=tree->vbfMass_JetFlavorQCDUp;
  mjj_JetFlavorQCDDown=tree->vbfMass_JetFlavorQCDDown;
  mjj_JetHFUp=tree->vbfMass_JetHFUp;
  mjj_JetHFDown=tree->vbfMass_JetHFDown;
  mjj_JetHFyearUp=tree->vbfMass_JetHFyearUp;
  mjj_JetHFyearDown=tree->vbfMass_JetHFyearDown;
  mjj_JetRelativeBalUp=tree->vbfMass_JetRelativeBalUp;
  mjj_JetRelativeBalDown=tree->vbfMass_JetRelativeBalDown;
  mjj_JetRelativeSampleUp=tree->vbfMass_JetRelativeSampleUp;
  mjj_JetRelativeSampleDown=tree->vbfMass_JetRelativeSampleDown;

  NUP=tree->NUP;
  npu=tree->nTruePU;
  npv=tree->nvtx;

  extraelec_veto=(tree->eVetoZTTp001dxyzR0>0);
  extramuon_veto=(tree->muVetoZTTp001dxyzR0>1);
  dilepton_veto=(tree->dimuonVeto>0);

  float pt_1_treated = pt_1;
  float pt_2_treated = pt_2;

  if (pt_1 < 15.) {
      pt_1_treated = 16.;
  }
  if (pt_1 > 120.) {
      pt_1_treated = 119.;
  }
  if (pt_2 < 15.) {
      pt_2_treated = 16.;
  }
  if (pt_2 > 200.) {
      pt_2_treated = 199.;
  }

  TFile *f1 = TFile::Open("sf_el_2018_HLTMu8Ele23.root");
  TFile *f2 = TFile::Open("sf_mu_2018_HLTMu8Ele23.root");
  TFile *f3 = TFile::Open("sf_el_2018_HLTMu23Ele12.root");
  TFile *f4 = TFile::Open("sf_mu_2018_HLTMu23Ele12.root");
  auto electronset = correction::CorrectionSet::from_file("electron.json");
  auto muonset = correction::CorrectionSet::from_file("muon_Z.json");
  auto embeddingset = correction::CorrectionSet::from_file("embeddingselection_2018UL.json");
  auto embeddingeleset = correction::CorrectionSet::from_file("electron_2018UL.json"); 
  auto embeddingmuset = correction::CorrectionSet::from_file("muon_2018UL.json");

  if (year==2017) {
    //f1 = TFile::Open("sf_el_2017_HLTMu8Ele23.root");
    //f2 = TFile::Open("sf_mu_2017_HLTMu8Ele23.root");
    //f3 = TFile::Open("sf_el_2017_HLTMu23Ele12.root");
    //f4 = TFile::Open("sf_mu_2017_HLTMu23Ele12.root");
    electronset = correction::CorrectionSet::from_file("electron_2017.json");
    muonset = correction::CorrectionSet::from_file("muon_Z_2017.json");
    embeddingset = correction::CorrectionSet::from_file("embeddingselection_2017UL.json");
    embeddingeleset = correction::CorrectionSet::from_file("electron_2017UL.json");
    embeddingmuset = correction::CorrectionSet::from_file("muon_2017UL.json");
  }

  if (year==2016 && preVFP) {
    //f1 = TFile::Open("sf_el_2016_preVFP_HLTMu8Ele23.root");
    //f2 = TFile::Open("sf_mu_2016_preVFP_HLTMu8Ele23.root");
    //f3 = TFile::Open("sf_el_2016_preVFP_HLTMu23Ele12.root");
    //f4 = TFile::Open("sf_mu_2016_preVFP_HLTMu23Ele12.root");
    electronset = correction::CorrectionSet::from_file("electron_2016preVFP.json");
    muonset = correction::CorrectionSet::from_file("muon_Z_2016preVFP.json");
    embeddingset = correction::CorrectionSet::from_file("embeddingselection_2016preVFPUL.json");
    embeddingeleset = correction::CorrectionSet::from_file("electron_2016preVFPUL.json");
    embeddingmuset = correction::CorrectionSet::from_file("muon_2016preVFPUL.json");
  }

  if (year==2016 && !preVFP) {
    //f1 = TFile::Open("sf_el_2016_postVFP_HLTMu8Ele23.root");
    //f2 = TFile::Open("sf_mu_2016_postVFP_HLTMu8Ele23.root");
    //f3 = TFile::Open("sf_el_2016_postVFP_HLTMu23Ele12.root");
    //f4 = TFile::Open("sf_mu_2016_postVFP_HLTMu23Ele12.root");
    electronset = correction::CorrectionSet::from_file("electron_2016postVFP.json");
    muonset = correction::CorrectionSet::from_file("muon_Z_2016postVFP.json");
    embeddingset = correction::CorrectionSet::from_file("embeddingselection_2016postVFPUL.json");
    embeddingeleset = correction::CorrectionSet::from_file("electron_2016postVFPUL.json");
    embeddingmuset = correction::CorrectionSet::from_file("muon_2016postVFPUL.json");
  }

  RooWorkspace *wmc=wmc2018;
  if (year==2017) wmc=wmc2017;
  if (year==2016) wmc=wmc2016;

  if (ismc){
    wmc->var("z_gen_mass")->setVal(genM);
    wmc->var("z_gen_pt")->setVal(genpT);
    zptmass_weight_nom=wmc->function("zptmass_weight_nom")->getVal();
//     wmc->var("m_pt")->setVal(pt_2);
//     wmc->var("m_eta")->setVal(eta_2);
//     wmc->var("m_iso")->setVal(iso_2);
//     wmc->var("e_pt")->setVal(pt_1);
//     wmc->var("e_eta")->setVal(eta_1);
//     wmc->var("e_iso")->setVal(iso_1);
//     m_trg_8_ic_data=wmc->function("m_trg_8_ic_data")->getVal();
//     e_trg_23_ic_data=wmc->function("e_trg_23_ic_data")->getVal();
//     m_trg_23_ic_data=wmc->function("m_trg_23_ic_data")->getVal();
//     e_trg_12_ic_data=wmc->function("e_trg_12_ic_data")->getVal();
//     m_trg_8_ic_mc=wmc->function("m_trg_8_ic_mc")->getVal();
//     e_trg_23_ic_mc=wmc->function("e_trg_23_ic_mc")->getVal();
//     m_trg_23_ic_mc=wmc->function("m_trg_23_ic_mc")->getVal();
//     e_trg_12_ic_mc=wmc->function("e_trg_12_ic_mc")->getVal();

    TH2F *th2f_mc_ele_Mu8Ele23 = (TH2F*)f1->Get("eff_mc");
    int i_ele_Mu8Ele23 = th2f_mc_ele_Mu8Ele23->FindFixBin(pt_1_treated, eta_1);
    e_trg_23_ic_mc = th2f_mc_ele_Mu8Ele23->GetBinContent(i_ele_Mu8Ele23);

    TH2F *th2f_mc_muo_Mu8Ele23 = (TH2F*)f2->Get("eff_mc");
    int i_muo_Mu8Ele23 = th2f_mc_muo_Mu8Ele23->FindFixBin(pt_2_treated, std::abs(eta_2));
    m_trg_8_ic_mc = th2f_mc_muo_Mu8Ele23->GetBinContent(i_muo_Mu8Ele23);

    TH2F *th2f_mc_ele_Mu23Ele12 = (TH2F*)f3->Get("eff_mc");
    int i_ele_Mu23Ele12 = th2f_mc_ele_Mu23Ele12->FindFixBin(pt_1_treated, eta_1);
    e_trg_12_ic_mc = th2f_mc_ele_Mu23Ele12->GetBinContent(i_ele_Mu23Ele12);

    TH2F *th2f_mc_muon_Mu23Ele12 = (TH2F*)f4->Get("eff_mc");
    int i_muo_Mu23Ele12 = th2f_mc_muon_Mu23Ele12->FindFixBin(pt_2_treated, std::abs(eta_2));
    m_trg_23_ic_mc = th2f_mc_muon_Mu23Ele12->FindFixBin(i_muo_Mu23Ele12);

    TH2F *th2f_data_ele_Mu8Ele23 = (TH2F*)f1->Get("eff_data");
    e_trg_23_ic_data = th2f_data_ele_Mu8Ele23->GetBinContent(i_ele_Mu8Ele23);

    TH2F *th2f_data_muo_Mu8Ele23 = (TH2F*)f2->Get("eff_data");
    m_trg_8_ic_data = th2f_data_muo_Mu8Ele23->GetBinContent(i_muo_Mu8Ele23);

    TH2F *th2f_data_ele_Mu23Ele12 = (TH2F*)f3->Get("eff_data");
    e_trg_12_ic_data = th2f_data_ele_Mu23Ele12->GetBinContent(i_ele_Mu23Ele12);

    TH2F *th2f_data_muon_Mu23Ele12 = (TH2F*)f4->Get("eff_data");
    m_trg_23_ic_data = th2f_data_muon_Mu23Ele12->FindFixBin(i_muo_Mu23Ele12);

    e_trk_ratio = 1.;
    if (pt_1 >= 10.) e_idiso_ic_ratio = electronset->at("UL-Electron-ID-SF")->evaluate({"2018", "sf", "wp90noiso", eta_1, pt_1});
    else e_idiso_ic_ratio = electronset->at("UL-Electron-ID-SF")->evaluate({"2018", "sf", "wp90noiso", eta_1, 10.});

    if (year==2017) {
      if (pt_1 >= 10.) e_idiso_ic_ratio = electronset->at("UL-Electron-ID-SF")->evaluate({"2017", "sf", "wp90noiso", eta_1, pt_1});
      else e_idiso_ic_ratio = electronset->at("UL-Electron-ID-SF")->evaluate({"2017", "sf", "wp90noiso", eta_1, 10.});
    }

    if (year==2016 && preVFP) {
      if (pt_1 >= 10.) e_idiso_ic_ratio = electronset->at("UL-Electron-ID-SF")->evaluate({"2016preVFP", "sf", "wp90noiso", eta_1, pt_1});
      else e_idiso_ic_ratio = electronset->at("UL-Electron-ID-SF")->evaluate({"2016preVFP", "sf", "wp90noiso", eta_1, 10.});
    }

    if (year==2016 && !preVFP) {
      if (pt_1 >= 10.) e_idiso_ic_ratio = electronset->at("UL-Electron-ID-SF")->evaluate({"2016postVFP", "sf", "wp90noiso", eta_1, pt_1});
      else e_idiso_ic_ratio = electronset->at("UL-Electron-ID-SF")->evaluate({"2016postVFP", "sf", "wp90noiso", eta_1, 10.});
    }

    m_trk_ratio = 1.;
    if(pt_2 >= 15.) m_idiso_ic_ratio = muonset->at("NUM_MediumID_DEN_genTracks")->evaluate({eta_2, pt_2, "nominal"}) * muonset->at("NUM_TightRelIso_DEN_MediumID")->evaluate({eta_2, pt_2, "nominal"});
    else m_idiso_ic_ratio = muonset->at("NUM_MediumID_DEN_genTracks")->evaluate({eta_2, 15., "nominal"}) * muonset->at("NUM_TightRelIso_DEN_MediumID")->evaluate({eta_2, 15., "nominal"});

  }

  if (isembedded){
//     wmc->var("m_pt")->setVal(pt_2);
//     wmc->var("m_eta")->setVal(eta_2);
//     wmc->var("m_iso")->setVal(iso_2);
//     wmc->var("e_pt")->setVal(pt_1);
//     wmc->var("e_eta")->setVal(eta_1);
//     wmc->var("e_iso")->setVal(iso_1);
//     m_trg_8_ic_data=wmc->function("m_trg_8_ic_data")->getVal();
//     e_trg_23_ic_data=wmc->function("e_trg_23_ic_data")->getVal();
//     m_trg_23_ic_data=wmc->function("m_trg_23_ic_data")->getVal();
//     e_trg_12_ic_data=wmc->function("e_trg_12_ic_data")->getVal();
//     m_trg_8_ic_embed=wmc->function("m_trg_8_ic_embed")->getVal();
//     e_trg_23_ic_embed=wmc->function("e_trg_23_ic_embed")->getVal();
//     m_trg_23_ic_embed=wmc->function("m_trg_23_ic_embed")->getVal();
//     e_trg_12_ic_embed=wmc->function("e_trg_12_ic_embed")->getVal();

    TH2F *th2f_embed_ele_Mu8Ele23 = (TH2F*)f1->Get("eff_embedded");
    int i_ele_Mu8Ele23 = th2f_embed_ele_Mu8Ele23->FindFixBin(pt_1_treated, eta_1);
    e_trg_23_ic_embed = th2f_embed_ele_Mu8Ele23->GetBinContent(i_ele_Mu8Ele23);

    TH2F *th2f_embed_muo_Mu8Ele23 = (TH2F*)f2->Get("eff_embedded");
    int i_muo_Mu8Ele23 = th2f_embed_muo_Mu8Ele23->FindFixBin(pt_2_treated, std::abs(eta_2));
    m_trg_8_ic_embed = th2f_embed_muo_Mu8Ele23->GetBinContent(i_muo_Mu8Ele23);

    TH2F *th2f_embed_ele_Mu23Ele12 = (TH2F*)f3->Get("eff_embedded");
    int i_ele_Mu23Ele12 = th2f_embed_ele_Mu23Ele12->FindFixBin(pt_1_treated, eta_1);
    e_trg_12_ic_embed = th2f_embed_ele_Mu23Ele12->GetBinContent(i_ele_Mu23Ele12);

    TH2F *th2f_embed_muon_Mu23Ele12 = (TH2F*)f4->Get("eff_embedded");
    int i_muo_Mu23Ele12 = th2f_embed_muon_Mu23Ele12->FindFixBin(pt_2_treated, std::abs(eta_2));
    m_trg_23_ic_embed = th2f_embed_muon_Mu23Ele12->FindFixBin(i_muo_Mu23Ele12);

    TH2F *th2f_data_ele_Mu8Ele23 = (TH2F*)f1->Get("eff_data");
    e_trg_23_ic_data = th2f_data_ele_Mu8Ele23->GetBinContent(i_ele_Mu8Ele23);

    TH2F *th2f_data_muo_Mu8Ele23 = (TH2F*)f2->Get("eff_data");
    m_trg_8_ic_data = th2f_data_muo_Mu8Ele23->GetBinContent(i_muo_Mu8Ele23);

    TH2F *th2f_data_ele_Mu23Ele12 = (TH2F*)f3->Get("eff_data");
    e_trg_12_ic_data = th2f_data_ele_Mu23Ele12->GetBinContent(i_ele_Mu23Ele12);

    TH2F *th2f_data_muon_Mu23Ele12 = (TH2F*)f4->Get("eff_data");
    m_trg_23_ic_data = th2f_data_muon_Mu23Ele12->FindFixBin(i_muo_Mu23Ele12);

    e_trk_embed_ratio = 1.;
    if (pt_1 >= 10.) e_idiso_ic_embed_ratio = embeddingeleset->at("ID90_pt_bins_inc_eta")->evaluate({pt_1, fabs(eta_1), "emb"})*embeddingeleset->at("Iso_pt_eta_bins")->evaluate({pt_1, fabs(eta_1), "emb"});
    else e_idiso_ic_embed_ratio = embeddingeleset->at("ID90_pt_bins_inc_eta")->evaluate({10., fabs(eta_1), "emb"})*embeddingeleset->at("Iso_pt_eta_bins")->evaluate({10., fabs(eta_1), "emb"});
    m_trk_ratio = 1.; 
    if (pt_2 >= 10.) m_idiso_ic_embed_ratio = embeddingmuset->at("ID_pt_eta_bins")->evaluate({pt_2, fabs(eta_2), "emb"})*embeddingmuset->at("Iso_pt_eta_bins")->evaluate({pt_2, fabs(eta_2), "emb"});
    else m_idiso_ic_embed_ratio = embeddingmuset->at("ID_pt_eta_bins")->evaluate({10., fabs(eta_2), "emb"})*embeddingmuset->at("Iso_pt_eta_bins")->evaluate({10., fabs(eta_2), "emb"});
    if (pt_1 >= 10. && pt_2 >= 10.) m_sel_trg_ic_ratio = embeddingset->at("m_sel_trg_kit_ratio")->evaluate({pt_1, fabs(eta_1), pt_2, fabs(eta_2)});
    else m_sel_trg_ic_ratio = m_sel_trg_ic_ratio = embeddingset->at("m_sel_trg_kit_ratio")->evaluate({10., fabs(eta_1), 10., fabs(eta_2)});
    if (pt_1 >= 10.) m_sel_id_ic_ratio_1 = embeddingset->at("EmbID_pt_eta_bins")->evaluate({pt_1, fabs(eta_1)});
    else m_sel_id_ic_ratio_1 = embeddingset->at("EmbID_pt_eta_bins")->evaluate({10., fabs(eta_1)});
    if (pt_2 >= 10.) m_sel_id_ic_ratio_2 = embeddingset->at("EmbID_pt_eta_bins")->evaluate({pt_2, fabs(eta_2)});
    else m_sel_id_ic_ratio_2 = embeddingset->at("EmbID_pt_eta_bins")->evaluate({10., fabs(eta_2)});
  }

  Run_Tree->Fill();
  f1->Close(); f2->Close(); f3->Close(); f4->Close();
}

#endif

