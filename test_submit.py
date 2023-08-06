import os
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('--sample', '-s', default=None, help='Output name')
parser.add_argument('--channel', '-c', default=None, help='Output name')
parser.add_argument('--year', '-y', default=None, help='Output name')

args = parser.parse_args()

if __name__ == "__main__":

    place="/hdfs/store/user/pdas/VBFHToTauTau_M125_13TeV_powheg_pythia8/crab_VBFHtautau-sync/230804_221156/0000/"
    datatype="mc"
    name=["VBFHToTauTau_M125_13TeV_powheg_pythia8","VBFHTT","Z","2018"]

    datadir="/hdfs/store/user/pdas/haabbtt_"+args.channel+args.year
    all_File = open("do_submit_"+args.sample+"_"+args.channel+args.year+".sh" , 'w')
    line=""
    line+="mkdir -p "+datadir+ "\n"
    for j in range(0,len(name)/4):
       print name[4*j],name[4*j+1],name[4*j+2]
       submit_File = open("Submit_"+name[4*j+1]+"_"+datatype+"_"+args.channel+args.year+".sh" , 'w')
       line+="mkdir -p "+datadir+"Out_"+name[4*j+1]+"\n"
       line+="sh Submit_"+name[4*j+1]+"_"+datatype+"_"+args.channel+args.year+".sh" +"\n"
       f=os.popen("ls -t " + place + "/out* | sort")
       command1=""
       ligne=0
       for i in f.readlines():
           command1=command1+"./skim_"+args.channel+".exe "+datatype+" "+datadir+"Out_"+name[4*j+1]+"/"+name[4*j+1]+str(ligne)+".root " + i[0:-1] + " " + name[4*j+2] + " " + name[4*j+3] + "\n"
           ligne=ligne+1
       submit_File.write(command1)
       submit_File.close()
    all_File.write(line)
    all_File.close()
