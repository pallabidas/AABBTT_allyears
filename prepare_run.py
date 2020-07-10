import os
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('--sample', '-s', default=None, help='Output name')
parser.add_argument('--channel', '-c', default=None, help='Output name')
parser.add_argument('--year', '-y', default=None, help='Output name')

args = parser.parse_args()

if __name__ == "__main__":

    place=""
    datatype=""
    name=[]

    ###################################################
    # 2018 data 
    ###################################################
    if args.year=="2018" and args.sample=="data" and args.channel=="mt":
       place="/hdfs/store/user/caillol/HAABBTT_2018_12jun_data/"
       datatype="data"
       name=[
"data_SingleMuon_Run2018C-17Sep2018","SingleMuA","0","2018",
"data_SingleMuon_Run2018C-17Sep2018","SingleMuB","0","2018",
"data_SingleMuon_Run2018C-17Sep2018","SingleMuC","0","2018",
"data_SingleMuon_Run2018D-PromptReco","SingleMuD","0","2018"
]
    if args.year=="2018" and args.sample=="data" and args.channel=="et":
       place="/hdfs/store/user/caillol/HAABBTT_2018_12jun_data/"
       datatype="data"
       name=[
"data_EGamma_Run2018C-17Sep2018","SingleEleA","0","2018",
"data_EGamma_Run2018C-17Sep2018","SingleEleB","0","2018",
"data_EGamma_Run2018C-17Sep2018","SingleEleC","0","2018",
"data_EGamma_Run2018D-PromptReco","SingleEleD","0","2018"
]
    if args.year=="2018" and args.sample=="data" and args.channel=="em":
       place="/hdfs/store/user/caillol/HAABBTT_2018_12jun_data/"
       datatype="data"
       name=[
"data_MuonEG_Run2018C-17Sep2018","MuonEleA","0","2018",
"data_MuonEG_Run2018C-17Sep2018","MuonEleB","0","2018",
"data_MuonEG_Run2018C-17Sep2018","MuonEleC","0","2018",
"data_MuonEG_Run2018D-PromptReco","MuonEleD","0","2018"
]
    if args.year=="2018" and args.sample=="data" and args.channel=="tt":
       place="/hdfs/store/user/caillol/HAABBTT_2018_12jun_data/"
       datatype="data"
       name=[
"data_Tau_Run2018C-17Sep2018","DoubleTauA","0","2018",
"data_Tau_Run2018C-17Sep2018","DoubleTauB","0","2018",
"data_Tau_Run2018C-17Sep2018","DoubleTauC","0","2018",
"data_Tau_Run2018D-PromptReco","DoubleTauD","0","2018"
]

    if args.year=="2018" and args.sample=="mc":
       place="/hdfs/store/user/caillol/HAABBTT_2018_12jun_mc/"
       datatype="mc"
       name=[
"DY1JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8_-102X_upgrade2018_realistic_v15-v1","DY1_v1","Z","2018",
"DY1JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8_-102X_upgrade2018_realistic_v15-v2","DY1_v2","Z","2018",
"DY2JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8_-102X_upgrade2018_realistic_v15-v1","DY2_v1","Z","2018",
"DY2JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8_-102X_upgrade2018_realistic_v15-v2","DY2_v2","Z","2018",
"DY3JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8_-102X_upgrade2018_realistic_v15-v1","DY3_v1","Z","2018",
"DY3JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8_-102X_upgrade2018_realistic_v15-v2","DY3_v2","Z","2018",
"DY4JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8_-102X_upgrade2018_realistic_v15-v1","DY4_v1","Z","2018",
"DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8_-102X_upgrade2018_realistic_v15-v1","DY1_v1","Z","2018",
"GluGluHToTauTau_M125_13TeV_powheg_pythia8_-102X_upgrade2018_realistic_v15-v2","GGHTT","Z","2018",
"ST_t-channel_antitop_4f_InclusiveDecays_TuneCP5_13TeV-powheg-madspin-pythia8_-102X_upgrade2018_realistic_v15-v1","ST_t_antitop","0","2018",
"ST_t-channel_top_5f_TuneCP5_13TeV-powheg-pythia8_-102X_upgrade2018_realistic_v15-v1","ST_t_top","0","2018",
"ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8_-102X_upgrade2018_realistic_v15_ext1-v1","ST_tW_antitop","0","2018",
"ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8_-102X_upgrade2018_realistic_v15_ext1-v1","ST_tW_top","0","2018",
"TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8_-102X_upgrade2018_realistic_v15-v1","TTTo2L2Nu","0","2018",
"TTToHadronic_TuneCP5_13TeV-powheg-pythia8_-102X_upgrade2018_realistic_v15-v1","TTToHadronic_v1","0","2018",
"TTToHadronic_TuneCP5_13TeV-powheg-pythia8_-102X_upgrade2018_realistic_v15_ext2-v2","TTToHadronic_v2","0","2018",
"TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_-102X_upgrade2018_realistic_v15-v1","TTToSemiLeptonic_v1","0","2018",
"TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_-102X_upgrade2018_realistic_v15_ext3-v2","TTToSemiLeptonic_v2","0","2018",
"VBFHToTauTau_M125_13TeV_powheg_pythia8_-102X_upgrade2018_realistic_v15_ext1-v1","VBFHTT","Z","2018",
"VVTo2L2Nu_13TeV_amcatnloFXFX_madspin_pythia8_-102X_upgrade2018_realistic_v15-v1","VV2L2Nu","0","2018",
"W1JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8_-102X_upgrade2018_realistic_v15-v2","W1_v1","W","2018",
"W2JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8_-102X_upgrade2018_realistic_v15-v1","W2_v1","W","2018",
"W2JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8_-102X_upgrade2018_realistic_v15-v2","W2_v2","W","2018",
"W3JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8_-102X_upgrade2018_realistic_v15-v1","W3_v1","W","2018",
"W3JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8_-102X_upgrade2018_realistic_v15-v2","W3_v2","W","2018",
"W4JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8_-102X_upgrade2018_realistic_v15-v1","W4_v1","W","2018",
"W4JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8_-102X_upgrade2018_realistic_v15-v2","W4_v2","W","2018",
"WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8_-102X_upgrade2018_realistic_v15-v2","W_v1","W","2018",
"WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8_-102X_upgrade2018_realistic_v15-v1","WZ2L2Q","0","2018",
"WZTo3LNu_TuneCP5_13TeV-amcatnloFXFX-pythia8_-102X_upgrade2018_realistic_v15-v1","WZ3LNu_v1","0","2018",
"WZTo3LNu_TuneCP5_13TeV-amcatnloFXFX-pythia8_-102X_upgrade2018_realistic_v15_ext1-v2","WZ3LNu_v2","0","2018",
"WminusHToTauTau_M125_13TeV_powheg_pythia8_-102X_upgrade2018_realistic_v15-v2","WminusHTT","0","2018",
"WplusHToTauTau_M125_13TeV_powheg_pythia8_-102X_upgrade2018_realistic_v15-v2","WplusHTT","0","2018",
"ZHToTauTau_M125_13TeV_powheg_pythia8_-102X_upgrade2018_realistic_v15-v2","ZHTT","0","2018",
"ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8_-102X_upgrade2018_realistic_v15-v1","ZZ2L2Q","0","2018",
"ZZTo4L_TuneCP5_13TeV-amcatnloFXFX-pythia8_-102X_upgrade2018_realistic_v15-v1","ZZ4L","0","2018",
"ggZH_HToTauTau_ZToLL_M125_13TeV_powheg_pythia8_-102X_upgrade2018_realistic_v15-v1","GGZHLLTT","0","2018",
"ggZH_HToTauTau_ZToNuNu_M125_13TeV_powheg_pythia8_-102X_upgrade2018_realistic_v15-v1","GGZHNNTT","0","2018",
"ggZH_HToTauTau_ZToQQ_M125_13TeV_powheg_pythia8_-102X_upgrade2018_realistic_v15-v1","GGZHQQTT","0","2018",
]


    #####################################################################
    # 2017 MC 
    #####################################################################
    if args.year=="2017" and args.sample=="mc":
       place="/hdfs/store/user/aloeliger/SMHTT_2017_24Jun_2020/"
       datatype="mc"
       name=[
"VBFHToTauTau_M125_13TeV_powheg_pythia8_v2-PU2017_12Apr2018_new_pmx_94X_mc2017_realistic_v14-v1","VBFHTT","Z","2017"
]

    datadir="/nfs_scratch/caillol/haabbtt_"+args.channel+args.year+"_1jul/"
    all_File = open("do_submit_"+datatype+"_"+args.channel+args.year+".sh" , 'w')
    line=""
    line+="mkdir -p "+datadir+ "\n"
    for j in range(0,len(name)/4):
       print name[4*j],name[4*j+1],name[4*j+2]
       submit_File = open("Submit_"+name[4*j+1]+"_"+datatype+"_"+args.channel+args.year+".sh" , 'w')
       line+="mkdir -p "+datadir+"Out_"+name[4*j+1]+"\n"
       line+="sh Submit_"+name[4*j+1]+"_"+datatype+"_"+args.channel+args.year+".sh" +"\n"
       f=os.popen("ls -t " + place+name[4*j] + "/make* | sort")
       command1=""
       ligne=0
       for i in f.readlines():
	   command1=command1+"./skim_"+args.channel+".exe "+datatype+" "+datadir+"Out_"+name[4*j+1]+"/"+name[4*j+1]+str(ligne)+".root " + i[0:-1] + " " + name[4*j+2] + " " + name[4*j+3] + "\n"
           ligne=ligne+1
       submit_File.write(command1)
       submit_File.close()
    all_File.write(line)
    all_File.close()

