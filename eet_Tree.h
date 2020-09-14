#ifndef THTH_TREE_H
#define	THTH_TREE_H

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
#include "HTauTauTree_eet.h"
#include "RecoilCorrector.h"
//#include "myHelper.h"

using namespace std;

float prefiring_weight,prefiring_weight_up, prefiring_weight_down;
float lheweight_muR0p5_muF0p5,lheweight_muR0p5_muF1,lheweight_muR0p5_muF2,lheweight_muR1_muF0p5,lheweight_muR1_muF2,lheweight_muR2_muF0p5,lheweight_muR2_muF1,lheweight_muR2_muF2,PythiaWeight_fsr_muR0p25,PythiaWeight_fsr_muR0p5,PythiaWeight_fsr_muR2,PythiaWeight_fsr_muR4,PythiaWeight_isr_muR0p25,PythiaWeight_isr_muR0p5,PythiaWeight_isr_muR2,PythiaWeight_isr_muR4;
float bpt_deepflavour_1, beta_deepflavour_1, bphi_deepflavour_1, bflavour_deepflavour_1, bm_deepflavour_1, bscore_deepflavour_1;
float bpt_deepflavour_2, beta_deepflavour_2, bphi_deepflavour_2, bflavour_deepflavour_2, bm_deepflavour_2, bscore_deepflavour_2;
float bpt_deepcsv_1, beta_deepcsv_1, bphi_deepcsv_1, bflavour_deepcsv_1, bm_deepcsv_1, bscore_deepcsv_1;
float bpt_deepcsv_2, beta_deepcsv_2, bphi_deepcsv_2, bflavour_deepcsv_2, bm_deepcsv_2, bscore_deepcsv_2;
float deepVVVLooseVSjet_3,deepVVLooseVSjet_3,deepVLooseVSjet_3,deepLooseVSjet_3,deepMediumVSjet_3,deepTightVSjet_3,deepVTightVSjet_3;
float deepVVVLooseVSe_3,deepVVLooseVSe_3,deepVLooseVSe_3,deepLooseVSe_3,deepMediumVSe_3,deepTightVSe_3,deepVTightVSe_3;
float deepVVVLooseVSmu_3,deepVVLooseVSmu_3,deepVLooseVSmu_3,deepLooseVSmu_3,deepMediumVSmu_3,deepTightVSmu_3,deepVTightVSmu_3;
unsigned int run, lumi, evt, NUP = -10;
bool secondMuon=false;
int gen_match_1, gen_match_2, gen_match_3=0;
float met_norecoil;
float npu, rho, npv=-1, puweight, weight;
bool isZtt, isZmt, isZet, isZee, isZmm, isZem, isZEE, isZMM, isZLL, isFake;
float passMu27, passEle32, filterMu27_2, matchMu27_2, filterEle32_1, matchEle32_1, filterEle32_2, matchEle32_2;
float passEle35, filterEle35_1, matchEle35_1, filterEle35_2, matchEle35_2;
float passEle27, filterEle27_1, matchEle27_1, filterEle27_2, matchEle27_2;
float passMu24, matchMu24_2, filterMu24_2, passMu20Tau27, matchMu20Tau27_2, filterMu20Tau27_2, passEle24Tau30, matchEle24Tau30_1, filterEle24Tau30_1, matchEle24Tau30_3, filterEle24Tau30_3, matchMu20Tau27_3, filterMu20Tau27_3;
float passMu20HPSTau27, matchMu20HPSTau27_2, filterMu20HPSTau27_2, passEle24HPSTau30, matchEle24HPSTau30_1, filterEle24HPSTau30_1, matchEle24HPSTau30_3, filterEle24HPSTau30_3, matchMu20HPSTau27_3, filterMu20HPSTau27_3;
float againstElectronLooseMVA6_3, againstElectronMediumMVA6_3, againstElectronTightMVA6_3, againstElectronVLooseMVA6_3, againstElectronVTightMVA6_3, againstMuonLoose3_3, againstMuonTight3_3, decayModeFinding_3;
float e_1, px_1, py_1, pz_1, pt_1, phi_1, eta_1, m_1, q_1, d0_1, dZ_1, mt_1, iso_1, pt_1_ScaleUp, pt_1_ScaleDown, pt_1_SigmaUp, pt_1_SigmaDown, pt_2_ScaleUp, pt_2_ScaleDown, pt_2_SigmaUp, pt_2_SigmaDown;
float jetpt_1, jetpt_2, jetpt_3;
float eid90_1, eid80_1;
float e_2, px_2, py_2, pz_2, pt_2, phi_2, eta_2, m_2, q_2, d0_2, dZ_2, mt_2, iso_2, l2_decayMode;
float e_3, px_3, py_3, pz_3, pt_3, phi_3, eta_3, m_3, q_3, d0_3, dZ_3, mt_3, iso_3, l3_decayMode;
float id_m_medium_2,id_m_medium2016_2,id_m_tight_2;
float trigweight_3, byCombinedIsolationDeltaBetaCorrRaw3Hits_3, byIsolationMVA3oldDMwoLTraw_3, byIsolationMVA3oldDMwLTraw_3, byIsolationMVA3newDMwoLTraw_3, byIsolationMVA3newDMwLTraw_3, chargedIsoPtSum_3, neutralIsoPtSum_3, puCorrPtSum_3;
float mjj, jdeta, jdphi, dijetpt, dijetphi, hdijetphi, visjeteta, ptvis;
float mjj_JESDown, jdeta_JESDown,mjj_JESUp,jdeta_JESUp;
int njetingap, njetingap20, nbtag, njets, njetspt20,nbtagL;
int njetingap_JESDown, njetingap20_JESDown, njets_JESDown, njetspt20_JESDown;
int njetingap_JESUp, njetingap20_JESUp, njets_JESUp, njetspt20_JESUp;
float je_1, jmass_1, jpt_1, jpx_1, jpy_1, jpz_1, jeta_1, jphi_1, jrawf_1, jmva_1, jpfid_1, jpuid_1, jcsv_1;
float je_2, jmass_2, jpx_2, jpy_2, jpz_2, jpt_2, jeta_2, jphi_2, jrawf_2, jmva_2, jpfid_2, jpuid_2, jcsv_2;
float bpt_1, beta_1, bphi_1, brawf_1, bmva_1, bpfid_1, bpuid_1, bcsv_1, bflavor_1;
float bpt_2, beta_2, bphi_2, brawf_2, bmva_2, bpfid_2, bpuid_2, bcsv_2, bflavor_2;
float met, metphi, mvaMet, mvaMetphi, pzetavis, pzetamiss, mvacov00, mvacov01, mvacov11, mvacov10;
int nb_extra_electrons, nb_extra_muons=0;
float top_reweighting, gen_Higgs_pt, gen_Higgs_mass=1.0;
float extraelec_veto, extramuon_veto, dilepton_veto=false;
float extratau_veto, pt_top1, pt_top2, genweight, dphi_12, dphi_mumet, dphi_taumet;
float aMCatNLO_weight, numGenJets,jetPt_3,trackpt_3;
float met_px, met_py;
float genM,genpT,genpX,genpY,vispX,vispY;
float met_UESDown, met_UESUp, metphi_UESDown, metphi_UESUp;
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
float genDR_2;
float eid80iso_1,eid80noiso_1,eid90iso_1,eid90noiso_1;
float eid80iso_2,eid80noiso_2,eid90iso_2,eid90noiso_2;
float passEle25,passEle27eta2p1Loose;
float Flag_BadChargedCandidateFilter, Flag_BadPFMuonFilter, Flag_EcalDeadCellTriggerPrimitiveFilter, Flag_HBHENoiseFilter, Flag_HBHENoiseIsoFilter, Flag_badCloneMuon, Flag_badGlobalMuon, Flag_eeBadScFilter, Flag_globalTightHalo2016Filter, Flag_goodVertices, Flag_globalSuperTightHalo2016Filter, Flag_badMuons, Flag_duplicateMuons, Flag_ecalBadCalibFilter, Flag_ecalBadCalibReducedMINIAODFilter;
float matchEle25_1,matchEle27eta2p1Loose_1, matchEle25_2;
float filterEle25_1,filterEle27eta2p1Loose_1, filterEle25_2;
float Rivet_VEta,Rivet_VPt,Rivet_errorCode,Rivet_higgsEta,Rivet_higgsPt,Rivet_nJets25,Rivet_nJets30,Rivet_p4decay_VEta,Rivet_p4decay_VPt,Rivet_prodMode,Rivet_stage0_cat,Rivet_stage1_1_cat_pTjet30GeV,Rivet_stage1_1_fine_cat_pTjet30GeV, Rivet_stage1_cat_pTjet30GeV,Rivet_higgsRapidity,Rivet_j1pt,Rivet_j1eta,Rivet_j1phi,Rivet_j1m,Rivet_j2pt,Rivet_j2eta,Rivet_j2phi,Rivet_j2m;

RecoilCorrector recoilPFMetCorrector("SMH_et_2016/HTT-utilities/RecoilCorrections/data/TypeI-PFMet_Run2018.root");

float tes_dm0_2016=0.991;
float tes_dm1_2016=0.999;
float tes_dm10_2016=1.003;
float tes_dm11_2016=0.998;

float tes_dm0_2017=1.004;
float tes_dm1_2017=1.002;
float tes_dm10_2017=1.001;
float tes_dm11_2017=0.987;

float tes_dm0_2018=0.984;
float tes_dm1_2018=0.996;
float tes_dm10_2018=0.988;
float tes_dm11_2018=0.996;

float tes_dm0_fakeele_2016=0.995;
float tes_dm1_fakeele_2016=1.060;
float tes_dm0_fakemu_2016=1.000;
float tes_dm1_fakemu_2016=0.995;

float tes_dm0_fakeele_2017=1.003;
float tes_dm1_fakeele_2017=1.036;
float tes_dm0_fakemu_2017=1.000;
float tes_dm1_fakemu_2017=1.000;

float tes_dm0_fakeele_2018=0.968;
float tes_dm1_fakeele_2018=1.026;
float tes_dm0_fakemu_2018=0.998;
float tes_dm1_fakemu_2018=0.990;

void fillTree(TTree *Run_Tree, HTauTauTree_eet *tree, int entry_tree, int recoil, bool ismc, int year){

    tree->GetEntry(entry_tree);

    prefiring_weight=tree->prefiring_weight;
    prefiring_weight_up=tree->prefiring_weight_up;
    prefiring_weight_down=tree->prefiring_weight_down;

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

    float tes_dm0=tes_dm0_2018;
    float tes_dm1=tes_dm1_2018;
    float tes_dm10=tes_dm10_2018;
    float tes_dm11=tes_dm11_2018;
    float tes_dm0_fakeele=tes_dm0_fakeele_2018;
    float tes_dm1_fakeele=tes_dm1_fakeele_2018;
    float tes_dm0_fakemu=tes_dm0_fakemu_2018;
    float tes_dm1_fakemu=tes_dm1_fakemu_2018;

    if (year==2017){
       tes_dm0=tes_dm0_2017;
       tes_dm1=tes_dm1_2017;
       tes_dm10=tes_dm10_2017;
       tes_dm11=tes_dm11_2017;
       tes_dm0_fakeele=tes_dm0_fakeele_2017;
       tes_dm1_fakeele=tes_dm1_fakeele_2017;
       tes_dm0_fakemu=tes_dm0_fakemu_2017;
       tes_dm1_fakemu=tes_dm1_fakemu_2017;
    }
    if (year==2016){
       tes_dm0=tes_dm0_2016;
       tes_dm1=tes_dm1_2016;
       tes_dm10=tes_dm10_2016;
       tes_dm11=tes_dm11_2016;
       tes_dm0_fakeele=tes_dm0_fakeele_2016;
       tes_dm1_fakeele=tes_dm1_fakeele_2016;
       tes_dm0_fakemu=tes_dm0_fakemu_2016;
       tes_dm1_fakemu=tes_dm1_fakemu_2016;
    }

    run = tree->run;
    lumi = tree->lumi;
    evt =tree->evt;
    aMCatNLO_weight = tree->GenWeight;

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


    passEle25=tree->singleE25eta2p1TightPass;
    matchEle25_1=tree->e1MatchesEle25Path;
    filterEle25_1=tree->e1MatchesEle25Filter;
    matchEle25_2=tree->e2MatchesEle25Path;
    filterEle25_2=tree->e2MatchesEle25Filter;
    passEle32=tree->Ele32WPTightPass;
    matchEle32_1=tree->e1MatchesEle32Path;
    filterEle32_1=tree->e1MatchesEle32Filter;
    matchEle32_2=tree->e2MatchesEle32Path;
    filterEle32_2=tree->e2MatchesEle32Filter;
    passEle27=tree->Ele27WPTightPass;
    passEle35=tree->Ele35WPTightPass;
    matchEle27_1=tree->e1MatchesEle27Path;
    matchEle35_1=tree->e1MatchesEle35Path;
    filterEle27_1=tree->e1MatchesEle27Filter;
    filterEle35_1=tree->e1MatchesEle35Filter;
    matchEle27_2=tree->e2MatchesEle27Path;
    matchEle35_2=tree->e2MatchesEle35Path;
    filterEle27_2=tree->e2MatchesEle27Filter;
    filterEle35_2=tree->e2MatchesEle35Filter;

    genpX=tree->genpX;
    genpY=tree->genpY;
    genpT=tree->genpT;
    genM=tree->genM;
    vispX=tree->vispX;
    vispY=tree->vispY;

    pt_top1=tree->topQuarkPt1;
    pt_top2=tree->topQuarkPt2;

    TLorentzVector tau1;
    TLorentzVector tau2;
    TLorentzVector tau3;
    tau1.SetPtEtaPhiM(tree->e1Pt,tree->e1Eta,tree->e1Phi,tree->e1Mass);
    tau2.SetPtEtaPhiM(tree->e2Pt,tree->e2Eta,tree->e2Phi,tree->e2Mass);
    tau3.SetPtEtaPhiM(tree->tPt,tree->tEta,tree->tPhi,tree->tMass);

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

    for (int j=0; j<27; ++j){
       if (ismc && tree->tZTTGenMatching==5 && tree->tDecayMode==0) mymetvector[j]=mymetvector[j]+tau3-tes_dm0*tau3;
       else if (ismc && tree->tZTTGenMatching==5 && tree->tDecayMode==1) mymetvector[j]=mymetvector[j]+tau3-tes_dm1*tau3;
       else if (ismc && tree->tZTTGenMatching==5 && tree->tDecayMode==10) mymetvector[j]=mymetvector[j]+tau3-tes_dm10*tau3;
       else if (ismc && tree->tZTTGenMatching==5 && tree->tDecayMode==11) mymetvector[j]=mymetvector[j]+tau3-tes_dm11*tau3;
       else if (ismc && (tree->tZTTGenMatching==1 or tree->tZTTGenMatching==3) && tree->tDecayMode==0) mymetvector[j]=mymetvector[j]+tau3-tes_dm0_fakeele*tau3;
       else if (ismc && (tree->tZTTGenMatching==1 or tree->tZTTGenMatching==3) && tree->tDecayMode==1) mymetvector[j]=mymetvector[j]+tau3-tes_dm1_fakeele*tau3;
       else if (ismc && (tree->tZTTGenMatching==2 or tree->tZTTGenMatching==4) && tree->tDecayMode==0) mymetvector[j]=mymetvector[j]+tau3-tes_dm0_fakemu*tau3;
       else if (ismc && (tree->tZTTGenMatching==2 or tree->tZTTGenMatching==4) && tree->tDecayMode==1) mymetvector[j]=mymetvector[j]+tau3-tes_dm1_fakemu*tau3;
    }

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

    if (ismc && tree->tZTTGenMatching==5 && tree->tDecayMode==0) tau3=tau3*tes_dm0;
    else if (ismc && tree->tZTTGenMatching==5 && tree->tDecayMode==1) tau3=tau3*tes_dm1;
    else if (ismc && tree->tZTTGenMatching==5 && tree->tDecayMode==10) tau3=tau3*tes_dm10;
    else if (ismc && tree->tZTTGenMatching==5 && tree->tDecayMode==11) tau3=tau3*tes_dm11;
    if (ismc && (tree->tZTTGenMatching==1 or tree->tZTTGenMatching==3) && tree->tDecayMode==0) tau3=tau3*tes_dm0_fakeele;
    else if (ismc && (tree->tZTTGenMatching==1 or tree->tZTTGenMatching==3) && tree->tDecayMode==1) tau3=tau3*tes_dm1_fakeele;
    if (ismc && (tree->tZTTGenMatching==2 or tree->tZTTGenMatching==4) && tree->tDecayMode==0) tau3=tau3*tes_dm0_fakemu;
    else if (ismc && (tree->tZTTGenMatching==2 or tree->tZTTGenMatching==4) && tree->tDecayMode==1) tau3=tau3*tes_dm1_fakemu;

    nbtag = tree->bjetDeepCSVVeto20Medium_2018_DR0p5;
    nbtagL = tree->bjetDeepCSVVeto20Loose_2018_DR0p5;
    if (year==2016){
      nbtag = tree->bjetDeepCSVVeto20Medium_2016_DR0p5;
      nbtagL = tree->bjetDeepCSVVeto20Loose_2016_DR0p5;
    }
    if (year==2017){
      nbtag = tree->bjetDeepCSVVeto20Medium_2017_DR0p5;
      nbtagL = tree->bjetDeepCSVVeto20Loose_2017_DR0p5;
    }

    gen_match_1=tree->e1ZTTGenMatching;
    gen_match_2=tree->e2ZTTGenMatching;
    gen_match_3=tree->tZTTGenMatching;

    l3_decayMode=tree->tDecayMode;

    float uncorrectedE=tau1.E();
    TLorentzVector myeleScaleUp=tau1*(tree->e1EnergyScaleUp/uncorrectedE);
    TLorentzVector myeleScaleDown=tau1*(tree->e1EnergyScaleDown/uncorrectedE);
    TLorentzVector myeleSigmaUp=tau1*(tree->e1EnergySigmaUp/uncorrectedE);
    TLorentzVector myeleSigmaDown=tau1*(tree->e1EnergySigmaDown/uncorrectedE);
    tau1=tau1*(tree->e1CorrectedEt/uncorrectedE);
    m_1 = tree->e1Mass;
    e_1 = tau1.E();
    pt_1 = tau1.Pt();
    pt_1_ScaleUp = myeleScaleUp.Pt();
    pt_1_ScaleDown = myeleScaleDown.Pt();
    pt_1_SigmaUp = myeleSigmaUp.Pt();
    pt_1_SigmaDown = myeleSigmaDown.Pt();
    phi_1 = tau1.Phi();
    eta_1 = tau1.Eta();
    d0_1 = tree->e1PVDXY;
    dZ_1 = tree->e1PVDZ;
    q_1 = tree->e1Charge;
    iso_1 = tree->e1RelPFIsoRho;
    eid80iso_1=tree->e1MVAIsoWP80;
    eid90iso_1=tree->e1MVAIsoWP90;
    eid80noiso_1=tree->e1MVANoisoWP80;
    eid90noiso_1=tree->e1MVANoisoWP90;

    float uncorrectedE2=tau2.E();
    TLorentzVector myele2ScaleUp=tau2*(tree->e2EnergyScaleUp/uncorrectedE2);
    TLorentzVector myele2ScaleDown=tau2*(tree->e2EnergyScaleDown/uncorrectedE2);
    TLorentzVector myele2SigmaUp=tau2*(tree->e2EnergySigmaUp/uncorrectedE2);
    TLorentzVector myele2SigmaDown=tau2*(tree->e2EnergySigmaDown/uncorrectedE2);
    tau2=tau2*(tree->e2CorrectedEt/uncorrectedE2);
    m_2 = tree->e2Mass;
    e_2 = tau2.E();
    pt_2 = tau2.Pt();
    pt_2_ScaleUp = myele2ScaleUp.Pt();
    pt_2_ScaleDown = myele2ScaleDown.Pt();
    pt_2_SigmaUp = myele2SigmaUp.Pt();
    pt_2_SigmaDown = myele2SigmaDown.Pt();
    phi_2 = tau2.Phi();
    eta_2 = tau2.Eta();
    q_2 = tree->e2Charge;
    d0_2 = tree->e2PVDXY;
    dZ_2 = tree->e2PVDZ;
    iso_2 = tree->e2RelPFIsoRho;
    eid80iso_2=tree->e2MVAIsoWP80;
    eid90iso_2=tree->e2MVAIsoWP90;
    eid80noiso_2=tree->e2MVANoisoWP80;
    eid90noiso_2=tree->e2MVANoisoWP90;

    m_3 = tau3.M();
    if (tree->tDecayMode==0) m_3=tree->tMass;
    px_3 = tau3.Px();
    py_3 = tau3.Py();
    pz_3 = tau3.Pz();
    e_3 = tau3.E();
    pt_3 = tau3.Pt();
    phi_3 = tau3.Phi();
    eta_3 = tau3.Eta();
    dZ_3 = tree->tPVDZ;
    d0_3=tree->tPVDXY;
    q_3 = tree->tCharge;
    trackpt_3=tree->tLeadTrackPt;
    numGenJets=tree->numGenJets;

    decayModeFinding_3=tree->tDecayModeFinding;
    deepVVVLooseVSjet_3=tree->tVVVLooseDeepTau2017v2p1VSjet;
    deepVVLooseVSjet_3=tree->tVVLooseDeepTau2017v2p1VSjet;
    deepVLooseVSjet_3=tree->tVLooseDeepTau2017v2p1VSjet;
    deepLooseVSjet_3=tree->tLooseDeepTau2017v2p1VSjet;
    deepMediumVSjet_3=tree->tMediumDeepTau2017v2p1VSjet;
    deepTightVSjet_3=tree->tTightDeepTau2017v2p1VSjet;
    deepVTightVSjet_3=tree->tVTightDeepTau2017v2p1VSjet;
    deepVLooseVSmu_3=tree->tVLooseDeepTau2017v2p1VSmu;
    deepLooseVSmu_3=tree->tLooseDeepTau2017v2p1VSmu;
    deepMediumVSmu_3=tree->tMediumDeepTau2017v2p1VSmu;
    deepTightVSmu_3=tree->tTightDeepTau2017v2p1VSmu;
    deepVTightVSmu_3=tree->tVTightDeepTau2017v2p1VSmu;
    deepVVVLooseVSe_3=tree->tVVVLooseDeepTau2017v2p1VSe;
    deepVVLooseVSe_3=tree->tVVLooseDeepTau2017v2p1VSe;
    deepVLooseVSe_3=tree->tVLooseDeepTau2017v2p1VSe;
    deepLooseVSe_3=tree->tLooseDeepTau2017v2p1VSe;
    deepMediumVSe_3=tree->tMediumDeepTau2017v2p1VSe;
    deepTightVSe_3=tree->tTightDeepTau2017v2p1VSe;
    deepVTightVSe_3=tree->tVTightDeepTau2017v2p1VSe;

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

    
    jpt_1=tree->j1pt;
    jpt_2=tree->j2pt;
    jeta_1=tree->j1eta;
    jeta_2=tree->j2eta;
    jphi_1=tree->j1phi;
    jphi_2=tree->j2phi;


  NUP=tree->NUP;
  npu=tree->nTruePU;
  npv=tree->nvtx;
  rho=tree->rho;

  Run_Tree->Fill();
}

#endif


