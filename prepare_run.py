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

#    if args.year=="2016" and args.sample=="data" and args.channel=="et":
#       place="/hdfs/store/user/caillol/ZHTT_2016_15may_data/"
#       datatype="data"
#       name=[
#"data_SingleElectron_Run2016B_v1","SingleEleBv1","0","2016",
#"data_SingleElectron_Run2016B_v2","SingleEleBv2","0","2016",
#"data_SingleElectron_Run2016C","SingleEleC","0","2016",
#"data_SingleElectron_Run2016D","SingleEleD","0","2016",
#"data_SingleElectron_Run2016E","SingleEleE","0","2016",
#"data_SingleElectron_Run2016F","SingleEleF","0","2016",
#"data_SingleElectron_Run2016G","SingleEleG","0","2016",
#"data_SingleElectron_Run2016H","SingleEleH","0","2016"
#]

    if args.year=="2018" and args.sample=="mc":
       place="/hdfs/store/user/caillol/ZHTT_2018_15may_mc/"
       datatype="mc"
       name=[
"GluGluToContinToZZTo2e2tau_13TeV_MCFM701_pythia8_-102X_upgrade2018_realistic_v15-v3","GGZZ2e2tau","0","2018",
]

    datadir="/nfs_scratch/caillol/haabbtt_"+args.channel+args.year+"_26jun/"
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

