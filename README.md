Compile:
------
```bash
./Make.sh skim_mt.cc
```

Run over one file:
------------------

The order of the terms is exe - mc/data/embedded - output - input - /Z/W/0 (for the recoil corrections) - year
```bash
./skim_mt.exe mc /nfs_scratch/caillol/haabbtt_mt2018_1jul/Out_VBFHTT/VBFHTT61.root /hdfs/store/user/caillol/HAABBTT_2018_12jun_mc/VBFHToTauTau_M125_13TeV_powheg_pythia8_-102X_upgrade2018_realistic_v15_ext1-v1/make_ntuples_cfg-D3812ECF-8026-5A4B-9FF9-1AA0AE012E09.root Z 2018
```

Prepare running over all files:
-------------------------------

For example for 2018 MC, mutau final state:
```bash
python prepare_run.py --sample mc --channel mt --year 2018
```

Then in screen:
```bash
sh do_submit_mc_mt2018.sh
```

Can split in different files/screens to go faster, or submit several jobs via condor.

After, hadd all the output files. 

