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
#include "HTauTauTree_mmem.h"
#include "RecoilCorrector.h"
//#include "myHelper.h"

using namespace std;
float prefiring_weight,prefiring_weight_up, prefiring_weight_down,bweight_2016,bweight_2017,bweight_2018;
float metcov00,metcov01,metcov10,metcov11;
float bpt_deepflavour_1, beta_deepflavour_1, bphi_deepflavour_1, bflavour_deepflavour_1, bm_deepflavour_1, bscore_deepflavour_1;
float bpt_deepflavour_2, beta_deepflavour_2, bphi_deepflavour_2, bflavour_deepflavour_2, bm_deepflavour_2, bscore_deepflavour_2;
float bpt_deepcsv_1, beta_deepcsv_1, bphi_deepcsv_1, bflavour_deepcsv_1, bm_deepcsv_1, bscore_deepcsv_1;
float bpt_deepcsv_2, beta_deepcsv_2, bphi_deepcsv_2, bflavour_deepcsv_2, bm_deepcsv_2, bscore_deepcsv_2;
float deepVVVLooseVSjet_4,deepVVLooseVSjet_4,deepVLooseVSjet_4,deepLooseVSjet_4,deepMediumVSjet_4,deepTightVSjet_4,deepVTightVSjet_4;
float deepVVVLooseVSe_4,deepVVLooseVSe_4,deepVLooseVSe_4,deepLooseVSe_4,deepMediumVSe_4,deepTightVSe_4,deepVTightVSe_4;
float deepVVVLooseVSmu_4,deepVVLooseVSmu_4,deepVLooseVSmu_4,deepLooseVSmu_4,deepMediumVSmu_4,deepTightVSmu_4,deepVTightVSmu_4;
float deepVVVLooseVSjet_3,deepVVLooseVSjet_3,deepVLooseVSjet_3,deepLooseVSjet_3,deepMediumVSjet_3,deepTightVSjet_3,deepVTightVSjet_3;
float deepVVVLooseVSe_3,deepVVLooseVSe_3,deepVLooseVSe_3,deepLooseVSe_3,deepMediumVSe_3,deepTightVSe_3,deepVTightVSe_3;
float deepVVVLooseVSmu_3,deepVVLooseVSmu_3,deepVLooseVSmu_3,deepLooseVSmu_3,deepMediumVSmu_3,deepTightVSmu_3,deepVTightVSmu_3;
float eid80iso_3,eid80noiso_3,eid90iso_3,eid90noiso_3;
unsigned int run, lumi, evt, NUP = -10;
float trackpt_3, jetPt_3, trackpt_4,jetPt_4;
bool secondMuon=false;
int gen_match_1, gen_match_2, gen_match_3, gen_match_4=0;
float genM,genpT,genpX,genpY,vispX,vispY;
float met_norecoil;
float npu, rho, npv=-1, puweight, weight;
bool isZtt, isZmt, isZet, isZee, isZmm, isZem, isZEE, isZMM, isZLL, isFake;
float e_1, px_1, py_1, pz_1, pt_1, phi_1, eta_1, m_1, q_1, d0_1, dZ_1, mt_1, iso_1;
float e_2, px_2, py_2, pz_2, pt_2, phi_2, eta_2, m_2, q_2, d0_2, dZ_2, mt_2, iso_2;
float e_3, px_3, py_3, pz_3, pt_3, phi_3, eta_3, m_3, q_3, d0_3, dZ_3, mt_3, iso_3, l3_decayMode;
float e_4, px_4, py_4, pz_4, pt_4, phi_4, eta_4, m_4, q_4, d0_4, dZ_4, mt_4, iso_4, l4_decayMode;
float id_m_medium_1,id_m_medium2016_1,id_m_tight_1;
float id_m_medium_2,id_m_medium2016_2,id_m_tight_2;
float id_m_medium_4,id_m_medium2016_4,id_m_tight_4;
float mjj, jdeta, jdphi, dijetpt, dijetphi, hdijetphi, visjeteta, ptvis;
float mjj_JESDown, jdeta_JESDown,mjj_JESUp,jdeta_JESUp;
int njetingap, njetingap20, nbtag, njets, njetspt20,nbtagL;
int njetingap_JESDown, njetingap20_JESDown, njets_JESDown, njetspt20_JESDown;
int njetingap_JESUp, njetingap20_JESUp, njets_JESUp, njetspt20_JESUp;
float met, metphi, mvaMet, mvaMetphi, pzetavis, pzetamiss, mvacov00, mvacov01, mvacov11, mvacov10;
int nb_extra_electrons, nb_extra_muons=0;
float top_reweighting, gen_Higgs_pt, gen_Higgs_mass=1.0;
float extraelec_veto, extramuon_veto, dilepton_veto=false;
float extratau_veto, pt_top1, pt_top2, genweight, dphi_12, dphi_mumet, dphi_taumet;
float aMCatNLO_weight, numGenJets;
float met_px, met_py;
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

float genDR_3;
float Flag_BadChargedCandidateFilter, Flag_BadPFMuonFilter, Flag_EcalDeadCellTriggerPrimitiveFilter, Flag_HBHENoiseFilter, Flag_HBHENoiseIsoFilter, Flag_badCloneMuon, Flag_badGlobalMuon, Flag_eeBadScFilter, Flag_globalTightHalo2016Filter, Flag_goodVertices, Flag_globalSuperTightHalo2016Filter, Flag_badMuons, Flag_duplicateMuons, Flag_ecalBadCalibFilter, Flag_ecalBadCalibReducedMINIAODFilter;
float Rivet_VEta,Rivet_VPt,Rivet_errorCode,Rivet_higgsEta,Rivet_higgsPt,Rivet_nJets25,Rivet_nJets30,Rivet_p4decay_VEta,Rivet_p4decay_VPt,Rivet_prodMode,Rivet_stage0_cat,Rivet_stage1_1_cat_pTjet30GeV,Rivet_stage1_1_fine_cat_pTjet30GeV, Rivet_stage1_cat_pTjet30GeV,Rivet_higgsRapidity,Rivet_j1pt,Rivet_j1eta,Rivet_j1phi,Rivet_j1m,Rivet_j2pt,Rivet_j2eta,Rivet_j2phi,Rivet_j2m;
float bweight;
int channel;
float passDoubleMuMass3p8,passDoubleMuMass8,passMu24,matchMu24_1,filterMu24_1,matchMu24_2,filterMu24_2,passMu27,matchMu27_1,filterMu27_1,matchMu27_2,filterMu27_2,passMu22eta2p1,passTkMu22eta2p1,passMu22,passTkMu22,matchMu22eta2p1_1,matchTkMu22eta2p1_1,matchMu22_1,matchTkMu22_1,filterMu22eta2p1_1,filterTkMu22eta2p1_1,filterMu22_1,filterTkMu22_1,matchMu22eta2p1_2,matchTkMu22eta2p1_2,matchMu22_2,matchTkMu22_2,filterMu22eta2p1_2,filterTkMu22eta2p1_2,filterMu22_2,filterTkMu22_2;
float matchMu24_4,filterMu24_4,matchMu27_4,filterMu27_4,matchMu22eta2p1_4,matchTkMu22eta2p1_4,matchMu22_4,matchTkMu22_4,filterMu22eta2p1_4,filterTkMu22eta2p1_4,filterMu22_4,filterTkMu22_4;
float pt_3_ScaleUp,pt_3_ScaleDown,pt_3_SigmaUp,pt_3_SigmaDown;
float lheweight_muR0p5_muF0p5,lheweight_muR0p5_muF1,lheweight_muR0p5_muF2,lheweight_muR1_muF0p5,lheweight_muR1_muF2,lheweight_muR2_muF0p5,lheweight_muR2_muF1,lheweight_muR2_muF2,PythiaWeight_fsr_muR0p25,PythiaWeight_fsr_muR0p5,PythiaWeight_fsr_muR2,PythiaWeight_fsr_muR4,PythiaWeight_isr_muR0p25,PythiaWeight_isr_muR0p5,PythiaWeight_isr_muR2,PythiaWeight_isr_muR4;

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


void fillTree(TTree *Run_Tree, HTauTauTree_mmem *tree, int entry_tree, int recoil, bool ismc, int year){

    tree->GetEntry(entry_tree);

    metcov00=tree->metcov00;
    metcov01=tree->metcov01;
    metcov10=tree->metcov10;
    metcov11=tree->metcov11;

    passDoubleMuMass3p8=tree->doubleMuDZminMass3p8Pass;
    passDoubleMuMass8=tree->doubleMuDZminMass8Pass;
    passMu24=tree->IsoMu24Pass;
    passMu27=tree->IsoMu27Pass;
    passMu22eta2p1=tree->singleIsoMu22eta2p1Pass;
    passTkMu22eta2p1=tree->singleIsoTkMu22eta2p1Pass;
    passMu22=tree->singleIsoMu22Pass;
    passTkMu22=tree->singleIsoTkMu22Pass;

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
    /*bweight=tree->bweight_2018;
    if (year==2016) bweight=tree->bweight_2016;
    if (year==2017) bweight=tree->bweight_2017;*/

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
    TLorentzVector tau4;
    tau1.SetPtEtaPhiM(tree->m1Pt,tree->m1Eta,tree->m1Phi,tree->m1Mass);
    tau2.SetPtEtaPhiM(tree->m2Pt,tree->m2Eta,tree->m2Phi,tree->m2Mass);
    tau3.SetPtEtaPhiM(tree->ePt,tree->eEta,tree->ePhi,tree->eMass);
    tau4.SetPtEtaPhiM(tree->m3Pt,tree->m3Eta,tree->m3Phi,tree->m3Mass);

    int is_taudecay=3;
    float m12=10000;
    if (tree->m1Charge*tree->m2Charge<0) m12=(tau1+tau2).M();
    float m13=10000;
    if (tree->m1Charge*tree->m3Charge<0) m13=(tau1+tau4).M();
    float m23=10000;
    if (tree->m2Charge*tree->m3Charge<0) m23=(tau2+tau4).M();
    if (fabs(m12-91) < fabs(m13-91) and fabs(m12-91)<fabs(m23-91)) is_taudecay=3;
    if (fabs(m13-91) < fabs(m12-91) and fabs(m13-91)<fabs(m23-91)) is_taudecay=2;
    if (fabs(m23-91) < fabs(m12-91) and fabs(m23-91)<fabs(m13-91)) is_taudecay=1;
   
    if (is_taudecay==1){
      tau1.SetPtEtaPhiM(tree->m2Pt,tree->m2Eta,tree->m2Phi,tree->m2Mass);
      tau2.SetPtEtaPhiM(tree->m3Pt,tree->m3Eta,tree->m3Phi,tree->m3Mass);
      tau4.SetPtEtaPhiM(tree->m1Pt,tree->m1Eta,tree->m1Phi,tree->m1Mass);
    }
    if (is_taudecay==2){
      tau1.SetPtEtaPhiM(tree->m1Pt,tree->m1Eta,tree->m1Phi,tree->m1Mass);
      tau2.SetPtEtaPhiM(tree->m3Pt,tree->m3Eta,tree->m3Phi,tree->m3Mass);
      tau4.SetPtEtaPhiM(tree->m2Pt,tree->m2Eta,tree->m2Phi,tree->m2Mass);
    }

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

    gen_match_3=tree->eZTTGenMatching;

    m_1 = tau1.M();
    e_1 = tau1.E();
    pt_1 = tau1.Pt();
    phi_1 = tau1.Phi();
    eta_1 = tau1.Eta();
    m_2 = tau2.M();
    e_2 = tau2.E();
    pt_2 = tau2.Pt();
    phi_2 = tau2.Phi();
    eta_2 = tau2.Eta();
    m_4 = tau4.M();
    e_4 = tau4.E();
    pt_4 = tau4.Pt();
    phi_4 = tau4.Phi();
    eta_4 = tau4.Eta();

    if (is_taudecay==3){
       q_1 = tree->m1Charge;
       id_m_medium_1 = tree->m1PFIDMedium;
       id_m_tight_1 = tree->m1PFIDTight;
       iso_1 = tree->m1RelPFIsoDBDefault;
       gen_match_1=tree->m1ZTTGenMatching;
       matchMu24_1=tree->m1MatchesIsoMu24Path;
       filterMu24_1=tree->m1MatchesIsoMu24Filter;
       matchMu27_1=tree->m1MatchesIsoMu27Path;
       filterMu27_1=tree->m1MatchesIsoMu27Filter;
       matchMu22eta2p1_1=tree->m1MatchesIsoMu22eta2p1Path;
       matchTkMu22eta2p1_1=tree->m1MatchesIsoTkMu22eta2p1Path;
       matchMu22_1=tree->m1MatchesIsoMu22Path;
       matchTkMu22_1=tree->m1MatchesIsoTkMu22Path;
       filterMu22eta2p1_1=tree->m1MatchesIsoMu22eta2p1Filter;
       filterTkMu22eta2p1_1=tree->m1MatchesIsoTkMu22eta2p1Filter;
       filterMu22_1=tree->m1MatchesIsoMu22Filter;
       filterTkMu22_1=tree->m1MatchesIsoTkMu22Filter;

       q_2 = tree->m2Charge;
       id_m_medium_2 = tree->m2PFIDMedium;
       id_m_tight_2 = tree->m2PFIDTight;
       iso_2 = tree->m2RelPFIsoDBDefault;
       gen_match_2=tree->m2ZTTGenMatching;
       matchMu24_2=tree->m2MatchesIsoMu24Path;
       filterMu24_2=tree->m2MatchesIsoMu24Filter;
       matchMu27_2=tree->m2MatchesIsoMu27Path;
       filterMu27_2=tree->m2MatchesIsoMu27Filter;
       matchMu22eta2p1_2=tree->m2MatchesIsoMu22eta2p1Path;
       matchTkMu22eta2p1_2=tree->m2MatchesIsoTkMu22eta2p1Path;
       matchMu22_2=tree->m2MatchesIsoMu22Path;
       matchTkMu22_2=tree->m2MatchesIsoTkMu22Path;
       filterMu22eta2p1_2=tree->m2MatchesIsoMu22eta2p1Filter;
       filterTkMu22eta2p1_2=tree->m2MatchesIsoTkMu22eta2p1Filter;
       filterMu22_2=tree->m2MatchesIsoMu22Filter;
       filterTkMu22_2=tree->m2MatchesIsoTkMu22Filter;

       q_4 = tree->m3Charge;
       id_m_medium_4 = tree->m3PFIDMedium;
       id_m_tight_4 = tree->m3PFIDTight;
       iso_4 = tree->m3RelPFIsoDBDefault;
       gen_match_4=tree->m3ZTTGenMatching;
       matchMu24_4=tree->m3MatchesIsoMu24Path;
       filterMu24_4=tree->m3MatchesIsoMu24Filter;
       matchMu27_4=tree->m3MatchesIsoMu27Path;
       filterMu27_4=tree->m3MatchesIsoMu27Filter;
       matchMu22eta2p1_4=tree->m3MatchesIsoMu22eta2p1Path;
       matchTkMu22eta2p1_4=tree->m3MatchesIsoTkMu22eta2p1Path;
       matchMu22_4=tree->m3MatchesIsoMu22Path;
       matchTkMu22_4=tree->m3MatchesIsoTkMu22Path;
       filterMu22eta2p1_4=tree->m3MatchesIsoMu22eta2p1Filter;
       filterTkMu22eta2p1_4=tree->m3MatchesIsoTkMu22eta2p1Filter;
       filterMu22_4=tree->m3MatchesIsoMu22Filter;
       filterTkMu22_4=tree->m3MatchesIsoTkMu22Filter;
    }
    if (is_taudecay==2){
       q_1 = tree->m1Charge;
       id_m_medium_1 = tree->m1PFIDMedium;
       id_m_tight_1 = tree->m1PFIDTight;
       iso_1 = tree->m1RelPFIsoDBDefault;
       gen_match_1=tree->m1ZTTGenMatching;
       matchMu24_1=tree->m1MatchesIsoMu24Path;
       filterMu24_1=tree->m1MatchesIsoMu24Filter;
       matchMu27_1=tree->m1MatchesIsoMu27Path;
       filterMu27_1=tree->m1MatchesIsoMu27Filter;
       matchMu22eta2p1_1=tree->m1MatchesIsoMu22eta2p1Path;
       matchTkMu22eta2p1_1=tree->m1MatchesIsoTkMu22eta2p1Path;
       matchMu22_1=tree->m1MatchesIsoMu22Path;
       matchTkMu22_1=tree->m1MatchesIsoTkMu22Path;
       filterMu22eta2p1_1=tree->m1MatchesIsoMu22eta2p1Filter;
       filterTkMu22eta2p1_1=tree->m1MatchesIsoTkMu22eta2p1Filter;
       filterMu22_1=tree->m1MatchesIsoMu22Filter;
       filterTkMu22_1=tree->m1MatchesIsoTkMu22Filter;

       q_2 = tree->m3Charge;
       id_m_medium_2 = tree->m3PFIDMedium;
       id_m_tight_2 = tree->m3PFIDTight;
       iso_2 = tree->m3RelPFIsoDBDefault;
       gen_match_2=tree->m3ZTTGenMatching;
       matchMu24_2=tree->m3MatchesIsoMu24Path;
       filterMu24_2=tree->m3MatchesIsoMu24Filter;
       matchMu27_2=tree->m3MatchesIsoMu27Path;
       filterMu27_2=tree->m3MatchesIsoMu27Filter;
       matchMu22eta2p1_2=tree->m3MatchesIsoMu22eta2p1Path;
       matchTkMu22eta2p1_2=tree->m3MatchesIsoTkMu22eta2p1Path;
       matchMu22_2=tree->m3MatchesIsoMu22Path;
       matchTkMu22_2=tree->m3MatchesIsoTkMu22Path;
       filterMu22eta2p1_2=tree->m3MatchesIsoMu22eta2p1Filter;
       filterTkMu22eta2p1_2=tree->m3MatchesIsoTkMu22eta2p1Filter;
       filterMu22_2=tree->m3MatchesIsoMu22Filter;
       filterTkMu22_2=tree->m3MatchesIsoTkMu22Filter;

       q_4 = tree->m2Charge;
       id_m_medium_4 = tree->m2PFIDMedium;
       id_m_tight_4 = tree->m2PFIDTight;
       iso_4 = tree->m2RelPFIsoDBDefault;
       gen_match_4=tree->m2ZTTGenMatching;
       matchMu24_4=tree->m2MatchesIsoMu24Path;
       filterMu24_4=tree->m2MatchesIsoMu24Filter;
       matchMu27_4=tree->m2MatchesIsoMu27Path;
       filterMu27_4=tree->m2MatchesIsoMu27Filter;
       matchMu22eta2p1_4=tree->m2MatchesIsoMu22eta2p1Path;
       matchTkMu22eta2p1_4=tree->m2MatchesIsoTkMu22eta2p1Path;
       matchMu22_4=tree->m2MatchesIsoMu22Path;
       matchTkMu22_4=tree->m2MatchesIsoTkMu22Path;
       filterMu22eta2p1_4=tree->m2MatchesIsoMu22eta2p1Filter;
       filterTkMu22eta2p1_4=tree->m2MatchesIsoTkMu22eta2p1Filter;
       filterMu22_4=tree->m2MatchesIsoMu22Filter;
       filterTkMu22_4=tree->m2MatchesIsoTkMu22Filter;
    }
    if (is_taudecay==1){
       q_1 = tree->m2Charge;
       id_m_medium_1 = tree->m2PFIDMedium;
       id_m_tight_1 = tree->m2PFIDTight;
       iso_1 = tree->m2RelPFIsoDBDefault;
       gen_match_1=tree->m2ZTTGenMatching;
       matchMu24_1=tree->m2MatchesIsoMu24Path;
       filterMu24_1=tree->m2MatchesIsoMu24Filter;
       matchMu27_1=tree->m2MatchesIsoMu27Path;
       filterMu27_1=tree->m2MatchesIsoMu27Filter;
       matchMu22eta2p1_1=tree->m2MatchesIsoMu22eta2p1Path;
       matchTkMu22eta2p1_1=tree->m2MatchesIsoTkMu22eta2p1Path;
       matchMu22_1=tree->m2MatchesIsoMu22Path;
       matchTkMu22_1=tree->m2MatchesIsoTkMu22Path;
       filterMu22eta2p1_1=tree->m2MatchesIsoMu22eta2p1Filter;
       filterTkMu22eta2p1_1=tree->m2MatchesIsoTkMu22eta2p1Filter;
       filterMu22_1=tree->m2MatchesIsoMu22Filter;
       filterTkMu22_1=tree->m2MatchesIsoTkMu22Filter;

       q_2 = tree->m3Charge;
       id_m_medium_2 = tree->m3PFIDMedium;
       id_m_tight_2 = tree->m3PFIDTight;
       iso_2 = tree->m3RelPFIsoDBDefault;
       gen_match_2=tree->m3ZTTGenMatching;
       matchMu24_2=tree->m3MatchesIsoMu24Path;
       filterMu24_2=tree->m3MatchesIsoMu24Filter;
       matchMu27_2=tree->m3MatchesIsoMu27Path;
       filterMu27_2=tree->m3MatchesIsoMu27Filter;
       matchMu22eta2p1_2=tree->m3MatchesIsoMu22eta2p1Path;
       matchTkMu22eta2p1_2=tree->m3MatchesIsoTkMu22eta2p1Path;
       matchMu22_2=tree->m3MatchesIsoMu22Path;
       matchTkMu22_2=tree->m3MatchesIsoTkMu22Path;
       filterMu22eta2p1_2=tree->m3MatchesIsoMu22eta2p1Filter;
       filterTkMu22eta2p1_2=tree->m3MatchesIsoTkMu22eta2p1Filter;
       filterMu22_2=tree->m3MatchesIsoMu22Filter;
       filterTkMu22_2=tree->m3MatchesIsoTkMu22Filter;

       q_4 = tree->m1Charge;
       id_m_medium_4 = tree->m1PFIDMedium;
       id_m_tight_4 = tree->m1PFIDTight;
       iso_4 = tree->m1RelPFIsoDBDefault;
       gen_match_4=tree->m1ZTTGenMatching;
       matchMu24_4=tree->m1MatchesIsoMu24Path;
       filterMu24_4=tree->m1MatchesIsoMu24Filter;
       matchMu27_4=tree->m1MatchesIsoMu27Path;
       filterMu27_4=tree->m1MatchesIsoMu27Filter;
       matchMu22eta2p1_4=tree->m1MatchesIsoMu22eta2p1Path;
       matchTkMu22eta2p1_4=tree->m1MatchesIsoTkMu22eta2p1Path;
       matchMu22_4=tree->m1MatchesIsoMu22Path;
       matchTkMu22_4=tree->m1MatchesIsoTkMu22Path;
       filterMu22eta2p1_4=tree->m1MatchesIsoMu22eta2p1Filter;
       filterTkMu22eta2p1_4=tree->m1MatchesIsoTkMu22eta2p1Filter;
       filterMu22_4=tree->m1MatchesIsoMu22Filter;
       filterTkMu22_4=tree->m1MatchesIsoTkMu22Filter;
    }


    float uncorrectedE=tau3.E();
    TLorentzVector myeleScaleUp=tau3*(tree->eEnergyScaleUp/uncorrectedE);
    TLorentzVector myeleScaleDown=tau3*(tree->eEnergyScaleDown/uncorrectedE);
    TLorentzVector myeleSigmaUp=tau3*(tree->eEnergySigmaUp/uncorrectedE);
    TLorentzVector myeleSigmaDown=tau3*(tree->eEnergySigmaDown/uncorrectedE);
    tau3=tau3*(tree->eCorrectedEt/uncorrectedE);
    m_3 = tree->eMass;
    e_3 = tau3.E();
    pt_3 = tau3.Pt();
    pt_3_ScaleUp = myeleScaleUp.Pt();
    pt_3_ScaleDown = myeleScaleDown.Pt();
    pt_3_SigmaUp = myeleSigmaUp.Pt();
    pt_3_SigmaDown = myeleSigmaDown.Pt();
    phi_3 = tau3.Phi();
    eta_3 = tau3.Eta();
    d0_3 = tree->ePVDXY;
    dZ_3 = tree->ePVDZ;
    q_3 = tree->eCharge;
    iso_3 = tree->eRelPFIsoRho;
    eid80iso_3=tree->eMVAIsoWP80;
    eid90iso_3=tree->eMVAIsoWP90;
    eid80noiso_3=tree->eMVANoisoWP80;
    eid90noiso_3=tree->eMVANoisoWP90;

  channel=5; 
  NUP=tree->NUP;
  npu=tree->nTruePU;
  npv=tree->nvtx;
  rho=tree->rho;

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


  Run_Tree->Fill();
}

#endif


